#include "TruncateCommand.h"
#include "../InputOutput.h"

TruncateCommand::TruncateCommand(std::string cmdArgs) : CommandWithArgs(std::move(cmdArgs)) {}

std::string TruncateCommand::name = "truncate";

void TruncateCommand::run() {

    if(args.empty()) return;

    FileStream::deleteContentOfFile(args);
}
