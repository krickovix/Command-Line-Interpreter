#ifndef PROJEKAT_OUTPUTSTREAM_H
#define PROJEKAT_OUTPUTSTREAM_H

#include <iostream>

class OutputStream{
public:
    OutputStream(int outputType = CONSOLE, std::string outputFile = "");

    void output(std::string message);

    void setOutputType(int outputType);
    void setOutputFile(std::string outputFile);

    int getOutputType();
    std::string getOutputFile();

    enum TYPE{
        CONSOLE,
        FILE_EMPTY,
        FILE_ADD
    };

private:

    int type;
    std::string filename;
};

#endif //PROJEKAT_OUTPUTSTREAM_H
