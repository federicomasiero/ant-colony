# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\feder\CLionProjects\AntColony

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\feder\CLionProjects\AntColony\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\AntColony_gnuplot.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\AntColony_gnuplot.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\AntColony_gnuplot.dir\flags.make

CMakeFiles\AntColony_gnuplot.dir\main.cpp.obj: CMakeFiles\AntColony_gnuplot.dir\flags.make
CMakeFiles\AntColony_gnuplot.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\feder\CLionProjects\AntColony\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AntColony_gnuplot.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\AntColony_gnuplot.dir\main.cpp.obj /FdCMakeFiles\AntColony_gnuplot.dir\ /FS -c C:\Users\feder\CLionProjects\AntColony\main.cpp
<<

CMakeFiles\AntColony_gnuplot.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AntColony_gnuplot.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\AntColony_gnuplot.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\feder\CLionProjects\AntColony\main.cpp
<<

CMakeFiles\AntColony_gnuplot.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AntColony_gnuplot.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\AntColony_gnuplot.dir\main.cpp.s /c C:\Users\feder\CLionProjects\AntColony\main.cpp
<<

CMakeFiles\AntColony_gnuplot.dir\gnuplot_i.c.obj: CMakeFiles\AntColony_gnuplot.dir\flags.make
CMakeFiles\AntColony_gnuplot.dir\gnuplot_i.c.obj: ..\gnuplot_i.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\feder\CLionProjects\AntColony\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/AntColony_gnuplot.dir/gnuplot_i.c.obj"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\AntColony_gnuplot.dir\gnuplot_i.c.obj /FdCMakeFiles\AntColony_gnuplot.dir\ /FS -c C:\Users\feder\CLionProjects\AntColony\gnuplot_i.c
<<

CMakeFiles\AntColony_gnuplot.dir\gnuplot_i.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AntColony_gnuplot.dir/gnuplot_i.c.i"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\AntColony_gnuplot.dir\gnuplot_i.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\feder\CLionProjects\AntColony\gnuplot_i.c
<<

CMakeFiles\AntColony_gnuplot.dir\gnuplot_i.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AntColony_gnuplot.dir/gnuplot_i.c.s"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\AntColony_gnuplot.dir\gnuplot_i.c.s /c C:\Users\feder\CLionProjects\AntColony\gnuplot_i.c
<<

# Object files for target AntColony_gnuplot
AntColony_gnuplot_OBJECTS = \
"CMakeFiles\AntColony_gnuplot.dir\main.cpp.obj" \
"CMakeFiles\AntColony_gnuplot.dir\gnuplot_i.c.obj"

# External object files for target AntColony_gnuplot
AntColony_gnuplot_EXTERNAL_OBJECTS =

AntColony_gnuplot.exe: CMakeFiles\AntColony_gnuplot.dir\main.cpp.obj
AntColony_gnuplot.exe: CMakeFiles\AntColony_gnuplot.dir\gnuplot_i.c.obj
AntColony_gnuplot.exe: CMakeFiles\AntColony_gnuplot.dir\build.make
AntColony_gnuplot.exe: CMakeFiles\AntColony_gnuplot.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\feder\CLionProjects\AntColony\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable AntColony_gnuplot.exe"
	"C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\AntColony_gnuplot.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\AntColony_gnuplot.dir\objects1.rsp @<<
 /out:AntColony_gnuplot.exe /implib:AntColony_gnuplot.lib /pdb:C:\Users\feder\CLionProjects\AntColony\cmake-build-debug\AntColony_gnuplot.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\AntColony_gnuplot.dir\build: AntColony_gnuplot.exe

.PHONY : CMakeFiles\AntColony_gnuplot.dir\build

CMakeFiles\AntColony_gnuplot.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AntColony_gnuplot.dir\cmake_clean.cmake
.PHONY : CMakeFiles\AntColony_gnuplot.dir\clean

CMakeFiles\AntColony_gnuplot.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\feder\CLionProjects\AntColony C:\Users\feder\CLionProjects\AntColony C:\Users\feder\CLionProjects\AntColony\cmake-build-debug C:\Users\feder\CLionProjects\AntColony\cmake-build-debug C:\Users\feder\CLionProjects\AntColony\cmake-build-debug\CMakeFiles\AntColony_gnuplot.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\AntColony_gnuplot.dir\depend

