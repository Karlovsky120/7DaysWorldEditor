#include "Recipe.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

int Recipe::read(BinaryMemoryReader &reader) {
	reader.read<unsigned char>(recipeVersion);
	CHECK_VERSION(recipeVersion, RECIPE);

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

	return 0;
}

void Recipe::write(BinaryMemoryWriter &writer) const {
	writer.write<unsigned char>(recipeVersion);

	writer.write<std::string>(itemName);
	writer.write<int>(count);
	writer.write<bool>(scrapable);
	writer.write<bool>(wildcardForgeCategory);
	writer.write<bool>(wildcardCampfireCategory);

	writer.write<std::string>(craftingToolTypeName);
	writer.write<float>(craftingTime);
	writer.write<std::string>(craftingArea);
	writer.write<std::string>(tooltip);

#pragma warning (suppress: 4267)
	writer.writeConst<int>(nameStackSizeList.size());

	for (unsigned int i = 0; i < nameStackSizeList.size(); ++i) {
		std::string name = std::get<0>(nameStackSizeList[i]);
		writer.write<std::string>(name);
		int stackSize = std::get<1>(nameStackSizeList[i]);
		writer.write<int>(stackSize);

		writer.write<int>(zero1);
		writer.write<int>(zero2);
	}

	writer.write<bool>(materialBasedRecipe);
	writer.write<int>(craftingExpGain);
}

Recipe::Recipe() {}
Recipe::~Recipe() {}