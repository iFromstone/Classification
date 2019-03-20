set( SRCROOT ${CMAKE_CURRENT_LIST_DIR} )

target_sources( ${TARGET_NAME}
    PRIVATE
        ${SRCROOT}/TestClasses.cpp
        ${SRCROOT}/TestClasses.h
        ${SRCROOT}/TestSuite.cpp
)

target_include_directories( ${TARGET_NAME}
    PRIVATE
        ${SRCROOT}
)
