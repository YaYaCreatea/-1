#ifndef _FIELD_PTR_H_
#define _FIELD_PTR_H_

#include <memory>

//フィールドポインタ
class Field;
using FieldPtr = std::shared_ptr<Field>;

//フィールドの作成
template<class T, class... Args>
inline FieldPtr new_field(Args&&... args)
{
	return std::make_shared<T>(args...);
}

#endif