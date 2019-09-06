set(base_SRCS
        Timestamp.cc
        )

add_library(yiheng_base ${base_SRCS})
target_link_libraries(yiheng_base pthread rt)

install(TARGETS yiheng_base DESTINATION lib)

file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION include/yiheng/base)

if (YIHENG_BUILD_EXAMPLES)
    add_subdirectory(tests)
endif ()