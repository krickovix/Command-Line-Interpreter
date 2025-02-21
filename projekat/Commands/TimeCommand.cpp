#include "TimeCommand.h"
#include "../InputOutput.h"
#include <ctime>

#define MSG_SIZE 30

TimeCommand::TimeCommand() = default;

std::string TimeCommand::name = "time";

void TimeCommand::run() {
    time_t timestamp = time(nullptr);
    tm* time = localtime(&timestamp);

    char *message = new char[MSG_SIZE];
    sprintf(message, "The current time is: %02d:%02d:%02d", time->tm_hour, time->tm_min, time->tm_sec);

    outputStream->output(message);
}
