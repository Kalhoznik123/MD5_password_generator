#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include <optional>
#include "SimpleIni.h"
#include "password_builder.h"

namespace  config_reader{

class FileConfigReader
{
public:
    FileConfigReader(std::string file);
    bool IsLoaded() const;
    std::optional<int> GetRandomStringLength() const;
    void SetOptions(password::PasswordBuilder& builder);
private:
    std::optional<std::string> GetValue(const std::string& section,const std::string& key)const;

    CSimpleIniA conf_reader_;
    SI_Error rc_;
};
}

