#pragma once


namespace dae
{
    class GameObject;
    class Component
    {

    public:
        explicit Component(GameObject* owner) : m_owner(owner) {}
        virtual ~Component() = default;

        Component(const Component&) = delete;
        Component(Component&&) = delete;
        Component& operator=(const Component&) = delete;
        Component& operator=(Component&&) = delete;

        virtual void UpdateComponent() = 0;
        virtual void RenderComponent() const = 0;

        GameObject* GetOwner() const { return m_owner; }

    private:

        GameObject* m_owner{};
    };
}