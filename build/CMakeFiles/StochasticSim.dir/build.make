# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Projects\StochasticProcesses

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Projects\StochasticProcesses\build

# Include any dependencies generated for this target.
include CMakeFiles/StochasticSim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/StochasticSim.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/StochasticSim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StochasticSim.dir/flags.make

CMakeFiles/StochasticSim.dir/src/Process.cpp.obj: CMakeFiles/StochasticSim.dir/flags.make
CMakeFiles/StochasticSim.dir/src/Process.cpp.obj: CMakeFiles/StochasticSim.dir/includes_CXX.rsp
CMakeFiles/StochasticSim.dir/src/Process.cpp.obj: C:/Projects/StochasticProcesses/src/Process.cpp
CMakeFiles/StochasticSim.dir/src/Process.cpp.obj: CMakeFiles/StochasticSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Projects\StochasticProcesses\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StochasticSim.dir/src/Process.cpp.obj"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/StochasticSim.dir/src/Process.cpp.obj -MF CMakeFiles\StochasticSim.dir\src\Process.cpp.obj.d -o CMakeFiles\StochasticSim.dir\src\Process.cpp.obj -c C:\Projects\StochasticProcesses\src\Process.cpp

CMakeFiles/StochasticSim.dir/src/Process.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/StochasticSim.dir/src/Process.cpp.i"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Projects\StochasticProcesses\src\Process.cpp > CMakeFiles\StochasticSim.dir\src\Process.cpp.i

CMakeFiles/StochasticSim.dir/src/Process.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/StochasticSim.dir/src/Process.cpp.s"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Projects\StochasticProcesses\src\Process.cpp -o CMakeFiles\StochasticSim.dir\src\Process.cpp.s

CMakeFiles/StochasticSim.dir/src/main.cpp.obj: CMakeFiles/StochasticSim.dir/flags.make
CMakeFiles/StochasticSim.dir/src/main.cpp.obj: CMakeFiles/StochasticSim.dir/includes_CXX.rsp
CMakeFiles/StochasticSim.dir/src/main.cpp.obj: C:/Projects/StochasticProcesses/src/main.cpp
CMakeFiles/StochasticSim.dir/src/main.cpp.obj: CMakeFiles/StochasticSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Projects\StochasticProcesses\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/StochasticSim.dir/src/main.cpp.obj"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/StochasticSim.dir/src/main.cpp.obj -MF CMakeFiles\StochasticSim.dir\src\main.cpp.obj.d -o CMakeFiles\StochasticSim.dir\src\main.cpp.obj -c C:\Projects\StochasticProcesses\src\main.cpp

CMakeFiles/StochasticSim.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/StochasticSim.dir/src/main.cpp.i"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Projects\StochasticProcesses\src\main.cpp > CMakeFiles\StochasticSim.dir\src\main.cpp.i

CMakeFiles/StochasticSim.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/StochasticSim.dir/src/main.cpp.s"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Projects\StochasticProcesses\src\main.cpp -o CMakeFiles\StochasticSim.dir\src\main.cpp.s

# Object files for target StochasticSim
StochasticSim_OBJECTS = \
"CMakeFiles/StochasticSim.dir/src/Process.cpp.obj" \
"CMakeFiles/StochasticSim.dir/src/main.cpp.obj"

# External object files for target StochasticSim
StochasticSim_EXTERNAL_OBJECTS =

StochasticSim_Debug.exe: CMakeFiles/StochasticSim.dir/src/Process.cpp.obj
StochasticSim_Debug.exe: CMakeFiles/StochasticSim.dir/src/main.cpp.obj
StochasticSim_Debug.exe: CMakeFiles/StochasticSim.dir/build.make
StochasticSim_Debug.exe: CMakeFiles/StochasticSim.dir/linkLibs.rsp
StochasticSim_Debug.exe: CMakeFiles/StochasticSim.dir/objects1.rsp
StochasticSim_Debug.exe: CMakeFiles/StochasticSim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Projects\StochasticProcesses\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable StochasticSim_Debug.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\StochasticSim.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StochasticSim.dir/build: StochasticSim_Debug.exe
.PHONY : CMakeFiles/StochasticSim.dir/build

CMakeFiles/StochasticSim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\StochasticSim.dir\cmake_clean.cmake
.PHONY : CMakeFiles/StochasticSim.dir/clean

CMakeFiles/StochasticSim.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Projects\StochasticProcesses C:\Projects\StochasticProcesses C:\Projects\StochasticProcesses\build C:\Projects\StochasticProcesses\build C:\Projects\StochasticProcesses\build\CMakeFiles\StochasticSim.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/StochasticSim.dir/depend

