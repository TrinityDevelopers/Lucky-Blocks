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
	int testId = bs.getLevel()->getRandom()->genrand_int32() % 512;
	while(Item::mItems[testId] == NULL) {
		testId = bs.getLevel()->getRandom()->genrand_int32() % 512;
	}
	
	popResource(bs, pos, ItemInstance(testId, 10, 0));
}

int LuckyBlock::getResource(Random& rand, int i1, int i2) {
	return NULL;
}
