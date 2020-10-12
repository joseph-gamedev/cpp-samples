#pragma once

class ISystem;

class SystemManager
{
public:
	template <typename T, typename... Args>
	T& CreateSystem(int entityId, Args&&... args);

	template <typename T>
	T* GetSystem(int systemTypeId);

private:

};

