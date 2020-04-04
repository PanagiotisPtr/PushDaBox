# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.16.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.16.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/panagiotispetridis/Projects/cpp_cw/cw4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/panagiotispetridis/Projects/cpp_cw/cw4

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.16.3/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.16.3/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/panagiotispetridis/Projects/cpp_cw/cw4/CMakeFiles /Users/panagiotispetridis/Projects/cpp_cw/cw4/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/panagiotispetridis/Projects/cpp_cw/cw4/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named SDL2_App

# Build rule for target.
SDL2_App: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 SDL2_App
.PHONY : SDL2_App

# fast build rule for target.
SDL2_App/fast:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/build
.PHONY : SDL2_App/fast

src/BaseEngine.o: src/BaseEngine.cpp.o

.PHONY : src/BaseEngine.o

# target to build an object file
src/BaseEngine.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/BaseEngine.cpp.o
.PHONY : src/BaseEngine.cpp.o

src/BaseEngine.i: src/BaseEngine.cpp.i

.PHONY : src/BaseEngine.i

# target to preprocess a source file
src/BaseEngine.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/BaseEngine.cpp.i
.PHONY : src/BaseEngine.cpp.i

src/BaseEngine.s: src/BaseEngine.cpp.s

.PHONY : src/BaseEngine.s

# target to generate assembly for a file
src/BaseEngine.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/BaseEngine.cpp.s
.PHONY : src/BaseEngine.cpp.s

src/BouncingBall.o: src/BouncingBall.cpp.o

.PHONY : src/BouncingBall.o

# target to build an object file
src/BouncingBall.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/BouncingBall.cpp.o
.PHONY : src/BouncingBall.cpp.o

src/BouncingBall.i: src/BouncingBall.cpp.i

.PHONY : src/BouncingBall.i

# target to preprocess a source file
src/BouncingBall.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/BouncingBall.cpp.i
.PHONY : src/BouncingBall.cpp.i

src/BouncingBall.s: src/BouncingBall.cpp.s

.PHONY : src/BouncingBall.s

# target to generate assembly for a file
src/BouncingBall.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/BouncingBall.cpp.s
.PHONY : src/BouncingBall.cpp.s

src/BouncingBallMain.o: src/BouncingBallMain.cpp.o

.PHONY : src/BouncingBallMain.o

# target to build an object file
src/BouncingBallMain.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/BouncingBallMain.cpp.o
.PHONY : src/BouncingBallMain.cpp.o

src/BouncingBallMain.i: src/BouncingBallMain.cpp.i

.PHONY : src/BouncingBallMain.i

# target to preprocess a source file
src/BouncingBallMain.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/BouncingBallMain.cpp.i
.PHONY : src/BouncingBallMain.cpp.i

src/BouncingBallMain.s: src/BouncingBallMain.cpp.s

.PHONY : src/BouncingBallMain.s

# target to generate assembly for a file
src/BouncingBallMain.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/BouncingBallMain.cpp.s
.PHONY : src/BouncingBallMain.cpp.s

src/DisplayableObject.o: src/DisplayableObject.cpp.o

.PHONY : src/DisplayableObject.o

# target to build an object file
src/DisplayableObject.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/DisplayableObject.cpp.o
.PHONY : src/DisplayableObject.cpp.o

src/DisplayableObject.i: src/DisplayableObject.cpp.i

.PHONY : src/DisplayableObject.i

# target to preprocess a source file
src/DisplayableObject.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/DisplayableObject.cpp.i
.PHONY : src/DisplayableObject.cpp.i

src/DisplayableObject.s: src/DisplayableObject.cpp.s

.PHONY : src/DisplayableObject.s

# target to generate assembly for a file
src/DisplayableObject.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/DisplayableObject.cpp.s
.PHONY : src/DisplayableObject.cpp.s

src/DraggingDemo.o: src/DraggingDemo.cpp.o

.PHONY : src/DraggingDemo.o

# target to build an object file
src/DraggingDemo.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/DraggingDemo.cpp.o
.PHONY : src/DraggingDemo.cpp.o

