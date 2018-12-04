#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
#include "j1Render.h"
#include "p2DynArray.h"
#include "p2SString.h"

#define CURSOR_WIDTH 2

// TODO 1: Create your structure of classes

enum UiType {
	LABEL,
	BUTTON,
	IMAGE,
	CHECKBOX,
	NONE
};

class GuiElement;
// ---------------------------------------------------
class j1Gui : public j1Module
{
public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// TODO 2: Create the factory methods
	// Gui creation functions
	GuiElement* CreateImage(int x, int y, SDL_Rect rect);

	const SDL_Texture* GetAtlas() const;

public:

	SDL_Texture* atlas;
	p2SString atlas_file_name;
	p2DynArray<GuiElement*> element;
};

#endif // __j1GUI_H__