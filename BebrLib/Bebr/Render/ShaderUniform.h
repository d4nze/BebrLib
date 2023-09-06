#pragma once
#include <string>

#include "../Math/Vector2.h"
#include "../Math/Vector3.h"
#include "../Math/Vector4.h"

namespace bebr
{
	namespace render
	{
		class ShaderUniform
		{
		public:
			ShaderUniform( unsigned int location, std::string name );

			void setInt1( int value ) const;
			void setInt2( int value1, int value2 ) const;
			void setInt3( int value1, int value2, int value3 ) const;
			void setInt4( int value1, int value2, int value3, int value4 ) const;

			void setUInt1( unsigned int value ) const;
			void setUInt2( unsigned int value1, unsigned int value2 ) const;
			void setUInt3( unsigned int value1, unsigned int value2, unsigned int value3 ) const;
			void setUInt4( unsigned int value1, unsigned int value2, unsigned int value3, unsigned int value4 ) const;

			void setFloat1( float value ) const;
			void setFloat2( float value1, float value2 ) const;
			void setFloat3( float value1, float value2, float value3 ) const;
			void setFloat4( float value1, float value2, float value3, float value4 ) const;

			void setDouble1( double value ) const;
			void setDouble2( double value1, double value2 ) const;
			void setDouble3( double value1, double value2, double value3 ) const;
			void setDouble4( double value1, double value2, double value3, double value4 ) const;

			template<typename T>
			void setVec2( math::Vector2<T> value ) const;
			template<typename T>
			void setVec3( math::Vector3<T> value ) const;
			template<typename T>
			void setVec4( math::Vector4<T> value ) const;

		private:
			std::string m_name;
			unsigned int m_location;

			friend class ShaderProgram;
		};
		//template<typename T>
		//inline void ShaderUniform::setVec2( math::Vector2<T> value ) const {}
		//template<typename T>
		//inline void ShaderUniform::setVec3( math::Vector3<T> value ) const {}
		//template<typename T>
		//inline void ShaderUniform::setVec4( math::Vector4<T> value ) const {}
	}
}
