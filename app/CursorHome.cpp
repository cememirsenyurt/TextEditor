// CursorHome.cpp

#include "CursorHome.hpp"
#include <iostream>

CursorHome::CursorHome()
{
}

void CursorHome::execute(EditorModel& model)
{
    model.EditorModel::takeCursorHome();
}


void CursorHome::undo(EditorModel& model)
{
    std::cout << "HERE" << std::endl;
}

