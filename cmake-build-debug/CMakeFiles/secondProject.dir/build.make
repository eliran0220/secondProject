# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/afik/Desktop/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/afik/Desktop/clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/afik/CLionProjects/secondProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/afik/CLionProjects/secondProject/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/secondProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/secondProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/secondProject.dir/flags.make

CMakeFiles/secondProject.dir/main.cpp.o: CMakeFiles/secondProject.dir/flags.make
CMakeFiles/secondProject.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/afik/CLionProjects/secondProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/secondProject.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/secondProject.dir/main.cpp.o -c /home/afik/CLionProjects/secondProject/main.cpp

CMakeFiles/secondProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/secondProject.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/afik/CLionProjects/secondProject/main.cpp > CMakeFiles/secondProject.dir/main.cpp.i

CMakeFiles/secondProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/secondProject.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/afik/CLionProjects/secondProject/main.cpp -o CMakeFiles/secondProject.dir/main.cpp.s

CMakeFiles/secondProject.dir/serverPackage/MySerialServer.cpp.o: CMakeFiles/secondProject.dir/flags.make
CMakeFiles/secondProject.dir/serverPackage/MySerialServer.cpp.o: ../serverPackage/MySerialServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/afik/CLionProjects/secondProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/secondProject.dir/serverPackage/MySerialServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/secondProject.dir/serverPackage/MySerialServer.cpp.o -c /home/afik/CLionProjects/secondProject/serverPackage/MySerialServer.cpp

CMakeFiles/secondProject.dir/serverPackage/MySerialServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/secondProject.dir/serverPackage/MySerialServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/afik/CLionProjects/secondProject/serverPackage/MySerialServer.cpp > CMakeFiles/secondProject.dir/serverPackage/MySerialServer.cpp.i

CMakeFiles/secondProject.dir/serverPackage/MySerialServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/secondProject.dir/serverPackage/MySerialServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/afik/CLionProjects/secondProject/serverPackage/MySerialServer.cpp -o CMakeFiles/secondProject.dir/serverPackage/MySerialServer.cpp.s

CMakeFiles/secondProject.dir/clientPackage/MyTestClientHandler.cpp.o: CMakeFiles/secondProject.dir/flags.make
CMakeFiles/secondProject.dir/clientPackage/MyTestClientHandler.cpp.o: ../clientPackage/MyTestClientHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/afik/CLionProjects/secondProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/secondProject.dir/clientPackage/MyTestClientHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/secondProject.dir/clientPackage/MyTestClientHandler.cpp.o -c /home/afik/CLionProjects/secondProject/clientPackage/MyTestClientHandler.cpp

CMakeFiles/secondProject.dir/clientPackage/MyTestClientHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/secondProject.dir/clientPackage/MyTestClientHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/afik/CLionProjects/secondProject/clientPackage/MyTestClientHandler.cpp > CMakeFiles/secondProject.dir/clientPackage/MyTestClientHandler.cpp.i

CMakeFiles/secondProject.dir/clientPackage/MyTestClientHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/secondProject.dir/clientPackage/MyTestClientHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/afik/CLionProjects/secondProject/clientPackage/MyTestClientHandler.cpp -o CMakeFiles/secondProject.dir/clientPackage/MyTestClientHandler.cpp.s

CMakeFiles/secondProject.dir/cachePackage/FileCacheManager.cpp.o: CMakeFiles/secondProject.dir/flags.make
CMakeFiles/secondProject.dir/cachePackage/FileCacheManager.cpp.o: ../cachePackage/FileCacheManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/afik/CLionProjects/secondProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/secondProject.dir/cachePackage/FileCacheManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/secondProject.dir/cachePackage/FileCacheManager.cpp.o -c /home/afik/CLionProjects/secondProject/cachePackage/FileCacheManager.cpp

CMakeFiles/secondProject.dir/cachePackage/FileCacheManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/secondProject.dir/cachePackage/FileCacheManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/afik/CLionProjects/secondProject/cachePackage/FileCacheManager.cpp > CMakeFiles/secondProject.dir/cachePackage/FileCacheManager.cpp.i

CMakeFiles/secondProject.dir/cachePackage/FileCacheManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/secondProject.dir/cachePackage/FileCacheManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/afik/CLionProjects/secondProject/cachePackage/FileCacheManager.cpp -o CMakeFiles/secondProject.dir/cachePackage/FileCacheManager.cpp.s

