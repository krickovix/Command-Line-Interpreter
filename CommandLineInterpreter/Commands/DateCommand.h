#ifndef PROJEKAT_DATECOMMAND_H
#define PROJEKAT_DATECOMMAND_H

#include "AbstractCommands.h"

class DateCommand: public Command{
public:
    DateCommand();
    void run() override;

    static std::string name;
};

#endif //PROJEKAT_DATECOMMAND_H
