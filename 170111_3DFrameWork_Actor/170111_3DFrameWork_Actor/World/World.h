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
	//�R���X�g���N�^
	World();
	//������
	void initialize();
	//�X�V
	void update(float delta_time);
	//�`��
	void draw()const;
	//���b�Z�[�W����
	void handle_message(EventMessage message, void* param);
	//���b�Z�[�W���X�i�[�̓o�^
	void add_event_message_listener(EventMessageListener listener);
	//�t�B�[���h�̒ǉ�
	void add_field(const FieldPtr& field);
	//�J�����̒ǉ�
	void add_camera(const ActorPtr& camera);
	//���C�g�̒ǉ�
	void add_light(const ActorPtr& light);
	//����
	void clear();

	//�A�N�^�[�̒ǉ�
	virtual void add_actor(ActorGroup group, const ActorPtr& actor)override;
	//�A�N�^�[�̌���
	virtual ActorPtr find_actor(ActorGroup group, const std::string& name)const override;
	//�A�N�^�[���̎擾
	virtual unsigned int count_actor(ActorGroup group)const override;
	//�A�N�^�[�̏���
	virtual void each_actor(ActorGroup group, std::function<void(const ActorPtr&)>fn)const override;
	//���b�Z�[�W�̑��M
	virtual void send_message(EventMessage message, void* param = nullptr)override;
	//�t�B�[���h���擾
	virtual Field& get_field()override;

	//�R�s�[�֎~
	World(const World& other) = delete;
	World& operator=(const World& other) = delete;

private:
	//�A�N�^�[�O���[�v�}�l�[�W���[
	ActorGroupManager actors_;
	//���C�g
	ActorPtr light_;
	//�J����
	ActorPtr camera_;
	//�t�B�[���h
	FieldPtr field_;
	//���b�Z�[�W���X�i�[
	EventMessageListener listener_{ [](EventMessage,void*) {} };
};

#endif