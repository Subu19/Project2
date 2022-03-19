cmake_minimum_required(VERSION 3.0.0)
project(game CXX)


project(game)
add_executable(${PROJECT_NAME} 
    src/Game.cpp
    main.cpp)
    # add installation prefix of SFML to CMAKE_PREFIX_PATH
    set(CMAKE_PREFIX_PATH "SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5.1 REQUIRED COMPONENTS graphics window)
target_include_directories(game PRIVATE src/Headers)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window)
install(TARGETS game)
