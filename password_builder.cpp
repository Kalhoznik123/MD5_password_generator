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
}

void PasswordBuilder::SetRandomStringLength(size_t size){
    random_string_length_ = size;
}

size_t PasswordBuilder::GetRandomStringLength() const{
    return random_string_length_;
}

size_t PasswordBuilder::GetMD5HashSummLength() const{
    return  MD5_HASH_SUMM_LENGTH;
}

std::string PasswordBuilder::GenerateAndShuffle(std::string salt) const{

if(password_size_ > random_string_length_ + MD5_HASH_SUMM_LENGTH)
    return {};

const std::string random_str = GenerateRandomString(random_string_length_);

std::string result = random_str + md5(salt); // md5-hash equal 32 bit
std::random_shuffle(result.begin(),result.end());

return {result.begin(),result.begin() + password_size_};
}
}
