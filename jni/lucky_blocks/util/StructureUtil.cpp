#include "StructureUtil.h"

#include "mcpe/leveledit.h"
#include "mcpe/world/level/block/Block.h"
#include "mcpe/world/util/Random.h"

#include "lucky_blocks/LuckyBlocks.h"

int StructureUtil::getEdgeDistance(int firstPos, int newPos) {
	int distance = newPos - firstPos;
	if (distance < 0) {
		distance *= -1;
	}
	return distance;
}

bool StructureUtil::isEdgeSingleSide(int firstPos, int newPos, int edgeDistance) {
	if (getEdgeDistance(firstPos, newPos) == edgeDistance) {
		return true;
	}
	return false;
}

bool StructureUtil::isEdge(int firstPosX, int firstPosZ, int newPosX, int newPosZ, int edgeDistance) {
	if ((getEdgeDistance(firstPosX, newPosX) == edgeDistance) && (getEdgeDistance(firstPosZ, newPosZ) <= edgeDistance)) {
		return true;
	}
	if ((getEdgeDistance(firstPosZ, newPosZ) == edgeDistance) && (getEdgeDistance(firstPosX, newPosX) <= edgeDistance)) {
		return true;
	}
	return false;
}

bool StructureUtil::isCenterEdge(int firstPosX, int firstPosZ, int newPosX, int newPosZ, int edgeDistance) {
	if ((getEdgeDistance(firstPosX, newPosX) == edgeDistance) && (getEdgeDistance(firstPosZ, newPosZ) == 0)) {
		return true;
	}
	if ((getEdgeDistance(firstPosZ, newPosZ) == edgeDistance) && (getEdgeDistance(firstPosX, newPosX) == 0)) {
		return true;
	}
	return false;
}

bool StructureUtil::isCorner(int firstPosX, int firstPosZ, int newPosX, int newPosZ, int cornerDistance) {
	if ((getEdgeDistance(firstPosX, newPosX) == cornerDistance) && (getEdgeDistance(firstPosZ, newPosZ) == cornerDistance)) {
	  return true;
	}
	return false;
}

void StructureUtil::fill(BlockSource& world, const BlockPos& pos, int length, int heigth, int width, Block* block) {
	for (int x = pos.x; x < pos.x + length; x++) {
		for (int y = pos.y; y < pos.y + height; y++) {
			for (int z = pos.z; z < pos.z + width; z++) {
				setBlock(world, {x, y, z}, block);
			}
		}
	}
}

void StructureUtil::fill(BlockSource& world, const BlockPos& pos, int length, int heigth, int width, Block* block, int meta) {
	for (int x = pos.x; x < pos.x + length; x++) {
		for (int y = pos.y; y < pos.y + height; y++) {
			for (int z = pos.z; z < pos.z + width; z++) {
				setBlock(world, {x, y, z}, block, meta);
			}
		}
	}
}

void StructureUtil::fillHollow(BlockSource& world, const BlockPos& pos, int length, int heigth, int width, Block* block) {
	for (int x = pos.x; x < pos.x + length; x++) {
		for (int y = pos.y; y < pos.y + height; y++) {
			for (int z = pos.z; z < pos.z + width; z++) {
				if ((x == pos.x) || (x == pos.x + length - 1) || (y == pos.y) || (y == pos.y + height - 1) || (z == pos.z) || (z == pos.z + width - 1)) {
					setBlock(world, {x, y, z}, block);
				}
			}
		}
	}
}

void StructureUtil::fillHollow(BlockSource& world, const BlockPos& pos, int length, int heigth, int width, Block* block, int meta) {
	for (int x = pos.x; x < pos.x + length; x++) {
		for (int y = pos.y; y < pos.y + height; y++) {
			for (int z = pos.z; z < pos.z + width; z++) {
				if ((x == pos.x) || (x == pos.x + length - 1) || (y == pos.y) || (y == pos.y + height - 1) || (z == pos.z) || (z == pos.z + width - 1)) {
					setBlock(world, {x, y, z}, block, meta);
				}
			}
		}
	}
}

