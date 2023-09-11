#pragma once
#include "../Math/Vector2.h"
#include "../Math/Matrix.h"

namespace bebr
{
	namespace transform
	{
		class ScaleMatrix2
		{
		public:
			ScaleMatrix2();
			ScaleMatrix2( float x, float y );
			ScaleMatrix2( math::Vector2f scale );

			void setScale( float x, float y );
			void setScale( math::Vector2f scale );
			math::Vector2f getScale() const;

		protected:
			math::Mat4& getMatrix() const;

		private:
			float m_x, m_y;
		};
	}
}
