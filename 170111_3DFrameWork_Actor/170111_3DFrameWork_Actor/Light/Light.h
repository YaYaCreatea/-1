#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "../Actor/Actor.h"

class Light :public Actor
{
public:
	//�R���X�g���N�^
	Light(IWorld& world, const GSvector3& position);
	//�`��
	virtual void draw()const override;
};

#endif