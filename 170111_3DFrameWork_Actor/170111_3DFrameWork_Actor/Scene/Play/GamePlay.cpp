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

	//メッシュ読み込み
	//プレイヤー
	gsLoadMesh(0, "res/chiya/千夜.msh");
	gsLoadSkeleton(0, "res/chiya/千夜.skl");
	gsLoadAnimation(0, "res/chiya/千夜.anm");
	//エネミー
	gsLoadMesh(2, "res/gray.msh");
	gsLoadSkeleton(2, "res/gray.skl");
	gsLoadAnimation(2, "res/gray.anm");

	//スカイボックス用のメッシュの読み込み
	gsLoadMesh(1, "res/スカイボックス.msh");
	//フィールド用オクツリーの読み込み
	gsLoadOctree(0, "res/地形.oct");
	//テクスチャの読み込み
	gsLoadTexture(0, "res/fire.bmp");
	gsLoadTexture(1, "res/NUM.png");

	//ワールドの初期化
	world_.initialize();

	//カメラオブジェクト作成
	//FPS
	//auto camera = new_actor<Camera>(world);
	//TPS
	auto tpsCamera = new_actor<TpsCamera>(world_);

	//ライトオブジェクト生成
	auto light = new_actor<Light>(world_, GSvector3{ 100.0f,100.0f,100.0f });

	//フィールドオブジェクト作成
	auto field = new_field<Field>(0/*オクツリーID*/, 1/*スカイボックスID*/);

	//プレイヤーオブジェクト作成
	auto player = new_actor<Player>(world_, GSvector3{ -10.0f,0.0f,0.0f });

	//エネミーオブジェクト作成
	//auto enemy = new_actor<Enemy>(world_, GSvector3{ 0.0f,0.0f,10.0f });

	//ワールドに追加
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
