#include "BoundingSphere.h"

//�R���X�g���N�^
BoundingSphere::BoundingSphere(const GSvector3 & center, float radius)
	:center{ center }, radius{ radius }
{
}

//�R���X�g���N�^
BoundingSphere::BoundingSphere(float radius)
	: BoundingSphere{ {0.0f,0.0f,0.0f},radius }
{
}

//���s�ړ�
BoundingSphere BoundingSphere::translate(const GSvector3 & position) const
{
	return{ center + position,radius };
}

//���W�ϊ�
BoundingSphere BoundingSphere::transform(const GSmatrix4 & matrix) const
{
	return{ matrix.transform(center),radius*matrix.getScale().y };
}

//�������Ă��邩�H
bool BoundingSphere::intersects(const BoundingSphere & other) const
{
	return gsCollisionSphereAndSphere(&center, radius, &other.center, other.radius) == GS_TRUE;
}

//�f�o�b�O�\��
void BoundingSphere::draw() const
{
	glPushMatrix();
		glTranslatef(center.x, center.y, center.z);
		glutWireSphere(radius,16,16);
	glPopMatrix();
}