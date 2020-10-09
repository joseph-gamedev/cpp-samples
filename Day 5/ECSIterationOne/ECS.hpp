#pragma once

// Wrong way of doing 
// Start with something

#include <vector>

//Component: the raw data for one aspect of the object, and how it interacts with the world
class Component
{
public:
	void SetActive(bool isActive)
	{
		m_isActive = isActive;
	}
	bool IsActive()
	{
		return m_isActive;
	}

private:
	bool m_isActive;
};

// Entity: The entity is a general purpose object. Usually, it only consists of a unique id.
// An entity only consists of an ID and a container of components.
// The idea is to have no game methods embedded in the entity.
class Entity
{
public:
	~Entity()
	{
		for (auto component : m_components)
		{
			if (component)
			{
				delete component;
			}
		}
		m_components.clear();
	}

	int GetId() { return m_id; }

	void AddComponent(Component* component)
	{
		m_components.push_back(component);
	}
	void RemoveComponent(Component* component)
	{
		auto it = std::find(m_components.begin(), m_components.end(), component);
		if (it != m_components.end())
		{
			m_components.erase(it);
		}
	}
	Component* GetComponent(Component* component)
	{
		auto it = std::find(m_components.begin(), m_components.end(), component);
		if (it != m_components.end())
		{
			return *it;
		}
		return nullptr;
	}

private:

	std::vector<Component*> m_components;
	int m_id;
};


class System
{


};