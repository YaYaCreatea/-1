#ifndef _ANIMATED_MESH_H_
#define _ANIMATED_MESH_H_

//���C�u�����֘A
#include <gslib.h>

//�z��֘A
#include <array>

//�V�X�e���֘A
#include "../LerpAnimation/LerpAnimation.h"

class AnimatedMesh
{
public:
	using Matrices = std::array<GSmatrix4, 256>;

public:
	//�R���X�g���N�^
	AnimatedMesh(GSuint mesh, GSuint skeleton, GSuint animation, GSuint motion = 0);

	//�X�V
	void update(float delta_time);

	//�`��
	void draw()const;

	//���[�V�����ύX
	void change_motion(GSuint moiton);

	//�X�P���g���̕ϊ��s����v�Z����
	void transform(const GSmatrix4& matrix);

	//���[�V�����̏I�����Ԃ��擾
	float motion_end_time()const;

	//�{�[���̕ϊ��s����擾
	GSmatrix4 get_bone_matrix(int bone_no)const;

private:
	GSuint mesh_;			//���b�V��
	GSuint skeleton_;		//�X�P���g��
	LerpAnimation animation_;	//�A�j���[�V����
	Matrices matrices_;		//�X�P���g���ϊ��s��
};

#endif