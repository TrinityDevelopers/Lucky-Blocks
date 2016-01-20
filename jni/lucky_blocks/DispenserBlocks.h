#pragma once
class Block;
class BlockItem;

class DispenserBlocks {
public:
	static Block* dispenserBlock;
	static BlockItem* dispenserBlockItem;
	
	static void initBlocks();
	static void registerBlock(Block*);
	static int getNewRandomBlockID();
	
	static void initCreativeItems();
};
