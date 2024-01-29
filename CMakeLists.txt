cmake_minimum_required(VERSION 3.20)
project(userver-mre CXX)

# Compatibility mode: some systems don't support these features
set(USERVER_FEATURE_CRYPTOPP_BLAKE2 OFF CACHE BOOL "" FORCE)
set(USERVER_FEATURE_GRPC_CHANNELZ OFF CACHE BOOL "" FORCE)
set(USERVER_FEATURE_REDIS_HI_MALLOC ON CACHE BOOL "" FORCE)
set(CXX_STANDARD_REQUIRED 17)

# Adding userver dependency
add_subdirectory(third_party/userver)
userver_setup_environment()

# Common sources
add_library(${PROJECT_NAME}_objs OBJECT
    src/handlers/hello/hello.hpp
    src/handlers/hello/hello.cpp
    src/handlers/bye/bye.hpp
    src/handlers/bye/bye.cpp
)
target_link_libraries(${PROJECT_NAME}_objs PUBLIC userver-core)

# The Service
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_objs)

# Install
include(GNUInstallDirs)

if(DEFINED ENV{PREFIX})
  message(STATUS "Set install prefix: $ENV{PREFIX}")
  file(TO_CMAKE_PATH "$ENV{PREFIX}" PREFIX_PATH)
  set(CMAKE_INSTALL_PREFIX "${PREFIX_PATH}")
endif()

file(GLOB CONFIGS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/configs/*.yaml ${CMAKE_CURRENT_SOURCE_DIR}/configs/*.json)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT ${PROJECT_NAME})
install(FILES ${CONFIGS_FILES} DESTINATION ${CMAKE_INSTALL_SYSCONFDIR}/${PROJECT_NAME} COMPONENT ${PROJECT_NAME})
