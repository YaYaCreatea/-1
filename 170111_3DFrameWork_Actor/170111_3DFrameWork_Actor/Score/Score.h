#ifndef _SCORE_H_
#define _SCORE_H_

class Score
{
public:
	Score(int score = 0);
	//�X�R�A���Z
	void add(int score);
	//�X�R�A�̕`��
	void draw()const;
	//�X�R�A�̎擾
	int get()const;

private:
	int score_;	//�X�R�A
};

#endif