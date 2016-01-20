#pragma once
class Block;
class BlockItem;

class LuckyBlocks {
public:
	static Block* luckyBlock;
	static BlockItem* luckyBlockItem;
	
	static Block* dropperBlock;
	
	static void initBlocks();
	static void registerBlock(Block*);
	static int getNewRandomBlockID();
	
	static void initCreativeItems();
};