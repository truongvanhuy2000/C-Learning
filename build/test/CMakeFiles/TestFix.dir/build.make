# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\C++\GoogleTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\C++\build

# Include any dependencies generated for this target.
include test/CMakeFiles/TestFix.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/TestFix.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/TestFix.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/TestFix.dir/flags.make

test/CMakeFiles/TestFix.dir/SImpleTest.cpp.obj: test/CMakeFiles/TestFix.dir/flags.make
test/CMakeFiles/TestFix.dir/SImpleTest.cpp.obj: test/CMakeFiles/TestFix.dir/includes_CXX.rsp
test/CMakeFiles/TestFix.dir/SImpleTest.cpp.obj: D:/C++/GoogleTest/test/SImpleTest.cpp
test/CMakeFiles/TestFix.dir/SImpleTest.cpp.obj: test/CMakeFiles/TestFix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\C++\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/TestFix.dir/SImpleTest.cpp.obj"
	cd /d D:\C++\build\test && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/TestFix.dir/SImpleTest.cpp.obj -MF CMakeFiles\TestFix.dir\SImpleTest.cpp.obj.d -o CMakeFiles\TestFix.dir\SImpleTest.cpp.obj -c D:\C++\GoogleTest\test\SImpleTest.cpp

test/CMakeFiles/TestFix.dir/SImpleTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestFix.dir/SImpleTest.cpp.i"
	cd /d D:\C++\build\test && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\C++\GoogleTest\test\SImpleTest.cpp > CMakeFiles\TestFix.dir\SImpleTest.cpp.i

test/CMakeFiles/TestFix.dir/SImpleTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestFix.dir/SImpleTest.cpp.s"
	cd /d D:\C++\build\test && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\C++\GoogleTest\test\SImpleTest.cpp -o CMakeFiles\TestFix.dir\SImpleTest.cpp.s

# Object files for target TestFix
TestFix_OBJECTS = \
"CMakeFiles/TestFix.dir/SImpleTest.cpp.obj"

# External object files for target TestFix
TestFix_EXTERNAL_OBJECTS =

test/TestFix.exe: test/CMakeFiles/TestFix.dir/SImpleTest.cpp.obj
test/TestFix.exe: test/CMakeFiles/TestFix.dir/build.make
test/TestFix.exe: lib/libgtest_main.a
test/TestFix.exe: libExample.a
test/TestFix.exe: lib/libgtest.a
test/TestFix.exe: test/CMakeFiles/TestFix.dir/linklibs.rsp
test/TestFix.exe: test/CMakeFiles/TestFix.dir/objects1.rsp
test/TestFix.exe: test/CMakeFiles/TestFix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\C++\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestFix.exe"
	cd /d D:\C++\build\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TestFix.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/TestFix.dir/build: test/TestFix.exe
.PHONY : test/CMakeFiles/TestFix.dir/build

test/CMakeFiles/TestFix.dir/clean:
	cd /d D:\C++\build\test && $(CMAKE_COMMAND) -P CMakeFiles\TestFix.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/TestFix.dir/clean

test/CMakeFiles/TestFix.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\C++\GoogleTest D:\C++\GoogleTest\test D:\C++\build D:\C++\build\test D:\C++\build\test\CMakeFiles\TestFix.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/TestFix.dir/depend

