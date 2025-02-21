#include "EchoCommand.h"
#include "../InputOutput.h"

EchoCommand::EchoCommand(std::string cmdArgs) : CommandWithArgs(std::move(cmdArgs)) {}

std::string EchoCommand::name = "echo";

void EchoCommand::run() {

    if(args.empty()) return;

    outputStream->output(args );
}
