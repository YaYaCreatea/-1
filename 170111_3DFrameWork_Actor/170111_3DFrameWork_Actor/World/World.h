#ifndef _WORLD_H_
#define _WORLD_H_

#include "IWorld.h"
#include "../ActorGroup/ActorGroupManager.h"
#include "../Actor/ActorPtr.h"
#include "../Field/FieldPtr.h"

#include <functional>

enum class EventMessage;

class World :public IWorld
{
public:
	using EventMessageListener = std::function<void(EventMessage, void*)>;

public:
	//コンストラクタ
	World();
	//初期化
	void initialize();
	//更新
	void update(float delta_time);
	//描画
	void draw()const;
	//メッセージ処理
	void handle_message(EventMessage message, void* param);
	//メッセージリスナーの登録
	void add_event_message_listener(EventMessageListener listener);
	//フィールドの追加
	void add_field(const FieldPtr& field);
	//カメラの追加
	void add_camera(const ActorPtr& camera);
	//ライトの追加
	void add_light(const ActorPtr& light);
	//消去
	void clear();

	//アクターの追加
	virtual void add_actor(ActorGroup group, const ActorPtr& actor)override;
	//アクターの検索
	virtual ActorPtr find_actor(ActorGroup group, const std::string& name)const override;
	//アクター数の取得
	virtual unsigned int count_actor(ActorGroup group)const override;
	//アクターの巡回
	virtual void each_actor(ActorGroup group, std::function<void(const ActorPtr&)>fn)const override;
	//メッセージの送信
	virtual void send_message(EventMessage message, void* param = nullptr)override;
	//フィールドを取得
	virtual Field& get_field()override;

	//コピー禁止
	World(const World& other) = delete;
	World& operator=(const World& other) = delete;

private:
	//アクターグループマネージャー
	ActorGroupManager actors_;
	//ライト
	ActorPtr light_;
	//カメラ
	ActorPtr camera_;
	//フィールド
	FieldPtr field_;
	//メッセージリスナー
	EventMessageListener listener_{ [](EventMessage,void*) {} };
};

#endif