#ifndef PROJEKAT_FILESTREAM_H
#define PROJEKAT_FILESTREAM_H

#include <iostream>

class FileStream{
public:

    static std::string input(std::string filename);
    static void output(std::string filename, std::string message);

    static void createEmptyFile(std::string filename);
    static void createUnexistingFile(std::string filename);
    static void deleteContentOfFile(std::string filename);
    static void deleteFile(std::string filename);

    static bool fileExists(std::string filename);
    static bool isFileEmpty(std::string filename);
};

#endif //PROJEKAT_FILESTREAM_H
