cmake_minimum_required(VERSION 3.28)
project(BankingServices VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(SOURCES 
    src/core/Account.cpp
    src/core/Bank.cpp
    src/core/main.cpp
    src/core/Application.cpp
    src/core/Transactions.cpp
    src/core/User.cpp
    src/util/helpers.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)