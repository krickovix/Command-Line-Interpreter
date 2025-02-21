#ifndef PROJEKAT_TOUCHCOMMAND_H
#define PROJEKAT_TOUCHCOMMAND_H

#include "AbstractCommands.h"

class TouchCommand: public CommandWithArgs{
public:
    explicit TouchCommand(std::string cmdArgs = "");
    void run() override;

    //std::string extractArgs(std::string* cmdLine) override;

    static std::string name;
};

#endif //PROJEKAT_TOUCHCOMMAND_H
