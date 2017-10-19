#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "../../Actor/Actor.h"

class Enemy :public Actor
{
public:
	//コンストラクタ
	Enemy(IWorld& world, const GSvector3& position);

private:
	virtual void update(float deltaTime)override;
	virtual void draw()const override;
	//衝突処理
	virtual void react(Actor& other)override;

	virtual void handle_message(EventMessage message, void*param);

private:
	float anmTimer_;

};

#endif