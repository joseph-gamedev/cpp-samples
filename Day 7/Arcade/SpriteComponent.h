#pragma once

#include <memory>

class Texture2d;

class SpriteComponent
{
public:
	SpriteComponent(std::unique_ptr<Texture2d> texture);
	Texture2d* GetTexture();

private:
	std::unique_ptr<Texture2d> m_texture;
	bool m_flipX;
	bool m_flipY;
};

