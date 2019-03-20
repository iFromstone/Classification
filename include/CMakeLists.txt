set( SRCROOT ${CMAKE_CURRENT_LIST_DIR} )

target_sources( ${TARGET_NAME}
    PRIVATE
        ${SRCROOT}/Classification.h
        ${SRCROOT}/Object.h
)

target_include_directories( ${TARGET_NAME}
    PRIVATE
        ${SRCROOT}
    INTERFACE
        ${SRCROOT}
)
