#include "HeadCommand.h"
#include "../IO/StringEditor.h"
#include <string>

HeadCommand::HeadCommand(std::string cmdArgs, std::string cmdOpts) :
        CommandWithArgsOpts(std::move(cmdArgs), std::move(cmdOpts)){}

std::string HeadCommand::name = "head";

void HeadCommand::run() {

    if(opts.empty()) return;

    int n = 0;
    if(opts[0] == 'n') n = std::stoi(opts.substr(1, opts.size()-1));

    outputStream->output(StringEditor::getLines(args, n) );
}