cmake_minimum_required(VERSION 3.10)

project( Classification )

option( ENABLE_TEST "Enables test suite execution" TRUE )

set( TARGET_NAME ${PROJECT_NAME} )
add_library( ${TARGET_NAME} STATIC "" )
add_subdirectory( include )
add_subdirectory( src )

if( ENABLE_TEST )
    set( TARGET_NAME ${PROJECT_NAME}_test )
    add_executable( ${TARGET_NAME} "" )
    add_subdirectory( test )
    add_subdirectory( thirdparty )
    
    target_link_libraries( ${TARGET_NAME}
                           ${PROJECT_NAME}
                           gtest
                           gtest_main )

    enable_testing()
    add_test( NAME    ${TARGET_NAME}
              COMMAND ${TARGET_NAME} )
endif()