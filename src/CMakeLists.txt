set( SRCROOT ${CMAKE_CURRENT_LIST_DIR} )

target_sources( ${TARGET_NAME}
    PRIVATE
        ${SRCROOT}/Classification.cpp
        ${SRCROOT}/Object.cpp
)

target_include_directories( ${TARGET_NAME}
    PRIVATE
        ${SRCROOT}
)
