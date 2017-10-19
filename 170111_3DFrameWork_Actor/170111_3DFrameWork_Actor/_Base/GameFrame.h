#ifndef _GAME_FRAME_H_
#define _GAME_FRAME_H_

#include <GSgame.h>
#include <GSeffect.h>

//システム関連
#include "../SceneManager/SceneManager.h"

class GameFrame :public gslib::Game
{
public:
	GameFrame();
	void start()override;
	void update(float delta_time)override;
	void draw()override;
	void end()override;

private:
	SceneManager sceneManager_;
};

#endif