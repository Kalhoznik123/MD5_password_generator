cmake_minimum_required(VERSION 3.5)

project(pas_gen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add variables for sources
set(GENERATOR_FILES generator.cpp generator.h)
set(PASSWORD_BUILDER_FILES password_builder.cpp password_builder.h)
set(FILEREADER_FILES FileConfigReader.cpp FileConfigReader.h)
add_executable(pas_gen main.cpp ${GENERATOR_FILES} ${PASSWORD_BUILDER_FILES} ${FILEREADER_FILES}) #добавляем тарегет приложения
add_subdirectory(md5lib)

#link a md5_library to project
target_include_directories(pas_gen PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/md5lib)
target_include_directories(pas_gen PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/simpleini)
target_link_libraries(pas_gen md5lib)
