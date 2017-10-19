#ifndef _BOUNDING_SPHERE_H_
#define _BOUNDING_SPHERE_H_

#include <gslib.h>

class BoundingSphere
{
public:
	//�R���X�g���N�^
	BoundingSphere(const GSvector3& center, float radius);
	//�R���X�g���N�^(����1�̎���explicit(�Öٕϊ��֎~))
	explicit BoundingSphere(float radius = 0.0f);
	//���s�ړ�
	BoundingSphere translate(const GSvector3& position)const;
	//���W�ϊ�
	BoundingSphere transform(const GSmatrix4& matrix)const;
	//�������Ă��邩�H
	bool intersects(const BoundingSphere& other)const;
	//�f�o�b�O�\��
	void draw()const;

public:
	GSvector3 center;	//���S���W
	float radius;		//���a
};

#endif