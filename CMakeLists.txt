cmake_minimum_required(VERSION 3.6)
project(BingoCards)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/Deck.cpp src/Deck.h src/Card.cpp src/Card.h src/Error.h)
add_executable(BingoCards src/main.cpp ${SOURCE_FILES})
