#ifndef ERROR_H
#define ERROR_H

// Everything is awesome
#define SUCCESS 0

// Pointer is unexpectedly null
#define UNEXPECTED_NULL_POINTER -1

// General table class errors
#define TABLE_NOT_INITIALISED -100
#define INVALID_TABLE_PARAMETER -101
#define Y_INDEX_OUT_OF_BOUNDS -102

// Saving and loading file errors
#define INVALID_FILE -200
#define INVALID_FILENAME -201
#define FILE_NOT_ACCESSIBLE -202
#define FILE_NOT_FOUND -203
#define FILE_NOT_SAVED -204

// Rule class errors
#define RULE_NUM_OUT_RANGE -300
#define DECIMAL_VAL_OUT_OF_RANGE -301

// Vector errors
#define INVALID_VECTOR_OPERATION -400
#define VECTOR_AT_MAX_SIZE -401

// Displays an error message to the user based on the apppropriate error code
// imported
void checkValidity(int valid);

#endif