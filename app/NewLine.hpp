// NewLine.hpp

#ifndef NEWLINE_HPP
#define NEWLINE_HPP

#include "Command.hpp"

class NewLine : public Command
{
public:
    NewLine();
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
};

#endif
