#ifndef _ACTOR_MANAGER_H_
#define _ACTOR_MANAGER_H_

#include "../Actor/Actor.h"
#include "../Actor/ActorPtr.h"
#include <list>
#include <functional>

class ActorManager
{
public:
	//コンストラクタ
	ActorManager() = default;
	//アクターの追加
	void add(const ActorPtr& actor);
	//更新
	void update(float delta_time);
	//描画
	void draw()const;
	//衝突判定
	void collide();
	//衝突判定
	void collide(Actor& other);
	//衝突判定
	void collide(ActorManager& other);
	//削除
	void remove();
	//アクターの検索
	ActorPtr find(const std::string& name)const;
	//アクター数を返す
	unsigned int count()const;
	//アクターの巡回
	void each(std::function<void(const ActorPtr&)>fn)const;
	//メッセージ処理
	void handle_message(EventMessage message, void*param);
	//消去
	void clear();
	//コピー禁止
	ActorManager(const ActorManager& other) = delete;
	ActorManager& operator=(const ActorManager& other) = delete;

private:
	using ActorList = std::list<ActorPtr>;
	//アクターリスト
	ActorList actors_;
};

#endif