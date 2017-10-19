#include "Score.h"
#include "../Utility/Texture/NumberTexture.h"
#include <gslib.h>
#include <algorithm>

Score::Score(int score)
	:score_{ score }
{
}

//スコア加算
void Score::add(int score)
{
	score_ = std::min(score_ + score, 9999999);
}

//スコアの描画
void Score::draw() const
{
	static const NumberTexture number{ 1,16,16 };
	number.draw(GSvector2{ 0,0 }, score_, 2);
}

//スコアの取得
int Score::get() const
{
	return score_;
}
