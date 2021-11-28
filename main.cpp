#include <iostream>
#include "password_builder.h"

/* пока длина пароля максиму 44 байта потому что 12 байтэто длина рандомно генерируемой строки
 */




using namespace std;

int main(int argc, char *argv[]){
    if(argc != 3){
        std::cout << "Incorrect number of characters entered, enter the password length and salt"s << std::endl;
        return 1;
    }
    int password_lengs = std::strtoll(argv[1],nullptr,10);
    if(!password_lengs){
        std::cout << "Password length must be a non-negative number and must not be equal to zero"s << std::endl;
        return 1;
    }

    const password::PasswordBuilder pas_builder(password_lengs);

    const std::string password  = pas_builder.GeneratePassword(argv[2]);


    if(password.length()){
        std::cout << password <<std::endl;
    }else{
        std::cout << "Password length is more than 44 characters"s<<std::endl;
    }


    return 0;
}
