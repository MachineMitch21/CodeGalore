# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/mitch/Documents/GameEngineStuff/Antisocial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mitch/Documents/GameEngineStuff/Antisocial/build

# Include any dependencies generated for this target.
include CMakeFiles/antisocial.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/antisocial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/antisocial.dir/flags.make

CMakeFiles/antisocial.dir/src/Application.cpp.o: CMakeFiles/antisocial.dir/flags.make
CMakeFiles/antisocial.dir/src/Application.cpp.o: ../src/Application.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mitch/Documents/GameEngineStuff/Antisocial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/antisocial.dir/src/Application.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/antisocial.dir/src/Application.cpp.o -c /home/mitch/Documents/GameEngineStuff/Antisocial/src/Application.cpp

CMakeFiles/antisocial.dir/src/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antisocial.dir/src/Application.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mitch/Documents/GameEngineStuff/Antisocial/src/Application.cpp > CMakeFiles/antisocial.dir/src/Application.cpp.i

CMakeFiles/antisocial.dir/src/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antisocial.dir/src/Application.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mitch/Documents/GameEngineStuff/Antisocial/src/Application.cpp -o CMakeFiles/antisocial.dir/src/Application.cpp.s

CMakeFiles/antisocial.dir/src/Application.cpp.o.requires:

.PHONY : CMakeFiles/antisocial.dir/src/Application.cpp.o.requires

CMakeFiles/antisocial.dir/src/Application.cpp.o.provides: CMakeFiles/antisocial.dir/src/Application.cpp.o.requires
	$(MAKE) -f CMakeFiles/antisocial.dir/build.make CMakeFiles/antisocial.dir/src/Application.cpp.o.provides.build
.PHONY : CMakeFiles/antisocial.dir/src/Application.cpp.o.provides

CMakeFiles/antisocial.dir/src/Application.cpp.o.provides.build: CMakeFiles/antisocial.dir/src/Application.cpp.o


CMakeFiles/antisocial.dir/src/AssetLoader.cpp.o: CMakeFiles/antisocial.dir/flags.make
CMakeFiles/antisocial.dir/src/AssetLoader.cpp.o: ../src/AssetLoader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mitch/Documents/GameEngineStuff/Antisocial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/antisocial.dir/src/AssetLoader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/antisocial.dir/src/AssetLoader.cpp.o -c /home/mitch/Documents/GameEngineStuff/Antisocial/src/AssetLoader.cpp

CMakeFiles/antisocial.dir/src/AssetLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antisocial.dir/src/AssetLoader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mitch/Documents/GameEngineStuff/Antisocial/src/AssetLoader.cpp > CMakeFiles/antisocial.dir/src/AssetLoader.cpp.i

CMakeFiles/antisocial.dir/src/AssetLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antisocial.dir/src/AssetLoader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mitch/Documents/GameEngineStuff/Antisocial/src/AssetLoader.cpp -o CMakeFiles/antisocial.dir/src/AssetLoader.cpp.s

CMakeFiles/antisocial.dir/src/AssetLoader.cpp.o.requires:

.PHONY : CMakeFiles/antisocial.dir/src/AssetLoader.cpp.o.requires

CMakeFiles/antisocial.dir/src/AssetLoader.cpp.o.provides: CMakeFiles/antisocial.dir/src/AssetLoader.cpp.o.requires
	$(MAKE) -f CMakeFiles/antisocial.dir/build.make CMakeFiles/antisocial.dir/src/AssetLoader.cpp.o.provides.build
.PHONY : CMakeFiles/antisocial.dir/src/AssetLoader.cpp.o.provides

CMakeFiles/antisocial.dir/src/AssetLoader.cpp.o.provides.build: CMakeFiles/antisocial.dir/src/AssetLoader.cpp.o


CMakeFiles/antisocial.dir/src/Mesh.cpp.o: CMakeFiles/antisocial.dir/flags.make
CMakeFiles/antisocial.dir/src/Mesh.cpp.o: ../src/Mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mitch/Documents/GameEngineStuff/Antisocial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/antisocial.dir/src/Mesh.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/antisocial.dir/src/Mesh.cpp.o -c /home/mitch/Documents/GameEngineStuff/Antisocial/src/Mesh.cpp

