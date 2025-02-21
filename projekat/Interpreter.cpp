#include "Interpreter.h"

#include "InputOutput.h"
#include "Commands/DateCommand.h"
#include "Commands/TimeCommand.h"
#include "Commands/EchoCommand.h"
#include "Commands/TouchCommand.h"
#include "Commands/WCCommand.h"
#include "Commands/PromptCommand.h"
#include "Commands/TruncateCommand.h"
#include "Commands/RmCommand.h"
#include "Commands/HeadCommand.h"
#include "Commands/BatchCommand.h"

Interpreter::Interpreter(int defaultOutputType, std::string defaultOutputFile) {
    defaultOutputStream = new OutputStream();

    setDefaultOutput(defaultOutputType, defaultOutputFile);
    setCommands();
}

void Interpreter::setCommands() {
    commands[EchoCommand::name] = new EchoCommand();
    commands[TouchCommand::name] = new TouchCommand();
    commands[TimeCommand::name] = new TimeCommand();
    commands[DateCommand::name] = new DateCommand();
    commands[WCCommand::name] = new WCCommand();
    commands[PromptCommand::name] = new PromptCommand();
    commands[TruncateCommand::name] = new TruncateCommand();
    commands[RmCommand::name] = new RmCommand();
    commands[HeadCommand::name] = new HeadCommand();
    commands[BatchCommand::name] = new BatchCommand();
}

void Interpreter::setDefaultOutput(int defaultOutputType, std::string defaultOutputFile) {

    defaultOutputStream->setOutputType(defaultOutputType);

    if(defaultOutputType == OutputStream::FILE_EMPTY){
        FileStream::createEmptyFile(defaultOutputFile);
        defaultOutputStream->setOutputType(OutputStream::FILE_ADD);
    }

    defaultOutputStream->setOutputFile(defaultOutputFile);
}

void Interpreter::interpret(std::string cmdLine) {

    std::string cmdName = extractName(&cmdLine);

    Command* cmd = commands[cmdName];
    if(!cmd){
        ConsoleStream::raiseUknownCommandError(cmdName);
        return;
    }

    cmd->setVals(cmdLine, defaultOutputStream);
    cmd->run();
}

std::string Interpreter::extractName(std::string *cmdLine) {
    std::string cmdName;

    int i = StringEditor::indexOfFirstNotSpaceChar(*cmdLine);
    while(!isspace((*cmdLine)[i]) && (*cmdLine)[i] != '\0') cmdName.append(1, (*cmdLine)[i++]);

    *cmdLine = (*cmdLine).substr(i, (*cmdLine).size()-i);

    return cmdName;
}
