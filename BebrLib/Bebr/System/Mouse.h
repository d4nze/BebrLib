#pragma once
#include "../Math/Vector2.h"

namespace bebr
{
	namespace system
	{
		class Window;
		class Mouse
		{
		public:
			static Mouse& GetInstance();

			void setPosition(int x, int y) const;
			void setPosition(math::Vector2i position) const;
			math::Vector2i getPosition() const;

			void setPosition(int x, int y, const Window& window) const;
			void setPosition(math::Vector2i position, const Window& window) const;
			math::Vector2i getPosition(const Window& window) const;

			void setVisible( bool visible );
			bool getVisible() const;

			enum Icon { Arrow, Loading, Select };
			void setIcon( Icon icon );
			Icon getIcon() const;

		private:
			Mouse();
			void updateIcon() const;

			friend class Window;

			bool m_visible;
			Icon m_icon;
		};
	}
}
