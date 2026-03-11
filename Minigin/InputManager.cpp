#include <SDL3/SDL.h>
#include "InputManager.h"
#include <backends/imgui_impl_sdl3.h>

bool dae::InputManager::ProcessInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_EVENT_QUIT) 
		{
			return false;
		}
		if (e.type == SDL_EVENT_KEY_DOWN) 
		{
			ExecuteIfBound(e.key.key, KeyState::Down);
		}
		if (e.type == SDL_EVENT_KEY_UP)
		{
			ExecuteIfBound(e.key.key, KeyState::Up);
		}
		if (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
			
		}

		const bool* keyboardState = SDL_GetKeyboardState(nullptr);

		for (int key = 0; key < SDL_SCANCODE_COUNT; ++key)
		{
			if (keyboardState[key])
			{
				ExecuteIfBound(key, KeyState::Pressed);
			}
		}

		for (auto& controller : m_Controllers)
		{
			controller.Update();
		}



		//process event for IMGUI
		ImGui_ImplSDL3_ProcessEvent(&e);
	}

	return true;
}

void dae::InputManager::Bind(int key, KeyState state, std::unique_ptr<Command> command)
{
	InputAction action{ key, state };
	m_bindings[action] = std::move(command);
}

void dae::InputManager::Unbind(int key, KeyState state)
{
	InputAction action{ key, state };
	m_bindings.erase(action);
}

void dae::InputManager::ExecuteIfBound(int key, KeyState state)
{
	InputAction action{ key, state };

	auto it = m_bindings.find(action);

	if (it != m_bindings.end())
	{
		it->second->execute();
	}
}