src/DraggingDemo.i: src/DraggingDemo.cpp.i

.PHONY : src/DraggingDemo.i

# target to preprocess a source file
src/DraggingDemo.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/DraggingDemo.cpp.i
.PHONY : src/DraggingDemo.cpp.i

src/DraggingDemo.s: src/DraggingDemo.cpp.s

.PHONY : src/DraggingDemo.s

# target to generate assembly for a file
src/DraggingDemo.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/DraggingDemo.cpp.s
.PHONY : src/DraggingDemo.cpp.s

src/DrawingSurface.o: src/DrawingSurface.cpp.o

.PHONY : src/DrawingSurface.o

# target to build an object file
src/DrawingSurface.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/DrawingSurface.cpp.o
.PHONY : src/DrawingSurface.cpp.o

src/DrawingSurface.i: src/DrawingSurface.cpp.i

.PHONY : src/DrawingSurface.i

# target to preprocess a source file
src/DrawingSurface.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/DrawingSurface.cpp.i
.PHONY : src/DrawingSurface.cpp.i

src/DrawingSurface.s: src/DrawingSurface.cpp.s

.PHONY : src/DrawingSurface.s

# target to generate assembly for a file
src/DrawingSurface.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/DrawingSurface.cpp.s
.PHONY : src/DrawingSurface.cpp.s

src/FlashingDemo.o: src/FlashingDemo.cpp.o

.PHONY : src/FlashingDemo.o

# target to build an object file
src/FlashingDemo.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/FlashingDemo.cpp.o
.PHONY : src/FlashingDemo.cpp.o

src/FlashingDemo.i: src/FlashingDemo.cpp.i

.PHONY : src/FlashingDemo.i

# target to preprocess a source file
src/FlashingDemo.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/FlashingDemo.cpp.i
.PHONY : src/FlashingDemo.cpp.i

src/FlashingDemo.s: src/FlashingDemo.cpp.s

.PHONY : src/FlashingDemo.s

# target to generate assembly for a file
src/FlashingDemo.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/FlashingDemo.cpp.s
.PHONY : src/FlashingDemo.cpp.s

src/FontManager.o: src/FontManager.cpp.o

.PHONY : src/FontManager.o

# target to build an object file
src/FontManager.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/FontManager.cpp.o
.PHONY : src/FontManager.cpp.o

src/FontManager.i: src/FontManager.cpp.i

.PHONY : src/FontManager.i

# target to preprocess a source file
src/FontManager.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/FontManager.cpp.i
.PHONY : src/FontManager.cpp.i

src/FontManager.s: src/FontManager.cpp.s

.PHONY : src/FontManager.s

# target to generate assembly for a file
src/FontManager.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/FontManager.cpp.s
.PHONY : src/FontManager.cpp.s

src/ImageMappingDemo.o: src/ImageMappingDemo.cpp.o

.PHONY : src/ImageMappingDemo.o

# target to build an object file
src/ImageMappingDemo.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/ImageMappingDemo.cpp.o
.PHONY : src/ImageMappingDemo.cpp.o

src/ImageMappingDemo.i: src/ImageMappingDemo.cpp.i

.PHONY : src/ImageMappingDemo.i

# target to preprocess a source file
src/ImageMappingDemo.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/ImageMappingDemo.cpp.i
.PHONY : src/ImageMappingDemo.cpp.i

src/ImageMappingDemo.s: src/ImageMappingDemo.cpp.s

.PHONY : src/ImageMappingDemo.s

# target to generate assembly for a file
src/ImageMappingDemo.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/ImageMappingDemo.cpp.s
.PHONY : src/ImageMappingDemo.cpp.s

src/ImageObjectDemo.o: src/ImageObjectDemo.cpp.o

.PHONY : src/ImageObjectDemo.o

# target to build an object file
src/ImageObjectDemo.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/ImageObjectDemo.cpp.o
.PHONY : src/ImageObjectDemo.cpp.o

src/ImageObjectDemo.i: src/ImageObjectDemo.cpp.i

.PHONY : src/ImageObjectDemo.i

