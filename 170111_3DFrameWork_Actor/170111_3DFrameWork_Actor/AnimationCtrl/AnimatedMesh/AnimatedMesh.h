#ifndef _ANIMATED_MESH_H_
#define _ANIMATED_MESH_H_

//ライブラリ関連
#include <gslib.h>

//配列関連
#include <array>

//システム関連
#include "../LerpAnimation/LerpAnimation.h"

class AnimatedMesh
{
public:
	using Matrices = std::array<GSmatrix4, 256>;

public:
	//コンストラクタ
	AnimatedMesh(GSuint mesh, GSuint skeleton, GSuint animation, GSuint motion = 0);

	//更新
	void update(float delta_time);

	//描画
	void draw()const;

	//モーション変更
	void change_motion(GSuint moiton);

	//スケルトンの変換行列を計算する
	void transform(const GSmatrix4& matrix);

	//モーションの終了時間を取得
	float motion_end_time()const;

	//ボーンの変換行列を取得
	GSmatrix4 get_bone_matrix(int bone_no)const;

private:
	GSuint mesh_;			//メッシュ
	GSuint skeleton_;		//スケルトン
	LerpAnimation animation_;	//アニメーション
	Matrices matrices_;		//スケルトン変換行列
};

#endif