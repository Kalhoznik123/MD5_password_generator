#include "generator.h"

bool IsForbiddenSymbol(char char_pos){
    static const std::set<char> forbiden_char{'"','\'','(',')',',',':',';',' ','[',']','<','>'};
    bool result = false;
    if (forbiden_char.count(char_pos))
        result = true;
    return result;
}

std::string GenerateRandomString(size_t size) {

    std::string random_str(size, 0);
    static std::random_device rd;
    std::mt19937 engine(rd());

    for (char& c : random_str) {
        do{
            c = static_cast<char>(std::uniform_int_distribution<int>('!', 'z')(engine));
        }while(IsForbiddenSymbol(c));
    }

    return random_str;
}
