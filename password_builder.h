#pragma once

#include <string>
namespace password {


class PasswordBuilder
{
public:
   explicit PasswordBuilder(size_t password_size);
   std::string GeneratePassword(std::string salt) const;

private:
    size_t password_size_;

    std::string GenerateAndShuffle(std::string salt)const;


};
}
