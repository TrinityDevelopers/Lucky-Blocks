#pragma once

#include "mcpe/world/item/recipes/Recipes.h"

#include <string>
#include <vector>

class LuckyCrafting {
public:
    static void initRecipes(Recipes*);

private:
    static Recipes* _Instance;
    static std::vector<Recipes::Type> _ingredients;
    
    static void pushIngredient(int, int, char);
    static void addRecipe(int, int, const std::vector<std::string>&);
};