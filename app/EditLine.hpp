// EditLine.hpp

#ifndef EDITLINE_HPP
#define EDITLINE_HPP

#include <string>
#include <vector>
#include "Command.hpp"

class EditLine : public Command
{
public:
    EditLine(char x);
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;  
private:
    char x;
};

#endif
