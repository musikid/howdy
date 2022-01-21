cmake_minimum_required(VERSION 3.21)
project(pam)

set(CMAKE_CXX_STANDARD 14)

# Find deps
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")
find_package(Boost REQUIRED locale)
find_package(PAM REQUIRED)
find_library(INIH_LIBRARY INIReader REQUIRED)
find_path(INIH_INCLUDE_DIR INIReader.h REQUIRED)

# Configure target for shared lib
add_library(pam_howdy SHARED main.cc main.hh optional_task.hh)
target_include_directories(
  pam_howdy PUBLIC ${Boost_INCLUDE_DIRS} ${PAM_INCLUDE_DIR} ${INIH_INCLUDE_DIR})
target_link_libraries(pam_howdy ${Boost_LIBRARIES} ${PAM_LIBRARIES} INIReader pthread)

# Output config
set_property(TARGET pam_howdy PROPERTY PREFIX "") # We don't want "lib" prefix
install(TARGETS pam_howdy DESTINATION /lib/security/)
