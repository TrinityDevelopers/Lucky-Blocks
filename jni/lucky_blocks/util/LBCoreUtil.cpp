#include "LBCoreUtil.h"

int LBCoreUtil::BlockID = 0;

int LBCoreUtil::findNextBlockID(int testId) {
	if(testId != 0)	
		return testId;
	while(Tile::tiles[LBCoreUtil::BlockID] != NULL) {
		LBCoreUtil::BlockID++;
	}
	return LBCoreUtil::BlockID;
}