#include "FileConfigReader.h"
#include "password_builder.h"
#include <cassert>
#include <iostream>
/* пока длина пароля максиму 44 байта потому что 12 байтэто длина рандомно генерируемой строки
 * Add documentation for methods
 */

/*и так подкидываем либу для создания конф файлов.
 *  1. создаем строку для считывания длины случайной последовательности
 *  2. не будет лишним заиметь метод для проверки длин на неотрецательное число
 *
  */
namespace test {

void TestOpenFile(){
    using namespace std::literals;
    config_reader::FileConfigReader conf_reader("config.ini"s);
    assert(conf_reader.IsLoaded() == true);
    std::cout << "File is open"s << std::endl;
}

void TestReadRandomStringSize(){
    using namespace std::literals;
    config_reader::FileConfigReader conf_reader("config.ini"s);
    std::string res = conf_reader.GetRandomStringLength();
    assert(res == "20"s);
    std::cout << "Is ok"s <<std::endl;

}
}
using namespace std;

int main(int argc, char *argv[]){

test::TestOpenFile();

test::TestReadRandomStringSize();

    //    if(argc != 3){
//        std::cout << "Incorrect number of characters entered, enter the password length and salt"s << std::endl;
//        return 1;
//    }
//    int password_lengs = std::strtoll(argv[1],nullptr,10);
//    if(!password_lengs){
//        std::cout << "Password length must be a non-negative number and must not be equal to zero"s << std::endl;
//        return 1;
//    }

//    const password::PasswordBuilder pas_builder(password_lengs);

//    const std::string password  = pas_builder.GeneratePassword(argv[2]);


//    if(password.length()){
//        std::cout << password <<std::endl;
//    }else{
//        std::cout << "Password length is more than 44 characters"s<<std::endl;
//    }


    return 0;
}
