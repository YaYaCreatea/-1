#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "../Actor/Actor.h"

class Light :public Actor
{
public:
	//コンストラクタ
	Light(IWorld& world, const GSvector3& position);
	//描画
	virtual void draw()const override;
};

#endif