#include "ECS.h"
#include "Entity.h"

ECS::ECS()
	: m_componentManager(nullptr)
	, m_systemManager(nullptr)
	, m_entityList(nullptr)
	, m_entityCount(0)
{

}

ECS::~ECS()
{
	Entity* entity = m_entityList;
	while (entity)
	{
		Entity* nextEntity = entity->m_next;
		delete entity;
		entity = nextEntity;
	}
}

Entity* ECS::CreateEntity()
{
	m_entityCount++;
	Entity* entity = new Entity(m_entityCount, *this);
	entity->m_prev = nullptr;
	entity->m_next = m_entityList;
	if (m_entityList)
	{
		m_entityList->m_prev = entity;
	}
	m_entityList = entity;
	return entity;
}

void ECS::DestroyEntity(Entity* entity)
{
	if (entity->m_prev)
	{
		entity->m_prev->m_next = entity->m_next;
	}
	if (entity->m_next)
	{
		entity->m_next->m_prev = entity->m_prev;
	}
	if (entity == m_entityList)
	{
		m_entityList = entity->m_next;
	}
	if (entity)
	{
		delete entity;
	}
}

Entity* ECS::GetEntityList()
{
	return m_entityList;
}

const Entity* ECS::GetEntityList() const
{
	return m_entityList;
}
