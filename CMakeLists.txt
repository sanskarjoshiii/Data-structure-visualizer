cmake_minimum_required(VERSION 3.15)

# Call your project "server"
project(server)

# Require at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Provide FetchContent fallback for header-only deps if not installed via vcpkg
include(FetchContent)

# --- Find Packages ---

# 1. Find the Crow library (this is a normal package)
#    We use CONFIG mode as suggested by vcpkg
find_package(Crow CONFIG QUIET)

# 2. Find the Asio library (a dependency for Crow)
#    This creates the variable ${asio_INCLUDE_DIRS}
find_package(asio QUIET)

# 3. Find the SQLite3 library (this is a normal package)
#    This creates the variable ${SQLite3_INCLUDE_DIRS}
find_package(SQLite3 QUIET)

# 4. Find the path to the sqlite_modern_cpp.h header file
#    (This is special for header-only libraries)
find_path(
    SQLITE_MODERN_CPP_INCLUDE_DIR 
    NAMES sqlite_modern_cpp.h
    HINTS ${CMAKE_PREFIX_PATH}/include
          ${VCPKG_ROOT}/installed/${VCPKG_TARGET_TRIPLET}/include
)

if(NOT SQLITE_MODERN_CPP_INCLUDE_DIR)
    message(STATUS "sqlite_modern_cpp.h not found - falling back to fetching header-only 'sqlite-modern-cpp' via FetchContent")

    FetchContent_Declare(
        sqlite_modern_cpp
        GIT_REPOSITORY https://github.com/SqliteModernCpp/sqlite_modern_cpp.git
        GIT_TAG        master
    )
    FetchContent_MakeAvailable(sqlite_modern_cpp)

    # The repo places headers under its include/ directory
    if (TARGET sqlite_modern_cpp)
        # no-op, but keep for clarity
    endif()

    # Try to set include dir to fetched content
    if (sqlite_modern_cpp_SOURCE_DIR)
        set(SQLITE_MODERN_CPP_INCLUDE_DIR "${sqlite_modern_cpp_SOURCE_DIR}/include")
    endif()
endif()


# --- Build Executable ---

# Tell CMake to build an executable named "server"
add_executable(server server.cpp)

# --- Link Libraries and Include Paths ---

# Link the compiled libraries to your "server" executable
target_link_libraries(server
    PRIVATE
)

# Link Crow if available as a target, otherwise add its include dir (fetched or installed single-header)
if(TARGET Crow::Crow)
    target_link_libraries(server PRIVATE Crow::Crow)
elseif(NOT TARGET Crow::Crow)
    # try to fetch single-header crow_all.h (lightweight fallback)
    if(NOT Crow_FOUND)
        message(STATUS "Crow not found via find_package - fetching single-header crow_all.h")
        FetchContent_Declare(
            crow_single_header
            GIT_REPOSITORY https://github.com/ipkn/crow.git
            GIT_TAG        master
        )
        FetchContent_MakeAvailable(crow_single_header)
        if(crow_single_header_SOURCE_DIR)
            # include the repo's include directory where crow_all.h lives
            target_include_directories(server PRIVATE "${crow_single_header_SOURCE_DIR}/include")
        endif()
    endif()
endif()

# Link asio if found
if(TARGET asio::asio)
    target_link_libraries(server PRIVATE asio::asio)
elseif(asio_FOUND)
    target_include_directories(server PRIVATE ${asio_INCLUDE_DIRS})
endif()

# Link SQLite3 if found
if(TARGET SQLite::SQLite3)
    target_link_libraries(server PRIVATE SQLite::SQLite3)
elseif(SQLite3_FOUND)
    target_include_directories(server PRIVATE ${SQLite3_INCLUDE_DIRS})
endif()

# On Windows link ws2_32 for networking
if(WIN32)
    target_link_libraries(server PRIVATE ws2_32)
endif()

# Tell the compiler where to find ALL the header files
# The find_package commands create these variables for us.
target_include_directories(server
    PRIVATE
        ${SQLITE_MODERN_CPP_INCLUDE_DIR}
    ${Crow_INCLUDE_DIRS}   # <-- Explicitly add Crow's include path (if set)
    ${asio_INCLUDE_DIRS}   # <-- Explicitly add asio's include path (if set)
    ${SQLite3_INCLUDE_DIRS} # <-- Explicitly add sqlite3's include path (if set)
)

