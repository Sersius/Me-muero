#include "GuiElement.h"
#include "j1App.h"
#include "j1Textures.h"

GuiElement::GuiElement(int x, int y, UiType type) : x(x), y(y), type(type){}

GuiElement::~GuiElement()
{
	App->tex->UnLoad(texture);
}

bool GuiElement::Start()
{
	return true;
}

void GuiElement::Update()
{
}

void GuiElement::Draw(SDL_Texture * texture)
{
}

void GuiElement::CheckMouseState()
{
}
