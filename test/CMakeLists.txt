#=============================================================================
# Setup unit tests
#=============================================================================
find_package(Boost 1.53 REQUIRED)

add_custom_target(unit COMMENT "build all the unit tests")
add_custom_target(check
    DEPENDS unit
    COMMAND ${CMAKE_CTEST_COMMAND}
    COMMENT "build and then run all the unit tests"
)

function(react_add_test name sources)
    add_executable(${name} EXCLUDE_FROM_ALL ${sources})
    set_property(TARGET ${name}
        APPEND PROPERTY INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIRS}
    )
    set_property(TARGET ${name}
        APPEND PROPERTY INCLUDE_DIRECTORIES ${react_SOURCE_DIR}/include
    )
    add_test(NAME ${name} COMMAND ${name})
    add_dependencies(unit ${name})
endfunction()


react_add_test(master_header master_header.cpp)