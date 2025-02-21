#ifndef PROJEKAT_WCCOMMAND_H
#define PROJEKAT_WCCOMMAND_H

#include "AbstractCommands.h"

class WCCommand: public CommandWithArgsOpts{
public:
    explicit WCCommand(std::string cmdArgs = "", std::string cmdOpts = "");
    void run() override;

    static std::string name;
protected:
    long countWords();
    long countChars();
};

#endif //PROJEKAT_WCCOMMAND_H
