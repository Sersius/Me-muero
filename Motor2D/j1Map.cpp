#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Map.h"
#include <math.h>

j1Map::j1Map() : j1Module(), map_loaded(false)
{
	name.create("map");
}

// Destructor
j1Map::~j1Map()
{}

// Called before render is available
bool j1Map::Awake(pugi::xml_node& config)
{
	LOG("Loading Map Parser");
	bool ret = true;

	folder.create(config.child("folder").child_value());

	return ret;
}

void j1Map::Draw()
{
	if(map_loaded == false)
		return;

	// TODO 6: Iterate all tilesets and draw all their 
	// images in 0,0 (you should have only one tileset for now)
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.h = 199;
	rect.w = 265;
	p2List_item<TileSet*>* item = tile_s.start;

	while (item != nullptr)
	{
		App->render->Blit(item->data->texture, 0,0, &rect);		
		item = item->next;
	}
}

// Called before quitting
bool j1Map::CleanUp()
{
	LOG("Unloading map");

	// TODO 2: Make sure you clean up any memory allocated
	// from tilesets / map


	map_file.reset();

	return true;
}

// Load new map
bool j1Map::Load(const char* file_name)
{
	bool ret = true;
	p2SString tmp("%s%s", folder.GetString(), file_name);

	pugi::xml_parse_result result = map_file.load_file(tmp.GetString());

	if(result == NULL)
	{
		LOG("Could not load map xml file %s. pugi error: %s", file_name, result.description());
		ret = false;
	}

	if(ret == true)
	{
		// TODO 3: Create and call a private function to load and fill
		// all your map data
		LoadMap(map_file);
	}

	// TODO 4: Create and call a private function to load a tileset
	// remember to support more any number of tilesets!
	LoadTileset(map_file);

	if(ret == true)
	{
		// TODO 5: LOG all the data loaded
		// iterate all tilesets and LOG everything
		LOG("Successfully parsed map XML file: %s", file_name);
		LOG("width: %d height: %d", map_s.width, map_s.height);
		LOG("tile_width: %d tile_height: %d", map_s.tilewidth, map_s.tileheight);

		p2List_item<TileSet*>* item = tile_s.start;
		while (item != NULL)
		{
			TileSet* s = item->data;
			LOG("Tileset ----");
			LOG("tile width: %d tile height: %d", s->tilewidth, s->tileheight);
			LOG("spacing: %d margin: %d", s->spacing, s->margin);
			item = item->next;
		}


	}

	map_loaded = ret;

	return ret;
}

void j1Map::LoadMap(pugi::xml_document& map_file)
{
	pugi::xml_node map;

	pugi::xml_parse_result result = map_file.load_file("maps/hello2.tmx");

	map = map_file.child("map");

	p2SString aux = map.attribute("orientation").as_string();
	
	if (aux == "orthogonal")
		map_s.orientation = orthogonal;
	else
		LOG("Error charging LoadMap()");

	aux = map.attribute("renderorder").as_string();

	if (aux == "right-down")
		map_s.renderorder = right_down;
	else
		LOG("Error charging LoadMap()");

	map_s.height = map.attribute("height").as_uint();
	map_s.width = map.attribute("width").as_uint();
	map_s.tileheight = map.attribute("tileheight").as_uint();
	map_s.tilewidth = map.attribute("tilewidth").as_uint();
}

void j1Map::LoadTileset(pugi::xml_document& map_file)
{
	pugi::xml_parse_result result = map_file.load_file("maps/hello2.tmx");
	TileSet* tileset = new TileSet;
	tile_s.add(tileset);
	p2List_item<TileSet*>* item = tile_s.start;
	

	for (pugi::xml_node tileset = map_file.child("map").child("tileset"); tileset; tileset = tileset.next_sibling("tileset"))
	{
		item->data->margin = tileset.attribute("margin").as_uint();
		item->data->spacing = tileset.attribute("spacing").as_uint();
		item->data->tileheight = tileset.attribute("tileheight").as_uint();
		item->data->tilewidth = tileset.attribute("tilewidth").as_uint();
		item->data->texture = App->tex->Load("maps/tmw_desert_spacing.png");
		item->next;
	}
}