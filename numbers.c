#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "numbers.h"


/**
 * This is the main program - it receives optional command
 * line arguments:
 * - input file name: contains valid input (2 digited numbers).
 * - output file name: file where the output will be printed.
 * If only the input file name received as argument, the output
 * will be redirected to stdout (screen).
 * If no arguments received at all, the program will get the output
 * from stdin (keyboard) and redirect the output to stdout (screen).
 * The errors will be redirected to stderr default file (screen).
 * The program parses the input integer numbers and prints each
 * number's literal representation in english lowercase letters
 * to output file.
 * if any error occured with the file opening, permission or the
 * file name passed as argument to program is not existent, an
 * appropriate error will be printed to output file and the program
 * will exit with error status code.
 * Otherwise, the program will finish the work and exit with success
 * status code.
*/
int main(int argc, char *argv[])
{
    char input[MAX_NUM_LEN];  /* input number length */
    char *args;
    char *prog = argv[0];  /* program name */

    /* set default input, output and error files */
    FILE *input_file = stdin;
    FILE *output_file = stdout;
    FILE *error_file = stderr;

    if (argc >= (TOTAL_ARGS_NUM - 1)) {  /* only input file name received */
        validate_file(argv[1], prog, READ_FILE_PERMISSION);
        input_file = fopen(argv[1], READ_FILE_PERMISSION);

        if (argc == TOTAL_ARGS_NUM) {  /* input and output file names received */
            validate_file(argv[2], prog, WRITE_FILE_PERMISSION);
            output_file = fopen(argv[2], WRITE_FILE_PERMISSION);
        }

        if (argc > TOTAL_ARGS_NUM) {  /* extraneous argument/s received, exit with error */
            fprintf(error_file, EXTRA_ARGS_ERR_MSG);
            exit(STATUS_CODE_ERR);
        }
    }

    /* read string tokens (numbers), ignoring blank lines
       until EOF/error and print literal representation to output file */
    while (fscanf(input_file, "%s", input) == INPUT_VALID) {
        print_number_literal(input, output_file);
    }

    /* empty file/other issue in file */
    if (feof(input_file) == FALSE && ferror(input_file)) {
        fprintf(error_file, EOF_OR_ERROR_MSG);
        exit(STATUS_CODE_ERR);
    }

    /* no errors occured during run, exit */
    exit(STATUS_CODE_OK);
}
