#include "Actor.h"

void Actor::update(float)
{
}

void Actor::draw() const
{
}

void Actor::react(Actor &)
{
}

void Actor::handle_message(EventMessage, void *)
{
}

void Actor::collide(Actor & other)
{
	if (is_collide(other))
	{
		react(other);
		other.react(*this);
	}
}

void Actor::die()
{
	dead_ = true;
}

bool Actor::is_collide(const Actor & other) const
{
	return get_body().intersects(other.get_body());
}

bool Actor::is_dead() const
{
	return dead_;
}

const std::string & Actor::get_name() const
{
	return name_;
}

GSvector3 Actor::get_position() const
{
	return position_;
}

GSmatrix4 Actor::get_rotation() const
{
	return rotation_;
}

GSvector3 Actor::get_velocity() const
{
	return velocity_;
}

GSmatrix4 Actor::get_pose() const
{
	return get_rotation().setPosition(position_);
}

BoundingSphere Actor::get_body() const
{
	return body_.transform(get_pose());;
}