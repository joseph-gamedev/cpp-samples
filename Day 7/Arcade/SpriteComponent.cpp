#include "SpriteComponent.h"
#include "Texture2d.h"

SpriteComponent::SpriteComponent(std::unique_ptr<Texture2d> texture)
	: m_texture(std::move(texture))
{

}

Texture2d* SpriteComponent::GetTexture()
{
	return m_texture.get();
}
