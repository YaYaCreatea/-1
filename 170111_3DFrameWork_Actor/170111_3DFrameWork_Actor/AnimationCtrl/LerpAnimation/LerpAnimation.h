#ifndef _LERP_ANIMATION_H_
#define _LERP_ANIMATION_H_

//���C�u�����֘A
#include <gslib.h>

//�z��֘A
#include <array>

class LerpAnimation
{
public:
	using Matrices = std::array<GSmatrix4, 256>;

public:
	//�R���X�g���N�^
	LerpAnimation(GSuint animation, GSuint motion);

	//�X�V
	void update(float delta_time);

	//���[�V�����ύX
	void change_motion(GSuint motion);

	//���ݍĐ����̃��[�V����
	GSuint current_motion()const;

	//�I�����Ԃ�Ԃ�
	GSfloat end_time()const;

	//�{�[������Ԃ�
	GSuint get_bone_count()const;

	//�ϊ��s����擾
	const LerpAnimation::Matrices& get_bone_matrices() const;

private:
	const GSfloat LERP_TIME{ 10.0f };	//��ԃt���[����

	GSuint animation_{ 0 };				//�A�j���[�V�����ԍ�
	GSuint motion_{ 0 };				//�Đ����̃��[�V�����ԍ�
	GSfloat motion_timer_{ 0.0f };		//�Đ����̃A�j���[�V�����^�C�}�[
	GSuint prev_motion_{ 0 };			//�O��Đ��������[�V�����ԍ�
	GSfloat prev_motion_timer_{ 0.0f };	//�O��Đ������ŏI�A�j���[�V�����^�C�}�[
	GSfloat lerp_timer{ 0.0f };			//��ԃA�j���[�V�����^�C�}�[

	Matrices matrices_;					//�A�j���[�V�����ϊ��s��
};

#endif