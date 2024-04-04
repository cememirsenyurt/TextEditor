// CursorDown.hpp

#ifndef CURSORDOWN_HPP
#define CURSORDOWN_HPP

#include "Command.hpp"

class CursorDown : public Command
{
public:
    CursorDown();
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
};


#endif
