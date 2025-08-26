#include "colors.h"


const Color darkGrey = {26, 31, 40, 255};
const Color green = {47, 230, 23, 255};
const Color red = {232, 18, 18, 255};
const Color orange = {226, 116, 17, 255};
const Color yellow = {226, 226, 17, 255};
const Color purple = {163, 17, 226, 255};
const Color cyan = {17, 226, 226, 255};
const Color blue = {17, 66, 226, 255};

std::vector<Color> GetCellColors()
{
    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}