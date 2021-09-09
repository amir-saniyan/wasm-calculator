set(MODULE_NAME calculator)

set(EXPORT_NAME createCalculator)

set(MODULE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(MODULE_INCLUDE_DIR "${MODULE_DIR}/include")
set(MODULE_SOURCE_DIR "${MODULE_DIR}/src")

configure_file("${MODULE_SOURCE_DIR}/version.h.in" "version.h")

file(GLOB_RECURSE MODULE_HEADER_FILES "${MODULE_INCLUDE_DIR}/*.h")
file(GLOB_RECURSE MODULE_SOURCE_FILES "${MODULE_SOURCE_DIR}/*.cpp")

if(EMSCRIPTEN)
    add_executable(${MODULE_NAME} ${MODULE_SOURCE_FILES})

    target_link_options(${MODULE_NAME} PRIVATE --bind)

    target_compile_options(${MODULE_NAME} PRIVATE -fno-exceptions)
    target_link_options(${MODULE_NAME} PRIVATE -fno-exceptions)

    target_link_options(${MODULE_NAME} PRIVATE -sMODULARIZE)
    target_link_options(${MODULE_NAME} PRIVATE -sEXPORT_NAME=${EXPORT_NAME})

    if(NOT CMAKE_BUILD_TYPE STREQUAL "" AND NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_link_options(${MODULE_NAME} PRIVATE --closure=1)
    endif()
else()
    add_library(${MODULE_NAME} SHARED ${MODULE_SOURCE_FILES})
endif()

set_property(TARGET ${MODULE_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${MODULE_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${MODULE_NAME} PROPERTY CXX_EXTENSIONS OFF)

target_include_directories(${MODULE_NAME} PRIVATE "${MODULE_INCLUDE_DIR}")
target_include_directories(${MODULE_NAME} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")

add_custom_command(TARGET ${MODULE_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} ARGS -E copy "${MODULE_DIR}/*.htm" "${CMAKE_CURRENT_BINARY_DIR}")
