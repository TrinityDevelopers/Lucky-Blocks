#include "LuckyBlock.h"

#include "mcpe/leveledit.h"
#include "mcpe/world/item/ItemInstance.h"
#include "mcpe/world/util/Random.h"

LuckyBlock::LuckyBlock(const std::string& name, int id) : 
	Block(name, id, name, Material::getMaterial(MaterialType::DECORATION)) {
	
	creativeCategory = 2;
	setDestroyTime(0.5F);
	setSoundType(SOUND_METAL);
	
}

void LuckyBlock::onRemove(BlockSource& bs, const BlockPos& pos) {
	//drop everything! :)
	popResource(bs, pos, ItemInstance(bs.getLevel()->getRandom()->genrand_int32() % 512, 10, 0));
}

int LuckyBlock::getResource(Random& rand, int i1, int i2) {
	return NULL;
}
