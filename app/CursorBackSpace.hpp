// CursorBackSpace.hpp

#ifndef CURSORBACKSPACE_HPP
#define CURSORBACKSPACE_HPP

#include "Command.hpp"

class CursorBackSpace : public Command
{
public:
    CursorBackSpace();
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
};

#endif
