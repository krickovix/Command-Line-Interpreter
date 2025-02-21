#ifndef PROJEKAT_CLI_H
#define PROJEKAT_CLI_H

#include <iostream>
#include <map>
#include "Commands/AbstractCommands.h"

class Interpreter{
public:
    explicit Interpreter(int defaultOutputType = 0, std::string defaultOutputFile = "");

    void interpret(std::string cmdLine);

protected:
    static std::string extractName(std::string *cmdLine);

    void setDefaultOutput(int defaultOutputType, std::string defaultOutputFile);
    void setCommands();

    std::map<std::string, Command*> commands;

private:
    OutputStream* defaultOutputStream;
};

#endif
