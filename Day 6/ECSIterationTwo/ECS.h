#pragma once

class ComponentManager;
class Entity;
class SystemManager;

class ECS
{
public:

	ECS();
	~ECS();

	Entity* CreateEntity();
	void DestroyEntity(Entity* entity);

	Entity* GetEntityList();
	const Entity* GetEntityList() const;

private:

	ComponentManager* m_componentManager;
	SystemManager* m_systemManager;
	Entity* m_entityList;

	int m_entityCount;

	
};

