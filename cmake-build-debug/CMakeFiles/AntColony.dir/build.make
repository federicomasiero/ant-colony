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
include CMakeFiles\AntColony.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\AntColony.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\AntColony.dir\flags.make

CMakeFiles\AntColony.dir\main.cpp.obj: CMakeFiles\AntColony.dir\flags.make
CMakeFiles\AntColony.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\feder\CLionProjects\AntColony\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AntColony.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\AntColony.dir\main.cpp.obj /FdCMakeFiles\AntColony.dir\ /FS -c C:\Users\feder\CLionProjects\AntColony\main.cpp
<<

CMakeFiles\AntColony.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AntColony.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\AntColony.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\feder\CLionProjects\AntColony\main.cpp
<<

CMakeFiles\AntColony.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AntColony.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\AntColony.dir\main.cpp.s /c C:\Users\feder\CLionProjects\AntColony\main.cpp
<<

CMakeFiles\AntColony.dir\AntColony.cpp.obj: CMakeFiles\AntColony.dir\flags.make
CMakeFiles\AntColony.dir\AntColony.cpp.obj: ..\AntColony.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\feder\CLionProjects\AntColony\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AntColony.dir/AntColony.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\AntColony.dir\AntColony.cpp.obj /FdCMakeFiles\AntColony.dir\ /FS -c C:\Users\feder\CLionProjects\AntColony\AntColony.cpp
<<

CMakeFiles\AntColony.dir\AntColony.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AntColony.dir/AntColony.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\AntColony.dir\AntColony.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\feder\CLionProjects\AntColony\AntColony.cpp
<<

CMakeFiles\AntColony.dir\AntColony.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AntColony.dir/AntColony.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\AntColony.dir\AntColony.cpp.s /c C:\Users\feder\CLionProjects\AntColony\AntColony.cpp
<<

CMakeFiles\AntColony.dir\Ant.cpp.obj: CMakeFiles\AntColony.dir\flags.make
CMakeFiles\AntColony.dir\Ant.cpp.obj: ..\Ant.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\feder\CLionProjects\AntColony\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AntColony.dir/Ant.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\AntColony.dir\Ant.cpp.obj /FdCMakeFiles\AntColony.dir\ /FS -c C:\Users\feder\CLionProjects\AntColony\Ant.cpp
<<

CMakeFiles\AntColony.dir\Ant.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AntColony.dir/Ant.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\AntColony.dir\Ant.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\feder\CLionProjects\AntColony\Ant.cpp
<<

CMakeFiles\AntColony.dir\Ant.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AntColony.dir/Ant.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\AntColony.dir\Ant.cpp.s /c C:\Users\feder\CLionProjects\AntColony\Ant.cpp
<<

CMakeFiles\AntColony.dir\Parser.cpp.obj: CMakeFiles\AntColony.dir\flags.make
CMakeFiles\AntColony.dir\Parser.cpp.obj: ..\Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\feder\CLionProjects\AntColony\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/AntColony.dir/Parser.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\AntColony.dir\Parser.cpp.obj /FdCMakeFiles\AntColony.dir\ /FS -c C:\Users\feder\CLionProjects\AntColony\Parser.cpp
<<

CMakeFiles\AntColony.dir\Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AntColony.dir/Parser.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\AntColony.dir\Parser.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\feder\CLionProjects\AntColony\Parser.cpp
<<

CMakeFiles\AntColony.dir\Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AntColony.dir/Parser.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\AntColony.dir\Parser.cpp.s /c C:\Users\feder\CLionProjects\AntColony\Parser.cpp
<<

CMakeFiles\AntColony.dir\Plotter.cpp.obj: CMakeFiles\AntColony.dir\flags.make
CMakeFiles\AntColony.dir\Plotter.cpp.obj: ..\Plotter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\feder\CLionProjects\AntColony\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/AntColony.dir/Plotter.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\AntColony.dir\Plotter.cpp.obj /FdCMakeFiles\AntColony.dir\ /FS -c C:\Users\feder\CLionProjects\AntColony\Plotter.cpp
<<

