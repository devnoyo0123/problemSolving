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
CMAKE_SOURCE_DIR = /Users/yosephnoh/Documents/algorithm/SWExpert/P4008

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yosephnoh/Documents/algorithm/SWExpert/P4008/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/P4008.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/P4008.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/P4008.dir/flags.make

CMakeFiles/P4008.dir/main.cpp.o: CMakeFiles/P4008.dir/flags.make
CMakeFiles/P4008.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yosephnoh/Documents/algorithm/SWExpert/P4008/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/P4008.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/P4008.dir/main.cpp.o -c /Users/yosephnoh/Documents/algorithm/SWExpert/P4008/main.cpp

CMakeFiles/P4008.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/P4008.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yosephnoh/Documents/algorithm/SWExpert/P4008/main.cpp > CMakeFiles/P4008.dir/main.cpp.i

CMakeFiles/P4008.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/P4008.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yosephnoh/Documents/algorithm/SWExpert/P4008/main.cpp -o CMakeFiles/P4008.dir/main.cpp.s

CMakeFiles/P4008.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/P4008.dir/main.cpp.o.requires

CMakeFiles/P4008.dir/main.cpp.o.provides: CMakeFiles/P4008.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/P4008.dir/build.make CMakeFiles/P4008.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/P4008.dir/main.cpp.o.provides

CMakeFiles/P4008.dir/main.cpp.o.provides.build: CMakeFiles/P4008.dir/main.cpp.o


# Object files for target P4008
P4008_OBJECTS = \
"CMakeFiles/P4008.dir/main.cpp.o"

# External object files for target P4008
P4008_EXTERNAL_OBJECTS =

P4008: CMakeFiles/P4008.dir/main.cpp.o
P4008: CMakeFiles/P4008.dir/build.make
P4008: CMakeFiles/P4008.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yosephnoh/Documents/algorithm/SWExpert/P4008/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable P4008"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/P4008.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/P4008.dir/build: P4008

.PHONY : CMakeFiles/P4008.dir/build

CMakeFiles/P4008.dir/requires: CMakeFiles/P4008.dir/main.cpp.o.requires

.PHONY : CMakeFiles/P4008.dir/requires

CMakeFiles/P4008.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/P4008.dir/cmake_clean.cmake
.PHONY : CMakeFiles/P4008.dir/clean

CMakeFiles/P4008.dir/depend:
	cd /Users/yosephnoh/Documents/algorithm/SWExpert/P4008/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yosephnoh/Documents/algorithm/SWExpert/P4008 /Users/yosephnoh/Documents/algorithm/SWExpert/P4008 /Users/yosephnoh/Documents/algorithm/SWExpert/P4008/cmake-build-debug /Users/yosephnoh/Documents/algorithm/SWExpert/P4008/cmake-build-debug /Users/yosephnoh/Documents/algorithm/SWExpert/P4008/cmake-build-debug/CMakeFiles/P4008.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/P4008.dir/depend
