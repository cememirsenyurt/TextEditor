// DeleteLine.hpp

#ifndef DELETELINE_HPP
#define DELETELINE_HPP

#include "Command.hpp"

class DeleteLine : public Command
{
public:
    DeleteLine();
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
};

#endif
