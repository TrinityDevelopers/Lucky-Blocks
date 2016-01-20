#include "LuckyBlock.h"

#include "mcpe/leveledit.h"
#include "mcpe/world/item/ItemInstance.h"
#include "mcpe/world/util/Random.h"
//#include "mcpe/world/entity/EntityFactory.h"
//#include "mcpe/world/entity/EntityType.h"

LuckyBlock::LuckyBlock(const std::string& name, int id) : 
	Block(name, id, name, Material::getMaterial(MaterialType::DECORATION)) {
	
	creativeCategory = 2;
	setDestroyTime(0.5F);
	setSoundType(SOUND_METAL);
	
}

void LuckyBlock::onRemove(BlockSource& bs, const BlockPos& pos) {
	//drop everything! :)
/*int testId = bs.getLevel()->getRandom()->genrand_int32() % 512;
while(Item::mItems[testId] == NULL) {
 testId = bs.getLevel()->getRandom()->genrand_int32() % 512;
}*/ 
Entity* entity;
int luck = bs.getLevel()->getRandom()->genrand_int32() % 3;

if(luck == 0){
popResource(bs, pos, ItemInstance(blockId, 10, 0));
//bs->region.getLevel()->addGlobalEntity(std::unique_ptr<Entity>(EntityType.ZOMBIE(bs->region, pos.x,pos.y,pos.z))));
	//	player->region.getLevel()->addGlobalEntity(std::unique_ptr<Entity>(new EntityExample(player->region, x, y + 2, z)));
}else if (luck == 1) {
	popResource(bs, pos, ItemInstance(blockId, 10, 0));
	popResource(bs, pos, ItemInstance(264, 10, 0));
}else if (luck == 2) {
	popResource(bs, pos, ItemInstance(276, 10, 0));
}else if (luck == 3){
	popResource(bs, {pos.x,pos.y + 10,pos.z}, ItemInstance(264, 2, 0));
	popResource(bs, {pos.x,pos.y + 10,pos.z+3}, ItemInstance(264, 4, 0));
	popResource(bs, {pos.x,pos.y + 10,pos.z-3}, ItemInstance(264, 6, 0));
	popResource(bs, {pos.x-3,pos.y + 10,pos.z}, ItemInstance(264, 8, 0));
	popResource(bs, {pos.x+3,pos.y + 10,pos.z}, ItemInstance(264, 10, 0));
	
}
}

int LuckyBlock::getResource(Random& rand, int i1, int i2) {
	return NULL;
}
