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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anil/Thesis/repos/leetcode/leetcode_medium

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anil/Thesis/repos/leetcode/build

# Include any dependencies generated for this target.
include CMakeFiles/find_substring.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/find_substring.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/find_substring.dir/flags.make

CMakeFiles/find_substring.dir/find_substring.cpp.o: CMakeFiles/find_substring.dir/flags.make
CMakeFiles/find_substring.dir/find_substring.cpp.o: /home/anil/Thesis/repos/leetcode/leetcode_medium/find_substring.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anil/Thesis/repos/leetcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/find_substring.dir/find_substring.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/find_substring.dir/find_substring.cpp.o -c /home/anil/Thesis/repos/leetcode/leetcode_medium/find_substring.cpp

CMakeFiles/find_substring.dir/find_substring.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/find_substring.dir/find_substring.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anil/Thesis/repos/leetcode/leetcode_medium/find_substring.cpp > CMakeFiles/find_substring.dir/find_substring.cpp.i

CMakeFiles/find_substring.dir/find_substring.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/find_substring.dir/find_substring.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anil/Thesis/repos/leetcode/leetcode_medium/find_substring.cpp -o CMakeFiles/find_substring.dir/find_substring.cpp.s

CMakeFiles/find_substring.dir/find_substring.cpp.o.requires:

.PHONY : CMakeFiles/find_substring.dir/find_substring.cpp.o.requires

CMakeFiles/find_substring.dir/find_substring.cpp.o.provides: CMakeFiles/find_substring.dir/find_substring.cpp.o.requires
	$(MAKE) -f CMakeFiles/find_substring.dir/build.make CMakeFiles/find_substring.dir/find_substring.cpp.o.provides.build
.PHONY : CMakeFiles/find_substring.dir/find_substring.cpp.o.provides

CMakeFiles/find_substring.dir/find_substring.cpp.o.provides.build: CMakeFiles/find_substring.dir/find_substring.cpp.o


# Object files for target find_substring
find_substring_OBJECTS = \
"CMakeFiles/find_substring.dir/find_substring.cpp.o"

# External object files for target find_substring
find_substring_EXTERNAL_OBJECTS =

find_substring: CMakeFiles/find_substring.dir/find_substring.cpp.o
find_substring: CMakeFiles/find_substring.dir/build.make
find_substring: CMakeFiles/find_substring.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anil/Thesis/repos/leetcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable find_substring"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/find_substring.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/find_substring.dir/build: find_substring

.PHONY : CMakeFiles/find_substring.dir/build

CMakeFiles/find_substring.dir/requires: CMakeFiles/find_substring.dir/find_substring.cpp.o.requires

.PHONY : CMakeFiles/find_substring.dir/requires

CMakeFiles/find_substring.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/find_substring.dir/cmake_clean.cmake
.PHONY : CMakeFiles/find_substring.dir/clean

CMakeFiles/find_substring.dir/depend:
	cd /home/anil/Thesis/repos/leetcode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anil/Thesis/repos/leetcode/leetcode_medium /home/anil/Thesis/repos/leetcode/leetcode_medium /home/anil/Thesis/repos/leetcode/build /home/anil/Thesis/repos/leetcode/build /home/anil/Thesis/repos/leetcode/build/CMakeFiles/find_substring.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/find_substring.dir/depend

