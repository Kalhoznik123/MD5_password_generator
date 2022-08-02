#pragma once
#include "FileConfigReader.h"
#include <cassert>



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
    int res = *conf_reader.GetRandomStringLength();
    assert(res == 20);
    std::cout << "TestReadRandomStringSize is OK"s <<std::endl;

}

void TestSetRandomStringSize(){
    using namespace std::literals;
    config_reader::FileConfigReader conf_reader("config.ini"s);
    password::PasswordBuilder builder(30);
    conf_reader.SetOptions(builder);
    assert(builder.GetRandomStringLength() == 20);
    std::cout << "TestSetRandomStringSize is OK"s <<std::endl;
}
}
