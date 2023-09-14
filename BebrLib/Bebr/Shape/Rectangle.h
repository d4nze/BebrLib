#pragma once
#include "Shape2.h"
#include "../Core/RectangleData.h"

namespace bebr
{
	namespace shape
	{
		class Rectangle : public Shape2
		{
		public:
			Rectangle();
			Rectangle( core::RectangleData rectangle );
			Rectangle( float x, float y, float width, float height );
			Rectangle( math::Vector2f position, math::Vector2f size );

			void setSize( float width, float height );
			void setSize( math::Vector2f size );
			math::Vector2f getSize() const;

			void setColor( core::Colorf color );
			enum Corner { TopLeft = 0u, TopRight, BottomRight, BottomLeft };
			void setColor( core::Colorf color, Corner corner );
			core::Colorf getColor( Corner corner ) const;

			void setTextureRectangle( core::RectangleData textureRectangle );
			core::RectangleData getTextureRectangle() const;

		private:
			void initVertices();
			void initIndices();

		protected:
			math::Vector2f m_size;
			core::RectangleData m_textureRectangle;
		};
	}
}
