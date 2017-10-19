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
	//カメラ移動
	void move(
		const GSvector3& restPosition,	//バネの静止位置
		float stiffness,				//バネの定数(バネの強さ)
		float friction,					//摩擦力
		float mass						//質量
		);

private:
	//値調整変数(固定値)
	const GSfloat CAMERA_SPEED{ 1.5f };	//ジャンプ力値

	GSvector3 target_{ 0.0f,0.0f,0.0f };	//目標位置

	GSvector3 mPlayerPosition;
	GSmatrix4 mPlayerRotate;

	GSvector2 right_stick;

	float mYawAngle;
	float mPitchAngle;
};

#endif