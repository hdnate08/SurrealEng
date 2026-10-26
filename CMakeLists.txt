cmake_minimum_required(VERSION 4.4.4)
project(physeng VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SurrealEng)

target_sources(SurrealEng
	PRIVATE
	    src/main.cpp
)
