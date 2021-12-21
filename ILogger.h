#ifndef ILOGGER_H
#define ILOGGER_H
#include <string>

class ILogger
{
public:
    ILogger() = default;
    virtual ~ILogger() = default;


    virtual void SendMessage(std::string message) = 0;

};

#endif // ILOGGER_H

class ConsoleLogger: public ILogger{
public:
    explicit ConsoleLogger(std::ostream& stream);
    ~ConsoleLogger() = default;
   void SendMessage(std::string message) override;
private:
   std::ostream& out_stream_;
};
