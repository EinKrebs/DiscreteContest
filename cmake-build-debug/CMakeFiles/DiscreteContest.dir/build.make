# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/137/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/137/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/krebs/CLionProjects/DiscreteContest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/krebs/CLionProjects/DiscreteContest/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DiscreteContest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DiscreteContest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DiscreteContest.dir/flags.make

CMakeFiles/DiscreteContest.dir/A.cpp.o: CMakeFiles/DiscreteContest.dir/flags.make
CMakeFiles/DiscreteContest.dir/A.cpp.o: ../A.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krebs/CLionProjects/DiscreteContest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DiscreteContest.dir/A.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DiscreteContest.dir/A.cpp.o -c /home/krebs/CLionProjects/DiscreteContest/A.cpp

CMakeFiles/DiscreteContest.dir/A.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DiscreteContest.dir/A.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krebs/CLionProjects/DiscreteContest/A.cpp > CMakeFiles/DiscreteContest.dir/A.cpp.i

CMakeFiles/DiscreteContest.dir/A.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DiscreteContest.dir/A.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krebs/CLionProjects/DiscreteContest/A.cpp -o CMakeFiles/DiscreteContest.dir/A.cpp.s

CMakeFiles/DiscreteContest.dir/B.cpp.o: CMakeFiles/DiscreteContest.dir/flags.make
CMakeFiles/DiscreteContest.dir/B.cpp.o: ../B.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krebs/CLionProjects/DiscreteContest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DiscreteContest.dir/B.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DiscreteContest.dir/B.cpp.o -c /home/krebs/CLionProjects/DiscreteContest/B.cpp

CMakeFiles/DiscreteContest.dir/B.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DiscreteContest.dir/B.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krebs/CLionProjects/DiscreteContest/B.cpp > CMakeFiles/DiscreteContest.dir/B.cpp.i

CMakeFiles/DiscreteContest.dir/B.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DiscreteContest.dir/B.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krebs/CLionProjects/DiscreteContest/B.cpp -o CMakeFiles/DiscreteContest.dir/B.cpp.s

# Object files for target DiscreteContest
DiscreteContest_OBJECTS = \
"CMakeFiles/DiscreteContest.dir/A.cpp.o" \
"CMakeFiles/DiscreteContest.dir/B.cpp.o"

# External object files for target DiscreteContest
DiscreteContest_EXTERNAL_OBJECTS =

DiscreteContest: CMakeFiles/DiscreteContest.dir/A.cpp.o
DiscreteContest: CMakeFiles/DiscreteContest.dir/B.cpp.o
DiscreteContest: CMakeFiles/DiscreteContest.dir/build.make
DiscreteContest: CMakeFiles/DiscreteContest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/krebs/CLionProjects/DiscreteContest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable DiscreteContest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DiscreteContest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DiscreteContest.dir/build: DiscreteContest

.PHONY : CMakeFiles/DiscreteContest.dir/build

CMakeFiles/DiscreteContest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DiscreteContest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DiscreteContest.dir/clean

CMakeFiles/DiscreteContest.dir/depend:
	cd /home/krebs/CLionProjects/DiscreteContest/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/krebs/CLionProjects/DiscreteContest /home/krebs/CLionProjects/DiscreteContest /home/krebs/CLionProjects/DiscreteContest/cmake-build-debug /home/krebs/CLionProjects/DiscreteContest/cmake-build-debug /home/krebs/CLionProjects/DiscreteContest/cmake-build-debug/CMakeFiles/DiscreteContest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DiscreteContest.dir/depend

