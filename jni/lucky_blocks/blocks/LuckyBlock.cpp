#include "LuckyBlock.h"

#include "mcpe/leveledit.h"
#include "mcpe/item/ItemInstance.h"

LuckyBlock::LuckyBlock(const std::string& name, int id) : 
	Block(name, id, name, Material::getMaterial(MaterialType::EXPLOSIVE)) {
	
	creativeCategory = 2;
	setDestroyTime(0.5F);
	setSoundType(SOUND_METAL);
	
}

void LuckyBlock::onRemove(BlockSource& bs, const BlockPos& pos) {
	//drop everything! :)
	popResource(bs, pos, ItemInstance(luckyBlockID, 0, 10));
}