#ifndef _ANIMATION_H_
#define _ANIMATION_H_

//���C�u�����֘A
#include <gslib.h>

//�z��֘A
#include <array>

class Animation
{
public:
	using Matrices = std::array<GSmatrix4, 256>;

public:
	//�R���X�g���N�^
	Animation(GSuint animation, GSuint motion);

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
	const Animation::Matrices& get_bone_matrices() const;

private:
	GSuint animation_{ 0 };			//�A�j���[�V�����ԍ�
	GSuint motion_{ 0 };			//�Đ����̃��[�V�����ԍ�
	GSfloat motion_timer_{ 0.0f };	//�Đ����̃A�j���[�V�����^�C�}�[
	Matrices matrices_;				//�A�j���[�V�����ϊ��s��
};

#endif