#include "DropperBlock.h"
#include "mcpe/leveledit.h"

DropperBlock::DropperBlock(const std::string& name, int id) : 
	Block(name, id, name, Material::getMaterial(MaterialType::DECORATION)) {
	
	creativeCategory = 3;
	setDestroyTime(3.5F);
	setSoundType(SOUND_METAL);
	
}


	
