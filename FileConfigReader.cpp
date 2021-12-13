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

std::optional<std::string> FileConfigReader::GetRandomStringLength() const{
    using namespace std::literals; //TODO: add a check that the variable is a number

    return GetValue("main"s,"random_string_length"s);
}

void FileConfigReader::SetOptions(password::PasswordBuilder &builder){

    auto result = GetRandomStringLength();
    if(result.has_value()){
        builder.SetRandomStringLength(std::stoi(*result));
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
