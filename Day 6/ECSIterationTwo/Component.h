#pragma once

#include "TypeId.h"

const int INVAILD_COMPONENT_ID = -1;

class IComponent
{
public:
	virtual ~IComponent() {}
	virtual bool IsActive() { return false; }
	virtual bool SetActive(bool isActive) {}
	virtual int GetId() { return INVAILD_COMPONENT_ID; }
};

template<class T>
class Component : IComponent
{
public:
	static const int TYPE_ID;

	virtual bool IsActive() override;
	virtual bool SetActive(bool isActive) override;
	virtual int GetId() override { return m_id; }

	int GetTypeId() const { return TYPE_ID; }
	
private:
	int m_id;
	bool m_isActive;
};

template<class T>
bool Component<T>::SetActive(bool isActive)
{
	m_isActive = isActive;
}

template<class T>
bool Component<T>::IsActive()
{
	return m_isActive;
}

template<class T>
const int Component<T>::TYPE_ID = TypeId<IComponent>::Get<T>();


