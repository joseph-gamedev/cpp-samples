set(SOURCE_FILES MathUtil.cpp)
set(HEADER_FILES ../include/MathUtil.h)

add_library(MathLib STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(MathLib PUBLIC "${PROJECT_SOURCE_DIR}/include")