#include "Field.h"
#include "../CollisionDetection/Ray.h"
#include "../CollisionDetection/Line.h"
#include "../CollisionDetection/BoundingSphere.h"

//コンストラクタ
Field::Field(GSuint octree, GSuint skybox)
	:octree_{ octree }, skybox_{ skybox }
{
}

//レイとの衝突判定
bool Field::collision(const Ray & ray, GSvector3 * intersect, GSplane * plane) const
{
	return gsOctreeCollisionRay(gsGetOctree(octree_), &ray.position, &ray.direction, intersect, plane) == GS_TRUE;
}

//線分との衝突判定
bool Field::collision(const Line & line, GSvector3 * intersect, GSplane * plane) const
{
	return gsOctreeCollisionLine(gsGetOctree(octree_), &line.start, &line.end, intersect, plane) == GS_TRUE;
}

//球体との衝突判定
bool Field::collision(const BoundingSphere& sphere, GSvector3 * intersect) const
{
	return gsOctreeCollisionSphere(gsGetOctree(octree_), &sphere.center, sphere.radius, intersect) == GS_TRUE;
}

//描画
void Field::draw() const
{
	gsDrawSkyBox(skybox_);
	gsDrawOctree(octree_);
}
