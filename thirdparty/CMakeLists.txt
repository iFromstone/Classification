if( WIN32 )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

add_subdirectory(googletest)
