#include "RmCommand.h"
#include "../InputOutput.h"

RmCommand::RmCommand(std::string cmdArgs): CommandWithArgs(std::move(cmdArgs)) {}

std::string RmCommand::name = "rm";

void RmCommand::run() {

    if(args.empty()) return;

    FileStream::deleteFile(args);
}
