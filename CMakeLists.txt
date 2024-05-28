cmake_minimum_required(VERSION 3.12)

project("3D Rad Custom Object")

file(GLOB src CONFIGURE_DEPENDS ".cpp" ".hpp")

add_library(TestObject SHARED ${src})