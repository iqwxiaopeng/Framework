#include "stdafx.h"
#include "Particle.h"

ParticleState::ParticleState() :
	r(0), g(0), b(0), a(255),
	x(0), y(0),
	rotation(0.f),
	scale(1.f),
	t(0)
{
}
ParticleState::ParticleState(sf::Color _color,int _x,int _y,float _rotation,float _scale,int _t):
	r(_color.r),g(_color.g),b(_color.b),a(_color.a),
	x((float)_x),y((float)_y),
	rotation(_rotation),
	scale(_scale),
	t(_t)
{
}

ParticleState ParticleState::operator+(ParticleState &rhp)
{
	ParticleState ret(*this);
	ret.r += rhp.r;
	ret.g += rhp.g;
	ret.b += rhp.b;
	ret.a += rhp.a;
	ret.x += rhp.x;
	ret.y += rhp.y;
	ret.rotation += rhp.rotation;
	ret.scale += rhp.scale;
	ret.t += rhp.t;
	return ret;
}
ParticleState ParticleState::operator+=(ParticleState &rhp)
{
	r += rhp.r;
	g += rhp.g;
	b += rhp.b;
	a += rhp.a;
	x += rhp.x;
	y += rhp.y;
	rotation += rhp.rotation;
	scale += rhp.scale;
	t += rhp.t;
	return *this;
}

ParticleState ParticleState::operator-(ParticleState &rhp)
{
	ParticleState ret(*this);
	ret.r -= rhp.r;
	ret.g -= rhp.g;
	ret.b -= rhp.b;
	ret.a -= rhp.a;
	ret.x -= rhp.x;
	ret.y -= rhp.y;
	ret.rotation -= rhp.rotation;
	ret.scale -= rhp.scale;
	ret.t -= rhp.t;
	return ret;
}
ParticleState ParticleState::operator-=(ParticleState &rhp)
{
	r -= rhp.r;
	g -= rhp.g;
	b -= rhp.b;
	a -= rhp.a;
	x -= rhp.x;
	y -= rhp.y;
	rotation -= rhp.rotation;
	scale -= rhp.scale;
	t -= rhp.t;
	return *this;
}

ParticleState ParticleState::operator /=(float rhp)
{
	r /= rhp;
	g /= rhp;
	b /= rhp;
	a /= rhp;
	x /= rhp;
	y /= rhp;
	rotation /= rhp;
	scale /= rhp;
	return *this;
}

ParticleState ParticleState::operator /(float rhp)
{
	ParticleState ret = *this;
	ret.r /= rhp;
	ret.g /= rhp;
	ret.b /= rhp;
	ret.a /= rhp;
	ret.x /= rhp;
	ret.y /= rhp;
	ret.rotation /= rhp;
	ret.scale /= rhp;
	return ret;
}

ParticleState ParticleState::lerp(ParticleState &first,ParticleState &second,float amount)
{
	ParticleState ret;
	ret.x =  first.x + (second.x - first.x) * amount;
	ret.y =  first.y + (second.y - first.y) * amount;
	ret.r =  first.r + (second.r - first.r) * amount;
	ret.g =  first.g + (second.g - first.g) * amount;
	ret.b =  first.b + (second.b - first.b) * amount;
	ret.a =  first.a + (second.a - first.a) * amount;
	ret.rotation =  first.rotation + (second.rotation - first.rotation) * amount;
	ret.scale =  first.scale + (second.scale - first.scale) * amount;
	ret.t = (int)(first.t + (second.t - first.t) * amount);
	return ret;
}

ParticleState::operator sf::Color()
{
	sf::Color ret((int)r%256,(int)g%256,(int)b%256,(int)a%256);
	return ret;
}