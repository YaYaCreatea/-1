#include "ActorGroupManager.h"

void ActorGroupManager::add(ActorGroup group)
{
	actor_group_map_[group].clear();
}

void ActorGroupManager::add(ActorGroup group, const ActorPtr & actor)
{
	actor_group_map_[group].add(actor);
}

void ActorGroupManager::update(float delta_time)
{
	for (auto& pair : actor_group_map_)
		pair.second.update(delta_time);
}

void ActorGroupManager::draw() const
{
	for (auto& pair : actor_group_map_)
		draw(pair.first);
}

void ActorGroupManager::draw(ActorGroup group) const
{
	actor_group_map_.at(group).draw();
}

void ActorGroupManager::clear()
{
	actor_group_map_.clear();
}

ActorPtr ActorGroupManager::find(ActorGroup group, const std::string & name) const
{
	return actor_group_map_.at(group).find(name);
}

unsigned int ActorGroupManager::count(ActorGroup group) const
{
	return actor_group_map_.at(group).count();
}

void ActorGroupManager::each(ActorGroup group, std::function<void(const ActorPtr&)> fn) const
{
	actor_group_map_.at(group).each(fn);
}

void ActorGroupManager::collide(ActorGroup group_1, ActorGroup group_2)
{
	actor_group_map_[group_1].collide(actor_group_map_[group_2]);
}

void ActorGroupManager::remove()
{
	for (auto& pair : actor_group_map_)
		pair.second.remove();
}

void ActorGroupManager::handle_message(EventMessage message, void * param)
{
	for (auto& pair : actor_group_map_)
		pair.second.handle_message(message, param);
}