# target to preprocess a source file
src/ImageObjectDemo.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/ImageObjectDemo.cpp.i
.PHONY : src/ImageObjectDemo.cpp.i

src/ImageObjectDemo.s: src/ImageObjectDemo.cpp.s

.PHONY : src/ImageObjectDemo.s

# target to generate assembly for a file
src/ImageObjectDemo.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/ImageObjectDemo.cpp.s
.PHONY : src/ImageObjectDemo.cpp.s

src/JasonsDemoA.o: src/JasonsDemoA.cpp.o

.PHONY : src/JasonsDemoA.o

# target to build an object file
src/JasonsDemoA.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/JasonsDemoA.cpp.o
.PHONY : src/JasonsDemoA.cpp.o

src/JasonsDemoA.i: src/JasonsDemoA.cpp.i

.PHONY : src/JasonsDemoA.i

# target to preprocess a source file
src/JasonsDemoA.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/JasonsDemoA.cpp.i
.PHONY : src/JasonsDemoA.cpp.i

src/JasonsDemoA.s: src/JasonsDemoA.cpp.s

.PHONY : src/JasonsDemoA.s

# target to generate assembly for a file
src/JasonsDemoA.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/JasonsDemoA.cpp.s
.PHONY : src/JasonsDemoA.cpp.s

src/JasonsObjectA.o: src/JasonsObjectA.cpp.o

.PHONY : src/JasonsObjectA.o

# target to build an object file
src/JasonsObjectA.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/JasonsObjectA.cpp.o
.PHONY : src/JasonsObjectA.cpp.o

src/JasonsObjectA.i: src/JasonsObjectA.cpp.i

.PHONY : src/JasonsObjectA.i

# target to preprocess a source file
src/JasonsObjectA.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/JasonsObjectA.cpp.i
.PHONY : src/JasonsObjectA.cpp.i

src/JasonsObjectA.s: src/JasonsObjectA.cpp.s

.PHONY : src/JasonsObjectA.s

# target to generate assembly for a file
src/JasonsObjectA.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/JasonsObjectA.cpp.s
.PHONY : src/JasonsObjectA.cpp.s

src/JasonsTileManager.o: src/JasonsTileManager.cpp.o

.PHONY : src/JasonsTileManager.o

# target to build an object file
src/JasonsTileManager.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/JasonsTileManager.cpp.o
.PHONY : src/JasonsTileManager.cpp.o

src/JasonsTileManager.i: src/JasonsTileManager.cpp.i

.PHONY : src/JasonsTileManager.i

# target to preprocess a source file
src/JasonsTileManager.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/JasonsTileManager.cpp.i
.PHONY : src/JasonsTileManager.cpp.i

src/JasonsTileManager.s: src/JasonsTileManager.cpp.s

.PHONY : src/JasonsTileManager.s

# target to generate assembly for a file
src/JasonsTileManager.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/JasonsTileManager.cpp.s
.PHONY : src/JasonsTileManager.cpp.s

src/JigsawDemo.o: src/JigsawDemo.cpp.o

.PHONY : src/JigsawDemo.o

# target to build an object file
src/JigsawDemo.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/JigsawDemo.cpp.o
.PHONY : src/JigsawDemo.cpp.o

src/JigsawDemo.i: src/JigsawDemo.cpp.i

.PHONY : src/JigsawDemo.i

# target to preprocess a source file
src/JigsawDemo.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/JigsawDemo.cpp.i
.PHONY : src/JigsawDemo.cpp.i

src/JigsawDemo.s: src/JigsawDemo.cpp.s

.PHONY : src/JigsawDemo.s

# target to generate assembly for a file
src/JigsawDemo.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/JigsawDemo.cpp.s
.PHONY : src/JigsawDemo.cpp.s

src/MazeDemoMain.o: src/MazeDemoMain.cpp.o

.PHONY : src/MazeDemoMain.o

# target to build an object file
src/MazeDemoMain.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/MazeDemoMain.cpp.o
.PHONY : src/MazeDemoMain.cpp.o

src/MazeDemoMain.i: src/MazeDemoMain.cpp.i

