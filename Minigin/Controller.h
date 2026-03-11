#pragma once

#include <memory>
namespace dae
{
    class Controller
    {
    public:

        enum class Button
        {
            DPadUp,
            DPadDown,
            DPadLeft,
            DPadRight,
        };

        Controller(int index);
        ~Controller();

        void Update();

        bool IsDown(Button button) const;
        bool IsPressed(Button button) const;
        bool IsUp(Button button) const;



    private:


        class Impl;
        std::unique_ptr<Impl> m_Impl;

    };
}