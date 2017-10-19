#ifndef _SCENE_NULL_H_
#define _SCENE_NULL_H_

#include "../../Scene/IScene.h"

class SceneNull :public IScene
{
public:
	void start()override;
	void update(float deltaTime)override;
	void draw()const override;
	bool is_end()const override;
	Scene next() const override;
	void end()override;
};

#endif