#include "LuckyBlock.h"

#include "mcpe/leveledit.h"
#include "mcpe/world/item/ItemInstance.h"

LuckyBlock::LuckyBlock(const std::string& name, int id) : 
	Block(name, id, name, Material::getMaterial(MaterialType::EXPLOSIVE)) {
	
	creativeCategory = 2;
	setDestroyTime(0.5F);
	setSoundType(SOUND_METAL);
	
}

void LuckyBlock::onRemove(BlockSource& bs, const BlockPos& pos) {
	//drop everything! :)
	popResource(bs, pos, ItemInstance(blockId, 10, 0));
}

int LuckyBlock::getResource(Random& rand, int i1, int i2) {
	return NULL;
}