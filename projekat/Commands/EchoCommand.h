#ifndef PROJEKAT_ECHOCOMMAND_H
#define PROJEKAT_ECHOCOMMAND_H

#include "AbstractCommands.h"

class EchoCommand: public CommandWithArgs{
public:
    explicit EchoCommand(std::string cmdArgs = "");

    void run() override;

    static std::string name;
};

#endif //PROJEKAT_ECHOCOMMAND_H
