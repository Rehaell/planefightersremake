# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rehaell/Documents/github/planefightersremake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rehaell/Documents/github/planefightersremake/build

# Include any dependencies generated for this target.
include CMakeFiles/PlaneFightersRemake.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PlaneFightersRemake.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PlaneFightersRemake.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PlaneFightersRemake.dir/flags.make

CMakeFiles/PlaneFightersRemake.dir/main.cpp.o: CMakeFiles/PlaneFightersRemake.dir/flags.make
CMakeFiles/PlaneFightersRemake.dir/main.cpp.o: ../main.cpp
CMakeFiles/PlaneFightersRemake.dir/main.cpp.o: CMakeFiles/PlaneFightersRemake.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rehaell/Documents/github/planefightersremake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PlaneFightersRemake.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PlaneFightersRemake.dir/main.cpp.o -MF CMakeFiles/PlaneFightersRemake.dir/main.cpp.o.d -o CMakeFiles/PlaneFightersRemake.dir/main.cpp.o -c /home/rehaell/Documents/github/planefightersremake/main.cpp

CMakeFiles/PlaneFightersRemake.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PlaneFightersRemake.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rehaell/Documents/github/planefightersremake/main.cpp > CMakeFiles/PlaneFightersRemake.dir/main.cpp.i

CMakeFiles/PlaneFightersRemake.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PlaneFightersRemake.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rehaell/Documents/github/planefightersremake/main.cpp -o CMakeFiles/PlaneFightersRemake.dir/main.cpp.s

# Object files for target PlaneFightersRemake
PlaneFightersRemake_OBJECTS = \
"CMakeFiles/PlaneFightersRemake.dir/main.cpp.o"

# External object files for target PlaneFightersRemake
PlaneFightersRemake_EXTERNAL_OBJECTS =

PlaneFightersRemake: CMakeFiles/PlaneFightersRemake.dir/main.cpp.o
PlaneFightersRemake: CMakeFiles/PlaneFightersRemake.dir/build.make
PlaneFightersRemake: _deps/raylib-build/raylib/libraylib.a
PlaneFightersRemake: /usr/lib/x86_64-linux-gnu/libGL.so
PlaneFightersRemake: /usr/lib/x86_64-linux-gnu/libGLU.so
PlaneFightersRemake: _deps/raylib-build/raylib/external/glfw/src/libglfw3.a
PlaneFightersRemake: /usr/lib/x86_64-linux-gnu/librt.a
PlaneFightersRemake: /usr/lib/x86_64-linux-gnu/libm.so
PlaneFightersRemake: CMakeFiles/PlaneFightersRemake.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rehaell/Documents/github/planefightersremake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PlaneFightersRemake"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PlaneFightersRemake.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PlaneFightersRemake.dir/build: PlaneFightersRemake
.PHONY : CMakeFiles/PlaneFightersRemake.dir/build

CMakeFiles/PlaneFightersRemake.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PlaneFightersRemake.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PlaneFightersRemake.dir/clean

CMakeFiles/PlaneFightersRemake.dir/depend:
	cd /home/rehaell/Documents/github/planefightersremake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rehaell/Documents/github/planefightersremake /home/rehaell/Documents/github/planefightersremake /home/rehaell/Documents/github/planefightersremake/build /home/rehaell/Documents/github/planefightersremake/build /home/rehaell/Documents/github/planefightersremake/build/CMakeFiles/PlaneFightersRemake.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PlaneFightersRemake.dir/depend
