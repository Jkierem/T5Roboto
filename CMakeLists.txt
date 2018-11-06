cmake_minimum_required(VERSION 3.0)

project(roboto)

find_package(CGAL REQUIRED)
include(${CGAL_USE_FILE})

find_package(Qt5 REQUIRED COMPONENTS OpenGL Xml Widgets)

add_executable(test_Delaunay main.cxx)
target_link_libraries(
  roboto
  ${CGAL_LIBRARIES} CGAL_Qt5
  Qt5::Xml Qt5::Widgets Qt5::OpenGL
  )
