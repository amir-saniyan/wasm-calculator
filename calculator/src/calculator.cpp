#include <string>

#include "version.h"
#include "calculator.h"

int Calculator::getMajorVersion()
{
    return CALCULATOR_VERSION_MAJOR;
}

int Calculator::getMinorVersion()
{
    return CALCULATOR_VERSION_MINOR;
}

int Calculator::getPatchVersion()
{
    return CALCULATOR_VERSION_PATCH;
}

std::string Calculator::getVersionString()
{
    return CALCULATOR_VERSION_STRING;
}

float Calculator::add(float a, float b)
{
    return a + b;
}

float Calculator::subtract(float a, float b)
{
    return a - b;
}

float Calculator::multiply(float a, float b)
{
    return a * b;
}

float Calculator::divide(float a, float b)
{
    return a / b;
}
