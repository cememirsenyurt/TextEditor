// NewLine.cpp

#include "NewLine.hpp"

Newline::NewLine()
{
}

void NewLine::execute(EditorModel& model)
{
    model.EditorModel::cursorNewLine();
}

/*
void NewLine::undo(EditorModel& model)
{
    
}
*/

