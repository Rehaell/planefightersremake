# CopyAssets.cmake

# Function to copy asset files
function(copy_assets DESTINATION_DIR)
    # Accept a list of source files as arguments
    set(SOURCE_FILES ${ARGN})

    # Create a custom command for each file to copy it if it's different
    foreach(FILE ${SOURCE_FILES})
        get_filename_component(FILENAME ${FILE} NAME)
        add_custom_command(
            OUTPUT "${DESTINATION_DIR}/${FILENAME}"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different ${FILE} "${DESTINATION_DIR}/${FILENAME}"
            DEPENDS ${FILE}
            COMMENT "Copying ${FILE} to ${DESTINATION_DIR}/${FILENAME}"
        )
    endforeach()

    # Collect the output files
    set(OUTPUT_FILES)
    foreach(FILE ${SOURCE_FILES})
        get_filename_component(FILENAME ${FILE} NAME)
        list(APPEND OUTPUT_FILES "${DESTINATION_DIR}/${FILENAME}")
    endforeach()

    # Define a custom target that depends on all the copied files
    add_custom_target(copy_assets ALL DEPENDS ${OUTPUT_FILES})
endfunction()