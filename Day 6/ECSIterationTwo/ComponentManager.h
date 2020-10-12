#pragma once

#include <unordered_map>
#include <set>
#include "Component.h"

class ComponentManager
{
public:

	template <typename T, typename... Args>
	T& AddComponent(int entityId, Args&&... args);

	template <typename T>
	void RemoveComponent(int entityId);

	template <typename T>
	T* GetComponent(int entityId);


private:
	std::vector<IComponent*> m_components;
	std::unordered_map<int, std::set<int>> m_componentTable;
};

template <typename T, typename... Args>
T& ComponentManager::AddComponent(int entityId, Args&&... args)
{
	static_assert(std::is_base_of<Component, T>(), "T is not a component");
	auto component = new T{ std::forward<Args>(args)... };
	m_componentTable[entityId]->insert(component->GetId());
	return *component;
}

template <typename T>
void ComponentManager::RemoveComponent(int entityId)
{
	static_assert(std::is_base_of<Component, T>(), "T is not a component");
	int typeId = T::TYPE_ID;
	static_assert(typeId != INVAID_TYPE_ID, "Invalid component id");


	auto componentsIt = m_componentTable.find(entityId);
	if (componentsIt == m_componentTable.end())
		return;

	//auto it = std::find(componentsIt->second.begin(), componentsIt->second.end(), component);
	//if (it != componentsIt->second.end())
	//{
	//	componentsIt->second.erase(it);
	//}

}

template <typename T>
T* ComponentManager::GetComponent(int entityId)
{
	return nullptr;//m_componentTable[entityId];
}

