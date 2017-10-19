#include "GameFrame.h"

//列挙型関連
#include "../Scene/Scene.h"

//シーン関連
#include "../Scene/Title/Title.h"
#include "../Scene/Play/GamePlay.h"

GameFrame::GameFrame()
	:Game(1024, 768)
{
}

void GameFrame::start()
{
	//エフェクト初期化
	gsInitEffect();
	sceneManager_.add(Scene::Title, new_scene<Title>());
	sceneManager_.add(Scene::GamePlay, new_scene<GamePlay>());
	sceneManager_.change(Scene::Title);
}

void GameFrame::update(float delta_time)
{
	sceneManager_.update(delta_time);
}

void GameFrame::draw()
{
	sceneManager_.draw();
}

void GameFrame::end()
{
	sceneManager_.end();
	//エフェクトの終了
	gsFinishEffect();
}