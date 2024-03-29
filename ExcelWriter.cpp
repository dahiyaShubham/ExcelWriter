// ExcelWriter.cpp : Defines the exported functions for the DLL application.
//

#include "xlsxwriter.h"
#include <iostream>
#include <string>

#ifdef _WIN32
#    ifdef LIBRARY_EXPORTS
#        define LIBRARY_API __declspec(dllexport)
#    else
#        define LIBRARY_API __declspec(dllimport)
#    endif
#elif
#    define LIBRARY_API
#endif

extern "C" {

	LIBRARY_API lxw_workbook* WorkbookNew(const char *file) {
		return workbook_new(file);
	}

	LIBRARY_API lxw_worksheet* WorkbookAddWorksheet(lxw_workbook *workbook, const char *sheetName) {
		return workbook_add_worksheet(workbook, sheetName);
	}

	LIBRARY_API lxw_format* WorkbookAddFormat(lxw_workbook *workbook) {
		return workbook_add_format(workbook);
	}

	LIBRARY_API void FormatSetBold(lxw_format *format) {
		return format_set_bold(format);
	}

	LIBRARY_API void WorksheetSetColumn(lxw_worksheet *worksheet,
		lxw_col_t first_col,
		lxw_col_t last_col,
		double width, lxw_format *format) {

		worksheet_set_column(worksheet, first_col, last_col, width, format);
	}
	
	LIBRARY_API void WorksheetSetRow(lxw_worksheet* worksheet,
		lxw_col_t row,
		double height, lxw_format *format) {

		worksheet_set_row(worksheet, row, height, format);
	}

	LIBRARY_API void WorksheetWriteString(lxw_worksheet *worksheet,
		lxw_row_t row,
		lxw_col_t col, const char *string,
		lxw_format *format) {

		worksheet_write_string(worksheet, row, col, string, format);
	}

	LIBRARY_API void WorksheetWriteNumber(lxw_worksheet *worksheet,
		lxw_row_t row,
		lxw_col_t col, double number,
		lxw_format *format) {

		worksheet_write_number(worksheet, row, col, number, format);
	}

	LIBRARY_API void WorksheetInsertImage(lxw_worksheet *worksheet,
		lxw_row_t row, lxw_col_t col,
		const char *filename) {

		worksheet_insert_image(worksheet, row, col, filename);
	}

	LIBRARY_API void WorkbookClose(lxw_workbook *workbook) {
		workbook_close(workbook);
	}

}