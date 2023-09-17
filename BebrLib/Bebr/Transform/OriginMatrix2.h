#pragma once
#include "../Math/Vector2.h"
#include "../Math/Matrix.h"

namespace bebr
{
	namespace transform
	{
		class OriginMatrix2
		{
		public:
			OriginMatrix2();
			OriginMatrix2( float x, float y );
			OriginMatrix2( math::Vector2f offset );

			void setOrigin( float x, float y );
			void setOrigin( math::Vector2f offset );
			math::Vector2f getOrigin() const;

		protected:
			math::Mat4& getMatrix() const;

		private:
			float m_x, m_y;
		};
	}
}
