// CursorEnd.hpp

#ifndef CURSOREND_HPP
#define CURSOREND_HPP

#include "Command.hpp"

class CursorEnd : public Command
{
public:
    CursorEnd();
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
};

#endif
