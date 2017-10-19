#ifndef _ACTOR_GROUP_MANAGER_H_
#define _ACTOR_GROUP_MANAGER_H_

#include <map>

#include "../ActorManager/ActorManager.h"

enum class ActorGroup;

class ActorGroupManager
{
public:
	//�f�t�H���g�R���X�g���N�^
	ActorGroupManager() = default;
	//�O���[�v�̒ǉ�
	void add(ActorGroup group);
	//�A�N�^�[�̒ǉ�
	void add(ActorGroup group, const ActorPtr& actor);
	//�X�V
	void update(float delta_time);
	//�`��
	void draw()const;
	//�`��
	void draw(ActorGroup group)const;
	//����
	void clear();
	//�A�N�^�[������
	ActorPtr find(ActorGroup group, const std::string& name)const;
	//�A�N�^�[����Ԃ�
	unsigned int count(ActorGroup group)const;
	//�A�N�^�[�̏���
	void each(ActorGroup group, std::function<void(const ActorPtr&)>fn)const;
	//�Փ˔���
	void collide(ActorGroup group_1, ActorGroup group_2);
	//�폜
	void remove();
	//���b�Z�[�W����
	void handle_message(EventMessage message, void* param);
	//�R�s�[�֎~
	ActorGroupManager(const ActorGroupManager& other) = delete;
	ActorGroupManager& operator=(const ActorGroupManager& other) = delete;

private:
	using ActorGroupMap = std::map<ActorGroup, ActorManager>;
	ActorGroupMap actor_group_map_;
};

#endif