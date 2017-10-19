#include "GamePlay.h"
#include "../Scene.h"
#include "../../ActorGroup/ActorGroup.h"
#include "../../World/World.h"
#include "../../Field/Field.h"
#include "../../Camera/Camera.h"
#include "../../Camera/TpsCamera.h"
#include "../../Light/Light.h"
#include "../../CharacterContains/Player/Player.h"
#include "../../EventMessage/EventMessage.h"

#include <GSgame.h>

void GamePlay::start()
{
	is_end_ = false;

	//���b�V���ǂݍ���
	//�v���C���[
	gsLoadMesh(0, "res/chiya/���.msh");
	gsLoadSkeleton(0, "res/chiya/���.skl");
	gsLoadAnimation(0, "res/chiya/���.anm");
	//�G�l�~�[
	gsLoadMesh(2, "res/gray.msh");
	gsLoadSkeleton(2, "res/gray.skl");
	gsLoadAnimation(2, "res/gray.anm");

	//�X�J�C�{�b�N�X�p�̃��b�V���̓ǂݍ���
	gsLoadMesh(1, "res/�X�J�C�{�b�N�X.msh");
	//�t�B�[���h�p�I�N�c���[�̓ǂݍ���
	gsLoadOctree(0, "res/�n�`.oct");
	//�e�N�X�`���̓ǂݍ���
	gsLoadTexture(0, "res/fire.bmp");
	gsLoadTexture(1, "res/NUM.png");

	//���[���h�̏�����
	world_.initialize();

	//�J�����I�u�W�F�N�g�쐬
	//FPS
	//auto camera = new_actor<Camera>(world);
	//TPS
	auto tpsCamera = new_actor<TpsCamera>(world_);

	//���C�g�I�u�W�F�N�g����
	auto light = new_actor<Light>(world_, GSvector3{ 100.0f,100.0f,100.0f });

	//�t�B�[���h�I�u�W�F�N�g�쐬
	auto field = new_field<Field>(0/*�I�N�c���[ID*/, 1/*�X�J�C�{�b�N�XID*/);

	//�v���C���[�I�u�W�F�N�g�쐬
	auto player = new_actor<Player>(world_, GSvector3{ -10.0f,0.0f,0.0f });

	//�G�l�~�[�I�u�W�F�N�g�쐬
	//auto enemy = new_actor<Enemy>(world_, GSvector3{ 0.0f,0.0f,10.0f });

	//���[���h�ɒǉ�
	//world_.add_camera(camera);
	world_.add_camera(tpsCamera);
	world_.add_light(light);
	world_.add_field(field);
	world_.add_actor(ActorGroup::Player, player);
	//world_.add_actor(ActorGroup::Enemy, enemy);
	world_.add_event_message_listener(
		[=](EventMessage message, void*param) {handle_message(message, param); });

	/*Actor* camera_actor = world_.find_Camera("TpsCamera").get();
	Actor* player_actor = world_.find_actor(ActorGroup::Player,"Player").get();

	TpsCamera* p_camera = dynamic_cast<TpsCamera*>(camera_actor);
	Player* p_player= dynamic_cast<Player*>(player_actor);

	p_player->SetTpsCamera(p_camera);*/
}

void GamePlay::update(float deltaTime)
{
	world_.update(deltaTime);

	if (gsGetKeyTrigger(GKEY_N) == GS_TRUE)
		is_end_ = true;

}

void GamePlay::draw() const
{
	world_.draw();
}

bool GamePlay::is_end() const
{
	return is_end_;
}

Scene GamePlay::next() const
{
	return Scene::Title;
}

void GamePlay::end()
{
	world_.clear();
	gsDeleteMesh(0);
	gsDeleteMesh(1);
	gsDeleteOctree(0);
	gsDeleteTexture(0);
}

void GamePlay::handle_message(EventMessage message, void * param)
{
}
