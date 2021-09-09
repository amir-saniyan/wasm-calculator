#pragma once

#include <string>

class Calculator
{
public:

    static int getMajorVersion();

    static int getMinorVersion();

    static int getPatchVersion();

    static std::string getVersionString();

    static float add(float a, float b);

    static float subtract(float a, float b);

    static float multiply(float a, float b);

    static float divide(float a, float b);
};
