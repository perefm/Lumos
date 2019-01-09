#include "JM.h"
#include "Input.h"

namespace jm
{

	Input* Input::s_Input;

	void Input::Create()
	{
		s_Input = new Input();
	}

	Input::Input()
	{
		Reset();
	}

	void Input::Reset()
	{
		memset(m_KeyHeld, 0, MAX_KEYS);
		memset(m_KeyPressed, 0, MAX_KEYS);
		memset(m_MouseClicked, 0, MAX_BUTTONS);
		memset(m_MouseHeld, 0, MAX_BUTTONS);

		m_MouseOnScreen = true;
		m_WindowFocus = true;
		m_ScrollOffset = 0.0f;
	}

	void Input::ResetPressed()
	{
		memset(m_KeyPressed, 0, MAX_KEYS);
		memset(m_MouseClicked, 0, MAX_BUTTONS);
	}

	void Input::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(Input::OnKeyPressed));
        dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FN(Input::OnKeyReleased));
		dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(Input::OnMousePressed));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FN(Input::OnMouseReleased));
		dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FN(Input::OnMouseScrolled));
		dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(Input::OnMouseMoved));
		dispatcher.Dispatch<MouseEnterEvent>(BIND_EVENT_FN(Input::OnMouseEnter));
	}

	bool Input::OnKeyPressed(KeyPressedEvent& e)
	{
		SetKeyPressed(e.GetKeyCode(), e.GetRepeatCount() < 1);
		SetKeyHeld(e.GetKeyCode(), true);
		return true;
	}

	bool Input::OnKeyReleased(KeyReleasedEvent& e)
	{
		SetKeyPressed(e.GetKeyCode(), false);
		SetKeyHeld(e.GetKeyCode(), false);
		return true;
	}

	bool Input::OnMousePressed(MouseButtonPressedEvent& e)
	{
		SetMouseClicked(e.GetMouseButton(), true);
		SetMouseHeld(e.GetMouseButton(), true);
		return true;
	}
	bool Input::OnMouseReleased(MouseButtonReleasedEvent& e)
	{
		SetMouseClicked(e.GetMouseButton(), false);
		SetMouseHeld(e.GetMouseButton(), false);
		return true;
	}

	bool Input::OnMouseScrolled(MouseScrolledEvent& e)
	{
		SetScrollOffset(e.GetYOffset());
		return true;
	}

	bool Input::OnMouseMoved(MouseMovedEvent& e)
	{
		StoreMousePosition((int)e.GetX(), (int)e.GetY());
		return true;
	}

	bool Input::OnMouseEnter(MouseEnterEvent& e)
	{
		SetMouseOnScreen(e.GetEntered());
		return true;
	}
}