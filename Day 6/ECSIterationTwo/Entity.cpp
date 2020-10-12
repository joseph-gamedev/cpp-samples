#include "Entity.h"

Entity::Entity(int id, ECS& ecs)
	: m_id(id)
	, m_ecs(&ecs)
	, m_prev(nullptr)
	, m_next(nullptr)
{

}
Entity::~Entity()
{

}
