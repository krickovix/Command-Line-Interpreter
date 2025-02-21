#include "TouchCommand.h"
#include "../InputOutput.h"

TouchCommand::TouchCommand(std::string cmdArgs) : CommandWithArgs(std::move(cmdArgs)) {}

std::string TouchCommand::name = "touch";

void TouchCommand::run() {

    if(args.empty()) return;

    FileStream::createUnexistingFile(args);
}

/*std::string TouchCommand::extractArgs(std::string *cmdLine) {
    std::string cmdArgs;

    int index = StringEditor::indexOfFirstNotSpaceChar(cmdLine);
    cmdLine = cmdLine.substr(index, cmdLine.size() - index);

    if(index == cmdLine.size())
        return ConsoleStream::input();

    if(cmdLine[0] == '"')
        return StringEditor::inputQMarks(cmdLine);

    if(cmdLine[0] == '>'){
        cmdLine = cmdLine.substr(1, cmdLine.size() - 1);
        return FileStream::input(cmdLine);
    }

    return cmdLine;
}*/