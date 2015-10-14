#include "LuckyBlockTile.h"

int LuckyBlockTile::luckyBlockID = 0;
Random* LuckyBlockTile::random = new Random();

LuckyBlockTile::LuckyBlockTile(std::string name) : Tile(LBCoreUtil::findNextBlockID(luckyBlockID), name, Material::decoration) {
	if(!luckyBlockID)
		luckyBlockID = LBCoreUtil::BlockID;
	setNameId(name);
	category = 2;
	setDestroyTime(0.5F);
	setSoundType(Tile::SOUND_METAL);
	init();
	
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
	
	new LuckyBlockItem(luckyBlockID - 256);
}

void LuckyBlockTile::onRemove(TileSource* ts, int x, int y, int z) {
	//drop everything! :)
	popResource(ts, x, y, z, ItemInstance(luckyBlockID, 0, 10));
}