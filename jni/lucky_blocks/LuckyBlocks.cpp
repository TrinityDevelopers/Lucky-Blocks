#include "LuckyBlocks.h"

#include "mcpe/world/level/block/Block.h"
#include "mcpe/world/item/Item.h"
#include "mcpe/world/item/BlockItem.h"

#include "blocks/DropperBlock.h"
#include "blocks/LuckyBlock.h"
#include "items/LuckyBlockItem.h"

Block* LuckyBlocks::luckyBlock;
BlockItem* LuckyBlocks::luckyBlockItem;

Block* LuckyBlocks::dropperBlock;

void LuckyBlocks::initBlocks() {
	luckyBlock = new LuckyBlock("lucky_block", getNewRandomBlockID());
	luckyBlockItem = new LuckyBlockItem(luckyBlock->getDescriptionId(), luckyBlock->blockId - 0x100);
	registerBlock(luckyBlock, luckyBlockItem);
	
	dropperBlock = new DropperBlock("dropper", 158);
	registerBlock(dropperBlock, new BlockItem(dropperBlock->getDescriptionId(), 158 - 0x100););
}

void LuckyBlocks::registerBlock(Block* block, BlockItem* blockItem) {
	block->init();
	Block::mBlocks[block->blockId] = block;
	Block::mOwnedBlocks.emplace_back(std::unique_ptr<Block>(block));
	Item::mItems[block->blockId] = blockItem;
}

int LuckyBlocks::getNewRandomBlockID() {
	for(int id = 0; id < 256; id++) {
		if(Block::mBlocks[id] == NULL) {
			return id;
		}
	}
	return 255;
}

void LuckyBlocks::initCreativeItems() {
	Item::addCreativeItem(luckyBlock, 0);
	Item::addCreativeItem(dropperBlock, 0);
}