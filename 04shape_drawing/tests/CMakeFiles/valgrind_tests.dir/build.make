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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/przemek/studia/sem4/cpp/04shape_drawing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/przemek/studia/sem4/cpp/04shape_drawing

# Utility rule file for valgrind_tests.

# Include the progress variables for this target.
include tests/CMakeFiles/valgrind_tests.dir/progress.make

tests/CMakeFiles/valgrind_tests: bin/tests
	cd /home/przemek/studia/sem4/cpp/04shape_drawing/bin && valgrind --leak-check=full /home/przemek/studia/sem4/cpp/04shape_drawing/bin/tests

valgrind_tests: tests/CMakeFiles/valgrind_tests
valgrind_tests: tests/CMakeFiles/valgrind_tests.dir/build.make

.PHONY : valgrind_tests

# Rule to build all files generated by this target.
tests/CMakeFiles/valgrind_tests.dir/build: valgrind_tests

.PHONY : tests/CMakeFiles/valgrind_tests.dir/build

tests/CMakeFiles/valgrind_tests.dir/clean:
	cd /home/przemek/studia/sem4/cpp/04shape_drawing/tests && $(CMAKE_COMMAND) -P CMakeFiles/valgrind_tests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/valgrind_tests.dir/clean

tests/CMakeFiles/valgrind_tests.dir/depend:
	cd /home/przemek/studia/sem4/cpp/04shape_drawing && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/przemek/studia/sem4/cpp/04shape_drawing /home/przemek/studia/sem4/cpp/04shape_drawing/tests /home/przemek/studia/sem4/cpp/04shape_drawing /home/przemek/studia/sem4/cpp/04shape_drawing/tests /home/przemek/studia/sem4/cpp/04shape_drawing/tests/CMakeFiles/valgrind_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/valgrind_tests.dir/depend

