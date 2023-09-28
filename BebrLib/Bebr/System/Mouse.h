#pragma once
#include "../Math/Vector2.h"

namespace bebr
{
	namespace system
	{
		class Mouse
		{
		public:
			static Mouse& GetInstance();

			math::Vector2i getPosition() const;

			void setVisible( bool visible );
			bool getVisible() const;

			enum Icon { Arrow, Loading, Select, Standart };
			void setIcon( Icon icon );
			Icon getIcon() const;

		private:
			Mouse();

			friend class Window;

			int m_x, m_y;
			bool m_visible;
			Icon m_icon;
		};
	}
}
