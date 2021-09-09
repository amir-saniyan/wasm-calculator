#if defined(__EMSCRIPTEN__)

#include <emscripten/bind.h>

#include "calculator.h"

EMSCRIPTEN_BINDINGS(Calculator)
{
    emscripten::function("getMajorVersion", &Calculator::getMajorVersion);
    
    emscripten::function("getMinorVersion", &Calculator::getMinorVersion);
    
    emscripten::function("getPatchVersion", &Calculator::getPatchVersion);
    
    emscripten::function("getVersionString", &Calculator::getVersionString);

    emscripten::function("add", &Calculator::add);
    
    emscripten::function("subtract", &Calculator::subtract);
    
    emscripten::function("multiply", &Calculator::multiply);
    
    emscripten::function("divide", &Calculator::divide);
}

#endif
