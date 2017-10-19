#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../../Actor/Actor.h"

#include "../../AnimationCtrl/AnimatedMesh/AnimatedMesh.h"

#include "PlayerStateName.h"

class Player :public Actor
{
public:
	//コンストラクタ
	Player(IWorld& world, const GSvector3& position);

	virtual void update(float deltaTime)override;

	virtual void draw()const override;

	//void SetTpsCamera(TpsCamera* tpsCamera);

	virtual void handle_message(EventMessage message, void*param)override;

private:
	//全挙動
	void Player_All_Motion(float deltaTime);
	//移動
	void Player_Move();
	//ジャンプ
	void Player_Jump();

private:
	const float GRAVITY{ 0.98f };
	//値調整変数(固定値)
	const GSfloat JUMP_POWER{ 2.5f };	//ジャンプ力値

	PlayerStateName state_;

	//メンバ変数
	GSvector2 left_stick;	//左スティックベクトル
	GSfloat direction;		//回転量

	bool mJump;				//ジャンプフラグ
	float anmTimer_;		//アニメーションタイマー

	AnimatedMesh mesh_;		//アニメーションメッシュ
	GSuint motion_;			//モーション番号
	float state_timer_;		//状態タイマー

	////カメラ
	//TpsCamera* p_TpsCamera;
	//カメラ情報
	GSmatrix4 m_CameraRotate;

	//マトリックス
	GSvector3 m_Front, m_Left, m_Right;
};
#endif
