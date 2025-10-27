#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "numbers.h"


/**
 * The function receives a file name (string), program name (string),
 * and file permission (string, r/w) and checks if the file could be
 * opened or if the permission passed allows to open a file. If a
 * problem occured while trying to open a file - an explanation of
 * the problem will be printed to error file, following by exiting
 * the program with error code. If no problem with file opening
 * occured, the function closes the opened file and continues.
 */
void validate_file(char *file_name, char *prog, char *f_permission) {
    FILE *fp;

    /* try to open the file and check if a pointer to file returned */
    if ((fp = fopen(file_name, f_permission)) == NULL) {
        /* file is restricted for writing */
        if (strcmp(f_permission, WRITE_FILE_PERMISSION) == STR_EQUAL) {
            fprintf(stderr, "%s: can't write to file - %s\n", prog, file_name);
            fprintf(stderr, WRITE_FILE_ERROR_MSG);
        }
        /* file doesn't exist or it's restricted for reading */
        if (strcmp(f_permission, READ_FILE_PERMISSION) == STR_EQUAL) {
            fprintf(stderr, "%s: can't read from file - %s\n", prog, file_name);
            fprintf(stderr, READ_FILE_ERROR_MSG);
        }

        exit(STATUS_CODE_ERR);  /* closes files if any open */
    }

    /* close the file if no error returned (exited program) */
    fclose(fp);
}


/**
 * The function receives an integer number and a pointer
 * to output file. The integer number represents the tens
 * of two-digited integer. The function prints to file a
 * literal represenetation of the integer number received,
 * in english lowercase letters. If the number is smaller 
 * than 10 or bigger than 90 (in tens), nothing printed.
 */
void print_tens(int num, FILE *output) {
    switch (num) {
        case 10:
            fprintf(output, "ten");
            break;
        case 20:
            fprintf(output, "twenty ");
            break;
        case 30:
            fprintf(output, "thirty ");
            break;
        case 40:
            fprintf(output, "fourty ");
            break;
        case 50:
            fprintf(output, "fifty ");
            break;
        case 60:
            fprintf(output, "sixty ");
            break;
        case 70:
            fprintf(output, "seventy ");
            break;
        case 80:
            fprintf(output, "eighty ");
            break;
        case 90:
            fprintf(output, "ninety ");
            break;
		default:
			break;
    }
}


/**
 * The function receives an integer number and a pointer
 * to output file. The integer number represents the units
 * of two-digited integer or a digit (1-9). The function
 * prints to file a literal represenetation of the integer
 * number received, in english lowercase letters. If the
 * number is not single-digited, nothing printed.
 */
void print_units(int num, FILE *output) {
    switch (num) {
        case 1:
            fprintf(output, "one");
            break;
        case 2:
            fprintf(output, "two");
            break;
        case 3:
            fprintf(output, "three");
            break;
        case 4:
            fprintf(output, "four");
            break;
        case 5:
            fprintf(output, "five");
            break;
        case 6:
            fprintf(output, "six");
            break;
        case 7:
            fprintf(output, "seven");
            break;
        case 8:
            fprintf(output, "eight");
            break;
        case 9:
            fprintf(output, "nine");
            break;
		default:
			break;
    }
}


/**
 * The function receives an integer number and a pointer
 * to output file. The integer number represents an integer
 * between 11 and 19. The function prints to file a literal
 * represenetation of the integer number received, in english
 * lowercase letters and returns a True status code. If the
 * number is not in range 11 to 19, nothing printed, and 
 * False status code returned.
 */
int print_eleven_to_nineteen(int num, FILE *output) {
    switch (num) {
        case 11:
            fprintf(output, "eleven");
            return TRUE;
        case 12:
            fprintf(output, "twelve");
            return TRUE;
        case 13:
            fprintf(output, "thirteen");
            return TRUE;
        case 14:
            fprintf(output, "fourteen");
            return TRUE;
        case 15:
            fprintf(output, "fifteen");
            return TRUE;
        case 16:
            fprintf(output, "sixteen");
            return TRUE;
        case 17:
            fprintf(output, "seventeen");
            return TRUE;
        case 18:
            fprintf(output, "eighteen");
            return TRUE;
        case 19:
            fprintf(output, "nineteen");
            return TRUE;
		default:
			break;
    }

    return FALSE;
}


/**
 * The function receives a string that represents
 * an integer number and a pointer to an output file,
 * converts the string to integer and prints the
 * literal representation of the number.
 */
void print_number_literal(char *number, FILE *output) {
    int num;

    num = atoi(number);  /* convert string to integer */

	/* handle zero case */
	if (num == 0) {
		fprintf(output, "zero");
		fprintf(output, NEWLINE);
		return;
	}

    /* handle 11 to 19 cases */
    if (print_eleven_to_nineteen(num, output)) {
        fprintf(output, NEWLINE);
        return;
    }

    /* the number is not zero and not between 11 and 19 */
    print_tens(get_tens(num), output);
    print_units(get_units(num), output);
    fprintf(output, NEWLINE);
}
