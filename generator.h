#ifndef GENERATOR_H
#define GENERATOR_H
#include <string>
#include <random>
#include <set>

const size_t RANDOM_STRING_LENGTH = 12;

//bool IsForbiddenSymbol(char char_pos);

//generade random string whith forbiden symbols
std::string GenerateRandomString(size_t size);


#endif // GENERATOR_H
