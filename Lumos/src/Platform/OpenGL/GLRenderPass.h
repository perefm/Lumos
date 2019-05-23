#pragma once
#include "LM.h"
#include "Graphics/API/RenderPass.h"

namespace lumos
{
    namespace graphics
    {
        class GLRenderPass : public RenderPass
        {
        public:
            GLRenderPass();
            ~GLRenderPass();

            bool Init(const RenderpassInfo& renderpassCI) override;
            void Unload() const  override;
            void BeginRenderpass(CommandBuffer * commandBuffer, const maths::Vector4& clearColour, Framebuffer* frame,
                                 SubPassContents contents, uint32_t width, uint32_t height) const  override;
            void EndRenderpass(CommandBuffer* commandBuffer) override;

		private:
			bool m_Clear = true;
        };
    }
}