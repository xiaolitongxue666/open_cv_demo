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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/liyong/Code/Opencv/open_cv_demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/liyong/Code/Opencv/open_cv_demo/build

# Include any dependencies generated for this target.
include CMakeFiles/open_cv_demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/open_cv_demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/open_cv_demo.dir/flags.make

CMakeFiles/open_cv_demo.dir/src/main.cpp.o: CMakeFiles/open_cv_demo.dir/flags.make
CMakeFiles/open_cv_demo.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liyong/Code/Opencv/open_cv_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/open_cv_demo.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/open_cv_demo.dir/src/main.cpp.o -c /Users/liyong/Code/Opencv/open_cv_demo/src/main.cpp

CMakeFiles/open_cv_demo.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/open_cv_demo.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liyong/Code/Opencv/open_cv_demo/src/main.cpp > CMakeFiles/open_cv_demo.dir/src/main.cpp.i

CMakeFiles/open_cv_demo.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/open_cv_demo.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liyong/Code/Opencv/open_cv_demo/src/main.cpp -o CMakeFiles/open_cv_demo.dir/src/main.cpp.s

CMakeFiles/open_cv_demo.dir/src/resize_img.cpp.o: CMakeFiles/open_cv_demo.dir/flags.make
CMakeFiles/open_cv_demo.dir/src/resize_img.cpp.o: ../src/resize_img.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liyong/Code/Opencv/open_cv_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/open_cv_demo.dir/src/resize_img.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/open_cv_demo.dir/src/resize_img.cpp.o -c /Users/liyong/Code/Opencv/open_cv_demo/src/resize_img.cpp

CMakeFiles/open_cv_demo.dir/src/resize_img.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/open_cv_demo.dir/src/resize_img.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liyong/Code/Opencv/open_cv_demo/src/resize_img.cpp > CMakeFiles/open_cv_demo.dir/src/resize_img.cpp.i

CMakeFiles/open_cv_demo.dir/src/resize_img.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/open_cv_demo.dir/src/resize_img.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liyong/Code/Opencv/open_cv_demo/src/resize_img.cpp -o CMakeFiles/open_cv_demo.dir/src/resize_img.cpp.s

CMakeFiles/open_cv_demo.dir/src/show_img.cpp.o: CMakeFiles/open_cv_demo.dir/flags.make
CMakeFiles/open_cv_demo.dir/src/show_img.cpp.o: ../src/show_img.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liyong/Code/Opencv/open_cv_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/open_cv_demo.dir/src/show_img.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/open_cv_demo.dir/src/show_img.cpp.o -c /Users/liyong/Code/Opencv/open_cv_demo/src/show_img.cpp

CMakeFiles/open_cv_demo.dir/src/show_img.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/open_cv_demo.dir/src/show_img.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liyong/Code/Opencv/open_cv_demo/src/show_img.cpp > CMakeFiles/open_cv_demo.dir/src/show_img.cpp.i

CMakeFiles/open_cv_demo.dir/src/show_img.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/open_cv_demo.dir/src/show_img.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liyong/Code/Opencv/open_cv_demo/src/show_img.cpp -o CMakeFiles/open_cv_demo.dir/src/show_img.cpp.s

# Object files for target open_cv_demo
open_cv_demo_OBJECTS = \
"CMakeFiles/open_cv_demo.dir/src/main.cpp.o" \
"CMakeFiles/open_cv_demo.dir/src/resize_img.cpp.o" \
"CMakeFiles/open_cv_demo.dir/src/show_img.cpp.o"

# External object files for target open_cv_demo
open_cv_demo_EXTERNAL_OBJECTS =

open_cv_demo: CMakeFiles/open_cv_demo.dir/src/main.cpp.o
open_cv_demo: CMakeFiles/open_cv_demo.dir/src/resize_img.cpp.o
open_cv_demo: CMakeFiles/open_cv_demo.dir/src/show_img.cpp.o
open_cv_demo: CMakeFiles/open_cv_demo.dir/build.make
open_cv_demo: /usr/local/lib/libopencv_dnn.4.3.0.dylib
open_cv_demo: /usr/local/lib/libopencv_gapi.4.3.0.dylib
open_cv_demo: /usr/local/lib/libopencv_highgui.4.3.0.dylib
open_cv_demo: /usr/local/lib/libopencv_ml.4.3.0.dylib
open_cv_demo: /usr/local/lib/libopencv_objdetect.4.3.0.dylib
open_cv_demo: /usr/local/lib/libopencv_photo.4.3.0.dylib
open_cv_demo: /usr/local/lib/libopencv_stitching.4.3.0.dylib
open_cv_demo: /usr/local/lib/libopencv_video.4.3.0.dylib
open_cv_demo: /usr/local/lib/libopencv_videoio.4.3.0.dylib
open_cv_demo: /usr/local/lib/libopencv_imgcodecs.4.3.0.dylib
open_cv_demo: /usr/local/lib/libopencv_calib3d.4.3.0.dylib
open_cv_demo: /usr/local/lib/libopencv_features2d.4.3.0.dylib
open_cv_demo: /usr/local/lib/libopencv_flann.4.3.0.dylib
open_cv_demo: /usr/local/lib/libopencv_imgproc.4.3.0.dylib
open_cv_demo: /usr/local/lib/libopencv_core.4.3.0.dylib
open_cv_demo: CMakeFiles/open_cv_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/liyong/Code/Opencv/open_cv_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable open_cv_demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/open_cv_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/open_cv_demo.dir/build: open_cv_demo

.PHONY : CMakeFiles/open_cv_demo.dir/build

CMakeFiles/open_cv_demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/open_cv_demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/open_cv_demo.dir/clean

CMakeFiles/open_cv_demo.dir/depend:
	cd /Users/liyong/Code/Opencv/open_cv_demo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/liyong/Code/Opencv/open_cv_demo /Users/liyong/Code/Opencv/open_cv_demo /Users/liyong/Code/Opencv/open_cv_demo/build /Users/liyong/Code/Opencv/open_cv_demo/build /Users/liyong/Code/Opencv/open_cv_demo/build/CMakeFiles/open_cv_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/open_cv_demo.dir/depend

