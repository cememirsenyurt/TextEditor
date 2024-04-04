// KeypressInteractionReader.cpp
//
// ICS 45C Fall 2021
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE
#include <iostream>
#include <string>
#include <vector>
#include "KeypressInteractionReader.hpp"
#include "CursorRight.hpp"
#include "CursorLeft.hpp"
#include "EditorModel.hpp"
#include "CursorDown.hpp"
#include "CursorUp.hpp"
#include "CursorHome.hpp"
#include "CursorEnd.hpp"
#include "CursorBackSpace.hpp"
#include "EditLine.hpp"
#include "NewLine.hpp"
#include "DeleteLine.hpp"

// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

std::vector<std::string> s;

Interaction KeypressInteractionReader::nextInteraction()
{
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly
            // UNDO REDO COMMAND QUIT

            switch (keypress.code())
            {
            case 'X':
                return Interaction::quit();
            case 'O':
                return Interaction::command(new CursorRight);
            case 'U':
                return Interaction::command(new CursorLeft);
            case 'K':
                return Interaction::command(new CursorDown);
            case 'I':
                return Interaction::command(new CursorUp);
            case 'Y':
                return Interaction::command(new CursorHome);
            case 'P':
                return Interaction::command(new CursorEnd);
            case 'H':
                return Interaction::command(new CursorBackSpace);
            case 'J':
            case 'M':
                return Interaction::command(new NewLine);
            case 'D':
                return Interaction::command(new DeleteLine);
            case 'Z':
                return Interaction::undo();
            case 'A':
                return Interaction::redo();
            }
        }
        else
        {
            char x = keypress.code();
            return Interaction::command(new EditLine(x));    
        }
    }
}
