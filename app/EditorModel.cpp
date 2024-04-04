// EditorModel.cpp
//
// ICS 45C Fall 2021
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "BooEditLog.hpp"

unsigned int EditorModel::enterLn = 1;

EditorModel::EditorModel() 
{
    //error = " ";
    error = "";
    input.push_back("");
    ln = 1;
    col = 1;
}

int EditorModel::cursorLine() const
{
    return ln;
}


int EditorModel::cursorColumn() const
{
    return col;
}


int EditorModel::lineCount() const
{
    enterLn = input.size();
    return enterLn;
}


const std::string& EditorModel::line(int lineNumber) const
{
    //booEditLog(input.at(lineNumber-1));
    if(lineNumber == 0)
    {
        return input.at(lineNumber);
    }
    else
    {
        return input.at(lineNumber-1);
    }
}

const std::string& EditorModel::currentErrorMessage() const
{
    return error;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
    error = errorMessage;
}


void EditorModel::clearErrorMessage()
{
    error.clear();
}

void EditorModel::moveCursorColumnRight()
{
    if(col >= input.at(cursorLine()-1).length() && ln == lineCount())
    {
        throw (EditorException("Already at the end"));
    }
    else if(ln < lineCount() && col == input.at(cursorLine()-1).length())
    {
        ln++;
        col = 1;
    }
    else
    {
        col++;
    }
}

void EditorModel::moveCursorColumnLeft()
{
    if(col == 1 && ln == 1)
    {
        throw (EditorException("Already at the beggining"));
    }
    else if(ln > 1 && col == 1)
    {
        ln--;
        col = input.at(cursorLine()-1).length();
    }
    else
    {
        col--;
    }
}

void EditorModel::moveCursorLineDown()
{
    if(ln < lineCount())
    {
        if(input.at(cursorLine() - 1).length() > input.at(cursorLine()).length())
        {
            ln++;
            col = input.at(cursorLine()).length();
        }
        else if(input.at(cursorLine() - 1).length() < input.at(cursorLine()).length())
        {
            ln++;
            col = cursorColumn();
        }
        else if(input.at(cursorLine() - 1).length() == input.at(cursorLine()).length())
        {
            ln++;
        }
        else if(input.at(cursorLine()) == "")
        {
            ln++;
            col = 1;
        }
    }
    else
    {
        throw (EditorException("Already at the bottom"));
    }
}

void EditorModel::moveCursorLineUp()
{
    if(ln == 1)
    {
        throw(EditorException("Already at the top"));
    }
    else if(input.at(cursorLine()-1).length() > input.at(cursorLine()-2).length())
    {
        ln--;
        col = input.at(cursorLine()-1).length();
    }
    else if(input.at(cursorLine()).length() < input.at(cursorLine()-1).length())
    {
        ln--;
        col = cursorColumn();
    }
    else
    {
        ln--;
    }
    
}

void EditorModel::takeCursorHome()
{
   col = 1; 
}

void EditorModel::moveCursorEnd()
{
    col = input.at(cursorLine() - 1).length();
}

void EditorModel::moveCursorBackSpace()
{
    if(ln > 1 && ln <= lineCount())
    {
        if(col != 1)
        {
            col--;
            input.at(cursorLine() - 1).erase(input.at(cursorLine() - 1).begin() + col-1);
        }
        else
        {
            input.at(cursorLine() - 1).erase(input.at(cursorLine() - 1).begin() + col-1);
            ln--;
            input.erase(input.begin()+ lineCount()-1);
            col = input.at(cursorLine() - 1). length() + 1;
        }  
    }
    else if(ln == 1)
    {
        if(col != 1)
        {
            col--;
            input.at(cursorLine() - 1).erase(input.at(cursorLine() - 1).begin() + col-1);
        }
        else
        {
            input.at(cursorLine() - 1).erase(input.at(cursorLine() - 1).begin() + col-1);
            throw (EditorException("Already the beginning"));
        }
    }
  
}

void EditorModel::editLine(char x)
{
    std::string s;

    s.push_back(x);
    input[ln - 1].insert(col - 1, s); 
    col++;
}

void EditorModel::reverseEditLine()
{
    if(input[ln-1].length() != 0)
    {
        col--;
        input.at(cursorLine() - 1).erase(input.at(cursorLine() - 1).begin() + col - 1);
        //col--;
    }
}

void EditorModel::cursorNewLine()
{
    //char x = '\n';
    //std::string s;

    //s.push_back(x);
    
    //input.insert(input.begin()+ln, s);
    
    enterLn++;
    input.resize(enterLn);

    ln++;
    col=1;
}

void EditorModel::deleteLine()
{
    if(ln == 1)
    {
        input.at(ln-1).erase();
        enterLn--;
        col=1;
    }
    else
    {
        input.at(ln-1).erase();
        ln--;
        enterLn--;
        col = 1;
    }
}
