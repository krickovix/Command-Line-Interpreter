cmake_minimum_required(VERSION 3.27)
project(projekat)

set(CMAKE_CXX_STANDARD 17)

add_executable(projekat main.cpp
        Interpreter.h
        Interpreter.cpp
        Terminal.h
        Terminal.cpp
        Interpreter.cpp
        Commands/EchoCommand.h
        Commands/EchoCommand.cpp
        Commands/DateCommand.h
        Commands/DateCommand.cpp
        Commands/TimeCommand.h
        Commands/TimeCommand.cpp
        Commands/AbstractCommands.cpp
        InputOutput.h
        Commands/TouchCommand.h
        Commands/TouchCommand.cpp
        Commands/WCCommand.h
        Commands/WCCommand.cpp
        Commands/PromptCommand.h
        Commands/PromptCommand.cpp
        Commands/TruncateCommand.cpp
        Commands/TruncateCommand.h
        Commands/RmCommand.cpp
        Commands/RmCommand.h
        IO/ConsoleStream.h
        IO/ConsoleStream.cpp
        IO/FileStream.cpp
        IO/StringEditor.h
        IO/FileStream.h
        Commands/HeadCommand.h
        Commands/HeadCommand.cpp
        Commands/BatchCommand.h
        Commands/BatchCommand.cpp
        IO/OutputStream.h
        IO/OutputStream.cpp
)
