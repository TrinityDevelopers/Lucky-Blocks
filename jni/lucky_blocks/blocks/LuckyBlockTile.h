#pragma once

#include <string>

#include "mcpe/tile/Tile.h"
#include "mcpe/util/Random.h"
#include "mcpe/tile/material/Material.h"
#include "mcpe/item/ItemInstance.h"
#include "lucky_blocks/items/LuckyBlockItem.h"
#include "lucky_blocks/util/LBCoreUtil.h"

class LuckyBlockTile : public Tile {
public:
	static int luckyBlockID;
	static Random* random;
	
	LuckyBlockTile(std::string);
	virtual void onRemove(TileSource*, int, int, int);
	
};