# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yosephnoh/Desktop/algorithm/SWExpert/BOJ16985

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yosephnoh/Desktop/algorithm/SWExpert/BOJ16985/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BOJ16985.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BOJ16985.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BOJ16985.dir/flags.make

CMakeFiles/BOJ16985.dir/main.cpp.o: CMakeFiles/BOJ16985.dir/flags.make
CMakeFiles/BOJ16985.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yosephnoh/Desktop/algorithm/SWExpert/BOJ16985/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BOJ16985.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BOJ16985.dir/main.cpp.o -c /Users/yosephnoh/Desktop/algorithm/SWExpert/BOJ16985/main.cpp

CMakeFiles/BOJ16985.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BOJ16985.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yosephnoh/Desktop/algorithm/SWExpert/BOJ16985/main.cpp > CMakeFiles/BOJ16985.dir/main.cpp.i

CMakeFiles/BOJ16985.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BOJ16985.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yosephnoh/Desktop/algorithm/SWExpert/BOJ16985/main.cpp -o CMakeFiles/BOJ16985.dir/main.cpp.s

CMakeFiles/BOJ16985.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/BOJ16985.dir/main.cpp.o.requires

CMakeFiles/BOJ16985.dir/main.cpp.o.provides: CMakeFiles/BOJ16985.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/BOJ16985.dir/build.make CMakeFiles/BOJ16985.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/BOJ16985.dir/main.cpp.o.provides

CMakeFiles/BOJ16985.dir/main.cpp.o.provides.build: CMakeFiles/BOJ16985.dir/main.cpp.o


# Object files for target BOJ16985
BOJ16985_OBJECTS = \
"CMakeFiles/BOJ16985.dir/main.cpp.o"

# External object files for target BOJ16985
BOJ16985_EXTERNAL_OBJECTS =

BOJ16985: CMakeFiles/BOJ16985.dir/main.cpp.o
BOJ16985: CMakeFiles/BOJ16985.dir/build.make
BOJ16985: CMakeFiles/BOJ16985.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yosephnoh/Desktop/algorithm/SWExpert/BOJ16985/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BOJ16985"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BOJ16985.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BOJ16985.dir/build: BOJ16985

.PHONY : CMakeFiles/BOJ16985.dir/build

CMakeFiles/BOJ16985.dir/requires: CMakeFiles/BOJ16985.dir/main.cpp.o.requires

.PHONY : CMakeFiles/BOJ16985.dir/requires

CMakeFiles/BOJ16985.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BOJ16985.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BOJ16985.dir/clean

CMakeFiles/BOJ16985.dir/depend:
	cd /Users/yosephnoh/Desktop/algorithm/SWExpert/BOJ16985/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yosephnoh/Desktop/algorithm/SWExpert/BOJ16985 /Users/yosephnoh/Desktop/algorithm/SWExpert/BOJ16985 /Users/yosephnoh/Desktop/algorithm/SWExpert/BOJ16985/cmake-build-debug /Users/yosephnoh/Desktop/algorithm/SWExpert/BOJ16985/cmake-build-debug /Users/yosephnoh/Desktop/algorithm/SWExpert/BOJ16985/cmake-build-debug/CMakeFiles/BOJ16985.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BOJ16985.dir/depend

