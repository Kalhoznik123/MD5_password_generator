#ifndef ILOGGER_H
#define ILOGGER_H

#include <string>

namespace logger{

class ILogger
{
public:
    ILogger() = default;
    virtual ~ILogger() = default;


    virtual void SendMessage(std::string message) = 0;

};


class ConsoleLogger: public ILogger{
public:
    explicit ConsoleLogger(std::ostream& stream);
    ~ConsoleLogger() = default;
   void SendMessage(std::string message) override;
private:
   std::ostream& out_stream_;
};
}
#endif // ILOGGER_H
