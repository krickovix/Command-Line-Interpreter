#include "AbstractCommands.h"

#include <utility>
#include "../InputOutput.h"

// Class Command

Command::Command(){
    outputStream = new OutputStream();
}

std::string Command::name;

void Command::run() {}

void Command::setVals(std::string cmdLine, OutputStream* defaultOutputStream) {
    setOutputStream(cmdLine, defaultOutputStream);
}

void Command::setOutputStream(std::string cmdLine, OutputStream* defaultOutputStream) {

    outputStream->setOutputType(readOutputType(cmdLine));

    if(outputStream->getOutputType() != OutputStream::CONSOLE){
        outputStream->setOutputFile(readOutputFile(cmdLine));
        return;
    }

    outputStream->setOutputType(defaultOutputStream->getOutputType());
    outputStream->setOutputFile(defaultOutputStream->getOutputFile());
}

int Command::readOutputType(std::string cmdLine) {
    int i = StringEditor::indexOfOutputRedirectionChar(cmdLine);

    if(i == cmdLine.size()) return OutputStream::CONSOLE;

    if(cmdLine[i+1] == '>') return OutputStream::FILE_ADD;

     return OutputStream::FILE_EMPTY;
}

std::string Command::readOutputFile(std::string cmdLine) {
    int i = StringEditor::indexOfFirstNotSpaceChar(cmdLine);
    while(cmdLine[i] == '>') i++;

    return cmdLine.substr(i, cmdLine.size()-i);
}


//Class CommandWithArguments

CommandWithArgs::CommandWithArgs(std::string cmdArg): args(std::move(cmdArg)) {}

void CommandWithArgs::run() {}

void CommandWithArgs::setVals(std::string cmdLine, OutputStream* defaultOutputStream){
    args = extractArgs(&cmdLine);
    setOutputStream(cmdLine, defaultOutputStream);
}

std::string CommandWithArgs::extractArgs(std::string* cmdLine) {

    int index = StringEditor::indexOfFirstNotSpaceChar(*cmdLine);
    *cmdLine = (*cmdLine).substr(index, (*cmdLine).size() - index);

    if(index == (*cmdLine).size())
        return ConsoleStream::input();

    index = StringEditor::indexOfOutputRedirectionChar(*cmdLine);

    std::string cmdArgs = (*cmdLine).substr(0, index);
    if(index < cmdLine->size()) *cmdLine = (*cmdLine).substr(index, (*cmdLine).size() - index);

    if(cmdArgs[0] == '"'){
        return StringEditor::inputQMarks(cmdArgs);
    }

    if(cmdArgs[0] == '<'){
        cmdArgs = cmdArgs.substr(1, cmdArgs.size() - 1);
        return FileStream::input(cmdArgs);
    }

    return FileStream::input(cmdArgs);
}


//Class CommandWithOptions

CommandWithOpts::CommandWithOpts(std::string cmdOpts): opts(std::move(cmdOpts)) {}

void CommandWithOpts::run() {}

void CommandWithOpts::setVals(std::string cmdLine, OutputStream* defaultOutputStream) {
    opts = extractOpts(&cmdLine);
    setOutputStream(cmdLine, defaultOutputStream);
}

std::string CommandWithOpts::extractOpts(std::string* cmdLine) {
    std::string cmdOpts;

    int index = StringEditor::indexOfFirstNotSpaceChar(*cmdLine);

    if((*cmdLine)[index] == '-'){
        index++;
        while(!isspace((*cmdLine)[index]) && (*cmdLine)[index] != '\0')
            cmdOpts.append(1, (*cmdLine)[index++]);
    }

    *cmdLine = (*cmdLine).substr(index, (*cmdLine).size()-index);

    return cmdOpts;
}


//Class CommandWithArgumentsAndOptions

CommandWithArgsOpts::CommandWithArgsOpts(std::string cmdArgs, std::string cmdOpts) :
    CommandWithArgs(std::move(cmdArgs)), CommandWithOpts(std::move(cmdOpts)) {}

void CommandWithArgsOpts::run() {}

void CommandWithArgsOpts::setVals(std::string cmdLine, OutputStream* defaultOutputStream){
    opts = extractOpts(&cmdLine);
    args = extractArgs(&cmdLine);
    setOutputStream(cmdLine, defaultOutputStream);
}