#pragma once

#include <string>

class GameObject
{
public:

	GameObject(const std::string& name);

	std::string& GetName();

private:

	std::string m_name;
};

