# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 2.8)

project ("Monopoly")

aux_source_directory(src DIR_SRCS)
include_directories(src)
add_executable(Monopoly ${DIR_SRCS})
