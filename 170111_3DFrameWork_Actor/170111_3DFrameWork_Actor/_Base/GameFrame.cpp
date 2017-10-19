#include "GameFrame.h"

//�񋓌^�֘A
#include "../Scene/Scene.h"

//�V�[���֘A
#include "../Scene/Title/Title.h"
#include "../Scene/Play/GamePlay.h"

GameFrame::GameFrame()
	:Game(1024, 768)
{
}

void GameFrame::start()
{
	//�G�t�F�N�g������
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
	//�G�t�F�N�g�̏I��
	gsFinishEffect();
}