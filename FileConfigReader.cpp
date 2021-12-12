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

std::string FileConfigReader::GetRandomStringLength() const{
    using namespace std::literals;

    return GetValue("main"s,"random_string_length"s);
}

/**Get value */
std::string FileConfigReader::GetValue(const std::string& section, const std::string& key) const{
    std::string result = conf_reader_.GetValue(section.c_str(),key.c_str());  //add check if key is not set. If GetValue reurn nullptr

    return result;
}
}
