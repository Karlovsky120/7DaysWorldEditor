#include "Recipe.h"

#include "BinaryMemoryReader.h"

void Recipe::read(BinaryMemoryReader &reader) {
	reader.read<unsigned char>(recipeVersion);

	reader.read<std::string>(itemName);
	reader.read<int>(count);
	reader.read<bool>(scrapable);
	reader.read<bool>(wildcardForgeCategory);
	reader.read<bool>(wildcardCampfireCategory);

	reader.read<std::string>(craftingToolTypeName);
	reader.read<float>(craftingTime);
	reader.read<std::string>(craftingArea);
	reader.read<std::string>(tooltip);

	int ingredientCount;
	reader.read<int>(ingredientCount);

	for (int i = 0; i < ingredientCount; ++i) {
		std::string name;
		reader.read<std::string>(name);
		int stackSize;
		reader.read<int>(stackSize);

		reader.read<int>(zero1);
		reader.read<int>(zero2);

		nameStackSizeList.push_back(std::tuple<std::string, int>(name, stackSize));
	}

	reader.read<bool>(materialBasedRecipe);
	reader.read<int>(craftingExpGain);
}

Recipe::Recipe() {}
Recipe::~Recipe() {}