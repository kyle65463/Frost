#pragma once

#include "event.h"

namespace Frost {
	class FROST_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: m_XOffset(x), m_YOffset(y) {}

		inline float getX() const { return m_XOffset; }
		inline float getY() const { return m_YOffset; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategory::Mouse | EventCategory::EventInput)

	private:
		unsigned int m_XOffset, m_YOffset;
	};

	class FROST_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float getXOffset() const { return m_XOffset; }
		inline float getYOffset() const { return m_YOffset; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategory::Mouse | EventCategory::EventInput)

	private:
		unsigned int m_XOffset, m_YOffset;
	};

	class FROST_API MouseButtonEvent : public Event
	{
	public:
		inline int getMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategory::Mouse | EventCategory::EventInput)

	protected:
		MouseButtonEvent(int button) : m_Button(button) {}
		int m_Button;
	};

	class FROST_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string toString() const override
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

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}
