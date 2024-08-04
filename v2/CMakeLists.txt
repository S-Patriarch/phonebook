cmake_minimum_required(VERSION 3.25)
project(pb)
set(CMAKE_BUILD_TYPE Release)
set(SOURCES
   main.cc
   info_logo.cc
   info_help.cc
   info.cc
   read_phonebook.cc
   check_files.cc
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
