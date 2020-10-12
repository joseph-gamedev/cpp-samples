//#pragma once
//
//// Wrong way of doing 
//// Start with something
//
//#include <set>
//#include <vector>
//#include <unordered_map>
//
//class Entity;
//
////Component: the raw data for one aspect of the object, and how it interacts with the world
//class Component
//{
//public:
//	void SetActive(bool isActive)
//	{
//		m_isActive = isActive;
//	}
//	bool IsActive()
//	{
//		return m_isActive;
//	}
//
//private:
//	bool m_isActive;
//};
//
//class System
//{
//
//
//};
//
//class ECS
//{
//public:
//	ECS()
//		: m_entityList(nullptr)
//		, m_entityCount(0)
//	{
//
//	}
//	~ECS()
//	{
//
//		Entity* entity = m_entityList;
//		while (entity)
//		{
//			Entity* nextEntity = entity->m_next;
//			delete entity;
//			entity = nextEntity;
//		}
//	}
//
//	Entity* CreateEntity()
//	{
//		m_entityCount++;
//		Entity* entity = new Entity(m_entityCount, *this);
//		entity->m_prev = nullptr;
//		entity->m_next = m_entityList;
//		if (m_entityList)
//		{
//			m_entityList->m_prev = entity;
//		}
//		m_entityList = entity;
//		return entity;
//	}
//
//	Entity* GetEntityList() { return m_entityList; }
//	const Entity* GetEntityList() const { return m_entityList; };
//
//	void DestroyEntity(Entity* entity)
//	{
//		if (entity->m_prev)
//		{
//			entity->m_prev->m_next = entity->m_next;
//		}
//
//		if (entity->m_next)
//		{
//			entity->m_next->m_prev = entity->m_prev;
//		}
//
//		if (entity == m_entityList)
//		{
//			m_entityList = entity->m_next;
//		}
//		if (entity)
//		{
//			delete entity;
//		}
//	}
//	template <typename T, typename... Args>
//	T& AddComponent(int, Args&&... args)
//	{
//		static_assert(std::is_base_of<Component, T>(), "is not a component");
//		auto component = new T{ std::forward<Args>(args)... };
//		//m_components.push_back(component);
//		return *component;
//	}
//
//private:
//	Entity* m_entityList;
//	int m_entityCount;
//	std::unordered_map<int, std::set<Component*>> m_componentTable;
//};
//
//// Entity: The entity is a general purpose object. Usually, it only consists of a unique id.
//// An entity only consists of an ID and a container of components.
//// The idea is to have no game methods embedded in the entity.
//class Entity
//{
//	friend class ECS;
//public:
//	Entity(int id, ECS& ecs)
//		: m_id(id)
//		, m_ecs(&ecs)
//	{
//
//	}
//	~Entity()
//	{
//		for (auto component : m_components)
//		{
//			if (component)
//			{
//				delete component;
//			}
//		}
//		m_components.clear();
//	}
//
//	Entity* GetNext() { return m_next; }
//	const Entity* GetNext() const { return m_next; }
//
//	ECS* GetECS() { return m_ecs; }
//	const ECS* GetECS() const { return m_ecs; }
//
//	int GetId() { return m_id; }
//
//	template <typename T, typename... Args>
//	T& AddComponent(Args&&... args)
//	{
//		return m_ecs->AddComponent(T, args...);
//		/*static_assert(std::is_base_of<Component, T>(), "is not a component");
//		auto component = new T{ std::forward<Args>(args)... };
//		m_components.push_back(component);
//		return *component;*/
//	}
//
//	template <typename T>
//	void RemoveComponent()
//	{
//
//	}
//
//	void AddComponent(Component* component)
//	{
//		m_components.push_back(component);
//	}
//	void RemoveComponent(Component* component)
//	{
//		auto it = std::find(m_components.begin(), m_components.end(), component);
//		if (it != m_components.end())
//		{
//			m_components.erase(it);
//		}
//	}
//	Component* GetComponent(Component* component)
//	{
//		auto it = std::find(m_components.begin(), m_components.end(), component);
//		if (it != m_components.end())
//		{
//			return *it;
//		}
//		return nullptr;
//	}
//
//private:
//
//	ECS* m_ecs;
//	Entity* m_prev;
//	Entity* m_next;
//
//	std::vector<Component*> m_components;
//	int m_id;
//};