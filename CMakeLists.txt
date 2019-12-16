cmake_minimum_required(VERSION 3.15)
project(AntColony)

set (Boost_USE_STATIC_LIBS OFF) #enable dynamic linking
set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:\\Program Files\\boost\\boost_1_72_0")
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "C:\\Program Files\\boost\\boost_1_72_0\\stage\\lib")
find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
# Note: a target should be already defined using 'add_executable' or 'add_library'
#target_link_libraries(TargetName ${Boost_LIBRARIES})


add_executable(AntColony main.cpp TSP.h AntColony.cpp Ant.cpp Parser.cpp Plotter.cpp gnuplot_i.c)
add_library(gnuplot_library STATIC gnuplot_i.c gnuplot_i.h)

find_library(GNUPLOT_LIBRARY gnuplot_library lib)
target_link_libraries(AntColony LINK_PUBLIC ${GNUPLOT_LIBRARY})