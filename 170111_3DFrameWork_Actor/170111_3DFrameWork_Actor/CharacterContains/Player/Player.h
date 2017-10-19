#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../../Actor/Actor.h"

#include "../../AnimationCtrl/AnimatedMesh/AnimatedMesh.h"

#include "PlayerStateName.h"

class Player :public Actor
{
public:
	//�R���X�g���N�^
	Player(IWorld& world, const GSvector3& position);

	virtual void update(float deltaTime)override;

	virtual void draw()const override;

	//void SetTpsCamera(TpsCamera* tpsCamera);

	virtual void handle_message(EventMessage message, void*param)override;

private:
	//�S����
	void Player_All_Motion(float deltaTime);
	//�ړ�
	void Player_Move();
	//�W�����v
	void Player_Jump();

private:
	const float GRAVITY{ 0.98f };
	//�l�����ϐ�(�Œ�l)
	const GSfloat JUMP_POWER{ 2.5f };	//�W�����v�͒l

	PlayerStateName state_;

	//�����o�ϐ�
	GSvector2 left_stick;	//���X�e�B�b�N�x�N�g��
	GSfloat direction;		//��]��

	bool mJump;				//�W�����v�t���O
	float anmTimer_;		//�A�j���[�V�����^�C�}�[

	AnimatedMesh mesh_;		//�A�j���[�V�������b�V��
	GSuint motion_;			//���[�V�����ԍ�
	float state_timer_;		//��ԃ^�C�}�[

	////�J����
	//TpsCamera* p_TpsCamera;
	//�J�������
	GSmatrix4 m_CameraRotate;

	//�}�g���b�N�X
	GSvector3 m_Front, m_Left, m_Right;
};
#endif
