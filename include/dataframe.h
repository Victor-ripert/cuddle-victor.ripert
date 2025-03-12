/*
** EPITECH PROJECT, 2025
** dataframe.h
** File description:
** e
*/

#ifndef DATAFRAME_H
    #define DATAFRAME_H
    #define MAX_LINE_LENGTH 1024
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

typedef enum {
    BOOL,
    INT,
    UINT,
    FLOAT,
    STRING,
    UNDEFINED
} column_type_t;

typedef struct {
    int nb_rows;
    int nb_columns;
    char **column_names;
    column_type_t *column_types;
    void ***data;
} dataframe_t;

dataframe_t *initialize_dataframe_from_file(FILE *file,
    const char *separator);
dataframe_t *init_dataframe(int nb_columns, char **column_names);
void free_dataframe(dataframe_t *df);
void print_dataframe(dataframe_t *df);
dataframe_t *df_read_csv(const char *filename, const char *separator);
void add_row_to_dataframe(dataframe_t *df, char *line,
    const char *separator);
column_type_t detect_type(const char *str);

#endif /* DATAFRAME_H */
