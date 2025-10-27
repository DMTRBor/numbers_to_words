#ifndef __NUMBERS__H__
#define __NUMBERS__H__

/* functions to extract tens and units digit from 1-2 digited number */
#define get_tens(num) (num - (num % 10))
#define get_units(num) (num % 10)

#define MAX_NUM_LEN 50
#define TOTAL_ARGS_NUM 3
#define STR_EQUAL 0
#define INPUT_VALID 1

#define NEWLINE "\n"
#define READ_FILE_PERMISSION "r"
#define WRITE_FILE_PERMISSION "w"

/* messages */
#define EOF_OR_ERROR_MSG "EOF/Input error! Exit...\n"
#define EXTRA_ARGS_ERR_MSG "Error - extraneous argument passed! Only 2 required! Exit...\n"
#define READ_FILE_ERROR_MSG "Verify the file exists and not restricted for reading\n"
#define WRITE_FILE_ERROR_MSG "Verify the filename valid and the file is not restricted for writing\n"

enum {
    STATUS_CODE_OK,
    STATUS_CODE_ERR
};

enum {
    FALSE,
    TRUE
};

void validate_file(char *, char *, char *);
void print_tens(int, FILE *);
void print_units(int, FILE *);
int print_eleven_to_nineteen(int, FILE *);
void print_number_literal(char *, FILE *);

#endif
