#pragma once

#include "mcpe/world/level/block/Block.h"

class LuckyBlock : public Block {
public:
	LuckyBlock(const std::string&, int);
	
	virtual void onRemove(BlockSource&, const BlockPos&);
	virtual int getResource(Random&, int, int);
};