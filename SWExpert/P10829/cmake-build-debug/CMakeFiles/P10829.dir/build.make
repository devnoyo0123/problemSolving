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
CMAKE_SOURCE_DIR = /Users/yosephnoh/Documents/BackJoon/P10829

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yosephnoh/Documents/BackJoon/P10829/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/P10829.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/P10829.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/P10829.dir/flags.make

CMakeFiles/P10829.dir/main.cpp.o: CMakeFiles/P10829.dir/flags.make
CMakeFiles/P10829.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yosephnoh/Documents/BackJoon/P10829/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/P10829.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/P10829.dir/main.cpp.o -c /Users/yosephnoh/Documents/BackJoon/P10829/main.cpp

CMakeFiles/P10829.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/P10829.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yosephnoh/Documents/BackJoon/P10829/main.cpp > CMakeFiles/P10829.dir/main.cpp.i

CMakeFiles/P10829.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/P10829.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yosephnoh/Documents/BackJoon/P10829/main.cpp -o CMakeFiles/P10829.dir/main.cpp.s

CMakeFiles/P10829.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/P10829.dir/main.cpp.o.requires

CMakeFiles/P10829.dir/main.cpp.o.provides: CMakeFiles/P10829.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/P10829.dir/build.make CMakeFiles/P10829.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/P10829.dir/main.cpp.o.provides

CMakeFiles/P10829.dir/main.cpp.o.provides.build: CMakeFiles/P10829.dir/main.cpp.o


# Object files for target P10829
P10829_OBJECTS = \
"CMakeFiles/P10829.dir/main.cpp.o"

# External object files for target P10829
P10829_EXTERNAL_OBJECTS =

P10829: CMakeFiles/P10829.dir/main.cpp.o
P10829: CMakeFiles/P10829.dir/build.make
P10829: CMakeFiles/P10829.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yosephnoh/Documents/BackJoon/P10829/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable P10829"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/P10829.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/P10829.dir/build: P10829

.PHONY : CMakeFiles/P10829.dir/build

CMakeFiles/P10829.dir/requires: CMakeFiles/P10829.dir/main.cpp.o.requires

.PHONY : CMakeFiles/P10829.dir/requires

CMakeFiles/P10829.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/P10829.dir/cmake_clean.cmake
.PHONY : CMakeFiles/P10829.dir/clean

CMakeFiles/P10829.dir/depend:
	cd /Users/yosephnoh/Documents/BackJoon/P10829/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yosephnoh/Documents/BackJoon/P10829 /Users/yosephnoh/Documents/BackJoon/P10829 /Users/yosephnoh/Documents/BackJoon/P10829/cmake-build-debug /Users/yosephnoh/Documents/BackJoon/P10829/cmake-build-debug /Users/yosephnoh/Documents/BackJoon/P10829/cmake-build-debug/CMakeFiles/P10829.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/P10829.dir/depend
