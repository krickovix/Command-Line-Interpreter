#include "OutputStream.h"
#include "../InputOutput.h"

OutputStream::OutputStream(int outputType, std::string outputFile):
    type(outputType), filename(outputFile) {}

void OutputStream::output(std::string message) {

    if(type == CONSOLE){
        ConsoleStream::output(message);
        return;
    }

    if(type == FILE_EMPTY)
        FileStream::createEmptyFile(filename);

    FileStream::output(filename, message);
}

void OutputStream::setOutputType(int outputType) {
    type = outputType;
}

void OutputStream::setOutputFile(std::string outputFile) {
    filename = outputFile;
}

int OutputStream::getOutputType() {return type;}

std::string OutputStream::getOutputFile() {return filename;}