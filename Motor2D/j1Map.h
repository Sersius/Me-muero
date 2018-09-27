#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"

// TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!
// ----------------------------------------------------
struct TileSet
{
	uint tilewidth = 0u;
	uint tileheight = 0u;
	uint spacing = 0u;
	uint margin = 0u;
	SDL_Texture* texture;
};

enum map_orientation
{
	NONE,
	orthogonal,
	isometric
};

enum map_renderorder
{
	none,
	right_down,
	right_up,
	left_down,
	left_up
};

// TODO 1: Create a struct needed to hold the information to Map node
struct Map
{
	uint width = 0u;
	uint height = 0u;
	uint tilewidth= 0u;
	uint tileheight = 0u;
	map_renderorder renderorder = map_renderorder::none;
	map_orientation orientation = map_orientation::NONE;

};

// ----------------------------------------------------
class j1Map : public j1Module
{
public:

	j1Map();

	// Destructor
	virtual ~j1Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	// Called each loop iteration
	void Draw();

	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* path);

private:

	void LoadMap(pugi::xml_document&);
	void LoadTileset(pugi::xml_document&);

public:

	// TODO 1: Add your struct for map info as public for now
	Map map_s;
	p2List<TileSet*> tile_s;
	

private:

	pugi::xml_document	map_file;
	p2SString			folder;
	bool				map_loaded;
};

#endif // __j1MAP_H__