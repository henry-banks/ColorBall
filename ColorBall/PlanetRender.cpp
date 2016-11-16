#include "PlanetRender.h"
#include "sfwdraw.h"


PlanetRender::PlanetRender()
{
}

PlanetRender::PlanetRender(unsigned aColor, int aSize)
{
	color = aColor;
	size = aSize;
}


PlanetRender::~PlanetRender()
{
}

void PlanetRender::draw(const Transform & planetTrans, const mat3 &t)
{
	mat3 glob = planetTrans.getGlobalTransform();

	mat3 l = t * glob;
	//vec3 nPos = l.c[2];

	float xRad = magnitude(l * vec3{ size, 0, 0 }) / 50;
	float yRad = magnitude(l * vec3{ 0, size, 0 }) / 50;

	vec2 pos = l.c[2].xy;

	//Top gets average of two radii, bottom gets larger of the two
	//float rad = (xRad + yRad) / 2;
	float rad = xRad > yRad ? xRad : yRad;

	sfw::drawCircle(pos.x, pos.y, size, 12, color);
}
