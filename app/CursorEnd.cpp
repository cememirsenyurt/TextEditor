// CursorEnd.cpp

#include "CursorEnd.hpp"
#include <iostream>

CursorEnd::CursorEnd()
{
}

void CursorEnd::execute(EditorModel& model)
{
    model.EditorModel::moveCursorEnd();
}

void CursorEnd::undo(EditorModel& model)
{
    std::cout << "HERE" << std::endl;
}

