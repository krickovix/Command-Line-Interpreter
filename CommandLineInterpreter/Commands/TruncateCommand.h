#ifndef PROJEKAT_TRUNCATECOMMAND_H
#define PROJEKAT_TRUNCATECOMMAND_H

#include "AbstractCommands.h"

class TruncateCommand: public CommandWithArgs{
public:
    explicit TruncateCommand(std::string cmdArgs = "");
    void run() override;

    static std::string name;
};

#endif //PROJEKAT_TRUNCATECOMMAND_H
