cmake_minimum_required(VERSION 3.30)
project(VariableInitialization)

set(CMAKE_CXX_STANDARD 20)

# Add to treat compiler extensions as errors
set(CUSTOM_CXX_FLAG_COMPILER_EXTENSION_AS_ERR "-pedantic-errors")

# Add Custom warnings from Clang - http://tinyurl.com/ClangDiagRef
set(CUSTOM_CXX_FLAG_WALL "-Wall")
set(CUSTOM_CXX_FLAG_TURN_WARN_TO_ERR "-Werror")
set(CUSTOM_CXX_FLAG_WARN_PEDANTIC "-Wpedantic")
set(CUSTOM_CXX_FLAG_PEDANTIC_ERR "-pedantic-errors")
set(CUSTOM_CXX_FLAG_WARN_EXTRA "-Wextra")
set(CUSTOM_CXX_FLAG_EFFECTIVE_CXX_ERR "-Weffc++")
set(CUSTOM_CXX_FLAG_CONVERSION_WARN "-Wconversion")
set(CUSTOM_CXX_FLAG_SIGN_CONVERSION_WARN "-Wsign-conversion")

# Combine errors
set(CUSTOM_WARN_ERRORS "\
${CUSTOM_CXX_FLAG_WALL} \
${CUSTOM_CXX_FLAG_TURN_WARN_TO_ERR} \
${CUSTOM_CXX_FLAG_WARN_PEDANTIC} \
${CUSTOM_CXX_FLAG_PEDANTIC_ERR} \
${CUSTOM_CXX_FLAG_WARN_EXTRA} \
${CUSTOM_CXX_FLAG_EFFECTIVE_CXX_ERR} \
${CUSTOM_CXX_FLAG_CONVERSION_WARN} \
${CUSTOM_CXX_FLAG_SIGN_CONVERSION_WARN}")

# Print warnings
message(CUSTOM_WARNINGS="${CUSTOM_WARN_ERRORS}")

set(CMAKE_CXX_FLAGS "${CUSTOM_WARN_ERRORS}")


add_executable(VariableInitialization main.cpp)
