cmake_minimum_required(VERSION 3.30)
project(hw11)

set(CMAKE_CXX_STANDARD 20)

# 设定构建运行路径，避免污染根目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/archive)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/library)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/runtime)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/path)

# 遍历项目根目录下所有的 .c 文件，自动添加
file(GLOB_RECURSE files *.c/*.c *.cpp */*,cpp)
foreach (file ${flies})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable(${exe} ${file})
    message(\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ runtime/${exe})
endforeach ()
