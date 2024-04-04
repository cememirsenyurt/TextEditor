// CursorHome.hpp

#ifndef CURSORHOME_HPP
#define CURSORHOME_HPP

#include "Command.hpp"

class CursorHome : public Command
{
public:
    CursorHome();
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
};

#endif
