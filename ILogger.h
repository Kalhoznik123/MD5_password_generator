#ifndef ILOGGER_H
#define ILOGGER_H
<<<<<<< HEAD

#include <string>

namespace logger{

=======
#include <string>

>>>>>>> f7c94147d7ed8535352b9889680bd485e9d2925d
class ILogger
{
public:
    ILogger() = default;
    virtual ~ILogger() = default;


    virtual void SendMessage(std::string message) = 0;

};

<<<<<<< HEAD
=======
#endif // ILOGGER_H
>>>>>>> f7c94147d7ed8535352b9889680bd485e9d2925d

class ConsoleLogger: public ILogger{
public:
    explicit ConsoleLogger(std::ostream& stream);
    ~ConsoleLogger() = default;
   void SendMessage(std::string message) override;
private:
   std::ostream& out_stream_;
};
<<<<<<< HEAD
}
#endif // ILOGGER_H
=======
>>>>>>> f7c94147d7ed8535352b9889680bd485e9d2925d
