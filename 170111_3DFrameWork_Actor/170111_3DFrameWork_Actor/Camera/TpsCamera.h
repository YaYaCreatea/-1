#ifndef _TPS_CAMERA_H_
#define _TPS_CAMERA_H_

#include "../Actor/Actor.h"

class TpsCamera :public Actor
{
public:
	TpsCamera(IWorld& world);

private:
	virtual void update(float deltaTime)override;
	virtual void draw() const override;
	//�J�����ړ�
	void move(
		const GSvector3& restPosition,	//�o�l�̐Î~�ʒu
		float stiffness,				//�o�l�̒萔(�o�l�̋���)
		float friction,					//���C��
		float mass						//����
		);

private:
	//�l�����ϐ�(�Œ�l)
	const GSfloat CAMERA_SPEED{ 1.5f };	//�W�����v�͒l

	GSvector3 target_{ 0.0f,0.0f,0.0f };	//�ڕW�ʒu

	GSvector3 mPlayerPosition;
	GSmatrix4 mPlayerRotate;

	GSvector2 right_stick;

	float mYawAngle;
	float mPitchAngle;
};

#endif