#include "GuiElement.h"

GuiElement::GuiElement(int x, int y, UiType type, SDL_Texture * texture) : position(x,y), type(type), texture(texture){}
