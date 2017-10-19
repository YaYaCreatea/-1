#include "LerpAnimation.h"

LerpAnimation::LerpAnimation(GSuint animation, GSuint motion)
	:animation_{ animation }, motion_{ motion }, prev_motion_{ motion }
{
	gsCalculateAnimation(
		animation_,
		motion_,
		motion_timer_,
		matrices_.data()
		);
}

void LerpAnimation::update(float delta_time)
{
	gsCalculateAnimationLerp(
		animation_, prev_motion_, prev_motion_timer_,
		animation_, motion_, motion_timer_,
		lerp_timer / LERP_TIME,
		matrices_.data()
		);

	motion_timer_ += delta_time;
	lerp_timer = std::min(lerp_timer + delta_time, LERP_TIME);
}

void LerpAnimation::change_motion(GSuint motion)
{
	//åªç›Ç∆ìØÇ∂ÉÇÅ[ÉVÉáÉìÇÃèÍçáÇÕâΩÇ‡ÇµÇ»Ç¢
	if (motion == motion_)return;
	prev_motion_ = motion_;
	prev_motion_timer_ = motion_timer_;
	motion_ = motion;
	motion_timer_ = 0.0f;
	lerp_timer = 0.0f;

	gsCalculateAnimationLerp(
		animation_, prev_motion_, prev_motion_timer_,
		animation_, motion_, motion_timer_,
		lerp_timer / LERP_TIME,
		matrices_.data()
		);
}

GSuint LerpAnimation::current_motion() const
{
	return motion_;
}

GSfloat LerpAnimation::end_time() const
{
	return gsGetEndAnimationTime(animation_, motion_);
}

GSuint LerpAnimation::get_bone_count() const
{
	return gsGetAnimationNumBones(animation_, motion_);
}

const LerpAnimation::Matrices & LerpAnimation::get_bone_matrices() const
{
	return matrices_;
}