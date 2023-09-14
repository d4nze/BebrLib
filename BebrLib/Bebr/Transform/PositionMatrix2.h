#pragma once
#include "../Math/Vector2.h"
#include "../Math/Matrix.h"

namespace bebr
{
	namespace transform
	{
		class PositionMatrix2
		{
		public:
			PositionMatrix2();
			PositionMatrix2( float x, float y );
			PositionMatrix2( math::Vector2f position );

			void setPosition( float x, float y );
			void setPosition( math::Vector2f position );
			math::Vector2f getPosition() const;

			void move( float x, float y );
			void move( math::Vector2f velocity );

		protected:
			math::Mat4& getMatrix() const;

		private:
			float m_x, m_y;
		};
	}
}
