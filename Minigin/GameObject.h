#pragma once
#include <string>
#include <memory>
#include "Transform.h"

namespace dae
{


	class Texture2D;
	class GameObject
	{
		Transform m_transform{};
		std::shared_ptr<Texture2D> m_texture{};  //not needed not every object need a texture
	public:
		virtual void Update();
		virtual void Render() const; //maybe not const?? see notes?

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);



		GameObject() = default;
		virtual ~GameObject() = default;
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;
	};
}
