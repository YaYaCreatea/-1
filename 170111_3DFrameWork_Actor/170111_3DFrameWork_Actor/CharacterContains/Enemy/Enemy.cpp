#include "Enemy.h"
#include "../../World/IWorld.h"
#include "../../ActorGroup/ActorGroup.h"
#include "../../Field/Field.h"
#include "../../CollisionDetection/Ray.h"
#include "../../EventMessage/EventMessage.h"

Enemy::Enemy(IWorld & world, const GSvector3 & position)
	:Actor{ world,"Enemy",position,BoundingSphere{2.0f} }, anmTimer_{ 0.0f }
{
}

void Enemy::update(float deltaTime)
{
	const auto player = world_->find_actor(ActorGroup::Player, "Player");
	if (player != nullptr)
	{
		//ƒvƒŒƒCƒ„[‚Æ‚Ì‹——£‚ð”»’è
		if (position_.distance(player->position()) < 10.0f)
		{
			const auto target = (player->position() - position_).getNormalized();
			position_ += target*0.1f*deltaTime;
			rotation_.identity().setAxisZ(target).nomalizeAxisZ();
		}
	}

	const Ray ray{ position_,{0.0f,0.1f,0.0f} };
	GSvector3 intersect;
	if (world_->field()->collision(ray, &intersect))
		position_ = intersect;

	anmTimer_ += deltaTime;
}

void Enemy::draw() const
{
	gsBindSkeleton(2);
	gsBindAnimation(2, 2, anmTimer_);
	glPushMatrix();
	glMultMatrixf(pose());
	glTranslatef(0.0f, 6.0f, 0.0f);
	gsDrawMesh(2);
	glPopMatrix();
}

//Õ“Ëˆ—
void Enemy::react(Actor & other)
{
	world_->add_actor(ActorGroup::Effect, new_actor<Explosion>(*world_, position_));
	int score = 10;
	world_->send_message(EventMessage::AddScore, &score);
	die();
}

void Enemy::handle_message(EventMessage message, void * param)
{
	switch (message)
	{
	case EventMessage::EnemyDead:
		die();

		break;
	}
}
