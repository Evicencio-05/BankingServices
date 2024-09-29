cmake_minimum_required(VERSION 3.15)
project(BankingServices)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(PostgreSQL REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBPQ REQUIRED libpq)

set(SOURCES
    src/account/main.cpp
    src/account/Account.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${PostgreSQL_INCLUDE_DIRS}
    ${LIBPQ_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    ${PostgreSQL_LIBRARIES}
    ${LIBPQ_LIBRARIES}
)
