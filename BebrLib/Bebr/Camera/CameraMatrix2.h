#pragma once
#include "../Math/Matrix.h"
#include "../Math/Vector2.h"
#include "../Core/RectangleData.h"

#include "../Transform/AngleMatrix2.h"
#include "../Transform/PositionMatrix2.h"
#include "../Transform/ScaleMatrix2.h"

namespace bebr
{
	namespace camera
	{
		class CameraMatrix2 : 
			protected transform::AngleMatrix2,
			protected transform::PositionMatrix2,
			protected transform::ScaleMatrix2
		{
		public:
			CameraMatrix2();
			CameraMatrix2( core::RectangleData rectangle );
			CameraMatrix2( float x, float y, float width, float height );
			CameraMatrix2( math::Vector2f position, math::Vector2f size );

			void setView( core::RectangleData rectangle );
			void setView( float x, float y, float width, float height );
			void setView( math::Vector2f position, math::Vector2f size );
			core::RectangleData getView() const;

			void setCenter( float x, float y );
			void setCenter( math::Vector2f center );
			math::Vector2f getCenter() const;

			void move( float x, float y );
			void move( math::Vector2f velocity );

			void setSize( float width, float height );
			void setSize( math::Vector2f size );
			math::Vector2f getSize() const;

			void setAngle( float angle );
			float getAngle() const;

			math::Mat4& getMatrix() const;
		};
	}
}
