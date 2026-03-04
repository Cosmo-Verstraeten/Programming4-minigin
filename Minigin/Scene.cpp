#include <algorithm>
#include "Scene.h"

using namespace dae;

void Scene::Add(std::unique_ptr<GameObject> object)
{
	assert(object != nullptr && "Cannot add a null GameObject to the scene.");
	m_objects.emplace_back(std::move(object));
}

void Scene::Remove(const GameObject& object)
{

	m_pendingRemoval.push_back(const_cast<GameObject*>(&object));
}

void Scene::RemoveAll()
{
	m_objects.clear();
}

void Scene::DefinitiveRemove()
{
	for (GameObject* toRemove : m_pendingRemoval)
	{
		m_objects.erase(
			std::remove_if(
				m_objects.begin(),
				m_objects.end(),
				[toRemove](const auto& ptr) { return ptr.get() == toRemove; }
			),
			m_objects.end()
		);
	}

	m_pendingRemoval.clear();
}

void Scene::Update()
{
	for(auto& object : m_objects)
	{
		object->Update();
	}

	DefinitiveRemove();

}

void Scene::Render() const
{
	for (const auto& object : m_objects)
	{
		object->Render();
	}
}

