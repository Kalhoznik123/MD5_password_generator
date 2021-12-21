#include "ILogger.h"

<<<<<<< HEAD
namespace logger {
=======
>>>>>>> f7c94147d7ed8535352b9889680bd485e9d2925d


ConsoleLogger::ConsoleLogger(std::ostream &stream)
    :out_stream_(stream)
{}

void ConsoleLogger::SendMessage(std::string message){

    out_stream_ << message;

}
<<<<<<< HEAD
}
=======
>>>>>>> f7c94147d7ed8535352b9889680bd485e9d2925d
