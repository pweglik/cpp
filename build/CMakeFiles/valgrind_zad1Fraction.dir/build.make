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
CMAKE_SOURCE_DIR = /home/przemek/studia/sem4/cpp/fraction

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/przemek/studia/sem4/cpp/build

# Utility rule file for valgrind_zad1Fraction.

# Include the progress variables for this target.
include CMakeFiles/valgrind_zad1Fraction.dir/progress.make

CMakeFiles/valgrind_zad1Fraction: bin/zad1Fraction
	/usr/bin/valgrind --leak-check=full /home/przemek/studia/sem4/cpp/build/bin/zad1Fraction

valgrind_zad1Fraction: CMakeFiles/valgrind_zad1Fraction
valgrind_zad1Fraction: CMakeFiles/valgrind_zad1Fraction.dir/build.make

.PHONY : valgrind_zad1Fraction

# Rule to build all files generated by this target.
CMakeFiles/valgrind_zad1Fraction.dir/build: valgrind_zad1Fraction

.PHONY : CMakeFiles/valgrind_zad1Fraction.dir/build

CMakeFiles/valgrind_zad1Fraction.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/valgrind_zad1Fraction.dir/cmake_clean.cmake
.PHONY : CMakeFiles/valgrind_zad1Fraction.dir/clean

CMakeFiles/valgrind_zad1Fraction.dir/depend:
	cd /home/przemek/studia/sem4/cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/przemek/studia/sem4/cpp/fraction /home/przemek/studia/sem4/cpp/fraction /home/przemek/studia/sem4/cpp/build /home/przemek/studia/sem4/cpp/build /home/przemek/studia/sem4/cpp/build/CMakeFiles/valgrind_zad1Fraction.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/valgrind_zad1Fraction.dir/depend

