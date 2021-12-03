cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(advancedQFcpp VERSION 0.1.0)

# Include dir
include_directories(/usr/local/include)

# Src
AUX_SOURCE_DIRECTORY(src SRC_FILES)

# Headers
set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include/advancedQFcpp_bits")

# Source files
set(SOURCE_FILES
    ${PROJECT_INCLUDE_DIR}/random.hpp
    ${PROJECT_INCLUDE_DIR}/eq1.hpp
    ${PROJECT_INCLUDE_DIR}/eq2.hpp
    ${PROJECT_INCLUDE_DIR}/matrix.hpp
    ${PROJECT_INCLUDE_DIR}/fx1.hpp
    ${PROJECT_INCLUDE_DIR}/ir.hpp
    ${PROJECT_INCLUDE_DIR}/credit.hpp
    ${PROJECT_SOURCE_DIR}/random.cpp
    ${PROJECT_SOURCE_DIR}/eq1.cpp
    ${PROJECT_SOURCE_DIR}/eq2.cpp
    ${PROJECT_SOURCE_DIR}/fx1.cpp
    ${PROJECT_SOURCE_DIR}/ir.cpp
    ${PROJECT_SOURCE_DIR}/credit.cpp
    ${PROJECT_SOURCE_DIR}/printer.cpp
)

# Set up such that XCode organizes the files correctly
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

# Add library
add_library(advancedQFcpp SHARED ${SOURCE_FILES})

# Include directories
target_include_directories(advancedQFcpp PRIVATE include/advancedQFcpp_bits)

# Install
install(TARGETS advancedQFcpp DESTINATION lib)

# Install the headers
install(FILES include/advancedQFcpp DESTINATION include)

# Create base directory
install(DIRECTORY include/advancedQFcpp_bits DESTINATION include)
