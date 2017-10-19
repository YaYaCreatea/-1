#include "Animation.h"

Animation::Animation(GSuint animation, GSuint motion)
{
	animation_ = animation;
	motion_ = motion;
	gsCalculateAnimation(
		animation_,
		motion_,
		motion_timer_,
		matrices_.data()
		);
}

void Animation::update(float delta_time)
{
	gsCalculateAnimation(
		animation_,
		motion_,
		motion_timer_,
		matrices_.data()
		);

	motion_timer_ += delta_time;
}

void Animation::change_motion(GSuint motion)
{
	//åªç›Ç∆ìØÇ∂ÉÇÅ[ÉVÉáÉìÇÃèÍçáÇÕâΩÇ‡ÇµÇ»Ç¢
	if (motion == motion_)return;
	motion_ = motion;
	motion_timer_ = 0.0f;
	gsCalculateAnimation(
		animation_,
		motion_,
		motion_timer_,
		matrices_.data()
		);
}

GSuint Animation::current_motion() const
{
	return motion_;
}

GSfloat Animation::end_time() const
{
	return (GSfloat)gsGetEndAnimationTime(animation_, motion_);
}

GSuint Animation::get_bone_count() const
{
	return gsGetAnimationNumBones(animation_, motion_);
}

const Animation::Matrices & Animation::get_bone_matrices() const
{
	return matrices_;
}