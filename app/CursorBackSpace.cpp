// CursorBackSpace.cpp

#include "CursorBackSpace.hpp"
#include <iostream>

CursorBackSpace::CursorBackSpace()
{
}

void CursorBackSpace::execute(EditorModel& model)
{
    model.EditorModel::moveCursorBackSpace();
}

void CursorBackSpace::undo(EditorModel& model)
{
    std::cout << "HERE";
}

