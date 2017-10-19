#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

#include "../Scene/IScenePtr.h"
#include <map>

enum class Scene;

class SceneManager
{
public:
	SceneManager();
	void initialize();
	void update(float deltaTime);
	void draw()const;
	void end();
	//シーン追加
	void add(Scene name, const IScenePtr& scene);
	//シーンの変更
	void change(Scene name);
	//コピー禁止
	SceneManager(const SceneManager& other) = delete;
	SceneManager& operator =(const SceneManager& other) = delete;

private:
	std::map<Scene, IScenePtr> scenes_;
	IScenePtr currentScene_;
};

#endif