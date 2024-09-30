cmake_minimum_required(VERSION 3.15)
project(BankingServices)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(PostgreSQL REQUIRED)
find_package(PkgConfig REQUIRED)

# Check and link libpqxx
pkg_check_modules(LIBPQ REQUIRED libpq)
pkg_check_modules(PQXX REQUIRED libpqxx)

add_library(account_library STATIC
    src/account/Account.cpp
)

# Include directories for the account library
target_include_directories(account_library PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${PQXX_INCLUDE_DIRS}
)

# Set source files for the main executable
set(SOURCES src/account/main.cpp)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories for the main executable
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# Include other dependencies
target_include_directories(${PROJECT_NAME} PRIVATE
    ${PostgreSQL_INCLUDE_DIRS}
    ${LIBPQ_INCLUDE_DIRS}
    ${PQXX_INCLUDE_DIRS}
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE 
    ${PostgreSQL_LIBRARIES}
    ${LIBPQ_LIBRARIES}
    ${PQXX_LIBRARIES}
    account_library
)
