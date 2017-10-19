#include "Camera.h"
#include "../World/IWorld.h"
#include "../Actor/ActorGroup.h"

//コンストラクタ
Camera::Camera(IWorld & world)
	:Actor{ world,"Camera",{0.0f,0.0f,0.0f},BoundingSphere{1.0f} }
{
}

//更新
void Camera::update(float deltaTime)
{
	const auto player = world_->find_actor(ActorGroup::Player, "Player");
	if (player == nullptr)return;
	position_ = player->get_position() + GSvector3{ 0.0f,2.0f,0.0f };
	rotation_ = player->get_rotation();
}

//描画
void Camera::draw() const
{
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(pose().convertViewRH());
}