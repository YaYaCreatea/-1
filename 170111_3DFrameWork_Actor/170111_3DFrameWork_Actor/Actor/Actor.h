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
	//�f�t�H���g�R���X�g���N�^
	Actor() = default;

	//���z�f�X�g���N�^
	virtual ~Actor() {}

	//�X�V
	virtual void update(float delta_time);

	//�`��
	virtual void draw()const;

	//�Փˎ��̃��A�N�V����
	virtual void react(Actor& other);

	//���b�Z�[�W����
	virtual void handle_message(EventMessage message, void* param = nullptr);

	//�Փ˔���
	void collide(Actor& other);

	//���S����
	void die();

	//�Փ˔��肵�Ă��邩
	bool is_collide(const Actor& other)const;

	//���S���Ă��邩
	bool is_dead()const;

	//���O���擾
	const std::string& get_name()const;

	//���W���擾
	GSvector3 get_position()const;

	//��]�ϊ��s����擾
	GSmatrix4 get_rotation()const;

	//�ړ��ʂ��擾
	GSvector3 get_velocity()const;

	//�ϊ��s����擾
	GSmatrix4 get_pose()const;

	//�Փ˔���f�[�^���擾
	BoundingSphere get_body()const;

	//�R�s�[�֎~
	Actor(const Actor& other) = delete;
	Actor& operator=(const Actor& other) = delete;

protected:
	//���[���h
	IWorld* world_{ nullptr };
	//���O
	std::string name_{};
	//���W
	GSvector3 position_{ 0.0f,0.0f,0.0f };
	//��]
	GSmatrix4 rotation_{ GS_MATRIX4_IDENTITY };
	//�ړ���
	GSvector3 velocity_{ 0.0f,0.0f,0.0f };
	//�Փ˔���
	BoundingSphere body_{};
	//���S�t���O
	bool dead_{ false };
};

#endif