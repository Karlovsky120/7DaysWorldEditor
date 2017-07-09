#pragma once

#include <string>
#include <tuple>
#include <vector>

class BinaryMemoryReader;
class ItemStack;

class Recipe
{
public:
	int *count;
	std::string *craftingArea;
	int *craftingExpGain;
	float *craftingTime;
	std::string *craftingToolTypeName;
	std::vector<ItemStack *> ingredients;
	std::string *itemName;
	bool *materialBasedRecipe;
	std::vector<std::tuple<std::string *, int *> *> nameStackSizeList;
	unsigned char *recipeVersion;
	bool *scrapable;
	std::string *tooltip;
	bool *wildcardCampfireCategory;
	bool *wildcardForgeCategory;
	int *zero1;
	int *zero2;

	Recipe *read(BinaryMemoryReader *const reader);

	Recipe();
	~Recipe();
};

