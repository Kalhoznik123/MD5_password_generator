#include "ILogger.h"



ConsoleLogger::ConsoleLogger(std::ostream &stream)
    :out_stream_(stream)
{}

void ConsoleLogger::SendMessage(std::string message){

    out_stream_ << message;

}
