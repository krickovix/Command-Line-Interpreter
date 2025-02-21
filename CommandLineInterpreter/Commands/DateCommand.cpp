#include "DateCommand.h"
#include "../InputOutput.h"
#include <ctime>

#define MSG_SIZE 32

DateCommand::DateCommand() = default;

std::string DateCommand::name = "date";

void DateCommand::run() {
    time_t timestamp = time(nullptr);
    tm* time = localtime(&timestamp);

    char *message = new char[MSG_SIZE];
    sprintf(message, "The current date is: %02d-%02d-%d", time->tm_mday, 1+time->tm_mon, 1900+time->tm_year);

    outputStream->output(message);
}
