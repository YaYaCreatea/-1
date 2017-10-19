#ifndef _SCORE_H_
#define _SCORE_H_

class Score
{
public:
	Score(int score = 0);
	//スコア加算
	void add(int score);
	//スコアの描画
	void draw()const;
	//スコアの取得
	int get()const;

private:
	int score_;	//スコア
};

#endif