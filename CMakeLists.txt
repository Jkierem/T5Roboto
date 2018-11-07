cmake_minimum_required(VERSION 3.0)

project(roboto)

find_package(CGAL REQUIRED)
include(${CGAL_USE_FILE})
set (CMAKE_CXX_STANDARD 11)

add_executable(
  roboto
  ./src/main.cxx
  ./src/Core/Core.h
  ./src/Traits/LogicTraits.h
  ./src/Traits/ReaderTraits.h
  ./src/FileReader/FileReader.h
  ./src/FileWriter/FileWriter.h
  ./src/MatrixInserter/MatrixInserter.h
)

target_link_libraries(
  roboto
  ${CGAL_LIBRARIES} 
  )
