#ifndef _ACTOR_H_
#define _ACTOR_H_

#include <gslib.h>
#include <string>

#include "../CollisionDetection/BoundingSphere.h"

class IWorld;
enum class EventMessage;

class Actor
{
public:
	//デフォルトコンストラクタ
	Actor() = default;

	//仮想デストラクタ
	virtual ~Actor() {}

	//更新
	virtual void update(float delta_time);

	//描画
	virtual void draw()const;

	//衝突時のリアクション
	virtual void react(Actor& other);

	//メッセージ処理
	virtual void handle_message(EventMessage message, void* param = nullptr);

	//衝突判定
	void collide(Actor& other);

	//死亡する
	void die();

	//衝突判定しているか
	bool is_collide(const Actor& other)const;

	//死亡しているか
	bool is_dead()const;

	//名前を取得
	const std::string& get_name()const;

	//座標を取得
	GSvector3 get_position()const;

	//回転変換行列を取得
	GSmatrix4 get_rotation()const;

	//移動量を取得
	GSvector3 get_velocity()const;

	//変換行列を取得
	GSmatrix4 get_pose()const;

	//衝突判定データを取得
	BoundingSphere get_body()const;

	//コピー禁止
	Actor(const Actor& other) = delete;
	Actor& operator=(const Actor& other) = delete;

protected:
	//ワールド
	IWorld* world_{ nullptr };
	//名前
	std::string name_{};
	//座標
	GSvector3 position_{ 0.0f,0.0f,0.0f };
	//回転
	GSmatrix4 rotation_{ GS_MATRIX4_IDENTITY };
	//移動量
	GSvector3 velocity_{ 0.0f,0.0f,0.0f };
	//衝突判定
	BoundingSphere body_{};
	//死亡フラグ
	bool dead_{ false };
};

#endif