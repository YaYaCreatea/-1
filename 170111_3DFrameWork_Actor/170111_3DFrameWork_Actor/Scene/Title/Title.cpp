#include "Title.h"
#include "../Scene.h"
#include <gslib.h>

void Title::start()
{
	is_end_ = false;
}

void Title::update(float deltaTime)
{
	(void)deltaTime;

	if (gsGetKeyTrigger(GKEY_SPACE) == GS_TRUE
		||
		gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_START) == GS_TRUE)
		is_end_ = true;
}

void Title::draw() const
{
	gsDrawText("ƒ^ƒCƒgƒ‹‰æ–Ê");
}

bool Title::is_end() const
{
	return is_end_;
}

Scene Title::next() const
{
	return Scene::GamePlay;
}

void Title::end()
{
}
