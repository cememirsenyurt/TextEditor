// EditLine.cpp

#include "EditLine.hpp"
#include <string>
#include <iostream>

EditLine::EditLine(char x)
    : x{x}
{
}


void EditLine::execute(EditorModel& model)
{       
    model.EditorModel::editLine(x);
}

void EditLine::undo(EditorModel& model)
{
    //model.EditorModel::reverseEditLine();
    model.EditorModel::reverseEditLine();
}


