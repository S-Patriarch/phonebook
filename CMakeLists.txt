# 
# (c) 2024 S-Patriarch
# 

cmake_minimum_required(VERSION 3.25)

project(pb)

set(ts_VERSION_MAJOR 1)
set(ts_VERSION_MINOR 1)
set(ts_VERSION_PATCH 2)
set(ts_VERSION "${ts_VERSION_MAJOR}.${ts_VERSION_MINOR}.${ts_VERSION_PATCH}")

set(CMAKE_BUILD_TYPE Release)

set(SOURCES
   main.cc
   info_logo.cc
   info_help.cc
   info.cc
   read_phonebook.cc
   check_files.cc
   a_phonebook.cc
   c_phonebook.cc
   d_phonebook.cc
   q_phonebook.cc
   s_phonebook.cc
   p_phonebook.cc
)

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(
   ${PROJECT_NAME} PROPERTIES
   CXX_STANDARD 17
   CXX_STANDARD_REQUIRED ON
)

