#pragma once
#include <string>
#include <stdexcept>
#include <optional>
#include "SimpleIni.h"
#include "password_builder.h"

namespace  config_reader{


namespace reader_exeption {
class ReaderExeprion:public std::runtime_error{
public:
    using std::runtime_error::runtime_error;
};
}


class FileConfigReader
{
public:
    FileConfigReader(std::string file);
    bool IsLoaded() const;
    std::optional<std::string> GetRandomStringLength() const;
    void SetOptions(password::PasswordBuilder& builder);
private:
    std::optional<std::string> GetValue(const std::string& section,const std::string& key)const;

    CSimpleIniA conf_reader_;
    SI_Error rc_;
};
}

