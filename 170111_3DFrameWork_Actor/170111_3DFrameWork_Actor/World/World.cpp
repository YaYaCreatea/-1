#include "World.h"
#include "../Field/Field.h"
#include "../ActorGroup/ActorGroup.h"
#include "../Actor/Actor.h"

#include <GSeffect.h>

World::World()
{
	initialize();
}

void World::initialize()
{
	clear();
	actors_.add(ActorGroup::Player);
	actors_.add(ActorGroup::PlayerAttack);
	actors_.add(ActorGroup::Enemy);
	actors_.add(ActorGroup::EnemyAttack);
	actors_.add(ActorGroup::Effect);
	actors_.add(ActorGroup::Neutral);
}

void World::update(float delta_time)
{
	actors_.update(delta_time);

	actors_.collide(ActorGroup::Player, ActorGroup::Enemy);
	actors_.collide(ActorGroup::Player, ActorGroup::EnemyAttack);
	actors_.collide(ActorGroup::PlayerAttack, ActorGroup::Enemy);

	actors_.remove();

	camera_->update(delta_time);
	light_->update(delta_time);

	//エフェクトの更新
	gsUpdateEffect(delta_time);
}

void World::draw() const
{
	camera_->draw();
	light_->draw();
	field_->draw();
	actors_.draw();

	//カメラの同期
	gsSetEffectCamera();
	//エフェクトの描画
	gsDrawEffect();
}

void World::handle_message(EventMessage message, void * param)
{
	//ワールドのメッセージ処理
	listener_(message, param);

	//アクターのメッセージ処理
	actors_.handle_message(message, param);
	camera_->handle_message(message, param);
	light_->handle_message(message, param);
}

void World::add_event_message_listener(EventMessageListener listener)
{
	listener_ = listener;
}

void World::add_field(const FieldPtr & field)
{
	field_ = field;
}

void World::add_camera(const ActorPtr & camera)
{
	camera_ = camera;
}

void World::add_light(const ActorPtr & light)
{
	light_ = light;
}

void World::clear()
{
	actors_.clear();
	field_ = nullptr;
	light_ = nullptr;
	camera_ = nullptr;
	listener_ = [](EventMessage, void*) {};
}

void World::add_actor(ActorGroup group, const ActorPtr & actor)
{
	actors_.add(group, actor);
}

ActorPtr World::find_actor(ActorGroup group, const std::string & name) const
{
	return actors_.find(group, name);
}

unsigned int World::count_actor(ActorGroup group) const
{
	return actors_.count(group);
}

void World::each_actor(ActorGroup group, std::function<void(const ActorPtr&)> fn) const
{
	actors_.each(group, fn);
}

void World::send_message(EventMessage message, void * param)
{
	handle_message(message, param);
}

Field & World::get_field()
{
	return *field_;
}