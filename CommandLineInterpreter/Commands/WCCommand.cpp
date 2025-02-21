#include "WCCommand.h"
#include <string>

WCCommand::WCCommand(std::string cmdArgs, std::string cmdOpts) :
    CommandWithArgsOpts(std::move(cmdArgs), std::move(cmdOpts)){}

std::string WCCommand::name = "wc";

void WCCommand::run() {
    if(opts.empty()) return;

    long res = 0;
    if(opts == "w") res = countWords();
    if(opts == "c") res = countChars();

    if(args.empty()) res = 0;

    outputStream->output(std::to_string(res));
}

long WCCommand::countWords() {
    long res = 0;
    int i = 0;

    while(args[i] != '\0'){
        if(i && (isspace(args[i]) && !isspace(args[i-1]))) res++;
        i++;
    }

    if(!isspace(args[i-1])) res++;

    return res;
}

long WCCommand::countChars() {
    long i = 0;
    while(args[i] != '\0') i++;

    return i;
}