.PHONY : src/MazeDemoMain.i

# target to preprocess a source file
src/MazeDemoMain.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/MazeDemoMain.cpp.i
.PHONY : src/MazeDemoMain.cpp.i

src/MazeDemoMain.s: src/MazeDemoMain.cpp.s

.PHONY : src/MazeDemoMain.s

# target to generate assembly for a file
src/MazeDemoMain.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/MazeDemoMain.cpp.s
.PHONY : src/MazeDemoMain.cpp.s

src/MazeDemoObject.o: src/MazeDemoObject.cpp.o

.PHONY : src/MazeDemoObject.o

# target to build an object file
src/MazeDemoObject.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/MazeDemoObject.cpp.o
.PHONY : src/MazeDemoObject.cpp.o

src/MazeDemoObject.i: src/MazeDemoObject.cpp.i

.PHONY : src/MazeDemoObject.i

# target to preprocess a source file
src/MazeDemoObject.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/MazeDemoObject.cpp.i
.PHONY : src/MazeDemoObject.cpp.i

src/MazeDemoObject.s: src/MazeDemoObject.cpp.s

.PHONY : src/MazeDemoObject.s

# target to generate assembly for a file
src/MazeDemoObject.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/MazeDemoObject.cpp.s
.PHONY : src/MazeDemoObject.cpp.s

src/MazeDemoTileManager.o: src/MazeDemoTileManager.cpp.o

.PHONY : src/MazeDemoTileManager.o

# target to build an object file
src/MazeDemoTileManager.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/MazeDemoTileManager.cpp.o
.PHONY : src/MazeDemoTileManager.cpp.o

src/MazeDemoTileManager.i: src/MazeDemoTileManager.cpp.i

.PHONY : src/MazeDemoTileManager.i

# target to preprocess a source file
src/MazeDemoTileManager.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/MazeDemoTileManager.cpp.i
.PHONY : src/MazeDemoTileManager.cpp.i

src/MazeDemoTileManager.s: src/MazeDemoTileManager.cpp.s

.PHONY : src/MazeDemoTileManager.s

# target to generate assembly for a file
src/MazeDemoTileManager.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/MazeDemoTileManager.cpp.s
.PHONY : src/MazeDemoTileManager.cpp.s

src/PlayingCardsDemo.o: src/PlayingCardsDemo.cpp.o

.PHONY : src/PlayingCardsDemo.o

# target to build an object file
src/PlayingCardsDemo.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/PlayingCardsDemo.cpp.o
.PHONY : src/PlayingCardsDemo.cpp.o

src/PlayingCardsDemo.i: src/PlayingCardsDemo.cpp.i

.PHONY : src/PlayingCardsDemo.i

# target to preprocess a source file
src/PlayingCardsDemo.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/PlayingCardsDemo.cpp.i
.PHONY : src/PlayingCardsDemo.cpp.i

src/PlayingCardsDemo.s: src/PlayingCardsDemo.cpp.s

.PHONY : src/PlayingCardsDemo.s

# target to generate assembly for a file
src/PlayingCardsDemo.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/PlayingCardsDemo.cpp.s
.PHONY : src/PlayingCardsDemo.cpp.s

src/RawImage.o: src/RawImage.cpp.o

.PHONY : src/RawImage.o

# target to build an object file
src/RawImage.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/RawImage.cpp.o
.PHONY : src/RawImage.cpp.o

src/RawImage.i: src/RawImage.cpp.i

.PHONY : src/RawImage.i

# target to preprocess a source file
src/RawImage.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/RawImage.cpp.i
.PHONY : src/RawImage.cpp.i

src/RawImage.s: src/RawImage.cpp.s

.PHONY : src/RawImage.s

# target to generate assembly for a file
src/RawImage.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/RawImage.cpp.s
.PHONY : src/RawImage.cpp.s

src/SimpleDemo.o: src/SimpleDemo.cpp.o

.PHONY : src/SimpleDemo.o

# target to build an object file
src/SimpleDemo.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/SimpleDemo.cpp.o
.PHONY : src/SimpleDemo.cpp.o