CMakeFiles/antisocial.dir/src/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antisocial.dir/src/Mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mitch/Documents/GameEngineStuff/Antisocial/src/Mesh.cpp > CMakeFiles/antisocial.dir/src/Mesh.cpp.i

CMakeFiles/antisocial.dir/src/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antisocial.dir/src/Mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mitch/Documents/GameEngineStuff/Antisocial/src/Mesh.cpp -o CMakeFiles/antisocial.dir/src/Mesh.cpp.s

CMakeFiles/antisocial.dir/src/Mesh.cpp.o.requires:

.PHONY : CMakeFiles/antisocial.dir/src/Mesh.cpp.o.requires

CMakeFiles/antisocial.dir/src/Mesh.cpp.o.provides: CMakeFiles/antisocial.dir/src/Mesh.cpp.o.requires
	$(MAKE) -f CMakeFiles/antisocial.dir/build.make CMakeFiles/antisocial.dir/src/Mesh.cpp.o.provides.build
.PHONY : CMakeFiles/antisocial.dir/src/Mesh.cpp.o.provides

CMakeFiles/antisocial.dir/src/Mesh.cpp.o.provides.build: CMakeFiles/antisocial.dir/src/Mesh.cpp.o


CMakeFiles/antisocial.dir/src/Model.cpp.o: CMakeFiles/antisocial.dir/flags.make
CMakeFiles/antisocial.dir/src/Model.cpp.o: ../src/Model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mitch/Documents/GameEngineStuff/Antisocial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/antisocial.dir/src/Model.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/antisocial.dir/src/Model.cpp.o -c /home/mitch/Documents/GameEngineStuff/Antisocial/src/Model.cpp

CMakeFiles/antisocial.dir/src/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antisocial.dir/src/Model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mitch/Documents/GameEngineStuff/Antisocial/src/Model.cpp > CMakeFiles/antisocial.dir/src/Model.cpp.i

CMakeFiles/antisocial.dir/src/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antisocial.dir/src/Model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mitch/Documents/GameEngineStuff/Antisocial/src/Model.cpp -o CMakeFiles/antisocial.dir/src/Model.cpp.s

CMakeFiles/antisocial.dir/src/Model.cpp.o.requires:

.PHONY : CMakeFiles/antisocial.dir/src/Model.cpp.o.requires

CMakeFiles/antisocial.dir/src/Model.cpp.o.provides: CMakeFiles/antisocial.dir/src/Model.cpp.o.requires
	$(MAKE) -f CMakeFiles/antisocial.dir/build.make CMakeFiles/antisocial.dir/src/Model.cpp.o.provides.build
.PHONY : CMakeFiles/antisocial.dir/src/Model.cpp.o.provides

CMakeFiles/antisocial.dir/src/Model.cpp.o.provides.build: CMakeFiles/antisocial.dir/src/Model.cpp.o


CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.o: CMakeFiles/antisocial.dir/flags.make
CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.o: ../src/PrimitiveCreator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mitch/Documents/GameEngineStuff/Antisocial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.o -c /home/mitch/Documents/GameEngineStuff/Antisocial/src/PrimitiveCreator.cpp

CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mitch/Documents/GameEngineStuff/Antisocial/src/PrimitiveCreator.cpp > CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.i

CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mitch/Documents/GameEngineStuff/Antisocial/src/PrimitiveCreator.cpp -o CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.s

CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.o.requires:

.PHONY : CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.o.requires

CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.o.provides: CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.o.requires
	$(MAKE) -f CMakeFiles/antisocial.dir/build.make CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.o.provides.build
.PHONY : CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.o.provides

CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.o.provides.build: CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.o


CMakeFiles/antisocial.dir/src/Renderer.cpp.o: CMakeFiles/antisocial.dir/flags.make
CMakeFiles/antisocial.dir/src/Renderer.cpp.o: ../src/Renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mitch/Documents/GameEngineStuff/Antisocial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/antisocial.dir/src/Renderer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/antisocial.dir/src/Renderer.cpp.o -c /home/mitch/Documents/GameEngineStuff/Antisocial/src/Renderer.cpp

CMakeFiles/antisocial.dir/src/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antisocial.dir/src/Renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mitch/Documents/GameEngineStuff/Antisocial/src/Renderer.cpp > CMakeFiles/antisocial.dir/src/Renderer.cpp.i

