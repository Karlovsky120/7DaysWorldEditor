#pragma once

#include <string>
#include <tuple>
#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class Recipe {
public:
    int count;
    std::string craftingArea;
    int craftingExpGain;
    float craftingTime;
    std::string craftingToolTypeName;
    std::string itemName;
    bool materialBasedRecipe;
    std::vector<std::tuple<std::string, int>> nameStackSizeList;
    unsigned char recipeVersion;
    bool scrapable;
    std::string tooltip;
    bool wildcardCampfireCategory;
    bool wildcardForgeCategory;
    int zero1;
    int zero2;

    Recipe();
    ~Recipe();

    int read(BinaryMemoryReader &reader);
    void write(BinaryMemoryWriter &writer) const;
};
