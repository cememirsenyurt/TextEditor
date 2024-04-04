// CursorLeft.cpp

#include <iostream>
#include "CursorLeft.hpp"

CursorLeft::CursorLeft()
{
}

void CursorLeft::execute(EditorModel& model)
{
    model.EditorModel::moveCursorColumnLeft();
}

void CursorLeft::undo(EditorModel& model)
{
    model.EditorModel::moveCursorColumnRight();
}


