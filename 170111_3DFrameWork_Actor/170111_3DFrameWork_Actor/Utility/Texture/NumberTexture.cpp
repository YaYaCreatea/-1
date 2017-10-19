#include "NumberTexture.h"
#include <sstream>
#include <iomanip>

NumberTexture::NumberTexture(GSuint texture, int width, int height)
	:texture_{ texture }, width_{ width }, height_{ height }
{
}

void NumberTexture::draw(const GSvector2 & position, int num, int digit, char fill) const
{
	std::stringstream ss;
	ss << std::setw(digit) << std::setfill(fill) << num;
	draw(position, ss.str());
}

void NumberTexture::draw(const GSvector2 & position, int num) const
{
	draw(position, std::to_string(num));
}

void NumberTexture::draw(const GSvector2 & position, const std::string & num) const
{
	for (int i = 0; i < (int)num.size(); ++i)
	{
		if (num[i] == ' ')continue;
		const int n = num[i] - '0';
		const GSrect rect{ (float)n*width_,0.0f,(float)(n*width_) + width_,(float)height_ };
		const GSvector2 pos{ position.x + i*width_,position.y };
		gsDrawSprite2D(texture_, &pos, &rect, NULL, NULL, NULL, 0);
	}
}