CMakeFiles\AntColony.dir\Plotter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AntColony.dir/Plotter.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\AntColony.dir\Plotter.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\feder\CLionProjects\AntColony\Plotter.cpp
<<

CMakeFiles\AntColony.dir\Plotter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AntColony.dir/Plotter.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\AntColony.dir\Plotter.cpp.s /c C:\Users\feder\CLionProjects\AntColony\Plotter.cpp
<<

CMakeFiles\AntColony.dir\gnuplot_i.c.obj: CMakeFiles\AntColony.dir\flags.make
CMakeFiles\AntColony.dir\gnuplot_i.c.obj: ..\gnuplot_i.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\feder\CLionProjects\AntColony\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/AntColony.dir/gnuplot_i.c.obj"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\AntColony.dir\gnuplot_i.c.obj /FdCMakeFiles\AntColony.dir\ /FS -c C:\Users\feder\CLionProjects\AntColony\gnuplot_i.c
<<

CMakeFiles\AntColony.dir\gnuplot_i.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AntColony.dir/gnuplot_i.c.i"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\AntColony.dir\gnuplot_i.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\feder\CLionProjects\AntColony\gnuplot_i.c
<<

CMakeFiles\AntColony.dir\gnuplot_i.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AntColony.dir/gnuplot_i.c.s"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\AntColony.dir\gnuplot_i.c.s /c C:\Users\feder\CLionProjects\AntColony\gnuplot_i.c
<<

# Object files for target AntColony
AntColony_OBJECTS = \
"CMakeFiles\AntColony.dir\main.cpp.obj" \
"CMakeFiles\AntColony.dir\AntColony.cpp.obj" \
"CMakeFiles\AntColony.dir\Ant.cpp.obj" \
"CMakeFiles\AntColony.dir\Parser.cpp.obj" \
"CMakeFiles\AntColony.dir\Plotter.cpp.obj" \
"CMakeFiles\AntColony.dir\gnuplot_i.c.obj"

# External object files for target AntColony
AntColony_EXTERNAL_OBJECTS =

AntColony.exe: CMakeFiles\AntColony.dir\main.cpp.obj
AntColony.exe: CMakeFiles\AntColony.dir\AntColony.cpp.obj
AntColony.exe: CMakeFiles\AntColony.dir\Ant.cpp.obj
AntColony.exe: CMakeFiles\AntColony.dir\Parser.cpp.obj
AntColony.exe: CMakeFiles\AntColony.dir\Plotter.cpp.obj
AntColony.exe: CMakeFiles\AntColony.dir\gnuplot_i.c.obj
AntColony.exe: CMakeFiles\AntColony.dir\build.make
AntColony.exe: gnuplot_library.lib
AntColony.exe: CMakeFiles\AntColony.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\feder\CLionProjects\AntColony\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable AntColony.exe"
	"C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\AntColony.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\AntColony.dir\objects1.rsp @<<
 /out:AntColony.exe /implib:AntColony.lib /pdb:C:\Users\feder\CLionProjects\AntColony\cmake-build-debug\AntColony.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console gnuplot_library.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\AntColony.dir\build: AntColony.exe

.PHONY : CMakeFiles\AntColony.dir\build

CMakeFiles\AntColony.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AntColony.dir\cmake_clean.cmake
.PHONY : CMakeFiles\AntColony.dir\clean

CMakeFiles\AntColony.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\feder\CLionProjects\AntColony C:\Users\feder\CLionProjects\AntColony C:\Users\feder\CLionProjects\AntColony\cmake-build-debug C:\Users\feder\CLionProjects\AntColony\cmake-build-debug C:\Users\feder\CLionProjects\AntColony\cmake-build-debug\CMakeFiles\AntColony.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\AntColony.dir\depend

