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
CMAKE_COMMAND = /home/lab307/DJY/Clion/clion-2020.1.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/lab307/DJY/Clion/clion-2020.1.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lab307/DJY/code/clion_pro/disp_self

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lab307/DJY/code/clion_pro/disp_self/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/opencv_demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/opencv_demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opencv_demo.dir/flags.make

CMakeFiles/opencv_demo.dir/main.cpp.o: CMakeFiles/opencv_demo.dir/flags.make
CMakeFiles/opencv_demo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lab307/DJY/code/clion_pro/disp_self/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/opencv_demo.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_demo.dir/main.cpp.o -c /home/lab307/DJY/code/clion_pro/disp_self/main.cpp

CMakeFiles/opencv_demo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_demo.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lab307/DJY/code/clion_pro/disp_self/main.cpp > CMakeFiles/opencv_demo.dir/main.cpp.i

CMakeFiles/opencv_demo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_demo.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lab307/DJY/code/clion_pro/disp_self/main.cpp -o CMakeFiles/opencv_demo.dir/main.cpp.s

CMakeFiles/opencv_demo.dir/census.cpp.o: CMakeFiles/opencv_demo.dir/flags.make
CMakeFiles/opencv_demo.dir/census.cpp.o: ../census.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lab307/DJY/code/clion_pro/disp_self/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/opencv_demo.dir/census.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_demo.dir/census.cpp.o -c /home/lab307/DJY/code/clion_pro/disp_self/census.cpp

CMakeFiles/opencv_demo.dir/census.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_demo.dir/census.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lab307/DJY/code/clion_pro/disp_self/census.cpp > CMakeFiles/opencv_demo.dir/census.cpp.i

CMakeFiles/opencv_demo.dir/census.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_demo.dir/census.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lab307/DJY/code/clion_pro/disp_self/census.cpp -o CMakeFiles/opencv_demo.dir/census.cpp.s

CMakeFiles/opencv_demo.dir/dispart_estimate.cpp.o: CMakeFiles/opencv_demo.dir/flags.make
CMakeFiles/opencv_demo.dir/dispart_estimate.cpp.o: ../dispart_estimate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lab307/DJY/code/clion_pro/disp_self/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/opencv_demo.dir/dispart_estimate.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_demo.dir/dispart_estimate.cpp.o -c /home/lab307/DJY/code/clion_pro/disp_self/dispart_estimate.cpp

CMakeFiles/opencv_demo.dir/dispart_estimate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_demo.dir/dispart_estimate.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lab307/DJY/code/clion_pro/disp_self/dispart_estimate.cpp > CMakeFiles/opencv_demo.dir/dispart_estimate.cpp.i

CMakeFiles/opencv_demo.dir/dispart_estimate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_demo.dir/dispart_estimate.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lab307/DJY/code/clion_pro/disp_self/dispart_estimate.cpp -o CMakeFiles/opencv_demo.dir/dispart_estimate.cpp.s

# Object files for target opencv_demo
opencv_demo_OBJECTS = \
"CMakeFiles/opencv_demo.dir/main.cpp.o" \
"CMakeFiles/opencv_demo.dir/census.cpp.o" \
"CMakeFiles/opencv_demo.dir/dispart_estimate.cpp.o"

# External object files for target opencv_demo
opencv_demo_EXTERNAL_OBJECTS =

opencv_demo: CMakeFiles/opencv_demo.dir/main.cpp.o
opencv_demo: CMakeFiles/opencv_demo.dir/census.cpp.o
opencv_demo: CMakeFiles/opencv_demo.dir/dispart_estimate.cpp.o
opencv_demo: CMakeFiles/opencv_demo.dir/build.make
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_cudabgsegm.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_cudaobjdetect.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_cudastereo.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_stitching.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_superres.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_videostab.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_aruco.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_bgsegm.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_bioinspired.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_ccalib.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_dnn_objdetect.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_dpm.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_face.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_freetype.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_fuzzy.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_hdf.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_hfs.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_img_hash.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_line_descriptor.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_optflow.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_reg.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_rgbd.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_saliency.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_stereo.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_structured_light.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_surface_matching.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_tracking.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_xfeatures2d.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_ximgproc.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_xobjdetect.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_xphoto.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_cudafeatures2d.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_shape.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_cudacodec.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_cudaoptflow.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_cudalegacy.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_cudawarping.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_highgui.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_videoio.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_phase_unwrapping.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_video.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_datasets.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_plot.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_text.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_dnn.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_ml.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_imgcodecs.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_objdetect.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_calib3d.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_features2d.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_flann.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_photo.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_cudaimgproc.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_cudafilters.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_cudaarithm.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_imgproc.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_core.so.3.4.11
opencv_demo: /home/lab307/DJY/opencv3411/debug/lib/libopencv_cudev.so.3.4.11
opencv_demo: CMakeFiles/opencv_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lab307/DJY/code/clion_pro/disp_self/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable opencv_demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opencv_demo.dir/build: opencv_demo

.PHONY : CMakeFiles/opencv_demo.dir/build

CMakeFiles/opencv_demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opencv_demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opencv_demo.dir/clean

CMakeFiles/opencv_demo.dir/depend:
	cd /home/lab307/DJY/code/clion_pro/disp_self/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lab307/DJY/code/clion_pro/disp_self /home/lab307/DJY/code/clion_pro/disp_self /home/lab307/DJY/code/clion_pro/disp_self/cmake-build-debug /home/lab307/DJY/code/clion_pro/disp_self/cmake-build-debug /home/lab307/DJY/code/clion_pro/disp_self/cmake-build-debug/CMakeFiles/opencv_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opencv_demo.dir/depend