src/SimpleDemo.i: src/SimpleDemo.cpp.i

.PHONY : src/SimpleDemo.i

# target to preprocess a source file
src/SimpleDemo.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/SimpleDemo.cpp.i
.PHONY : src/SimpleDemo.cpp.i

src/SimpleDemo.s: src/SimpleDemo.cpp.s

.PHONY : src/SimpleDemo.s

# target to generate assembly for a file
src/SimpleDemo.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/SimpleDemo.cpp.s
.PHONY : src/SimpleDemo.cpp.s

src/SimpleImage.o: src/SimpleImage.cpp.o

.PHONY : src/SimpleImage.o

# target to build an object file
src/SimpleImage.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/SimpleImage.cpp.o
.PHONY : src/SimpleImage.cpp.o

src/SimpleImage.i: src/SimpleImage.cpp.i

.PHONY : src/SimpleImage.i

# target to preprocess a source file
src/SimpleImage.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/SimpleImage.cpp.i
.PHONY : src/SimpleImage.cpp.i

src/SimpleImage.s: src/SimpleImage.cpp.s

.PHONY : src/SimpleImage.s

# target to generate assembly for a file
src/SimpleImage.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/SimpleImage.cpp.s
.PHONY : src/SimpleImage.cpp.s

src/StarfieldDemo.o: src/StarfieldDemo.cpp.o

.PHONY : src/StarfieldDemo.o

# target to build an object file
src/StarfieldDemo.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/StarfieldDemo.cpp.o
.PHONY : src/StarfieldDemo.cpp.o

src/StarfieldDemo.i: src/StarfieldDemo.cpp.i

.PHONY : src/StarfieldDemo.i

# target to preprocess a source file
src/StarfieldDemo.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/StarfieldDemo.cpp.i
.PHONY : src/StarfieldDemo.cpp.i

src/StarfieldDemo.s: src/StarfieldDemo.cpp.s

.PHONY : src/StarfieldDemo.s

# target to generate assembly for a file
src/StarfieldDemo.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/StarfieldDemo.cpp.s
.PHONY : src/StarfieldDemo.cpp.s

src/TileManager.o: src/TileManager.cpp.o

.PHONY : src/TileManager.o

# target to build an object file
src/TileManager.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/TileManager.cpp.o
.PHONY : src/TileManager.cpp.o

src/TileManager.i: src/TileManager.cpp.i

.PHONY : src/TileManager.i

# target to preprocess a source file
src/TileManager.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/TileManager.cpp.i
.PHONY : src/TileManager.cpp.i

src/TileManager.s: src/TileManager.cpp.s

.PHONY : src/TileManager.s

# target to generate assembly for a file
src/TileManager.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/TileManager.cpp.s
.PHONY : src/TileManager.cpp.s

src/ZoomingDemo.o: src/ZoomingDemo.cpp.o

.PHONY : src/ZoomingDemo.o

# target to build an object file
src/ZoomingDemo.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/ZoomingDemo.cpp.o
.PHONY : src/ZoomingDemo.cpp.o

src/ZoomingDemo.i: src/ZoomingDemo.cpp.i

.PHONY : src/ZoomingDemo.i

# target to preprocess a source file
src/ZoomingDemo.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/ZoomingDemo.cpp.i
.PHONY : src/ZoomingDemo.cpp.i

src/ZoomingDemo.s: src/ZoomingDemo.cpp.s

.PHONY : src/ZoomingDemo.s

# target to generate assembly for a file
src/ZoomingDemo.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/ZoomingDemo.cpp.s
.PHONY : src/ZoomingDemo.cpp.s

src/mainfunction.o: src/mainfunction.cpp.o

.PHONY : src/mainfunction.o

# target to build an object file
src/mainfunction.cpp.o:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/mainfunction.cpp.o
.PHONY : src/mainfunction.cpp.o

src/mainfunction.i: src/mainfunction.cpp.i

.PHONY : src/mainfunction.i

# target to preprocess a source file
src/mainfunction.cpp.i:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/mainfunction.cpp.i
.PHONY : src/mainfunction.cpp.i

