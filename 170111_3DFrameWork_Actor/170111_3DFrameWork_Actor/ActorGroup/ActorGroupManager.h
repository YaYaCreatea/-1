#ifndef _ACTOR_GROUP_MANAGER_H_
#define _ACTOR_GROUP_MANAGER_H_

#include <map>

#include "../ActorManager/ActorManager.h"

enum class ActorGroup;

class ActorGroupManager
{
public:
	//デフォルトコンストラクタ
	ActorGroupManager() = default;
	//グループの追加
	void add(ActorGroup group);
	//アクターの追加
	void add(ActorGroup group, const ActorPtr& actor);
	//更新
	void update(float delta_time);
	//描画
	void draw()const;
	//描画
	void draw(ActorGroup group)const;
	//消去
	void clear();
	//アクターを検索
	ActorPtr find(ActorGroup group, const std::string& name)const;
	//アクター数を返す
	unsigned int count(ActorGroup group)const;
	//アクターの巡回
	void each(ActorGroup group, std::function<void(const ActorPtr&)>fn)const;
	//衝突判定
	void collide(ActorGroup group_1, ActorGroup group_2);
	//削除
	void remove();
	//メッセージ処理
	void handle_message(EventMessage message, void* param);
	//コピー禁止
	ActorGroupManager(const ActorGroupManager& other) = delete;
	ActorGroupManager& operator=(const ActorGroupManager& other) = delete;

private:
	using ActorGroupMap = std::map<ActorGroup, ActorManager>;
	ActorGroupMap actor_group_map_;
};

#endif