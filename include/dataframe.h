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
    #include <stdbool.h>

typedef enum {
    BOOL = 0,
    INT = 1,
    UINT = 2,
    FLOAT = 3,
    STRING = 4,
    UNDEFINED
} column_type_t;

typedef struct {
    int nb_rows;
    int nb_columns;
    char **column_names;
    column_type_t *column_types;
    void ***data;
    char *separator;
} dataframe_t;

typedef struct type_to_str_s {
    column_type_t type;
    char *name;
} type_to_str_t;

typedef struct dataframe_shape_s {
    int nb_rows;
    int nb_columns;
} dataframe_shape_t;

typedef struct {
    dataframe_t *df;
    dataframe_t *new_df;
    int col_index;
    int *new_i;
    bool (*filter_func)(void *);
} filter_context_t;

dataframe_shape_t df_shape(dataframe_t *dataframe);

dataframe_t *initialize_dataframe_from_file(FILE *file,
    const char *separator);
dataframe_t *init_dataframe(int nb_columns, char **column_names,
    const char *separator);
void free_dataframe(dataframe_t *df);
void print_dataframe(dataframe_t *df);
dataframe_t *df_read_csv(const char *filename, const char *separator);
void add_row_to_dataframe(dataframe_t *df, char *line,
    const char *separator);
column_type_t detect_type(const char *str);
int df_write_csv(dataframe_t *dataframe, const char *filename);
column_type_t detect_column_type(dataframe_t *dataframe, int col);
void describe_loop(dataframe_t *dataframe, int pos_column);
dataframe_t *df_head(dataframe_t *dataframe, int nb_rows);
dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows);
dataframe_t *df_filter(dataframe_t *dataframe, const char *column,
    bool (*filter_func)(void *));

#endif /* DATAFRAME_H */
