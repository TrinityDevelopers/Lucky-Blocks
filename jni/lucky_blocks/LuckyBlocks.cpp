#include "LuckyBlocks.h"

#include "mcpe/world/level/block/Block.h"
#include "mcpe/world/item/Item.h"

#include "blocks/LuckyBlock.h"
#include "items/LuckyBlockItem.h"

Block* LuckyBlocks::luckyBlock;
BlockItem* LuckyBlocks::luckyBlockItem;

void LuckyBlocks::initBlocks() {
	luckyBlock = new LuckyBlock("lucky_block", getNewRandomBlockID());
	luckyBlockItem = new LuckyBlockItem(luckyBlock->getDescriptionId(), luckyBlock->blockId - 0x100);
	
	registerBlock(luckyBlock);
}

void LuckyBlocks::registerBlock(Block* block) {
	block->init();
	Block::mBlocks[block->blockId] = block;
	Block::mOwnedBlocks.emplace_back(std::unique_ptr<Block>(block));
	Item::mItems[block->blockId] = luckyBlockItem;
}

int LuckyBlocks::getNewRandomBlockID() {
	for(int id = 0; id < 256; id++) {
		if(Block::mBlocksHook[id] == NULL) {
			return id;
		}
	}
	return 255;
}

void LuckyBlocks::initCreativeItems() {
	Item::addCreativeItem(luckyBlock, 0);
}