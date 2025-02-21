#include "ConsoleStream.h"

std::string ConsoleStream::input(){
    std::string res;
    char c;

    while((c = getchar()) != EOF) res.append(1, c);

    if(res[res.size()-1] == '\n') res.erase(res.size()-1);

    return res;
}

void ConsoleStream::output(std::string message) {
    std::cout<<message<<std::endl;
}

void ConsoleStream::raiseError(std::string message) {
    std::cout<<"Error: "<<message<<std::endl;
}

void ConsoleStream::raiseNoArgError() {
    raiseError("No arguments given.");
}

void ConsoleStream::raiseUknownCommandError(std::string message) {
    std::cout<<"Uknown command: command "<<message<<std::endl;
}

void ConsoleStream::raiseWarning(std::string message) {
    std::cout<<"Warning: "<<message<<std::endl;
}