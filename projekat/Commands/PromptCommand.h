#ifndef PROJEKAT_PROMPTCOMMAND_H
#define PROJEKAT_PROMPTCOMMAND_H

#include "AbstractCommands.h"

class PromptCommand: public CommandWithArgs{
public:
    PromptCommand(std::string cmdArgs = "");
    void run() override;

    static std::string name;
};

#endif //PROJEKAT_PROMPTCOMMAND_H
