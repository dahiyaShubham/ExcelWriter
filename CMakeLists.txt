cmake_minimum_required (VERSION 3.8)

SET(PROJECT_NAME ExcelWriter)
project(${PROJECT_NAME})

if (WIN32)
	message("env var value: " $ENV{LIB_XLSXWRITER_LIB_DIR})
	set(Libxlsxwriter_DIR $ENV{LIB_XLSXWRITER_LIB_DIR})
endif ()

message("libslsxwriter dir: " ${Libxlsxwriter_DIR})

find_package(Libxlsxwriter REQUIRED)

add_library (${PROJECT_NAME} SHARED "ExcelWriter.cpp")

add_compile_definitions(LIBRARY_EXPORTS)

target_link_libraries(
			${PROJECT_NAME}
			xlsxwriter::xlsxwriter
	)
