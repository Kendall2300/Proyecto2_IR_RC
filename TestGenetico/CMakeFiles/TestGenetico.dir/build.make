# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/dlurena24/Programs/clion-2021.2.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/dlurena24/Programs/clion-2021.2.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dlurena24/CLionProjects/TestGenetico

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dlurena24/CLionProjects/TestGenetico

# Include any dependencies generated for this target.
include CMakeFiles/TestGenetico.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/TestGenetico.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestGenetico.dir/flags.make

CMakeFiles/TestGenetico.dir/TestGenetico.cpp.o: CMakeFiles/TestGenetico.dir/flags.make
CMakeFiles/TestGenetico.dir/TestGenetico.cpp.o: TestGenetico.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dlurena24/CLionProjects/TestGenetico/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestGenetico.dir/TestGenetico.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestGenetico.dir/TestGenetico.cpp.o -c /home/dlurena24/CLionProjects/TestGenetico/TestGenetico.cpp

CMakeFiles/TestGenetico.dir/TestGenetico.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestGenetico.dir/TestGenetico.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dlurena24/CLionProjects/TestGenetico/TestGenetico.cpp > CMakeFiles/TestGenetico.dir/TestGenetico.cpp.i

CMakeFiles/TestGenetico.dir/TestGenetico.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestGenetico.dir/TestGenetico.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dlurena24/CLionProjects/TestGenetico/TestGenetico.cpp -o CMakeFiles/TestGenetico.dir/TestGenetico.cpp.s

CMakeFiles/TestGenetico.dir/Species.cpp.o: CMakeFiles/TestGenetico.dir/flags.make
CMakeFiles/TestGenetico.dir/Species.cpp.o: Species.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dlurena24/CLionProjects/TestGenetico/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TestGenetico.dir/Species.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestGenetico.dir/Species.cpp.o -c /home/dlurena24/CLionProjects/TestGenetico/Species.cpp

CMakeFiles/TestGenetico.dir/Species.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestGenetico.dir/Species.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dlurena24/CLionProjects/TestGenetico/Species.cpp > CMakeFiles/TestGenetico.dir/Species.cpp.i

CMakeFiles/TestGenetico.dir/Species.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestGenetico.dir/Species.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dlurena24/CLionProjects/TestGenetico/Species.cpp -o CMakeFiles/TestGenetico.dir/Species.cpp.s

# Object files for target TestGenetico
TestGenetico_OBJECTS = \
"CMakeFiles/TestGenetico.dir/TestGenetico.cpp.o" \
"CMakeFiles/TestGenetico.dir/Species.cpp.o"

# External object files for target TestGenetico
TestGenetico_EXTERNAL_OBJECTS =

TestGenetico: CMakeFiles/TestGenetico.dir/TestGenetico.cpp.o
TestGenetico: CMakeFiles/TestGenetico.dir/Species.cpp.o
TestGenetico: CMakeFiles/TestGenetico.dir/build.make
TestGenetico: /usr/local/lib/libopencv_gapi.so.4.5.4
TestGenetico: /usr/local/lib/libopencv_highgui.so.4.5.4
TestGenetico: /usr/local/lib/libopencv_ml.so.4.5.4
TestGenetico: /usr/local/lib/libopencv_objdetect.so.4.5.4
TestGenetico: /usr/local/lib/libopencv_photo.so.4.5.4
TestGenetico: /usr/local/lib/libopencv_stitching.so.4.5.4
TestGenetico: /usr/local/lib/libopencv_video.so.4.5.4
TestGenetico: /usr/local/lib/libopencv_videoio.so.4.5.4
TestGenetico: /usr/local/lib/libopencv_imgcodecs.so.4.5.4
TestGenetico: /usr/local/lib/libopencv_dnn.so.4.5.4
TestGenetico: /usr/local/lib/libopencv_calib3d.so.4.5.4
TestGenetico: /usr/local/lib/libopencv_features2d.so.4.5.4
TestGenetico: /usr/local/lib/libopencv_flann.so.4.5.4
TestGenetico: /usr/local/lib/libopencv_imgproc.so.4.5.4
TestGenetico: /usr/local/lib/libopencv_core.so.4.5.4
TestGenetico: CMakeFiles/TestGenetico.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dlurena24/CLionProjects/TestGenetico/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TestGenetico"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestGenetico.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestGenetico.dir/build: TestGenetico
.PHONY : CMakeFiles/TestGenetico.dir/build

CMakeFiles/TestGenetico.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestGenetico.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestGenetico.dir/clean

CMakeFiles/TestGenetico.dir/depend:
	cd /home/dlurena24/CLionProjects/TestGenetico && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dlurena24/CLionProjects/TestGenetico /home/dlurena24/CLionProjects/TestGenetico /home/dlurena24/CLionProjects/TestGenetico /home/dlurena24/CLionProjects/TestGenetico /home/dlurena24/CLionProjects/TestGenetico/CMakeFiles/TestGenetico.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestGenetico.dir/depend