CMakeFiles/antisocial.dir/src/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antisocial.dir/src/Renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mitch/Documents/GameEngineStuff/Antisocial/src/Renderer.cpp -o CMakeFiles/antisocial.dir/src/Renderer.cpp.s

CMakeFiles/antisocial.dir/src/Renderer.cpp.o.requires:

.PHONY : CMakeFiles/antisocial.dir/src/Renderer.cpp.o.requires

CMakeFiles/antisocial.dir/src/Renderer.cpp.o.provides: CMakeFiles/antisocial.dir/src/Renderer.cpp.o.requires
	$(MAKE) -f CMakeFiles/antisocial.dir/build.make CMakeFiles/antisocial.dir/src/Renderer.cpp.o.provides.build
.PHONY : CMakeFiles/antisocial.dir/src/Renderer.cpp.o.provides

CMakeFiles/antisocial.dir/src/Renderer.cpp.o.provides.build: CMakeFiles/antisocial.dir/src/Renderer.cpp.o


CMakeFiles/antisocial.dir/src/Shader.cpp.o: CMakeFiles/antisocial.dir/flags.make
CMakeFiles/antisocial.dir/src/Shader.cpp.o: ../src/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mitch/Documents/GameEngineStuff/Antisocial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/antisocial.dir/src/Shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/antisocial.dir/src/Shader.cpp.o -c /home/mitch/Documents/GameEngineStuff/Antisocial/src/Shader.cpp

CMakeFiles/antisocial.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antisocial.dir/src/Shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mitch/Documents/GameEngineStuff/Antisocial/src/Shader.cpp > CMakeFiles/antisocial.dir/src/Shader.cpp.i

CMakeFiles/antisocial.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antisocial.dir/src/Shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mitch/Documents/GameEngineStuff/Antisocial/src/Shader.cpp -o CMakeFiles/antisocial.dir/src/Shader.cpp.s

CMakeFiles/antisocial.dir/src/Shader.cpp.o.requires:

.PHONY : CMakeFiles/antisocial.dir/src/Shader.cpp.o.requires

CMakeFiles/antisocial.dir/src/Shader.cpp.o.provides: CMakeFiles/antisocial.dir/src/Shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/antisocial.dir/build.make CMakeFiles/antisocial.dir/src/Shader.cpp.o.provides.build
.PHONY : CMakeFiles/antisocial.dir/src/Shader.cpp.o.provides

CMakeFiles/antisocial.dir/src/Shader.cpp.o.provides.build: CMakeFiles/antisocial.dir/src/Shader.cpp.o


CMakeFiles/antisocial.dir/src/Texture2D.cpp.o: CMakeFiles/antisocial.dir/flags.make
CMakeFiles/antisocial.dir/src/Texture2D.cpp.o: ../src/Texture2D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mitch/Documents/GameEngineStuff/Antisocial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/antisocial.dir/src/Texture2D.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/antisocial.dir/src/Texture2D.cpp.o -c /home/mitch/Documents/GameEngineStuff/Antisocial/src/Texture2D.cpp

CMakeFiles/antisocial.dir/src/Texture2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antisocial.dir/src/Texture2D.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mitch/Documents/GameEngineStuff/Antisocial/src/Texture2D.cpp > CMakeFiles/antisocial.dir/src/Texture2D.cpp.i

CMakeFiles/antisocial.dir/src/Texture2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antisocial.dir/src/Texture2D.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mitch/Documents/GameEngineStuff/Antisocial/src/Texture2D.cpp -o CMakeFiles/antisocial.dir/src/Texture2D.cpp.s

CMakeFiles/antisocial.dir/src/Texture2D.cpp.o.requires:

.PHONY : CMakeFiles/antisocial.dir/src/Texture2D.cpp.o.requires

CMakeFiles/antisocial.dir/src/Texture2D.cpp.o.provides: CMakeFiles/antisocial.dir/src/Texture2D.cpp.o.requires
	$(MAKE) -f CMakeFiles/antisocial.dir/build.make CMakeFiles/antisocial.dir/src/Texture2D.cpp.o.provides.build
.PHONY : CMakeFiles/antisocial.dir/src/Texture2D.cpp.o.provides

CMakeFiles/antisocial.dir/src/Texture2D.cpp.o.provides.build: CMakeFiles/antisocial.dir/src/Texture2D.cpp.o


