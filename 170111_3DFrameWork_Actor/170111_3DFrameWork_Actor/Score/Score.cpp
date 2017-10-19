#include "Score.h"
#include "../Utility/Texture/NumberTexture.h"
#include <gslib.h>
#include <algorithm>

Score::Score(int score)
	:score_{ score }
{
}

//�X�R�A���Z
void Score::add(int score)
{
	score_ = std::min(score_ + score, 9999999);
}

//�X�R�A�̕`��
void Score::draw() const
{
	static const NumberTexture number{ 1,16,16 };
	number.draw(GSvector2{ 0,0 }, score_, 2);
}

//�X�R�A�̎擾
int Score::get() const
{
	return score_;
}
