#include "SceneNull.h"
#include "../Scene.h"

void SceneNull::start()
{
}

void SceneNull::update(float deltaTime)
{
}

void SceneNull::draw() const
{
}

bool SceneNull::is_end() const
{
	return false;
}

Scene SceneNull::next() const
{
	return Scene::None;
}

void SceneNull::end()
{
}
