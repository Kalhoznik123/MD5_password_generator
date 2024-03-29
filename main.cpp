#include "FileConfigReader.h"
#include "password_builder.h"
#include "test.h"
#include <iostream>
#include <string>

/*
 * Add documentation for methods
 */

/*и так подкидываем либу для создания конф файлов.
 *  1. создаем строку для считывания длины случайной последовательности
 *  2. не будет лишним заиметь метод для проверки длин на неотрецательное число
 *
  */

using namespace std;

int main(int argc, char *argv[]){
    using namespace std::literals;
#ifdef ENABLE_TEST
test::TestOpenFile();
test::TestReadRandomStringSize();
test::TestSetRandomStringSize();
#endif
    if(argc != 3){
        std::cout << "Incorrect number of characters entered, enter the password length and salt"s << std::endl;
        return 1;
    }
    int password_lengs = std::strtoll(argv[1],nullptr,10);

    if(!password_lengs){
        std::cout << "Password length must be a non-negative number and must not be equal to zero"s << std::endl;
        return 1;
    }

    password::PasswordBuilder pas_builder(password_lengs);

    config_reader::FileConfigReader conf_reader("config.ini"s);

    conf_reader.SetOptions(pas_builder);



    const std::string password  = pas_builder.GeneratePassword(argv[2]);


    if(password.length()){
        std::cout << password <<std::endl;
    }else{
        std::cout << "Password length is more than "<< pas_builder.GetRandomStringLength() + pas_builder.GetMD5HashSummLength() << " characters"s<<std::endl;
    }


    return 0;
}
