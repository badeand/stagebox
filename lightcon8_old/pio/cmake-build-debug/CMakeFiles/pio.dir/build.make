# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "/Users/badeand/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/183.4588.63/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/badeand/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/183.4588.63/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/badeand/dev/stagebox/lightcon8_old/pio

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/badeand/dev/stagebox/lightcon8_old/pio/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pio.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pio.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pio.dir/flags.make

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBoards.cpp.o: CMakeFiles/pio.dir/flags.make
CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBoards.cpp.o: ../.piolibdeps/OSC_ID423/OSCBoards.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/badeand/dev/stagebox/lightcon8_old/pio/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBoards.cpp.o"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBoards.cpp.o -c /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/OSCBoards.cpp

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBoards.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBoards.cpp.i"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/OSCBoards.cpp > CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBoards.cpp.i

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBoards.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBoards.cpp.s"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/OSCBoards.cpp -o CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBoards.cpp.s

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBundle.cpp.o: CMakeFiles/pio.dir/flags.make
CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBundle.cpp.o: ../.piolibdeps/OSC_ID423/OSCBundle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/badeand/dev/stagebox/lightcon8_old/pio/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBundle.cpp.o"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBundle.cpp.o -c /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/OSCBundle.cpp

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBundle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBundle.cpp.i"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/OSCBundle.cpp > CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBundle.cpp.i

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBundle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBundle.cpp.s"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/OSCBundle.cpp -o CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBundle.cpp.s

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCData.cpp.o: CMakeFiles/pio.dir/flags.make
CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCData.cpp.o: ../.piolibdeps/OSC_ID423/OSCData.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/badeand/dev/stagebox/lightcon8_old/pio/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCData.cpp.o"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCData.cpp.o -c /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/OSCData.cpp

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCData.cpp.i"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/OSCData.cpp > CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCData.cpp.i

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCData.cpp.s"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/OSCData.cpp -o CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCData.cpp.s

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMatch.c.o: CMakeFiles/pio.dir/flags.make
CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMatch.c.o: ../.piolibdeps/OSC_ID423/OSCMatch.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/badeand/dev/stagebox/lightcon8_old/pio/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMatch.c.o"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMatch.c.o   -c /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/OSCMatch.c

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMatch.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMatch.c.i"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/OSCMatch.c > CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMatch.c.i

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMatch.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMatch.c.s"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/OSCMatch.c -o CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMatch.c.s

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMessage.cpp.o: CMakeFiles/pio.dir/flags.make
CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMessage.cpp.o: ../.piolibdeps/OSC_ID423/OSCMessage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/badeand/dev/stagebox/lightcon8_old/pio/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMessage.cpp.o"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMessage.cpp.o -c /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/OSCMessage.cpp

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMessage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMessage.cpp.i"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/OSCMessage.cpp > CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMessage.cpp.i

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMessage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMessage.cpp.s"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/OSCMessage.cpp -o CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMessage.cpp.s

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCTiming.cpp.o: CMakeFiles/pio.dir/flags.make
CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCTiming.cpp.o: ../.piolibdeps/OSC_ID423/OSCTiming.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/badeand/dev/stagebox/lightcon8_old/pio/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCTiming.cpp.o"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCTiming.cpp.o -c /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/OSCTiming.cpp

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCTiming.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCTiming.cpp.i"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/OSCTiming.cpp > CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCTiming.cpp.i

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCTiming.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCTiming.cpp.s"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/OSCTiming.cpp -o CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCTiming.cpp.s

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedSerial.cpp.o: CMakeFiles/pio.dir/flags.make
CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedSerial.cpp.o: ../.piolibdeps/OSC_ID423/SLIPEncodedSerial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/badeand/dev/stagebox/lightcon8_old/pio/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedSerial.cpp.o"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedSerial.cpp.o -c /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/SLIPEncodedSerial.cpp

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedSerial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedSerial.cpp.i"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/SLIPEncodedSerial.cpp > CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedSerial.cpp.i

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedSerial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedSerial.cpp.s"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/SLIPEncodedSerial.cpp -o CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedSerial.cpp.s

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedUSBSerial.cpp.o: CMakeFiles/pio.dir/flags.make
CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedUSBSerial.cpp.o: ../.piolibdeps/OSC_ID423/SLIPEncodedUSBSerial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/badeand/dev/stagebox/lightcon8_old/pio/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedUSBSerial.cpp.o"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedUSBSerial.cpp.o -c /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/SLIPEncodedUSBSerial.cpp

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedUSBSerial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedUSBSerial.cpp.i"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/SLIPEncodedUSBSerial.cpp > CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedUSBSerial.cpp.i

CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedUSBSerial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedUSBSerial.cpp.s"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/badeand/dev/stagebox/lightcon8_old/pio/.piolibdeps/OSC_ID423/SLIPEncodedUSBSerial.cpp -o CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedUSBSerial.cpp.s

CMakeFiles/pio.dir/src/main.cpp.o: CMakeFiles/pio.dir/flags.make
CMakeFiles/pio.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/badeand/dev/stagebox/lightcon8_old/pio/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/pio.dir/src/main.cpp.o"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pio.dir/src/main.cpp.o -c /Users/badeand/dev/stagebox/lightcon8_old/pio/src/main.cpp

CMakeFiles/pio.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pio.dir/src/main.cpp.i"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/badeand/dev/stagebox/lightcon8_old/pio/src/main.cpp > CMakeFiles/pio.dir/src/main.cpp.i

CMakeFiles/pio.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pio.dir/src/main.cpp.s"
	/Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/badeand/dev/stagebox/lightcon8_old/pio/src/main.cpp -o CMakeFiles/pio.dir/src/main.cpp.s

# Object files for target pio
pio_OBJECTS = \
"CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBoards.cpp.o" \
"CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBundle.cpp.o" \
"CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCData.cpp.o" \
"CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMatch.c.o" \
"CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMessage.cpp.o" \
"CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCTiming.cpp.o" \
"CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedSerial.cpp.o" \
"CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedUSBSerial.cpp.o" \
"CMakeFiles/pio.dir/src/main.cpp.o"

# External object files for target pio
pio_EXTERNAL_OBJECTS =

pio: CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBoards.cpp.o
pio: CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCBundle.cpp.o
pio: CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCData.cpp.o
pio: CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMatch.c.o
pio: CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCMessage.cpp.o
pio: CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/OSCTiming.cpp.o
pio: CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedSerial.cpp.o
pio: CMakeFiles/pio.dir/.piolibdeps/OSC_ID423/SLIPEncodedUSBSerial.cpp.o
pio: CMakeFiles/pio.dir/src/main.cpp.o
pio: CMakeFiles/pio.dir/build.make
pio: CMakeFiles/pio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/badeand/dev/stagebox/lightcon8_old/pio/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable pio"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pio.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pio.dir/build: pio

.PHONY : CMakeFiles/pio.dir/build

CMakeFiles/pio.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pio.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pio.dir/clean

CMakeFiles/pio.dir/depend:
	cd /Users/badeand/dev/stagebox/lightcon8_old/pio/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/badeand/dev/stagebox/lightcon8_old/pio /Users/badeand/dev/stagebox/lightcon8_old/pio /Users/badeand/dev/stagebox/lightcon8_old/pio/cmake-build-debug /Users/badeand/dev/stagebox/lightcon8_old/pio/cmake-build-debug /Users/badeand/dev/stagebox/lightcon8_old/pio/cmake-build-debug/CMakeFiles/pio.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pio.dir/depend
