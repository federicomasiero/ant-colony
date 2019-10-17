cmake_minimum_required(VERSION 3.15)
project(AntColony)

set(CMAKE_CXX_STANDARD 14)

add_executable(AntColony main.cpp TSP.h AntColony.cpp Ant.cpp Parser.cpp Plotter.cpp gnuplot_i.c gnuplot_i.h)
add_library(gnuplot_library STATIC gnuplot_i.c gnuplot_i.h)

find_library(GNUPLOT_LIBRARY gnuplot_library lib)
target_link_libraries(AntColony LINK_PUBLIC ${GNUPLOT_LIBRARY})