// CursorRight.cpp

#include "CursorRight.hpp"
#include <iostream>

CursorRight::CursorRight()
{
}

void CursorRight::execute(EditorModel& model)
{
    model.EditorModel::moveCursorColumnRight();
}

void CursorRight::undo(EditorModel& model)
{
    model.EditorModel::moveCursorColumnLeft();
}


