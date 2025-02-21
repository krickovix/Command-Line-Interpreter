#ifndef PROJEKAT_COMMANDS_H
#define PROJEKAT_COMMANDS_H

#include <iostream>
#include "../IO/OutputStream.h"

//Class Command
class Command{
public:
    Command();
    virtual void run() = 0;
    virtual void setVals(std::string cmdLine, OutputStream* defaultOutputStream = nullptr);

    static std::string name;

protected:
    void setOutputStream(std::string cmdLine, OutputStream* defaultOutputStream);

    int readOutputType(std::string cmdLine);
    std::string readOutputFile(std::string cmdLine);

    OutputStream* outputStream;
};

//Class CommandWithArgs
class CommandWithArgs: virtual public Command{
public:
    explicit CommandWithArgs(std::string cmdArgs = "");
    void run() override = 0;
    void setVals(std::string cmdLine, OutputStream* defaultOutputStream = nullptr) override;

protected:

    virtual std::string extractArgs(std::string* cmdLine);
    std::string args;
};

//Class CommandWithOptions
class CommandWithOpts: virtual public Command{
public:
     explicit CommandWithOpts(std::string cmdOpts = "");
     void run() override = 0;

    void setVals(std::string cmdLine, OutputStream* defaultOutputStream = nullptr) override;

protected:

    virtual std::string extractOpts(std::string* cmdLine);
    std::string opts;
};

//Class CommandWithArgumentsAndOptions
class CommandWithArgsOpts: public CommandWithArgs, public CommandWithOpts{
public:
    explicit CommandWithArgsOpts(std::string cmdArgs, std::string cmdOpts);
    void run() override = 0;

    void setVals(std::string cmdLine, OutputStream* defaultOutputStream) override;
};

#endif //PROJEKAT_COMMANDS_H
