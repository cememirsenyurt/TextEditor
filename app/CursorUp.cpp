// CursorUp.cpp

#include "CursorUp.hpp"
#include <iostream>

CursorUp::CursorUp()
{
}

void CursorUp::execute(EditorModel& model)
{
    model.EditorModel::moveCursorLineUp();
}

void CursorUp::undo(EditorModel& model)
{
    std::cout << "here" << std::endl;   
}

