#ifndef __GUIIMAGE__
#define __GUIIMAGE__

#include "GuiElement.h"

class GuiImage : public GuiElement {

public:
	GuiImage(int x, int y, SDL_Rect rect);
	~GuiImage();
	void Draw(SDL_Texture* atlas);

private:
	SDL_Rect rect;

};
#endif