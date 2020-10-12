// ECSTwo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ECS.hpp"
#include "ComponentManager.h"
#include "SpriteComponent.h"
#include "MeshComponent.h"

//class SpriteComponent : public Component
//{
//
//};

int main()
{
   /* ECS ecs;
    Entity* entity1 = ecs.CreateEntity();
    entity1->AddComponent<SpriteComponent>();

    Entity* entity2 = ecs.CreateEntity();*/
    std::cout << Component<SpriteComponent>::TYPE_ID << std::endl;
    std::cout << Component<MeshComponent>::TYPE_ID << std::endl;
    std::cout << Component<SpriteComponent>::TYPE_ID << std::endl;
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
