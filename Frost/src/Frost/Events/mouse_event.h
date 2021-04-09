#pragma once

#include "event.h"

namespace Frost {
	class FROST_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: m_XOffset(x), m_YOffset(y) {}

		inline float GetX() const { return m_XOffset; }
		inline float GetY() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategory::Mouse | EventCategory::Input)

	private:
		unsigned int m_XOffset, m_YOffset;
	};

	class FROST_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategory::Mouse | EventCategory::Input)

	private:
		unsigned int m_XOffset, m_YOffset;
	};

	class FROST_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategory::Mouse | EventCategory::Input)

	protected:
		MouseButtonEvent(int button) : m_Button(button) {}
		int m_Button;
	};

	class FROST_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class FROST_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}
