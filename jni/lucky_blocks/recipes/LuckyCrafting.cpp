#include "LuckyCrafting.h"

#include "lucky_blocks/LuckyBlocks.h"

#include "mcpe/world/item/ItemInstance.h"
#include "mcpe/world/item/Item.h"
#include "mcpe/world/level/block/Block.h"

Recipes* LuckyCrafting::_Instance;
std::vector<Recipes::Type> LuckyCrafting::_ingredients;

void LuckyCrafting::initRecipes(Recipes* instance) {
	_Instance = instance;
	
		pushIngredient(41, 0, 'g');
		pushIngredient(158, 0, 'd');
	addRecipe(LuckyBlocks::luckyBlock->blockId, 1, {"ggg", "gdg", "ggg"});
	
		pushIngredient(4, 0, 's');
		pushIngredient(331, 0, 'r');
	addRecipe(158, 1, {"sss", "s s", "srs"});
}

void LuckyCrafting::pushIngredient(int id, int data, char letter) {
	Recipes::Type type {Item::mItems[id], NULL, ItemInstance(), letter};
	_ingredients.push_back(type);
}

void LuckyCrafting::addRecipe(int outputId, int outputCount, const std::vector<std::string>& shape) {
	ItemInstance output(outputId, outputCount, 0);
	_Instance->addShapedRecipe(output, shape, _ingredients);
	_ingredients.clear();
}
