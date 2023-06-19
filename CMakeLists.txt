cmake_minimum_required(VERSION 3.0)
project(Twitterak)

set(CMAKE_CXX_STANDARD 11)

include_directories(include/ hash-library-master/)


set(SOURCES
	
   src/Display_Class.cpp
   src/Main.cpp
   src/Tweet_Class.cpp
   src/Twitterak_Class.cpp
   src/User_Class.cpp
   src/sha256.cpp
   src/TD_Class.cpp
)

add_executable(app ${SOURCES})