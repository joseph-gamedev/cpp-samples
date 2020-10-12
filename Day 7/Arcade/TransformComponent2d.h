#pragma once

#include "Vector2.h"

class TransformComponent2d
{
public:
	TransformComponent2d();
	TransformComponent2d(const Vector2& position, const Vector2& rotation, const Vector2& scale);

	Vector2 GetPosition();
	Vector2 GetRotation();
	Vector2 GetScale();

private:

	Vector2 m_position;
	Vector2 m_rotation;
	Vector2 m_scale;
};

