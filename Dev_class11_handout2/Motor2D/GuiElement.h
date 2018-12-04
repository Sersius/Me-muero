#ifndef _GUIELEMENT_
#define _GUIELEMENT_

#include "j1Gui.h"
#include "SDL/include/SDL.h"

struct SDL_Texture;

enum class MouseState {
	START_CLICK,
	END_CLICK,
	REPEAT_CLICK,
	HOVER,
	NONE
};
class GuiElement {

public:
	GuiElement();
	GuiElement(int x, int y, UiType type);
	virtual ~GuiElement();

	virtual bool Start();
	virtual void Update();
	virtual void Draw(SDL_Texture* texture);
	virtual void CheckMouseState();

public:
	UiType type = NONE;
	int x, y;
	SDL_Texture* texture;
	MouseState mouseState;

};

#endif // !_GUIELEMENT_