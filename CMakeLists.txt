project(Twitterak)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
	
   src/Display_Class.cpp
   src/main.cpp
   src/Twitt_Class.cpp
   src/Twitterak_Class.cpp
   src/User_Class.cpp
)

cmake_minimum_required(VERSION 3.0)

include_directories(include/ hash-library-master/)

add_executable(app ${SOURCES})