#pragma once
#include <string>

struct Dwarf : Character
{
    Dwarf(std::string name_, int hp, int armor_);

    ~Dwarf() override;
    const std::string& getName() override;
    std::string getStats() override;

private:
    const std::string name;
};
