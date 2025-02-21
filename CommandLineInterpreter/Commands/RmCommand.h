#ifndef PROJEKAT_RMCOMMAND_H
#define PROJEKAT_RMCOMMAND_H

#include "AbstractCommands.h"

class RmCommand: public CommandWithArgs{
public:
    RmCommand(std::string cmdArgs = "");
    void run() override;

    static std::string name;
};

#endif //PROJEKAT_RMCOMMAND_H
