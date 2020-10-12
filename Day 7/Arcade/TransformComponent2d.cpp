#include "TransformComponent2d.h"

TransformComponent2d::TransformComponent2d()
	: m_position(Vector2::Zero)
	, m_rotation(Vector2::Zero)
	, m_scale(Vector2::One)
{

}

TransformComponent2d::TransformComponent2d(const Vector2& position, const Vector2& rotation, const Vector2& scale)
	: m_position(position)
	, m_rotation(rotation)
	, m_scale(scale)
{

}

Vector2 TransformComponent2d::GetPosition()
{
	return m_position;
}

Vector2 TransformComponent2d::GetRotation()
{
	return m_rotation;
}

Vector2 TransformComponent2d::GetScale()
{
	return m_rotation;
}
