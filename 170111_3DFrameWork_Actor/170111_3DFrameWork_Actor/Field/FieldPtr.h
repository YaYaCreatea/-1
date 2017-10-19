#ifndef _FIELD_PTR_H_
#define _FIELD_PTR_H_

#include <memory>

//�t�B�[���h�|�C���^
class Field;
using FieldPtr = std::shared_ptr<Field>;

//�t�B�[���h�̍쐬
template<class T, class... Args>
inline FieldPtr new_field(Args&&... args)
{
	return std::make_shared<T>(args...);
}

#endif