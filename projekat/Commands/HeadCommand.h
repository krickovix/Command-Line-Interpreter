#ifndef PROJEKAT_HEADCOMMAND_H
#define PROJEKAT_HEADCOMMAND_H

#include "AbstractCommands.h"

class HeadCommand: public CommandWithArgsOpts{
public:
    explicit HeadCommand(std::string cmdArgs = "", std::string cmdOpts = "");
    void run() override;

    static std::string name;
};

#endif //PROJEKAT_HEADCOMMAND_H
