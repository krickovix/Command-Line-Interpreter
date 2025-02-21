#include "Terminal.h"
#include "Interpreter.h"
#include <string>

#define MAX 512

Terminal *Terminal::Instance() {
    static Terminal terminal;
    return &terminal;
}

[[noreturn]] void Terminal::run() {

    std::string cmdLine;
    auto* interpreter = new Interpreter();

    while(true){
        std::cout<<readySign;
        std::getline(std::cin, cmdLine);

        if(cmdLine.size() > MAX) cmdLine = cmdLine.substr(0, MAX);

        interpreter->interpret(cmdLine);
    }
}

void Terminal::setReadySign(std::string sign) {readySign = std::move(sign);}