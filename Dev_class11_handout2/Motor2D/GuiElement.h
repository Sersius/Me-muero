#ifndef _GUIELEMENT_
#define _GUIELEMENT_

#include "j1Gui.h"

enum class MouseState {

};
class GuiElement : public j1Gui
{
public:
	GuiElement();
	GuiElement(int x, int y, UiType type, SDL_Texture* texture);
	~GuiElement();
private:
	UiType type;
	fPoint position;
	SDL_Texture* texture;

};

#endif // !_GUIELEMENT_