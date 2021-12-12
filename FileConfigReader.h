#pragma once
#include <string>
#include <stdexcept>
#include "SimpleIni.h"


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
    bool IsLoaded()const;
    std::string GetRandomStringLength()const;
private:
    std::string GetValue(const std::string& section,const std::string& key)const;

    CSimpleIniA conf_reader_;
    SI_Error rc_;
};
}

