#ifndef _ACTOR_PTR_H_
#define _ACTOR_PTR_H_

#include <memory>

//�A�N�^�[�|�C���^
class Actor;
using ActorPtr = std::shared_ptr<Actor>;

//�A�N�^�[�쐬
template<class T, class... Args>
inline ActorPtr new_actor(Args&&... args)
{
	return std::make_shared<T>(args...);
}

#endif