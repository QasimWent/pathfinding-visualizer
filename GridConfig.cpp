#include "GridConfig.h"

GridConfig* GridConfig::instance = nullptr;
int GridConfig::rows = 10;
int GridConfig::cols = 10;
Position GridConfig::start{0,0};
Position GridConfig::end{7,6};

GridConfig* GridConfig::get()
{
    if (instance == nullptr)
    {
        instance = new GridConfig();
    }
    return instance;
}

void GridConfig::setInfo(int rowNum, int colNum, Position startPos, Position endPos)
{
    rows = rowNum;
    cols = colNum;
    start = startPos;
    end = endPos;
}