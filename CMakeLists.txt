cmake_minimum_required(VERSION 3.26)
project(HummingBirdKasperSpecific)

set(CMAKE_CXX_STANDARD 23)


set(HUMMINGBIRDCORE_DIR ../KBTools/HummingBirdCore)
set(HUMMINGBIRDVENDOR_DIR ../KBTools/vendor)

include_directories(
    ${HUMMINGBIRDCORE_DIR}/src
    ${HUMMINGBIRDVENDOR_DIR}
    ${HUMMINGBIRDVENDOR_DIR}/fmt/include
    ${HUMMINGBIRDVENDOR_DIR}/spdlog/include
    ${HUMMINGBIRDVENDOR_DIR}/glad/include
    ${HUMMINGBIRDVENDOR_DIR}/imgui
    ${HUMMINGBIRDVENDOR_DIR}/sdl/include
)

add_library(HummingBirdKasperSpecific
        src/HelloLibrary.cpp)