CMakeFiles/antisocial.dir/src/Transform.cpp.o: CMakeFiles/antisocial.dir/flags.make
CMakeFiles/antisocial.dir/src/Transform.cpp.o: ../src/Transform.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mitch/Documents/GameEngineStuff/Antisocial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/antisocial.dir/src/Transform.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/antisocial.dir/src/Transform.cpp.o -c /home/mitch/Documents/GameEngineStuff/Antisocial/src/Transform.cpp

CMakeFiles/antisocial.dir/src/Transform.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antisocial.dir/src/Transform.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mitch/Documents/GameEngineStuff/Antisocial/src/Transform.cpp > CMakeFiles/antisocial.dir/src/Transform.cpp.i

CMakeFiles/antisocial.dir/src/Transform.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antisocial.dir/src/Transform.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mitch/Documents/GameEngineStuff/Antisocial/src/Transform.cpp -o CMakeFiles/antisocial.dir/src/Transform.cpp.s

CMakeFiles/antisocial.dir/src/Transform.cpp.o.requires:

.PHONY : CMakeFiles/antisocial.dir/src/Transform.cpp.o.requires

CMakeFiles/antisocial.dir/src/Transform.cpp.o.provides: CMakeFiles/antisocial.dir/src/Transform.cpp.o.requires
	$(MAKE) -f CMakeFiles/antisocial.dir/build.make CMakeFiles/antisocial.dir/src/Transform.cpp.o.provides.build
.PHONY : CMakeFiles/antisocial.dir/src/Transform.cpp.o.provides

CMakeFiles/antisocial.dir/src/Transform.cpp.o.provides.build: CMakeFiles/antisocial.dir/src/Transform.cpp.o


CMakeFiles/antisocial.dir/src/Window.cpp.o: CMakeFiles/antisocial.dir/flags.make
CMakeFiles/antisocial.dir/src/Window.cpp.o: ../src/Window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mitch/Documents/GameEngineStuff/Antisocial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/antisocial.dir/src/Window.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/antisocial.dir/src/Window.cpp.o -c /home/mitch/Documents/GameEngineStuff/Antisocial/src/Window.cpp

CMakeFiles/antisocial.dir/src/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antisocial.dir/src/Window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mitch/Documents/GameEngineStuff/Antisocial/src/Window.cpp > CMakeFiles/antisocial.dir/src/Window.cpp.i

CMakeFiles/antisocial.dir/src/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antisocial.dir/src/Window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mitch/Documents/GameEngineStuff/Antisocial/src/Window.cpp -o CMakeFiles/antisocial.dir/src/Window.cpp.s

CMakeFiles/antisocial.dir/src/Window.cpp.o.requires:

.PHONY : CMakeFiles/antisocial.dir/src/Window.cpp.o.requires

CMakeFiles/antisocial.dir/src/Window.cpp.o.provides: CMakeFiles/antisocial.dir/src/Window.cpp.o.requires
	$(MAKE) -f CMakeFiles/antisocial.dir/build.make CMakeFiles/antisocial.dir/src/Window.cpp.o.provides.build
.PHONY : CMakeFiles/antisocial.dir/src/Window.cpp.o.provides

CMakeFiles/antisocial.dir/src/Window.cpp.o.provides.build: CMakeFiles/antisocial.dir/src/Window.cpp.o


CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.o: CMakeFiles/antisocial.dir/flags.make
CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.o: ../src/vendor/stb_image/stb_image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mitch/Documents/GameEngineStuff/Antisocial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.o -c /home/mitch/Documents/GameEngineStuff/Antisocial/src/vendor/stb_image/stb_image.cpp

CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mitch/Documents/GameEngineStuff/Antisocial/src/vendor/stb_image/stb_image.cpp > CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.i

CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mitch/Documents/GameEngineStuff/Antisocial/src/vendor/stb_image/stb_image.cpp -o CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.s

CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.o.requires:

.PHONY : CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.o.requires

CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.o.provides: CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.o.requires
	$(MAKE) -f CMakeFiles/antisocial.dir/build.make CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.o.provides.build
.PHONY : CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.o.provides

CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.o.provides.build: CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.o


CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.o: CMakeFiles/antisocial.dir/flags.make
CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.o: ../src/vendor/imgui/imgui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mitch/Documents/GameEngineStuff/Antisocial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.o -c /home/mitch/Documents/GameEngineStuff/Antisocial/src/vendor/imgui/imgui.cpp

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mitch/Documents/GameEngineStuff/Antisocial/src/vendor/imgui/imgui.cpp > CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.i

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mitch/Documents/GameEngineStuff/Antisocial/src/vendor/imgui/imgui.cpp -o CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.s

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.o.requires:

.PHONY : CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.o.requires

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.o.provides: CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.o.requires
	$(MAKE) -f CMakeFiles/antisocial.dir/build.make CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.o.provides.build
.PHONY : CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.o.provides

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.o.provides.build: CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.o


CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.o: CMakeFiles/antisocial.dir/flags.make
CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.o: ../src/vendor/imgui/imgui_demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mitch/Documents/GameEngineStuff/Antisocial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.o -c /home/mitch/Documents/GameEngineStuff/Antisocial/src/vendor/imgui/imgui_demo.cpp

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mitch/Documents/GameEngineStuff/Antisocial/src/vendor/imgui/imgui_demo.cpp > CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.i

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mitch/Documents/GameEngineStuff/Antisocial/src/vendor/imgui/imgui_demo.cpp -o CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.s

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.o.requires:

.PHONY : CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.o.requires

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.o.provides: CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.o.requires
	$(MAKE) -f CMakeFiles/antisocial.dir/build.make CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.o.provides.build
.PHONY : CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.o.provides

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.o.provides.build: CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.o


CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.o: CMakeFiles/antisocial.dir/flags.make
CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.o: ../src/vendor/imgui/imgui_draw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mitch/Documents/GameEngineStuff/Antisocial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.o -c /home/mitch/Documents/GameEngineStuff/Antisocial/src/vendor/imgui/imgui_draw.cpp

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mitch/Documents/GameEngineStuff/Antisocial/src/vendor/imgui/imgui_draw.cpp > CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.i

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mitch/Documents/GameEngineStuff/Antisocial/src/vendor/imgui/imgui_draw.cpp -o CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.s

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.o.requires:

.PHONY : CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.o.requires

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.o.provides: CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.o.requires
	$(MAKE) -f CMakeFiles/antisocial.dir/build.make CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.o.provides.build
.PHONY : CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.o.provides

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.o.provides.build: CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.o


CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o: CMakeFiles/antisocial.dir/flags.make
CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o: ../src/vendor/imgui/imgui_impl_glfw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mitch/Documents/GameEngineStuff/Antisocial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o -c /home/mitch/Documents/GameEngineStuff/Antisocial/src/vendor/imgui/imgui_impl_glfw.cpp

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mitch/Documents/GameEngineStuff/Antisocial/src/vendor/imgui/imgui_impl_glfw.cpp > CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.i

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mitch/Documents/GameEngineStuff/Antisocial/src/vendor/imgui/imgui_impl_glfw.cpp -o CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.s

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o.requires:

.PHONY : CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o.requires

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o.provides: CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o.requires
	$(MAKE) -f CMakeFiles/antisocial.dir/build.make CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o.provides.build
.PHONY : CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o.provides

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o.provides.build: CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o


CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o: CMakeFiles/antisocial.dir/flags.make
CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o: ../src/vendor/imgui/imgui_impl_opengl3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mitch/Documents/GameEngineStuff/Antisocial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o -c /home/mitch/Documents/GameEngineStuff/Antisocial/src/vendor/imgui/imgui_impl_opengl3.cpp

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mitch/Documents/GameEngineStuff/Antisocial/src/vendor/imgui/imgui_impl_opengl3.cpp > CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.i

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mitch/Documents/GameEngineStuff/Antisocial/src/vendor/imgui/imgui_impl_opengl3.cpp -o CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.s

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o.requires:

.PHONY : CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o.requires

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o.provides: CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o.requires
	$(MAKE) -f CMakeFiles/antisocial.dir/build.make CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o.provides.build
.PHONY : CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o.provides

CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o.provides.build: CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o


