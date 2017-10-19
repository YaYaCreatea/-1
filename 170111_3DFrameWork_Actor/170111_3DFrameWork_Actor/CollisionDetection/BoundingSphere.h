#ifndef _BOUNDING_SPHERE_H_
#define _BOUNDING_SPHERE_H_

#include <gslib.h>

class BoundingSphere
{
public:
	//コンストラクタ
	BoundingSphere(const GSvector3& center, float radius);
	//コンストラクタ(引数1つの時はexplicit(暗黙変換禁止))
	explicit BoundingSphere(float radius = 0.0f);
	//平行移動
	BoundingSphere translate(const GSvector3& position)const;
	//座標変換
	BoundingSphere transform(const GSmatrix4& matrix)const;
	//交差しているか？
	bool intersects(const BoundingSphere& other)const;
	//デバッグ表示
	void draw()const;

public:
	GSvector3 center;	//中心座標
	float radius;		//半径
};

#endif