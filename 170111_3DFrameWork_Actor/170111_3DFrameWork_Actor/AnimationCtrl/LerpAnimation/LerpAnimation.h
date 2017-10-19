#ifndef _LERP_ANIMATION_H_
#define _LERP_ANIMATION_H_

//ライブラリ関連
#include <gslib.h>

//配列関連
#include <array>

class LerpAnimation
{
public:
	using Matrices = std::array<GSmatrix4, 256>;

public:
	//コンストラクタ
	LerpAnimation(GSuint animation, GSuint motion);

	//更新
	void update(float delta_time);

	//モーション変更
	void change_motion(GSuint motion);

	//現在再生中のモーション
	GSuint current_motion()const;

	//終了時間を返す
	GSfloat end_time()const;

	//ボーン数を返す
	GSuint get_bone_count()const;

	//変換行列を取得
	const LerpAnimation::Matrices& get_bone_matrices() const;

private:
	const GSfloat LERP_TIME{ 10.0f };	//補間フレーム数

	GSuint animation_{ 0 };				//アニメーション番号
	GSuint motion_{ 0 };				//再生中のモーション番号
	GSfloat motion_timer_{ 0.0f };		//再生中のアニメーションタイマー
	GSuint prev_motion_{ 0 };			//前回再生したモーション番号
	GSfloat prev_motion_timer_{ 0.0f };	//前回再生した最終アニメーションタイマー
	GSfloat lerp_timer{ 0.0f };			//補間アニメーションタイマー

	Matrices matrices_;					//アニメーション変換行列
};

#endif