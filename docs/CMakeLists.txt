# 
#                     Copyright (C) 2020 Clovis Durand
# 
# -----------------------------------------------------------------------------

# CMakeLists.txt that generates the Doxygen documentation
find_package(Doxygen)
option(BUILD_DOC "Build API documentation" ${DOXYGEN_FOUND})

set(doxy_main_page ${CMAKE_SOURCE_DIR}/README.md)

if(DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN  ${CMAKE_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_SOURCE_DIR}/docs/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target(doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/docs
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
else(DOXYGEN_FOUND)
    message("[WARN ] Doxygen is required to generate the doxygen documentation")
endif(DOXYGEN_FOUND)

set(HTML_DOCS_DIR
    ${CMAKE_SOURCE_DIR}/docs/html
)

set(LATEX_DOCS_DIR
    ${CMAKE_SOURCE_DIR}/docs/latex
)

set(MAN_DOCS_DIR
    ${CMAKE_SOURCE_DIR}/docs/man
)
