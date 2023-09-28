#pragma once
#include "Shape2.h"
#include "../Core/Rect.h"

namespace bebr
{
	namespace shape
	{
		class Circle : public Shape2
		{
		public:
			Circle();
			Circle( core::Rect rectangle );
			Circle( float x, float y, float radius );
			Circle( math::Vector2f position, float radius );
			Circle( float x, float y, float width, float height );
			Circle( math::Vector2f position, math::Vector2f size );

			void setCount( int count );
			int getCount() const;

			void setSize( float width, float height );
			void setSize( math::Vector2f size );
			void setRadius( float radius );
			math::Vector2f getSize() const;

			void setColor( core::Colorf color );
			core::Colorf getColor() const;

			void setTextureRectangle( core::Rect textureRectangle );
			core::Rect getTextureRectangle() const;

		protected:
			int m_count;
			math::Vector2f m_size;
			core::Rect m_textureRectangle;
		};
	}
}
