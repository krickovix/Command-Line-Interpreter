#ifndef PROJEKAT_CONSOLESTREAM_H
#define PROJEKAT_CONSOLESTREAM_H

#include <iostream>

class ConsoleStream{
public:
    static std::string input();
    static void output(std::string message);

    static void raiseError(std::string message = "");
    static void raiseNoArgError();
    static void raiseUknownCommandError(std::string message = "");
    static void raiseWarning(std::string message = "");
};

#endif //PROJEKAT_CONSOLESTREAM_H
