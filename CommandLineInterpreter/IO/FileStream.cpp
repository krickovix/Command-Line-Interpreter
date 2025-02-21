#include "../InputOutput.h"
#include <fstream>

std::string FileStream::input(std::string filename) {

    std::fstream file (filename.c_str());

    if(!file.is_open()){
        ConsoleStream::raiseError("File does not exist.");
        return "";
    }

    std::string res;
    char c;
    while((c = file.get()) != EOF) res.append(1, c);

    file.close();

    if(res.empty()) ConsoleStream::raiseWarning("File empty.");

    return res;
}

void FileStream::output(std::string filename, std::string message) {

    std::fstream file (filename, std::ios::app);

    if(!file){
        ConsoleStream::raiseError("Could not open file.");
        return;
    }

    if(!isFileEmpty(filename)) file<<std::endl;

    file<<message;
    file.close();
}

void FileStream::createEmptyFile(std::string filename) {
    std::fstream file (filename.c_str(), std::ios::out);
    if(!file.is_open()){
        ConsoleStream::raiseError("Could not create file.");
        return;
    }

    file<<"";
    file.close();
}

void FileStream::createUnexistingFile(std::string filename) {
    if(fileExists(filename)){
        ConsoleStream::raiseError("File already exists.");
        return;
    }

    createEmptyFile(filename);

    std::cout<<"File "<<filename<<" created.\n";
}

void FileStream::deleteContentOfFile(std::string filename) {
    if(!fileExists(filename)){
        ConsoleStream::raiseError("File does not exist.");
        return;
    }

    createEmptyFile(filename);

    std::cout<<"Deleted contents of "<<filename<<".\n";
}

void FileStream::deleteFile(std::string filename) {
    if(!fileExists(filename)){
        ConsoleStream::raiseError("File does not exist.");
        return;
    }

    remove(filename.c_str());

    std::cout<<"Deleted file "<<filename<<".\n";
}

bool FileStream::fileExists(std::string filename) {
    std::fstream file (filename.c_str());

    if(!file.is_open()) return false;

    file.close();
    return true;
}

bool FileStream::isFileEmpty(std::string filename) {
    std::fstream file (filename.c_str());

    if(!file){
        ConsoleStream::raiseError("Could not open file.");
        return true;
    }

    bool fileEmpty = false;
    if(file.get() == EOF) fileEmpty = true;

    file.close();
    return fileEmpty;
}