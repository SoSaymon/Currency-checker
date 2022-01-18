# CMakeList.txt : CMake project for Currency-checker, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.1)

project ("Currency-checker")

# Add source to this project's executable.
add_executable ("${PROJECT_NAME}" "Currency-checker.cpp" "Currency-checker.h" "file/file.h" "file/file.cpp" "date_time/date_time.h" "date_time/date_time.cpp" "web_handler/web_handler.h" "web_handler/web_handler.cpp")

# TODO: Add tests and install targets if needed.
find_package(cpr CONFIG REQUIRED)
target_link_libraries("${PROJECT_NAME}" PRIVATE cpr::cpr)
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries("${PROJECT_NAME}" PRIVATE nlohmann_json nlohmann_json::nlohmann_json)