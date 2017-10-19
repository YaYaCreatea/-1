#ifndef _IWORLD_H_
#define _IWORLD_H_

#include "../Actor/ActorPtr.h"
#include <string>
#include <functional>

enum class ActorGroup;
enum class EventMessage;
class Field;

class IWorld
{
public:
	//���z�f�X�g���N�^
	virtual ~IWorld() {}

	//�A�N�^�[��ǉ�
	virtual void add_actor(ActorGroup group, const ActorPtr& actor) = 0;

	//�A�N�^�[������
	virtual ActorPtr find_actor(ActorGroup group, const std::string& name) const = 0;

	//�A�N�^�[���̎擾
	virtual unsigned int count_actor(ActorGroup group)const = 0;

	//�A�N�^�[�̏���
	virtual void each_actor(ActorGroup group, std::function<void(const ActorPtr&)>fn)const = 0;

	//���b�Z�[�W�𑗐M
	virtual void send_message(EventMessage message, void* param = nullptr) = 0;

	//�t�B�[���h���擾
	virtual Field& get_field() = 0;
};

#endif