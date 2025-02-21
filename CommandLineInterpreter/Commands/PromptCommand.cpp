#include "PromptCommand.h"
#include "../Terminal.h"

PromptCommand::PromptCommand(std::string cmdArgs) : CommandWithArgs(std::move(cmdArgs)) {}

std::string PromptCommand::name = "prompt";

void PromptCommand::run() {

    if(args.empty()) return;

    Terminal::Instance()->setReadySign(args);
}
