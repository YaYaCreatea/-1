#ifndef _FIELD_H_
#define _FIELD_H_

#include <gslib.h>

class Line;
class Ray;
class BoundingSphere;

class Field
{
public:
	//�R���X�g���N�^
	Field(GSuint octree, GSuint skybox);
	//���C�Ƃ̏Փ˔���
	bool collision(const Ray& ray, GSvector3* intersect = nullptr, GSplane* plane = nullptr)const;
	//�����Ƃ̏Փ˔���
	bool collision(const Line& line, GSvector3* intersect = nullptr, GSplane* plane = nullptr)const;
	//���̂Ƃ̏Փ˔���
	bool collision(const BoundingSphere& sphere, GSvector3* intersect = nullptr)const;
	//�`��
	void draw()const;
	//�R�s�[�֎~
	Field(const Field& other) = delete;
	Field& operator=(const Field& other) = delete;

private:
	GSuint octree_;		//�I�N�c���[
	GSuint skybox_;		//�X�J�C�{�b�N�X
};

#endif