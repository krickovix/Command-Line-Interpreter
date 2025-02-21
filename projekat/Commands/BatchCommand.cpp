#include "BatchCommand.h"
#include "../IO/StringEditor.h"
#include "../Interpreter.h"

BatchCommand::BatchCommand(std::string cmdArgs) : CommandWithArgs(std::move(cmdArgs)) {}

std::string BatchCommand::name = "batch";

void BatchCommand::run() {

    if(args.empty()) return;

    std::string line, lines = args;

    auto* newInterpreter = new Interpreter(outputStream->getOutputType(),
                                           outputStream->getOutputFile());

    while(true){
        line = StringEditor::extractLine(&lines);
        if(line[0] == EOF) return;

        newInterpreter->interpret(line);
    }
}
