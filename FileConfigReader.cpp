#include "FileConfigReader.h"

namespace  config_reader{
FileConfigReader::FileConfigReader(std::string file)
{
    conf_reader_.SetUnicode();
    rc_ =  conf_reader_.LoadFile(std::move(file).c_str());
}

bool FileConfigReader::IsLoaded() const{
    return !(rc_ < 0);
}

std::optional<int> FileConfigReader::GetRandomStringLength() const{
    using namespace std::literals;
    const auto result = GetValue("main"s,"random_string_length"s);
    int value = 0;
    try {
        if(result.has_value())
            value = std::stoi(*result);
    }  catch (std::exception& ex) {
        std::cout << "ERROR: invalid random_string_length value"<<std::endl; //TODO: add noraml loggin
        std::abort();
    }

    return value;
}

void FileConfigReader::SetOptions(password::PasswordBuilder &builder){

    const auto result = GetRandomStringLength();

    if(*result > 0) {
        builder.SetRandomStringLength(*result);
    }else{
        builder.SetRandomStringLength(0);
    }

}

/**Get value */
std::optional<std::string> FileConfigReader::GetValue(const std::string& section, const std::string& key) const{
    std::optional<std::string> result;

    const char* value = conf_reader_.GetValue(section.c_str(),key.c_str());

    if(value != nullptr){
        result = value;
    }

    return result;
}
}
