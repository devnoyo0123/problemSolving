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
CMAKE_SOURCE_DIR = /Users/yosephnoh/Documents/algorithm/SWExpert/BOJ1152_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yosephnoh/Documents/algorithm/SWExpert/BOJ1152_2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BOJ1152_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BOJ1152_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BOJ1152_2.dir/flags.make

CMakeFiles/BOJ1152_2.dir/main.cpp.o: CMakeFiles/BOJ1152_2.dir/flags.make
CMakeFiles/BOJ1152_2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yosephnoh/Documents/algorithm/SWExpert/BOJ1152_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BOJ1152_2.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BOJ1152_2.dir/main.cpp.o -c /Users/yosephnoh/Documents/algorithm/SWExpert/BOJ1152_2/main.cpp

CMakeFiles/BOJ1152_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BOJ1152_2.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yosephnoh/Documents/algorithm/SWExpert/BOJ1152_2/main.cpp > CMakeFiles/BOJ1152_2.dir/main.cpp.i

CMakeFiles/BOJ1152_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BOJ1152_2.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yosephnoh/Documents/algorithm/SWExpert/BOJ1152_2/main.cpp -o CMakeFiles/BOJ1152_2.dir/main.cpp.s

CMakeFiles/BOJ1152_2.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/BOJ1152_2.dir/main.cpp.o.requires

CMakeFiles/BOJ1152_2.dir/main.cpp.o.provides: CMakeFiles/BOJ1152_2.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/BOJ1152_2.dir/build.make CMakeFiles/BOJ1152_2.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/BOJ1152_2.dir/main.cpp.o.provides

CMakeFiles/BOJ1152_2.dir/main.cpp.o.provides.build: CMakeFiles/BOJ1152_2.dir/main.cpp.o


# Object files for target BOJ1152_2
BOJ1152_2_OBJECTS = \
"CMakeFiles/BOJ1152_2.dir/main.cpp.o"

# External object files for target BOJ1152_2
BOJ1152_2_EXTERNAL_OBJECTS =

BOJ1152_2: CMakeFiles/BOJ1152_2.dir/main.cpp.o
BOJ1152_2: CMakeFiles/BOJ1152_2.dir/build.make
BOJ1152_2: CMakeFiles/BOJ1152_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yosephnoh/Documents/algorithm/SWExpert/BOJ1152_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BOJ1152_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BOJ1152_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BOJ1152_2.dir/build: BOJ1152_2

.PHONY : CMakeFiles/BOJ1152_2.dir/build

CMakeFiles/BOJ1152_2.dir/requires: CMakeFiles/BOJ1152_2.dir/main.cpp.o.requires

.PHONY : CMakeFiles/BOJ1152_2.dir/requires

CMakeFiles/BOJ1152_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BOJ1152_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BOJ1152_2.dir/clean

CMakeFiles/BOJ1152_2.dir/depend:
	cd /Users/yosephnoh/Documents/algorithm/SWExpert/BOJ1152_2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yosephnoh/Documents/algorithm/SWExpert/BOJ1152_2 /Users/yosephnoh/Documents/algorithm/SWExpert/BOJ1152_2 /Users/yosephnoh/Documents/algorithm/SWExpert/BOJ1152_2/cmake-build-debug /Users/yosephnoh/Documents/algorithm/SWExpert/BOJ1152_2/cmake-build-debug /Users/yosephnoh/Documents/algorithm/SWExpert/BOJ1152_2/cmake-build-debug/CMakeFiles/BOJ1152_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BOJ1152_2.dir/depend

