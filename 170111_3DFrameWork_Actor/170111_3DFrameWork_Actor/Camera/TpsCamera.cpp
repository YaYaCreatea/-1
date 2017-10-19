#include "TpsCamera.h"
#include "../World/IWorld.h"
#include "../ActorGroup/ActorGroup.h"
#include "../EventMessage/EventMessage.h"

TpsCamera::TpsCamera(IWorld& world)
	:mPlayerPosition{ 0.0f,0.0f,0.0f },
	mPlayerRotate{ GS_MATRIX4_IDENTITY },
	right_stick{ 0.0f,0.0f },
	mYawAngle{ 0.0f },
	mPitchAngle{ 0.0f }
{
	world_ = &world;
	name_ = "TpsCamera";
	body_ = BoundingSphere{ 1.0f };
}

void TpsCamera::update(float deltaTime)
{
	gsXBoxPadGetRightAxis(0, &right_stick);

	(void)deltaTime;

	mYawAngle -= right_stick.x*CAMERA_SPEED*deltaTime;
	mPitchAngle += right_stick.y*CAMERA_SPEED*deltaTime;


	rotation_.identity();  //�K�{(�O�̃t���[���̉�]�����Z�b�g���Ă����Ȃ��Ⴂ���Ȃ�����)

	rotation_.rotateX(mPitchAngle);  //�s���*���ԂŌ��ʂ��ς��(X*Y)��
	rotation_.rotateY(mYawAngle);  //(Y*X)�~

	auto player = world_->find_actor(ActorGroup::Player, "Player");
	if (player == nullptr)return;
	const GSvector3& backPosition = -(rotation_.getAxisZ().getNormalized())*50.0f;
	const GSvector3& upPosition = GSvector3(0.0f, 20.0f, 0.0f);
	position_ = player->get_position() + upPosition + backPosition;
	move(position_, 1.0f, 0.07f, 1.2f);

	world_->send_message(EventMessage::CameraRotate, &rotation_);
}

void TpsCamera::draw() const
{
	GSmatrix4 projection(rotation_);
	projection.setPosition(position_);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	GSmatrix4 pose = GSmatrix4(rotation_).setPosition(position_);
	glLoadMatrixf(pose.convertViewRH());
}

void TpsCamera::move(const GSvector3 & restPosition, float stiffness, float friction, float mass)
{
	//�o�l�̐L�ы���v�Z
	const auto stretch = position_ - restPosition;

	//�o�l�̗͂��v�Z
	const auto force = -stiffness*stretch;

	//�����x��ǉ�
	const auto acceleration = force / mass;

	//�ړ����x���v�Z
	velocity_ = friction*(velocity_ + acceleration);

	//���W�̍X�V
	position_ += velocity_;
}