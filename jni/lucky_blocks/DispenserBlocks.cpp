#include "DispenserBlocks.h"

#include "mcpe/world/level/block/Block.h"
#include "mcpe/world/item/Item.h"

#include "blocks/DispenserBlock.h"
#include "items/DispenserBlockItem.h"

Block* DispenserBlocks::dispenserBlock;
BlockItem* DispenserBlocks::dispenserBlockItem;

void DispenserBlocks::initBlocks() {
	dispenserBlock = new DispenserBlock("dispenser_block", getNewRandomBlockID());
	dispenserBlockItem = new DispenserBlockItem(dispenserBlock->getDescriptionId(), dispenserBlock->blockId - 0x100);
	
	registerBlock(dispenserBlock);
}

void DispenserBlocks::registerBlock(Block* block) {
	block->init();
	Block::mBlocks[block->blockId] = block;
	Block::mOwnedBlocks.emplace_back(std::unique_ptr<Block>(block));
	Item::mItems[block->blockId] = dispenserBlockItem;
}

int DispenserBlocks::getNewRandomBlockID() {
	for(int id = 0; id < 256; id++) {
		if(Block::mBlocksHook[id] == NULL) {
			return id;
		}
	}
	return 254;
}

void DispenserBlocks::initCreativeItems() {
	Item::addCreativeItem(dispenserBlock, 0);
}
