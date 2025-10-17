cmake_minimum_required(VERSION 3.15)
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_DIR}/scripts/buildsystems/vcpkg.cmake")

project(OPENKODP)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


find_package(sol2 REQUIRED)
find_package(Lua REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(TGUI CONFIG REQUIRED)
find_package(tinyxml2 CONFIG REQUIRED)

message(${SDL2_DIR})
#add_executable(${PROJECT_NAME} src/simulation/game.cpp)
add_executable(${PROJECT_NAME} src/utils/parse_mark_up.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${LUA_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PRIVATE sol2)
target_link_libraries(${PROJECT_NAME} PRIVATE  $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main> $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>)
target_link_libraries(${PROJECT_NAME} PRIVATE TGUI::TGUI)
target_link_libraries(${PROJECT_NAME} PRIVATE tinyxml2::tinyxml2)

#find_path(SOL_INCLUDE_DIR sol PATH_SUFFIXES sol)
#message(${SOL_INCLUDE_DIR})

#target_include_directories(main PRIVATE ${LUA_INCLUDE_DIR})
#target_include_directories(${PROJECT_NAME} PUBLIC ${SFML_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PUBLIC C:/vcpkg/installed/x64-windows/include/)
