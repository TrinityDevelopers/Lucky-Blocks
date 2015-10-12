#include "LuckyBlockTiles.h"

Tile* LuckyBlockTiles::sampleLuckyBlock = NULL;

void LuckyBlockTiles::initTiles() {
	LuckyBlockTiles::sampleLuckyBlock = (Tile*) new LuckyBlockTile("lucky_block");
}

void LuckyBlockTiles::initCreativeItems() {
	Item::addCreativeItem(LuckyBlockTiles::sampleLuckyBlock, 0);
}