#ifndef PROJEKAT_STRINGEDITOR_H
#define PROJEKAT_STRINGEDITOR_H

#include <iostream>

class StringEditor{
public:

    static std::string inputQMarks(std::string line);

    static int indexOfFirstNotSpaceChar(std::string line);
    static int indexOfOutputRedirectionChar(std::string line);

    static std::string getLines(std::string text, int num);
    static std::string extractLine(std::string *text);
};

#endif //PROJEKAT_STRINGEDITOR_H

inline std::string StringEditor::inputQMarks(std::string line) {

    std::string input;
    for(int i = 1; line[i] != '"'; i++) input.append(1, line[i]);

    return input;
}

inline int StringEditor::indexOfFirstNotSpaceChar(std::string line) {
    int i = 0;
    while(isspace(line[i]) && (line[i] != '\0')) i++;
    return i;
}

inline int StringEditor::indexOfOutputRedirectionChar(std::string line) {
    int i = 0;
    while((line[i] != '>') && (line[i] != '\0')) i++;
    return i;
}

inline std::string StringEditor::getLines(std::string text, int num = 1) {
    int curr = 0;
    std::string lines;

    for(int i = 0; text[i] != '\0' && curr < num; i++){

        lines.append(1, text[i]);
        if(text[i] == '\n') curr++;
    }

    return lines.substr(0, lines.size()-1);
}

inline std::string StringEditor::extractLine(std::string *text) {

    std::string line;

    if((*text).empty()) {
        line.append(1, EOF);
        return line;
    }

    int i = 0;
    while((*text)[i] != '\n' && (*text)[i] != '\0') line.append(1, (*text)[i++]);

    if((*text)[i] == '\n') i++;
    *text = (*text).substr(i, (*text).size()-i);

    return line;

}