src/mainfunction.s: src/mainfunction.cpp.s

.PHONY : src/mainfunction.s

# target to generate assembly for a file
src/mainfunction.cpp.s:
	$(MAKE) -f CMakeFiles/SDL2_App.dir/build.make CMakeFiles/SDL2_App.dir/src/mainfunction.cpp.s
.PHONY : src/mainfunction.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... SDL2_App"
	@echo "... src/BaseEngine.o"
	@echo "... src/BaseEngine.i"
	@echo "... src/BaseEngine.s"
	@echo "... src/BouncingBall.o"
	@echo "... src/BouncingBall.i"
	@echo "... src/BouncingBall.s"
	@echo "... src/BouncingBallMain.o"
	@echo "... src/BouncingBallMain.i"
	@echo "... src/BouncingBallMain.s"
	@echo "... src/DisplayableObject.o"
	@echo "... src/DisplayableObject.i"
	@echo "... src/DisplayableObject.s"
	@echo "... src/DraggingDemo.o"
	@echo "... src/DraggingDemo.i"
	@echo "... src/DraggingDemo.s"
	@echo "... src/DrawingSurface.o"
	@echo "... src/DrawingSurface.i"
	@echo "... src/DrawingSurface.s"
	@echo "... src/FlashingDemo.o"
	@echo "... src/FlashingDemo.i"
	@echo "... src/FlashingDemo.s"
	@echo "... src/FontManager.o"
	@echo "... src/FontManager.i"
	@echo "... src/FontManager.s"
	@echo "... src/ImageMappingDemo.o"
	@echo "... src/ImageMappingDemo.i"
	@echo "... src/ImageMappingDemo.s"
	@echo "... src/ImageObjectDemo.o"
	@echo "... src/ImageObjectDemo.i"
	@echo "... src/ImageObjectDemo.s"
	@echo "... src/JasonsDemoA.o"
	@echo "... src/JasonsDemoA.i"
	@echo "... src/JasonsDemoA.s"
	@echo "... src/JasonsObjectA.o"
	@echo "... src/JasonsObjectA.i"
	@echo "... src/JasonsObjectA.s"
	@echo "... src/JasonsTileManager.o"
	@echo "... src/JasonsTileManager.i"
	@echo "... src/JasonsTileManager.s"
	@echo "... src/JigsawDemo.o"
	@echo "... src/JigsawDemo.i"
	@echo "... src/JigsawDemo.s"
	@echo "... src/MazeDemoMain.o"
	@echo "... src/MazeDemoMain.i"
	@echo "... src/MazeDemoMain.s"
	@echo "... src/MazeDemoObject.o"
	@echo "... src/MazeDemoObject.i"
	@echo "... src/MazeDemoObject.s"
	@echo "... src/MazeDemoTileManager.o"
	@echo "... src/MazeDemoTileManager.i"
	@echo "... src/MazeDemoTileManager.s"
	@echo "... src/PlayingCardsDemo.o"
	@echo "... src/PlayingCardsDemo.i"
	@echo "... src/PlayingCardsDemo.s"
	@echo "... src/RawImage.o"
	@echo "... src/RawImage.i"
	@echo "... src/RawImage.s"
	@echo "... src/SimpleDemo.o"
	@echo "... src/SimpleDemo.i"
	@echo "... src/SimpleDemo.s"
	@echo "... src/SimpleImage.o"
	@echo "... src/SimpleImage.i"
	@echo "... src/SimpleImage.s"
	@echo "... src/StarfieldDemo.o"
	@echo "... src/StarfieldDemo.i"
	@echo "... src/StarfieldDemo.s"
	@echo "... src/TileManager.o"
	@echo "... src/TileManager.i"
	@echo "... src/TileManager.s"
	@echo "... src/ZoomingDemo.o"
	@echo "... src/ZoomingDemo.i"
	@echo "... src/ZoomingDemo.s"
	@echo "... src/mainfunction.o"
	@echo "... src/mainfunction.i"
	@echo "... src/mainfunction.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

