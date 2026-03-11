#include "Controller.h"

#include <Windows.h>
#include <Xinput.h>



class dae::Controller::Impl
{
public:

    Impl(int index)
        : m_Index(index)
    {

    }

    void Update()
    {
        m_PreviousState = m_CurrentState;

        ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
        XInputGetState(m_Index, &m_CurrentState);
    }

    bool IsDown(WORD button) const
    {
        return (m_CurrentState.Gamepad.wButtons & button) && !(m_PreviousState.Gamepad.wButtons & button);
    }

    bool IsPressed(WORD button) const
    {
        return (m_CurrentState.Gamepad.wButtons & button);
    }

    bool IsUp(WORD button) const
    {
        return !(m_CurrentState.Gamepad.wButtons & button) && (m_PreviousState.Gamepad.wButtons & button);
    }




private:

    int m_Index;

    XINPUT_STATE m_CurrentState{};
    XINPUT_STATE m_PreviousState{};


};

static WORD ToXInput(dae::Controller::Button button)
{
    switch (button)
    {
    case dae::Controller::Button::DPadUp: return XINPUT_GAMEPAD_DPAD_UP;
    case dae::Controller::Button::DPadDown: return XINPUT_GAMEPAD_DPAD_DOWN;
    case dae::Controller::Button::DPadLeft: return XINPUT_GAMEPAD_DPAD_LEFT;
    case dae::Controller::Button::DPadRight: return XINPUT_GAMEPAD_DPAD_RIGHT;
    }

    return 0;
};

dae::Controller::Controller(int index)
    : m_Impl(std::make_unique<Impl>(index))
{

}

dae::Controller::~Controller() = default;

void dae::Controller::Update()
{
    m_Impl->Update();
}

bool dae::Controller::IsDown(Button button) const
{
    return m_Impl->IsDown(ToXInput(button));
}

bool dae::Controller::IsPressed(Button button) const
{
    return m_Impl->IsPressed(ToXInput(button));
}

bool dae::Controller::IsUp(Button button) const
{
    return m_Impl->IsUp(ToXInput(button));
}
