#ifndef PROJEKAT_TIMECOMMAND_H
#define PROJEKAT_TIMECOMMAND_H

#include "AbstractCommands.h"

class TimeCommand: public Command{
public:
    TimeCommand();
    void run() override;

    static std::string name;
};

#endif //PROJEKAT_TIMECOMMAND_H
