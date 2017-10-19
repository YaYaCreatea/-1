#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "../Actor/Actor.h"

class Camera :public Actor
{
public:
	//コンストラクタ
	explicit Camera(IWorld& world);
private:
	//更新
	void update(float deltaTime)override;
	//描画
	void draw()const override;
};

#endif