#include "GridConfig.h"

GridConfig* GridConfig::instance = nullptr;
int GridConfig::rows = 10;
int GridConfig::cols = 10;
Position GridConfig::start;
Position GridConfig::end;

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