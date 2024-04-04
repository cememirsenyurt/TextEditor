// NewLine.cpp

#include "NewLine.hpp"
#include <iostream>

NewLine::NewLine()
{
}

void NewLine::execute(EditorModel& model)
{
    model.EditorModel::cursorNewLine();
}

void NewLine::undo(EditorModel& model)
{
    model.EditorModel::deleteLine();
}

    
