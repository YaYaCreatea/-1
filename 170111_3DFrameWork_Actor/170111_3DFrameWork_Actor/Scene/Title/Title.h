#ifndef _TITLE_H_
#define _TITLE_H_

#include "../IScene.h"

class Title :public IScene
{
public:
	Title() = default;
	void start() override;
	void update(float deltaTime)override;
	void draw()const override;
	bool is_end()const override;
	Scene next() const override;
	void end() override;

private:
	bool is_end_{ false };	//I—¹ƒtƒ‰ƒO
};


#endif