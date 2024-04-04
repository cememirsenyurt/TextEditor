// CursorRight.hpp

#ifndef CURSORRIGHT_HPP
#define CURSORRIGHT_HPP

#include "Command.hpp"

class CursorRight : public Command
{
public:
    CursorRight();
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;     
};

#endif
