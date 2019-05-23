#pragma once

#include "Core.h"
#include "Layer.h"
#include "Events/ApplicationEvent.h"

namespace lumos
{
	namespace graphics
	{
		class Renderer2D;
	}

    class LUMOS_EXPORT Layer2D : public Layer
	{
	public:
		Layer2D(graphics::Renderer2D* renderer, const std::string& name = "Layer2D");
		virtual ~Layer2D();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate(TimeStep* dt, Scene* scene) override;
		virtual void OnEvent(Event& event) override;
		virtual void OnRender(Scene* scene) override;

    protected:
        Scene* m_Scene;
        graphics::Renderer2D* m_Renderer;
	private:
        bool OnwindowResizeEvent(WindowResizeEvent& e);
	};

}
