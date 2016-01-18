#pragma once

#include <string>
#include <vector>

class Block;
class BlockPos;
class BlockSource;
class Random;

class StructureUtil {
public:
	static int getEdgeDistance(int, int);
	static bool isEdgeSingleSide(int, int, int);
	static bool isEdge(int, int, int, int, int);
	static bool isCenterEdge(int, int, int, int, int);
	static bool isCorner(int, int, int, int, int);
	static void fill(BlockSource&, const BlockPos&, int, int, int, Block*);
	static void fill(BlockSource&, const BlockPos&, int, int, int, Block*, int);
	static void fillHollow(BlockSource&, const BlockPos&, int, int, int, Block*);
	static void fillHollow(BlockSource&, const BlockPos&, int, int, int, Block*, int);
	static void fillPerimeter(BlockSource&, const BlockPos&, int, int, int, Block*);
	static void fillPerimeter(BlockSource&, const BlockPos&, int, int, int, Block*, int);
	static void fillPerimeterStairs(BlockSource&, const BlockPos&, int, int, int, Block*);
	static void fillCorners(BlockSource&, const BlockPos&, int, int, int, Block*);
	static void fillCorners(BlockSource&, const BlockPos&, int, int, int, Block*, int);
	static void makeSign(BlockSource&, const BlockPos&, Block*, int, std::vector<std::string>);
	static int getSurfacePosY(BlockSource&, const BlockPos&);
	static bool setBlock(BlockSource&, const BlockPos&, Block*);
	static bool setBlock(BlockSource&, const BlockPos&, Block*, int);
	static bool setLuckyBlock(BlockSource&, const BlockPos&, int);
	static bool setLuckyBlock(BlockSource&, Random*, const BlockPos&);
	static bool setBlockMeta(BlockSource&, const BlockPos&, int);
};