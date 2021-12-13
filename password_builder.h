#pragma once

#include <string>
namespace password {


class PasswordBuilder{
public:
    explicit PasswordBuilder(size_t password_size);
    std::string GeneratePassword(std::string salt) const;
    void SetRandomStringLength(size_t size);
    size_t GetRandomStringLength() const ;
    size_t GetMD5HashSummLength() const;
private:
    size_t password_size_;
    size_t random_string_length_;
    const size_t MD5_HASH_SUMM_LENGTH = 32;
    std::string GenerateAndShuffle(std::string salt)const;



};
}
