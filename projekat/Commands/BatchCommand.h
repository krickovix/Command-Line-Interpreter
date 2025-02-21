#ifndef PROJEKAT_BATCHCOMMAND_H
#define PROJEKAT_BATCHCOMMAND_H

#include "AbstractCommands.h"

class BatchCommand: public CommandWithArgs{
public:
    explicit BatchCommand(std::string cmdArgs = "");
    void run() override;

    static std::string name;
};

#endif //PROJEKAT_BATCHCOMMAND_H
