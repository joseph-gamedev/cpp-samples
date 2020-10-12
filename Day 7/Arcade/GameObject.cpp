#include "GameObject.h"

GameObject::GameObject(const std::string& name)
	:m_name(name)
{

}

std::string& GameObject::GetName()
{
	return m_name;
}
