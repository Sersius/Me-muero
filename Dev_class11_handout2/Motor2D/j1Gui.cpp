#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Gui.h"
#include "GuiImage.h"

j1Gui::j1Gui() : j1Module()
{
	name.create("gui");
}

// Destructor
j1Gui::~j1Gui()
{}

// Called before render is available
bool j1Gui::Awake(pugi::xml_node& conf)
{
	LOG("Loading GUI atlas");
	bool ret = true;

	atlas_file_name = conf.child("atlas").attribute("file").as_string("");

	return ret;
}

// Called before the first frame
bool j1Gui::Start()
{
	atlas = App->tex->Load(atlas_file_name.GetString());

	return true;
}

// Update all guis
bool j1Gui::PreUpdate()
{
	return true;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{
	for (uint i = 0u; i < element.Count(); i++) {
		if (element[i] != nullptr) {
			element[i]->Draw(atlas);
		}
	}

	return true;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	LOG("Freeing GUI");

	App->tex->UnLoad(atlas);

	return true;
}

GuiElement* j1Gui::CreateImage(int x, int y, SDL_Rect rect)
{
	GuiElement* image = new GuiImage(x,y,rect);
	element.PushBack(image);

	return nullptr;
}

// const getter for atlas
const SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}

// class Gui ---------------------------------------------------

