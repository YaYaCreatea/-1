#ifndef _FIELD_H_
#define _FIELD_H_

#include <gslib.h>

class Line;
class Ray;
class BoundingSphere;

class Field
{
public:
	//コンストラクタ
	Field(GSuint octree, GSuint skybox);
	//レイとの衝突判定
	bool collision(const Ray& ray, GSvector3* intersect = nullptr, GSplane* plane = nullptr)const;
	//線分との衝突判定
	bool collision(const Line& line, GSvector3* intersect = nullptr, GSplane* plane = nullptr)const;
	//球体との衝突判定
	bool collision(const BoundingSphere& sphere, GSvector3* intersect = nullptr)const;
	//描画
	void draw()const;
	//コピー禁止
	Field(const Field& other) = delete;
	Field& operator=(const Field& other) = delete;

private:
	GSuint octree_;		//オクツリー
	GSuint skybox_;		//スカイボックス
};

#endif