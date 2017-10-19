#ifndef _GAME_PLAY_H_
#define _GAME_PLAY_H_

#include "../IScene.h"
#include "../../World/World.h"

enum class EventMessage;

class GamePlay :public IScene
{
public:
	GamePlay() = default;
	void start()override;
	void update(float deltaTime)override;
	void draw()const override;
	bool is_end()const override;
	Scene next()const override;
	void end() override;
	void handle_message(EventMessage message, void*param);

private:
	World world_;			//���[���h�N���X
	bool is_end_{ false };	//�I���t���O
};

#endif