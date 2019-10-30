macro(worldbuilder_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} gtest gmock gtest_main)
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

worldbuilder_add_test( common-test
common/test_main.cpp
common/terrain_test.cpp
)

target_link_libraries( common-test WorldBuilderCore::Common )