void StructureUtil::fillPerimeter(BlockSource& world, const BlockPos& pos, int length, int heigth, int width, Block* block) {
	for (int x = pos.x; x < pos.x + length; x++) {
		for (int y = pos.y; y < pos.y + height; y++) {
			for (int z = pos.z; z < pos.z + width; z++) {
				if ((x == pos.x) || (x == pos.x + length - 1) || (z == pos.z) || (z == pos.z + width - 1)) {
					setBlock(world, {x, y, z}, block);
				}
			}
		}
	}
}

void StructureUtil::fillPerimeter(BlockSource& world, const BlockPos& pos, int length, int heigth, int width, Block* block, int meta) {
	for (int x = pos.x; x < pos.x + length; x++) {
		for (int y = pos.y; y < pos.y + height; y++) {
			for (int z = pos.z; z < pos.z + width; z++) {
				if ((x == pos.x) || (x == pos.x + length - 1) || (z == pos.z) || (z == pos.z + width - 1)) {
					setBlock(world, {x, y, z}, block, meta);
				}
			}
		}
	}
}

void StructureUtil::fillPerimeterStairs(BlockSource& world, const BlockPos& pos, int length, int heigth, int width, Block* block) {
	for (int y = pos.y; y <= pos.y + height - 1; y++) {
		fill(world, {pos.x + 1, y, pos.z}, length - 1, 1, 1, block, 2);
		fill(world, {pos.x + 1, y, pos.z + width - 1}, length - 1, 1, 1, block, 3);
		fill(world, {pos.x, y, pos.z}, 1, 1, width, block, 0);
		fill(world, {pos.x + length - 1, y, pos.z}, 1, 1, width, block, 1);
	}
}

void StructureUtil::fillCorners(BlockSource& world, const BlockPos& pos, int length, int heigth, int width, Block* block) {
	for (int x = pos.x; x < pos.x + length; x++) {
		for (int y = pos.y; y < pos.y + height; y++) {
			for (int z = pos.z; z < pos.z + width; z++) {
				if ((x == pos.x) || (x == pos.x + length - 1) || (z == pos.z) || (z == pos.z + width - 1)) {
					setBlock(world, {x, y, z}, block);
				}
			}
		}
	}
}

void StructureUtil::fillCorners(BlockSource& world, const BlockPos& pos, int length, int heigth, int width, Block* block, int meta) {
	for (int x = pos.x; x < pos.x + length; x++) {
		for (int y = pos.y; y < pos.y + height; y++) {
			for (int z = pos.z; z < pos.z + width; z++) {
				if ((x == pos.x) || (x == pos.x + length - 1) || (z == pos.z) || (z == pos.z + width - 1)) {
					setBlock(world, {x, y, z}, block, meta);
				}
			}
		}
	}
}

void StructureUtil::makeSign(BlockSource& world, const BlockPos& pos, Block* block, int meta, std::vector<std::string> text) {

}

int StructureUtil::getSurfacePosY(BlockSource& world, const BlockPos& pos) {

}

bool StructureUtil::setBlock(BlockSource& world, const BlockPos& pos, Block* block) {
	if (!world.setBlockAndData(pos, {block->blockId, 0}, 3)) {
		return false;
	}
	return true;
}

bool StructureUtil::setBlock(BlockSource& world, const BlockPos& pos, Block* block, int meta) {
	if (!world.setBlockAndData(pos, {block->blockId, meta}, 3)) {
		return false;
	}
	return true;
}

bool StructureUtil::setLuckyBlock(BlockSource& world, const BlockPos& pos, int luck) {

}

bool StructureUtil::setLuckyBlock(BlockSource& world, Random* random, const BlockPos& pos) {

}

bool StructureUtil::setBlockMeta(BlockSource& world, const BlockPos& pos, int meta) {
	world.setExtraData(pos, meta);
	return true;
}
