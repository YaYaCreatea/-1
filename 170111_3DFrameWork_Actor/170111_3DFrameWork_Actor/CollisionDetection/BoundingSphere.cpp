#include "BoundingSphere.h"

//コンストラクタ
BoundingSphere::BoundingSphere(const GSvector3 & center, float radius)
	:center{ center }, radius{ radius }
{
}

//コンストラクタ
BoundingSphere::BoundingSphere(float radius)
	: BoundingSphere{ {0.0f,0.0f,0.0f},radius }
{
}

//平行移動
BoundingSphere BoundingSphere::translate(const GSvector3 & position) const
{
	return{ center + position,radius };
}

//座標変換
BoundingSphere BoundingSphere::transform(const GSmatrix4 & matrix) const
{
	return{ matrix.transform(center),radius*matrix.getScale().y };
}

//交差しているか？
bool BoundingSphere::intersects(const BoundingSphere & other) const
{
	return gsCollisionSphereAndSphere(&center, radius, &other.center, other.radius) == GS_TRUE;
}

//デバッグ表示
void BoundingSphere::draw() const
{
	glPushMatrix();
		glTranslatef(center.x, center.y, center.z);
		glutWireSphere(radius,16,16);
	glPopMatrix();
}