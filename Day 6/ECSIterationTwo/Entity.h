#pragma once

#include <vector>

#include "ECS.h"
#include "ComponentManager.h"

// Entity: The entity is a general purpose object. Usually, it only consists of a unique id.
// An entity only consists of an ID and a container of components.
// The idea is to have no game methods embedded in the entity.
class Entity
{
	friend class ECS;
public:
	Entity(int id, ECS& ecs);
	~Entity();

	Entity* GetNext() { return m_next; }
	const Entity* GetNext() const { return m_next; }

	ECS* GetECS() { return m_ecs; }
	const ECS* GetECS() const { return m_ecs; }

	int GetId() { return m_id; }

	template <typename T, typename... Args>
	T& AddComponent(Args&&... args);

	template <typename T>
	void RemoveComponent();

	template <typename T>
	T* GetComponent();

private:

	ECS* m_ecs;
	Entity* m_prev;
	Entity* m_next;

	int m_id;
};

template <typename T, typename... Args>
T& Entity::AddComponent(Args&&... args)
{
	return m_ecs->m_componentManager->AddComponent<T>(args...);
}

template <typename T>
void Entity::RemoveComponent()
{
	m_ecs->m_componentManager->RemoveComponent<T>(m_id);
}

template <typename T>
T* Entity::GetComponent()
{
	return m_ecs->m_componentManager->GetComponent<T>(m_id);
}

