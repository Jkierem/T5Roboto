cmake_minimum_required(VERSION 3.0)

project(roboto)

set( CMAKE_BUILD_TYPE Debug )

find_package(CGAL REQUIRED)
include(${CGAL_USE_FILE})

find_package(Qt5 REQUIRED COMPONENTS OpenGL Xml Widgets)

set (CMAKE_CXX_STANDARD 11)

add_executable(
  roboto
  ./src/main.cxx
  ./src/Traits/Traits.h
  ./src/Voronoi/Voronoi.h
  ./src/Bresenham/Bresenham.h
  ./src/FileReader/FileReader.h
  ./src/FileWriter/FileWriter.h
  ./src/BorderDetection/BorderDetection.h
  ./src/ConnectedComponents/ConnectedComponents.h
)

target_link_libraries(
  roboto
  ${CGAL_LIBRARIES} CGAL_Qt5
  Qt5::Xml Qt5::Widgets Qt5::OpenGL
  )