CMakeFiles/secondProject.dir/solverPackage/StringReverser.cpp.o: CMakeFiles/secondProject.dir/flags.make
CMakeFiles/secondProject.dir/solverPackage/StringReverser.cpp.o: ../solverPackage/StringReverser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/afik/CLionProjects/secondProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/secondProject.dir/solverPackage/StringReverser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/secondProject.dir/solverPackage/StringReverser.cpp.o -c /home/afik/CLionProjects/secondProject/solverPackage/StringReverser.cpp

CMakeFiles/secondProject.dir/solverPackage/StringReverser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/secondProject.dir/solverPackage/StringReverser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/afik/CLionProjects/secondProject/solverPackage/StringReverser.cpp > CMakeFiles/secondProject.dir/solverPackage/StringReverser.cpp.i

CMakeFiles/secondProject.dir/solverPackage/StringReverser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/secondProject.dir/solverPackage/StringReverser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/afik/CLionProjects/secondProject/solverPackage/StringReverser.cpp -o CMakeFiles/secondProject.dir/solverPackage/StringReverser.cpp.s

CMakeFiles/secondProject.dir/clientPackage/MyClientHandler.cpp.o: CMakeFiles/secondProject.dir/flags.make
CMakeFiles/secondProject.dir/clientPackage/MyClientHandler.cpp.o: ../clientPackage/MyClientHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/afik/CLionProjects/secondProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/secondProject.dir/clientPackage/MyClientHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/secondProject.dir/clientPackage/MyClientHandler.cpp.o -c /home/afik/CLionProjects/secondProject/clientPackage/MyClientHandler.cpp

CMakeFiles/secondProject.dir/clientPackage/MyClientHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/secondProject.dir/clientPackage/MyClientHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/afik/CLionProjects/secondProject/clientPackage/MyClientHandler.cpp > CMakeFiles/secondProject.dir/clientPackage/MyClientHandler.cpp.i

CMakeFiles/secondProject.dir/clientPackage/MyClientHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/secondProject.dir/clientPackage/MyClientHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/afik/CLionProjects/secondProject/clientPackage/MyClientHandler.cpp -o CMakeFiles/secondProject.dir/clientPackage/MyClientHandler.cpp.s

# Object files for target secondProject
secondProject_OBJECTS = \
"CMakeFiles/secondProject.dir/main.cpp.o" \
"CMakeFiles/secondProject.dir/serverPackage/MySerialServer.cpp.o" \
"CMakeFiles/secondProject.dir/clientPackage/MyTestClientHandler.cpp.o" \
"CMakeFiles/secondProject.dir/cachePackage/FileCacheManager.cpp.o" \
"CMakeFiles/secondProject.dir/solverPackage/StringReverser.cpp.o" \
"CMakeFiles/secondProject.dir/clientPackage/MyClientHandler.cpp.o"

# External object files for target secondProject
secondProject_EXTERNAL_OBJECTS =

secondProject: CMakeFiles/secondProject.dir/main.cpp.o
secondProject: CMakeFiles/secondProject.dir/serverPackage/MySerialServer.cpp.o
secondProject: CMakeFiles/secondProject.dir/clientPackage/MyTestClientHandler.cpp.o
secondProject: CMakeFiles/secondProject.dir/cachePackage/FileCacheManager.cpp.o
secondProject: CMakeFiles/secondProject.dir/solverPackage/StringReverser.cpp.o
secondProject: CMakeFiles/secondProject.dir/clientPackage/MyClientHandler.cpp.o
secondProject: CMakeFiles/secondProject.dir/build.make
secondProject: CMakeFiles/secondProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/afik/CLionProjects/secondProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable secondProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/secondProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/secondProject.dir/build: secondProject

.PHONY : CMakeFiles/secondProject.dir/build

CMakeFiles/secondProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/secondProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/secondProject.dir/clean

CMakeFiles/secondProject.dir/depend:
	cd /home/afik/CLionProjects/secondProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/afik/CLionProjects/secondProject /home/afik/CLionProjects/secondProject /home/afik/CLionProjects/secondProject/cmake-build-debug /home/afik/CLionProjects/secondProject/cmake-build-debug /home/afik/CLionProjects/secondProject/cmake-build-debug/CMakeFiles/secondProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/secondProject.dir/depend

