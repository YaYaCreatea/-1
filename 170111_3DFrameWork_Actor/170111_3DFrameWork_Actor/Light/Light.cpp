#include "Light.h"

Light::Light(IWorld & world, const GSvector3 & position)
{
	world_ = &world;
	name_ = "Light";
	position_ = position;
}

void Light::draw() const
{
	static const float ambient[]{ 0.2f,0.2f,0.2f,1.0f };
	static const float diffuse[]{ 1.0f,1.0f,1.0f,1.0f };
	static const float specular[]{ 1.0f,1.0f,1.0f,1.0f };
	float position[]{ position_.x,position_.y,position_.z,0.0f };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
}
