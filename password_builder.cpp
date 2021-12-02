#include <algorithm>
#include "password_builder.h"
#include "generator.h"
#include "md5.h"
namespace password {

PasswordBuilder::PasswordBuilder(size_t password_size)
    :password_size_(password_size)
{
}

std::string PasswordBuilder::GeneratePassword(std::string salt) const {

    std::string result = GenerateAndShuffle(std::move(salt));

    if(result.empty())
        return {};

    for(size_t i =0 ; i< 3; ++i){

        result = GenerateAndShuffle(std::move(result));

    }
    return result;


    //if(password_size_ > 44) // пока используем данный костыль так как максимальная длина сгенерированного пароля 44 байта
    //    return {};

    //const std::string random_str = GenerateRandomString(RANDOM_STRING_LENGTH);

//std::string result = random_str + md5(salt); // md5-hath equal 32 bit
//std::random_shuffle(result.begin(),result.end());

//return {result.begin(),result.begin() + password_size_};
}

std::string PasswordBuilder::GenerateAndShuffle(std::string salt) const{

if(password_size_ > 44) // пока используем данный костыль так как максимальная длина сгенерированного пароля 44 байта
    return {};

const std::string random_str = GenerateRandomString(RANDOM_STRING_LENGTH);

std::string result = random_str + md5(salt); // md5-hath equal 32 bit
std::random_shuffle(result.begin(),result.end());

return {result.begin(),result.begin() + password_size_};

}
}
