#ifndef CELL_H
#define CELL_H

#include <memory>
#include "Jump.h"

class Cell {
public:
    std::shared_ptr<Jump> jump;

    Cell() : jump(nullptr) {}
};

#endif