# Object files for target antisocial
antisocial_OBJECTS = \
"CMakeFiles/antisocial.dir/src/Application.cpp.o" \
"CMakeFiles/antisocial.dir/src/AssetLoader.cpp.o" \
"CMakeFiles/antisocial.dir/src/Mesh.cpp.o" \
"CMakeFiles/antisocial.dir/src/Model.cpp.o" \
"CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.o" \
"CMakeFiles/antisocial.dir/src/Renderer.cpp.o" \
"CMakeFiles/antisocial.dir/src/Shader.cpp.o" \
"CMakeFiles/antisocial.dir/src/Texture2D.cpp.o" \
"CMakeFiles/antisocial.dir/src/Transform.cpp.o" \
"CMakeFiles/antisocial.dir/src/Window.cpp.o" \
"CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.o" \
"CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.o" \
"CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.o" \
"CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.o" \
"CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o" \
"CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o"

# External object files for target antisocial
antisocial_EXTERNAL_OBJECTS =

antisocial: CMakeFiles/antisocial.dir/src/Application.cpp.o
antisocial: CMakeFiles/antisocial.dir/src/AssetLoader.cpp.o
antisocial: CMakeFiles/antisocial.dir/src/Mesh.cpp.o
antisocial: CMakeFiles/antisocial.dir/src/Model.cpp.o
antisocial: CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.o
antisocial: CMakeFiles/antisocial.dir/src/Renderer.cpp.o
antisocial: CMakeFiles/antisocial.dir/src/Shader.cpp.o
antisocial: CMakeFiles/antisocial.dir/src/Texture2D.cpp.o
antisocial: CMakeFiles/antisocial.dir/src/Transform.cpp.o
antisocial: CMakeFiles/antisocial.dir/src/Window.cpp.o
antisocial: CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.o
antisocial: CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.o
antisocial: CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.o
antisocial: CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.o
antisocial: CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o
antisocial: CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o
antisocial: CMakeFiles/antisocial.dir/build.make
antisocial: CMakeFiles/antisocial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mitch/Documents/GameEngineStuff/Antisocial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable antisocial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/antisocial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/antisocial.dir/build: antisocial

.PHONY : CMakeFiles/antisocial.dir/build

CMakeFiles/antisocial.dir/requires: CMakeFiles/antisocial.dir/src/Application.cpp.o.requires
CMakeFiles/antisocial.dir/requires: CMakeFiles/antisocial.dir/src/AssetLoader.cpp.o.requires
CMakeFiles/antisocial.dir/requires: CMakeFiles/antisocial.dir/src/Mesh.cpp.o.requires
CMakeFiles/antisocial.dir/requires: CMakeFiles/antisocial.dir/src/Model.cpp.o.requires
CMakeFiles/antisocial.dir/requires: CMakeFiles/antisocial.dir/src/PrimitiveCreator.cpp.o.requires
CMakeFiles/antisocial.dir/requires: CMakeFiles/antisocial.dir/src/Renderer.cpp.o.requires
CMakeFiles/antisocial.dir/requires: CMakeFiles/antisocial.dir/src/Shader.cpp.o.requires
CMakeFiles/antisocial.dir/requires: CMakeFiles/antisocial.dir/src/Texture2D.cpp.o.requires
CMakeFiles/antisocial.dir/requires: CMakeFiles/antisocial.dir/src/Transform.cpp.o.requires
CMakeFiles/antisocial.dir/requires: CMakeFiles/antisocial.dir/src/Window.cpp.o.requires
CMakeFiles/antisocial.dir/requires: CMakeFiles/antisocial.dir/src/vendor/stb_image/stb_image.cpp.o.requires
CMakeFiles/antisocial.dir/requires: CMakeFiles/antisocial.dir/src/vendor/imgui/imgui.cpp.o.requires
CMakeFiles/antisocial.dir/requires: CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_demo.cpp.o.requires
CMakeFiles/antisocial.dir/requires: CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_draw.cpp.o.requires
CMakeFiles/antisocial.dir/requires: CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o.requires
CMakeFiles/antisocial.dir/requires: CMakeFiles/antisocial.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o.requires

.PHONY : CMakeFiles/antisocial.dir/requires

CMakeFiles/antisocial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/antisocial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/antisocial.dir/clean

CMakeFiles/antisocial.dir/depend:
	cd /home/mitch/Documents/GameEngineStuff/Antisocial/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mitch/Documents/GameEngineStuff/Antisocial /home/mitch/Documents/GameEngineStuff/Antisocial /home/mitch/Documents/GameEngineStuff/Antisocial/build /home/mitch/Documents/GameEngineStuff/Antisocial/build /home/mitch/Documents/GameEngineStuff/Antisocial/build/CMakeFiles/antisocial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/antisocial.dir/depend

