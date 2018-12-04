#include "GuiImage.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Gui.h"

GuiImage::GuiImage(int x, int y, SDL_Rect rect) :GuiElement(x, y, IMAGE)
{
	rect = rect;

}
GuiImage::~GuiImage()
{
}
void GuiImage::Draw(SDL_Texture* atlas) {
	App->render->Blit(atlas, x, y, &rect);
}