#pragma once
#include "Singleton.h"
#include <iostream>
#include <Command.h>
#include <map>
#include <vector>
#include "Controller.h"

namespace dae
{



	class InputManager final : public Singleton<InputManager>
	{
	public:
		enum class KeyState
		{
			Down,
			Up,
			Pressed
		};

		struct InputAction
		{
			int key;
			KeyState state;

			bool operator<(const InputAction& other) const
			{
				if (key != other.key)
				{
					return key < other.key;
				}

				return state < other.state;
			}
		};

		bool ProcessInput();
		void Bind(int key, KeyState state, std::unique_ptr<Command> command);
		void Unbind(int key, KeyState state);

		void ExecuteIfBound(int key, KeyState state);

	private:

		std::map<InputAction, std::unique_ptr<Command>> m_bindings;
		std::vector<Controller> m_Controllers;
	};

}
