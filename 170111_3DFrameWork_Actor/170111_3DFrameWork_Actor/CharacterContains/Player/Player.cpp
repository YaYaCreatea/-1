#include "Player.h"

//システム関連
#include "../../World/IWorld.h"

//衝突処理関連
#include "../../Field/Field.h"
#include "../../CollisionDetection/Ray.h"

//列挙型関連
#include "../../ActorGroup/ActorGroup.h"
#include "../../EventMessage/EventMessage.h"

Player::Player(IWorld & world, const GSvector3 & position)
	:mesh_{ 0,0,(GSuint)PlayerStateName::Idel,0 },
	left_stick{ 0.0f,0.0f },
	direction{ 0.0f },
	mJump{ false },
	anmTimer_{ 0.0f },
	m_CameraRotate{ GS_MATRIX4_IDENTITY },
	m_Front{ 0.0f,0.0f,0.0f },
	m_Left{ 0.0f,0.0f,0.0f },
	m_Right{ 0.0f,0.0f,0.0f },
	state_{ PlayerStateName::Idel }
{
	world_ = &world;
	name_ = "Player";
	position_ = position;
	body_ = BoundingSphere{ 2.0f };
	mesh_.transform(get_pose());
}

void Player::update(float deltaTime)
{
	gsXBoxPadGetLeftAxis(0, &left_stick);

	//地面との衝突判定
	/*Ray ray{ position_,GSvector3{0.0f,1.0f,0.0f} };
	GSvector3 intersect;
	if (world_->field()->collision(ray, &intersect))
	{
		position_ = intersect;
		velocity_.y = 0.0f;
		mJump = false;
	}*/


	Player_All_Motion(deltaTime);

	if (position_.y <= 0.0f)
	{
		position_.y = 0.0f;
		velocity_.y = 0.0f;
		mJump = false;
	}

	mesh_.update(deltaTime);
	mesh_.transform(get_pose());
	anmTimer_ += deltaTime;
}

void Player::draw() const
{
	mesh_.draw();
}

void Player::handle_message(EventMessage message, void * param)
{
	switch (message)
	{
	case EventMessage::CameraRotate:
		m_CameraRotate = *(GSmatrix4*)param;
		break;
	}
}

//void Player::SetTpsCamera(TpsCamera * tpsCamera)
//{
//	p_TpsCamera = tpsCamera;
//}

void Player::Player_All_Motion(float deltaTime)
{
	//移動
	Player_Move();
	//ジャンプ
	Player_Jump();



	if (left_stick != GSvector2{ 0.0f, 0.0f })
	{
		rotation_.setAxisZ(velocity_.normalize());
		rotation_.setAxisX(rotation_.getAxisY().cross(rotation_.getAxisZ()));
		position_ += rotation_.getAxisZ().getNormalized()*deltaTime;
	}
}

void Player::Player_Move()
{
	if (left_stick != GSvector2{ 0.0f, 0.0f })
	{
		rotation_.setAxisX(m_Left = m_CameraRotate.getAxisX());
		rotation_.setAxisZ(m_Front = m_Left.cross(rotation_.getAxisY()));
		m_Right = -m_Left;

		if (left_stick.y > 0.0f)
		{
			velocity_ += m_Front;
		}
		if (left_stick.y < 0.0f)
		{
			velocity_ += -m_Front;
		}
		if (left_stick.x < 0.0f)
		{
			velocity_ += m_Left;
		}
		if (left_stick.x > 0.0f)
		{
			velocity_ += m_Right;
		}
	}
}

void Player::Player_Jump()
{
	if (((gsGetKeyTrigger(GKEY_J) || gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_A)) == GS_TRUE)
		&&
		!mJump)
	{
		velocity_.y = JUMP_POWER;
		mJump = true;
	}
}