# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/david/design_pattern/open_closed

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/design_pattern/open_closed/build

# Include any dependencies generated for this target.
include CMakeFiles/creation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/creation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/creation.dir/flags.make

CMakeFiles/creation.dir/creational.cpp.o: CMakeFiles/creation.dir/flags.make
CMakeFiles/creation.dir/creational.cpp.o: ../creational.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/design_pattern/open_closed/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/creation.dir/creational.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/creation.dir/creational.cpp.o -c /home/david/design_pattern/open_closed/creational.cpp

CMakeFiles/creation.dir/creational.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/creation.dir/creational.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/design_pattern/open_closed/creational.cpp > CMakeFiles/creation.dir/creational.cpp.i

CMakeFiles/creation.dir/creational.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/creation.dir/creational.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/design_pattern/open_closed/creational.cpp -o CMakeFiles/creation.dir/creational.cpp.s

# Object files for target creation
creation_OBJECTS = \
"CMakeFiles/creation.dir/creational.cpp.o"

# External object files for target creation
creation_EXTERNAL_OBJECTS =

creation: CMakeFiles/creation.dir/creational.cpp.o
creation: CMakeFiles/creation.dir/build.make
creation: CMakeFiles/creation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/david/design_pattern/open_closed/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable creation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/creation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/creation.dir/build: creation

.PHONY : CMakeFiles/creation.dir/build

CMakeFiles/creation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/creation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/creation.dir/clean

CMakeFiles/creation.dir/depend:
	cd /home/david/design_pattern/open_closed/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/design_pattern/open_closed /home/david/design_pattern/open_closed /home/david/design_pattern/open_closed/build /home/david/design_pattern/open_closed/build /home/david/design_pattern/open_closed/build/CMakeFiles/creation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/creation.dir/depend
