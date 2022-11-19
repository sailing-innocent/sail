set(TARGET_NAME sailcu)

# aux_source_directory(source SAILCU_SOURCE)

list(APPEND SAILCU_SOURCE
    "source/hello.cu"
    "math/vector.cu"
)

list(APPEND LIBSAIL_CU_INCLUDE
    ${LIBSAIL_INCLUDE}
)

list(APPEND LIBSAIL_CU_LIBS
    cudart
    libsail
)

add_library(${TARGET_NAME} OBJECT ${SAILCU_SOURCE})
target_include_directories(${TARGET_NAME} PUBLIC ${LIBSAIL_CU_INCLUDE})
target_link_libraries(${TARGET_NAME} PUBLIC ${LIBSAIL_CU_LIBS})
target_compile_options(${TARGET_NAME} PUBLIC $<$<COMPILE_LANGUAGE:CUDA>:${CUDA_NVCC_FLAGS}>)

