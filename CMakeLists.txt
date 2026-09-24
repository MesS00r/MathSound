cmake_minimum_required(VERSION 3.10.0)
project(math_sound VERSION 0.1.0 LANGUAGES C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE ALL_SRC_FILES "src/*.*")
file(GLOB_RECURSE ALL_LIB_FILES "lib/*.*")

set(OCAML_ORIGINAL_SOURCES "")
set(C_SOURCES "")

foreach(FILE ${ALL_SRC_FILES} ${ALL_LIB_FILES})
    if(FILE MATCHES "\\.ml$")
        list(APPEND OCAML_ORIGINAL_SOURCES ${FILE})
    elseif(FILE MATCHES "\\.c$")
        list(APPEND C_SOURCES ${FILE})
    endif()
endforeach()

set(OCAML_COPIED_SOURCES "")
set(FINAL_BINARY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/math_sound")
set(ML_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/ml_build")

foreach(ML_FILE ${OCAML_ORIGINAL_SOURCES})
    get_filename_component(FILENAM ${ML_FILE} NAME)
    set(COPY_TARGET "${ML_BUILD_DIR}/${FILENAM}")
    
    add_custom_command(
        OUTPUT ${COPY_TARGET}

        COMMAND ${CMAKE_COMMAND} -E make_directory ${ML_BUILD_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${ML_FILE} ${COPY_TARGET}

        DEPENDS ${ML_FILE}
    )
    list(APPEND OCAML_COPIED_SOURCES ${COPY_TARGET})
endforeach()

get_filename_component(FINAL_BINARY_DIR ${FINAL_BINARY} DIRECTORY)

add_custom_command(
    OUTPUT ${FINAL_BINARY}

    COMMAND ${CMAKE_COMMAND} -E make_directory ${FINAL_BINARY_DIR}
    COMMAND ocamlopt -I ${ML_BUILD_DIR} -ccopt "-O1 -g" -o ${FINAL_BINARY} ${C_SOURCES} ${OCAML_COPIED_SOURCES}

    DEPENDS ${OCAML_COPIED_SOURCES} ${C_SOURCES}
)

add_custom_target(math_sound_target ALL DEPENDS ${FINAL_BINARY})