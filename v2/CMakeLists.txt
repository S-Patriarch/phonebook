cmake_minimum_required(VERSION 3.25)
project(pb)
set(CMAKE_BUILD_TYPE Release)
set(SOURCES
  main.cc
  check_files.cc
  read_phonebook.cc
  out_info_logo.cc
  out_info_help.cc
  enter_command.cc
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
