# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/noahwimmer/Desktop/Freshman Year/Second Semester/CS2050/cs-2050-labs/Lab11"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/noahwimmer/Desktop/Freshman Year/Second Semester/CS2050/cs-2050-labs/Lab11/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Lab11.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab11.dir/flags.make

CMakeFiles/Lab11.dir/main.c.o: CMakeFiles/Lab11.dir/flags.make
CMakeFiles/Lab11.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/noahwimmer/Desktop/Freshman Year/Second Semester/CS2050/cs-2050-labs/Lab11/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Lab11.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Lab11.dir/main.c.o -c "/Users/noahwimmer/Desktop/Freshman Year/Second Semester/CS2050/cs-2050-labs/Lab11/main.c"

CMakeFiles/Lab11.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lab11.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/noahwimmer/Desktop/Freshman Year/Second Semester/CS2050/cs-2050-labs/Lab11/main.c" > CMakeFiles/Lab11.dir/main.c.i

CMakeFiles/Lab11.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lab11.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/noahwimmer/Desktop/Freshman Year/Second Semester/CS2050/cs-2050-labs/Lab11/main.c" -o CMakeFiles/Lab11.dir/main.c.s

CMakeFiles/Lab11.dir/lab11.c.o: CMakeFiles/Lab11.dir/flags.make
CMakeFiles/Lab11.dir/lab11.c.o: ../lab11.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/noahwimmer/Desktop/Freshman Year/Second Semester/CS2050/cs-2050-labs/Lab11/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Lab11.dir/lab11.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Lab11.dir/lab11.c.o -c "/Users/noahwimmer/Desktop/Freshman Year/Second Semester/CS2050/cs-2050-labs/Lab11/lab11.c"

CMakeFiles/Lab11.dir/lab11.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lab11.dir/lab11.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/noahwimmer/Desktop/Freshman Year/Second Semester/CS2050/cs-2050-labs/Lab11/lab11.c" > CMakeFiles/Lab11.dir/lab11.c.i

CMakeFiles/Lab11.dir/lab11.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lab11.dir/lab11.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/noahwimmer/Desktop/Freshman Year/Second Semester/CS2050/cs-2050-labs/Lab11/lab11.c" -o CMakeFiles/Lab11.dir/lab11.c.s

# Object files for target Lab11
Lab11_OBJECTS = \
"CMakeFiles/Lab11.dir/main.c.o" \
"CMakeFiles/Lab11.dir/lab11.c.o"

# External object files for target Lab11
Lab11_EXTERNAL_OBJECTS =

Lab11: CMakeFiles/Lab11.dir/main.c.o
Lab11: CMakeFiles/Lab11.dir/lab11.c.o
Lab11: CMakeFiles/Lab11.dir/build.make
Lab11: CMakeFiles/Lab11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/noahwimmer/Desktop/Freshman Year/Second Semester/CS2050/cs-2050-labs/Lab11/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Lab11"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab11.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab11.dir/build: Lab11

.PHONY : CMakeFiles/Lab11.dir/build

CMakeFiles/Lab11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab11.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab11.dir/clean

CMakeFiles/Lab11.dir/depend:
	cd "/Users/noahwimmer/Desktop/Freshman Year/Second Semester/CS2050/cs-2050-labs/Lab11/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/noahwimmer/Desktop/Freshman Year/Second Semester/CS2050/cs-2050-labs/Lab11" "/Users/noahwimmer/Desktop/Freshman Year/Second Semester/CS2050/cs-2050-labs/Lab11" "/Users/noahwimmer/Desktop/Freshman Year/Second Semester/CS2050/cs-2050-labs/Lab11/cmake-build-debug" "/Users/noahwimmer/Desktop/Freshman Year/Second Semester/CS2050/cs-2050-labs/Lab11/cmake-build-debug" "/Users/noahwimmer/Desktop/Freshman Year/Second Semester/CS2050/cs-2050-labs/Lab11/cmake-build-debug/CMakeFiles/Lab11.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Lab11.dir/depend

