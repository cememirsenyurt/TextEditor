// CursorDown.cpp

#include "CursorDown.hpp"
#include <iostream>

CursorDown::CursorDown()
{
}

void CursorDown::execute(EditorModel& model)
{
    model.EditorModel::moveCursorLineDown();
}   

void CursorDown::undo(EditorModel& model)
{
    model.EditorModel::moveCursorLineUp();
}

