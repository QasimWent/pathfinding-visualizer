#ifndef GRIDCONFIG_H
#define GRIDCONFIG_H

#include <cstddef>
#include "Position.h"

class GridConfig 
{
public: 
    static GridConfig* get();
    static int getRows() { return rows;}
    static int getCols() { return cols; }
    static Position getStartPosition() { return start; };
    static Position getEndPosition() { return end; }
    static void setInfo(int rowNum, int colNum, Position startPos, Position endPos);

private:
    static GridConfig* instance;
    static int rows;
    static int cols;
    static Position start;
    static Position end;
    
    GridConfig(){};
};

#endif 