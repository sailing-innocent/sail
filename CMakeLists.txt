cmake_minimum_required(VERSION 3.24)
project(libsail
    VERSION 0.2
    DESCRIPTION "The Sail Tool Library"
    LANGUAGES C CUDA CXX
)
set(SAIL_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
########################## COMPILE CONFIGURATIONS #######################
set(CMAKE_C_STANDARD 14)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

if (MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_CRT_SECURE_NO_WARNINGS")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP24")
endif()

set(CMAKE_CUDA_STANDARD 14)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_EXTENSIONS OFF)
set(CUDA_LINK_LIBRARIES_KEYWORD PUBLIC)
set(CMAKE_CUDA_RUNTIME_LIBRARY Shared)

if (MSVC)
	list(APPEND CUDA_NVCC_FLAGS "-Xcompiler=-bigobj")
endif()
list(APPEND CUDA_NVCC_FLAGS "--extended-lambda")
list(APPEND CUDA_NVCC_FLAGS "--expt-relaxed-constexpr")

set(CMAKE_CUDA_ARCHITECTURES 86)

##############################################################################

######################## COMPILE TARGET ######################################

set(TEST_ENABLED TRUE)
set(BINDING_ENABLED FALSE)
set(CUDA_ENABLED TRUE)

####################### TARGET ###############################################

file(GLOB LIBSAIL_SOURCE CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/sail/**/*.cc)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${LIBSAIL_SOURCE})

# message(${LIBSAIL_SOURCE})

list(APPEND LIBSAIL_INCLUDE
    "D:/repos/sail/include"
    "D:/includes"
    "D:/source/eigen/"
)

list(APPEND LIBSAIL_DEP_LIBS
    # "python3"
)
list(APPEND LIBSAIL_DEP_DIRS
    # "E:/libs/fmt"
    # "E:/env/miniconda/libs"
)

add_library(libsail ${LIBSAIL_SOURCE})
target_include_directories(libsail PUBLIC ${LIBSAIL_INCLUDE})
target_link_directories(libsail PUBLIC ${LIBSAIL_DEP_DIRS})
target_link_libraries(libsail PUBLIC ${LIBSAIL_DEP_LIBS})

# CUDA

if (CUDA_ENABLED)
    add_subdirectory(sailcu)
endif()


# TESTING
if (TEST_ENABLED)
    add_subdirectory(utest)
endif()

if (${BINDING_ENABLED}) 

endif()
