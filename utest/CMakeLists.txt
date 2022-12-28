set(BASIC_TEST_ENABLED FALSE)
set(VIS_TEST_ENABLED FALSE)
set(MATH_TEST_ENABLED TRUE)
set(DEPS_TEST_ENABLED FALSE)
set(ALGORITHM_TEST_ENABLED FALSE)
set(LC_TEST_ENABLED TRUE)
set(UI_TEST_ENABLED FALSE)
set(CUDA_TEST_ENALBED TRUE)



list(APPEND LIBSAIL_TEST_INCLUDE
    ${LIBSAIL_INCLUDE}
)

list(APPEND LIBSAIL_TEST_LIBS
    ${LIBSAIL_DEP_LIBS}
    GTest::gtest_main
    $<TARGET_OBJECTS:libsail>
)

list(APPEND LIBSAIL_TEST_LIBDIRS
    ${LIBSAIL_DEP_DIRS}
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL file://D:/source/googletest # https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)
enable_testing()

if (${BASIC_TEST_ENABLED})
    list(APPEND BASIC_TEST_SOURCE
        # "hello_test.cc"
        "core/timer.test.cc"
        # "core/cpp_basic.test.cc"
        # "core/cpp_macro.test.cc"
        # "core/stl_vector.test.cc"
    )
    add_executable(basic_test ${BASIC_TEST_SOURCE})
    target_include_directories(basic_test PUBLIC ${LIBSAIL_TEST_INCLUDE})
    target_link_libraries(basic_test ${LIBSAIL_TEST_LIBS})
    target_link_directories(basic_test PUBLIC ${LIBSAIL_TEST_LIBDIRS})
    gtest_discover_tests(basic_test)
endif()

if (${VIS_TEST_ENABLED})
    list(APPEND VIS_TEST_SOURCE
        "visualize/vnode.test.cc"
    )
    add_executable(vis_test ${VIS_TEST_SOURCE})
    target_include_directories(vis_test PUBLIC ${LIBSAIL_TEST_INCLUDE})
    target_link_libraries(vis_test ${LIBSAIL_TEST_LIBS})
    gtest_discover_tests(vis_test)
endif()

if (${UI_TEST_ENABLED})
    list(APPEND UI_TEST_SOURCE
        "ui/histogram.test.cc"
    )
    add_executable(ui_test ${UI_TEST_SOURCE})
    target_include_directories(ui_test PUBLIC ${LIBSAIL_TEST_INCLUDE})
    target_link_libraries(ui_test PUBLIC ${LIBSAIL_TEST_LIBS})
    gtest_discover_tests(ui_test)
endif()

if (${MATH_TEST_ENABLED})
    list(APPEND MATH_TEST_SOURCE
        # "math/vec4f.test.cc"
        "math/vec2i.test.cc"
        # "visualize/vnode.test.cc"
        # "math/geometry.test.cc"
        # "math/matrix.test.cc"
        # "math/statistic.test.cc"
    )
    add_executable(math_test ${MATH_TEST_SOURCE})
    target_include_directories(math_test PUBLIC ${LIBSAIL_TEST_INCLUDE})
    target_link_libraries(math_test ${LIBSAIL_TEST_LIBS})
    gtest_discover_tests(math_test)
endif()

if (${ALGORITHM_TEST_ENABLED})
    list(APPEND ALGORITHM_TEST_SOURCE
        # "algorithm/node.test.cc"
        # "algorithm/list.test.cc"
        # "algorithm/stack.test.cc"
        # "algorithm/queue.test.cc"
        # "algorithm/tree.test.cc"
        "algorithm/sort.test.cc"
        # "algorithm/select.test.cc"
    )
    add_executable(algo_test ${ALGORITHM_TEST_SOURCE})
    target_include_directories(algo_test PUBLIC ${LIBSAIL_TEST_INCLUDE})
    target_link_libraries(algo_test PUBLIC ${LIBSAIL_TEST_LIBS})
    gtest_discover_tests(algo_test)
endif()

if (${DEPS_TEST_ENABLED})
    list(APPEND DEPS_TEST_SOURCE
        # "dependencies/eigen_basic.test.cc" 
        # "dependencies/fmt.test.cc"
        "dependencies/numcpp.test.cc"
    )
    add_executable(deps_test ${DEPS_TEST_SOURCE})
    target_include_directories(deps_test PUBLIC ${LIBSAIL_TEST_INCLUDE})
    target_link_libraries(deps_test ${LIBSAIL_TEST_LIBS})
    target_link_directories(deps_test PUBLIC ${LIBSAIL_TEST_LIBDIRS})
    gtest_discover_tests(deps_test)
endif()

if (${LC_TEST_ENABLED})
    list(APPEND LC_TEST_SOURCE
        # "leetcode/lc001.cc"
        # "leetcode/lc016.cc"
        # "leetcode/lc021.cc"
        # "leetcode/lc022.cc"
        # "leetcode/lc041.cc"
        "leetcode/lc042.cc"
    )
    add_executable(lc_test ${LC_TEST_SOURCE})
    target_include_directories(lc_test PUBLIC ${LIBSAIL_TEST_INCLUDE})
    target_link_libraries(lc_test PRIVATE ${LIBSAIL_TEST_LIBS})
    target_link_directories(lc_test PUBLIC ${LIBSAIL_TEST_LIBDIRS})
    gtest_discover_tests(lc_test)
endif()


if (${CUDA_TEST_ENALBED} AND ${CUDA_ENABLED})
    list(APPEND LIBSAIL_TEST_LIBS
        # $<TARGET_OBJECTS:sailcu>
        sailcu
    )
    list(APPEND CUDA_TEST_SOURCE
        "cuda/hello.test.cc"
        "cuda/vector.test.cc"
    )
    list(APPEND LIBSAIL_TEST_LIBDIRS
        # "D:/repos/sail/build/sailcu/Debug"
    )
    add_executable(cuda_test ${CUDA_TEST_SOURCE})
    target_include_directories(cuda_test PUBLIC ${LIBSAIL_TEST_INCLUDE})
    target_link_directories(cuda_test PUBLIC ${LIBSAIL_TEST_LIBDIRS})
    target_link_libraries(cuda_test PRIVATE ${LIBSAIL_TEST_LIBS})
    gtest_discover_tests(cuda_test)
endif()