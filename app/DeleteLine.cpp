// DeleteLine.cpp

#include "DeleteLine.hpp"
#include <iostream>

DeleteLine::DeleteLine()
{
}

void DeleteLine::execute(EditorModel& model)
{
    model.EditorModel::deleteLine();
}

void DeleteLine::undo(EditorModel& model)
{
    model.EditorModel::insertLine();
}



