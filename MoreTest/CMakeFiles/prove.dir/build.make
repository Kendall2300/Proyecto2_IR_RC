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
CMAKE_COMMAND = /home/gabriel/clion-2021.2.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/gabriel/clion-2021.2.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/gabriel/Escritorio/Proyecto2_IR_RC aa/MoreTest"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/gabriel/Escritorio/Proyecto2_IR_RC aa/MoreTest"

# Include any dependencies generated for this target.
include CMakeFiles/prove.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/prove.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prove.dir/flags.make

CMakeFiles/prove.dir/prove_autogen/mocs_compilation.cpp.o: CMakeFiles/prove.dir/flags.make
CMakeFiles/prove.dir/prove_autogen/mocs_compilation.cpp.o: prove_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/gabriel/Escritorio/Proyecto2_IR_RC aa/MoreTest/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/prove.dir/prove_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/prove.dir/prove_autogen/mocs_compilation.cpp.o -c "/home/gabriel/Escritorio/Proyecto2_IR_RC aa/MoreTest/prove_autogen/mocs_compilation.cpp"

CMakeFiles/prove.dir/prove_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prove.dir/prove_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/gabriel/Escritorio/Proyecto2_IR_RC aa/MoreTest/prove_autogen/mocs_compilation.cpp" > CMakeFiles/prove.dir/prove_autogen/mocs_compilation.cpp.i

CMakeFiles/prove.dir/prove_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prove.dir/prove_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/gabriel/Escritorio/Proyecto2_IR_RC aa/MoreTest/prove_autogen/mocs_compilation.cpp" -o CMakeFiles/prove.dir/prove_autogen/mocs_compilation.cpp.s

# Object files for target prove
prove_OBJECTS = \
"CMakeFiles/prove.dir/prove_autogen/mocs_compilation.cpp.o"

# External object files for target prove
prove_EXTERNAL_OBJECTS =

prove: CMakeFiles/prove.dir/prove_autogen/mocs_compilation.cpp.o
prove: CMakeFiles/prove.dir/build.make
prove: /home/gabriel/Qt/6.2.0/gcc_64/lib/libQt6Widgets.so.6.2.0
prove: /usr/local/lib/libopencv_gapi.so.4.5.4
prove: /usr/local/lib/libopencv_highgui.so.4.5.4
prove: /usr/local/lib/libopencv_ml.so.4.5.4
prove: /usr/local/lib/libopencv_objdetect.so.4.5.4
prove: /usr/local/lib/libopencv_photo.so.4.5.4
prove: /usr/local/lib/libopencv_stitching.so.4.5.4
prove: /usr/local/lib/libopencv_video.so.4.5.4
prove: /usr/local/lib/libopencv_videoio.so.4.5.4
prove: /home/gabriel/Qt/6.2.0/gcc_64/lib/libQt6Gui.so.6.2.0
prove: /home/gabriel/Qt/6.2.0/gcc_64/lib/libQt6Core.so.6.2.0
prove: /usr/lib/x86_64-linux-gnu/libGLX.so
prove: /usr/lib/x86_64-linux-gnu/libOpenGL.so
prove: /usr/local/lib/libopencv_imgcodecs.so.4.5.4
prove: /usr/local/lib/libopencv_dnn.so.4.5.4
prove: /usr/local/lib/libopencv_calib3d.so.4.5.4
prove: /usr/local/lib/libopencv_features2d.so.4.5.4
prove: /usr/local/lib/libopencv_flann.so.4.5.4
prove: /usr/local/lib/libopencv_imgproc.so.4.5.4
prove: /usr/local/lib/libopencv_core.so.4.5.4
prove: CMakeFiles/prove.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/gabriel/Escritorio/Proyecto2_IR_RC aa/MoreTest/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable prove"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prove.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prove.dir/build: prove
.PHONY : CMakeFiles/prove.dir/build

CMakeFiles/prove.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/prove.dir/cmake_clean.cmake
.PHONY : CMakeFiles/prove.dir/clean

CMakeFiles/prove.dir/depend:
	cd "/home/gabriel/Escritorio/Proyecto2_IR_RC aa/MoreTest" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/gabriel/Escritorio/Proyecto2_IR_RC aa/MoreTest" "/home/gabriel/Escritorio/Proyecto2_IR_RC aa/MoreTest" "/home/gabriel/Escritorio/Proyecto2_IR_RC aa/MoreTest" "/home/gabriel/Escritorio/Proyecto2_IR_RC aa/MoreTest" "/home/gabriel/Escritorio/Proyecto2_IR_RC aa/MoreTest/CMakeFiles/prove.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/prove.dir/depend
