#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "../Actor/Actor.h"

class Camera :public Actor
{
public:
	//�R���X�g���N�^
	explicit Camera(IWorld& world);
private:
	//�X�V
	void update(float deltaTime)override;
	//�`��
	void draw()const override;
};

#endif