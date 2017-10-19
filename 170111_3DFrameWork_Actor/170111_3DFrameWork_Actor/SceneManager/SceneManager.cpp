#include "SceneManager.h"
#include "../Scene/Null/SceneNull.h"

SceneManager::SceneManager()
	:currentScene_{ new_scene<SceneNull>() }
{
}

void SceneManager::initialize()
{
	end();
	scenes_.clear();
}

void SceneManager::update(float deltaTime)
{
	currentScene_->update(deltaTime);
	if (currentScene_->is_end())
		change(currentScene_->next());
}

void SceneManager::draw() const
{
	currentScene_->draw();
}

void SceneManager::end()
{
	currentScene_->end();
	currentScene_ = new_scene<SceneNull>();
}

void SceneManager::add(Scene name, const IScenePtr & scene)
{
	scenes_[name] = scene;
}

void SceneManager::change(Scene name)
{
	end();
	currentScene_ = scenes_[name];
	currentScene_->start();
}
