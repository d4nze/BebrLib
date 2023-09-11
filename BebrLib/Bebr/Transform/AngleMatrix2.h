#pragma once
#include "../Math/Vector2.h"
#include "../Math/Matrix.h"

namespace bebr
{
	namespace transform
	{
		class AngleMatrix2
		{
		public:
			AngleMatrix2();
			AngleMatrix2( float angle );

			void setAngle( float angle );
			float getAngle() const;

			void rotate( float rotation );

		protected:
			math::Mat4& getMatrix() const; // TODO: make 'protected'

		private:
			float m_angle;
		};
	}
}
