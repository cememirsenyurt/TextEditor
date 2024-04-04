// InteractionProcessor.cpp
//
// ICS 45C Fall 2021
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"
#include "BooEditLog.hpp"

#include <stack>

// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

void InteractionProcessor::run()
{
    view.refresh();
    
    std::stack<Command*> undoStack;
    std::stack<Command*> redoStack;

    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {         
            while(!undoStack.empty())          
            {
                delete undoStack.top();
                undoStack.pop();
            }
            while(!redoStack.empty())
            {
                delete redoStack.top();
                redoStack.pop();
            }
            

            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            if(!undoStack.empty())
            {
                undoStack.top()->undo(model);

                redoStack.push(undoStack.top());
                undoStack.pop();
            }
            view.refresh();
        }
        else if (interaction.type() == InteractionType::redo)
        {
            if(!redoStack.empty())
            {
                Command* command = redoStack.top();
                redoStack.pop();
        
                try
                {
                    command->execute(model);
                    undoStack.push(command);
                }
                catch (EditorException& e)
                {
                    model.setErrorMessage(e.getReason());
                }
            }
            view.refresh();
        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command();

            try
            {
                command->execute(model);
                undoStack.push(command);
                model.clearErrorMessage();
            }
            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
            }

            view.refresh();
        }
    }
}

