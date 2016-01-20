#include "DispenserBlock.h"
#include "mcpe/leveledit.h"

DispenserBlock::DispenserBlock(const std::string& name, int id) : 
	Block(name, id, name, Material::getMaterial(MaterialType::DECORATION)) {
	
	creativeCategory = 2;
	setDestroyTime(0.5F);
	setSoundType(SOUND_METAL);
	
}


	
