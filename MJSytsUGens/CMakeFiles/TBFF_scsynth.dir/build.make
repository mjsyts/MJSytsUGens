# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.29.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.29.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/josiahsytsma/TBFF/MJSytsUGens

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/josiahsytsma/TBFF/MJSytsUGens

# Include any dependencies generated for this target.
include CMakeFiles/TBFF_scsynth.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TBFF_scsynth.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TBFF_scsynth.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TBFF_scsynth.dir/flags.make

CMakeFiles/TBFF_scsynth.dir/plugins/TBFF/TBFF.cpp.o: CMakeFiles/TBFF_scsynth.dir/flags.make
CMakeFiles/TBFF_scsynth.dir/plugins/TBFF/TBFF.cpp.o: plugins/TBFF/TBFF.cpp
CMakeFiles/TBFF_scsynth.dir/plugins/TBFF/TBFF.cpp.o: CMakeFiles/TBFF_scsynth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/josiahsytsma/TBFF/MJSytsUGens/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TBFF_scsynth.dir/plugins/TBFF/TBFF.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TBFF_scsynth.dir/plugins/TBFF/TBFF.cpp.o -MF CMakeFiles/TBFF_scsynth.dir/plugins/TBFF/TBFF.cpp.o.d -o CMakeFiles/TBFF_scsynth.dir/plugins/TBFF/TBFF.cpp.o -c /Users/josiahsytsma/TBFF/MJSytsUGens/plugins/TBFF/TBFF.cpp

CMakeFiles/TBFF_scsynth.dir/plugins/TBFF/TBFF.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TBFF_scsynth.dir/plugins/TBFF/TBFF.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/josiahsytsma/TBFF/MJSytsUGens/plugins/TBFF/TBFF.cpp > CMakeFiles/TBFF_scsynth.dir/plugins/TBFF/TBFF.cpp.i

CMakeFiles/TBFF_scsynth.dir/plugins/TBFF/TBFF.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TBFF_scsynth.dir/plugins/TBFF/TBFF.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/josiahsytsma/TBFF/MJSytsUGens/plugins/TBFF/TBFF.cpp -o CMakeFiles/TBFF_scsynth.dir/plugins/TBFF/TBFF.cpp.s

# Object files for target TBFF_scsynth
TBFF_scsynth_OBJECTS = \
"CMakeFiles/TBFF_scsynth.dir/plugins/TBFF/TBFF.cpp.o"

# External object files for target TBFF_scsynth
TBFF_scsynth_EXTERNAL_OBJECTS =

TBFF_scsynth.scx: CMakeFiles/TBFF_scsynth.dir/plugins/TBFF/TBFF.cpp.o
TBFF_scsynth.scx: CMakeFiles/TBFF_scsynth.dir/build.make
TBFF_scsynth.scx: CMakeFiles/TBFF_scsynth.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/josiahsytsma/TBFF/MJSytsUGens/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared module TBFF_scsynth.scx"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TBFF_scsynth.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TBFF_scsynth.dir/build: TBFF_scsynth.scx
.PHONY : CMakeFiles/TBFF_scsynth.dir/build

CMakeFiles/TBFF_scsynth.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TBFF_scsynth.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TBFF_scsynth.dir/clean

CMakeFiles/TBFF_scsynth.dir/depend:
	cd /Users/josiahsytsma/TBFF/MJSytsUGens && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/josiahsytsma/TBFF/MJSytsUGens /Users/josiahsytsma/TBFF/MJSytsUGens /Users/josiahsytsma/TBFF/MJSytsUGens /Users/josiahsytsma/TBFF/MJSytsUGens /Users/josiahsytsma/TBFF/MJSytsUGens/CMakeFiles/TBFF_scsynth.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/TBFF_scsynth.dir/depend

