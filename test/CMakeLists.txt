cmake_minimum_required (VERSION 3.14)

set(PROJECT_NAME mmath_test)

project(${PROJECT_NAME})

# Include "mmath/include" for all tests
include_directories(../include/)

# Get all files match name "unittest.cmake"
file(GLOB_RECURSE UNITTEST_CMAKE_FILE_LIST
  "unittest.cmake"
)

if ("${UNITTEST_CMAKE_FILE_LIST}" STREQUAL "")
  message(FATAL_ERROR "No tests found.")
endif()

# Enable make test
enable_testing()
# Use googletest
find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
include(GoogleTest)

# Create unit test for each "unittest.cmake"
foreach(UNITTEST_CMAKE_FILE ${UNITTEST_CMAKE_FILE_LIST})

  # Init file lists.
  # These variables should be written in "unittest.cmake"
  set(unittest-includes)
  set(unittest-sources)
  set(unittest-test-sources)

  # Include "unittest.cmake"
  include("${UNITTEST_CMAKE_FILE}")

  # Get relative path of "unittest.cmake"
  get_filename_component(TEST_ABS_DIR ${UNITTEST_CMAKE_FILE} DIRECTORY)
  file(RELATIVE_PATH
       TEST_EXE_NAME # output
       ${PROJECT_SOURCE_DIR} # root
       ${TEST_ABS_DIR} #abs dirpath
  )

  # replace '\' or '/' to '-'
  string(REGEX REPLACE "/|\\\\" "-" TEST_EXE_NAME ${TEST_EXE_NAME})

  set(TEST_SUITES ${TEST_SUITES} ${TEST_EXE_NAME})

  set(LIBS_TO_BE_LINKED ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

  # Build directories list
  set(BUILD_DIRECTORIES)

  if (unittest-sources)
    # Create the testable static library.
    add_library("${TEST_EXE_NAME}.TESTUNIT" STATIC ${unittest-sources})
    target_include_directories("${TEST_EXE_NAME}.TESTUNIT" PRIVATE
      ${unittest-includes})
    set(LIBS_TO_BE_LINKED ${LIBS_TO_BE_LINKED} "${TEST_EXE_NAME}.TESTUNIT")

    # Append lib build directory to list
    list(APPEND BUILD_DIRECTORIES "./CMakeFiles/${TEST_EXE_NAME}.TESTUNIT.dir")
  endif(unittest-sources)

  if (unittest-test-sources)
    # Create the executable.
    add_executable(${TEST_EXE_NAME} ${unittest-test-sources})
    target_include_directories(${TEST_EXE_NAME} PRIVATE
      ${unittest-includes})

    # Link the executable with the libraries.
    target_link_libraries(${TEST_EXE_NAME} ${LIBS_TO_BE_LINKED})

    add_test(NAME "${TEST_EXE_NAME}" COMMAND ${TEST_EXE_NAME})

    # Append test build directory to list
    list(APPEND BUILD_DIRECTORIES "./CMakeFiles/${TEST_EXE_NAME}.dir")
  else()
    message(WARNING "No test source files found for ${TEST_EXE_NAME}.\n")
  endif(unittest-test-sources)
endforeach(UNITTEST_CMAKE_FILE)

