/*
** EPITECH PROJECT, 2025
** init_data.c
** File description:
** e
*/

#include "dataframe.h"

static int count_columns(const char *line, const char *separator)
{
    int count = 1;

    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == separator[0])
            count++;
    return count;
}

static char **get_column_names(char *line, const char *separator,
    int nb_columns)
{
    char **column_names = malloc(sizeof(char *) * nb_columns);
    char *token = strtok(line, separator);

    for (int i = 0; i < nb_columns && token; i++) {
        column_names[i] = strdup(token);
        token = strtok(NULL, separator);
    }
    return column_names;
}

void add_row_to_dataframe(dataframe_t *df, char *line,
    const char *separator)
{
    char *token;
    void **row = malloc(sizeof(void *) * df->nb_columns);

    token = strtok(line, separator);
    for (int i = 0; i < df->nb_columns && token; i++) {
        // row[i] = strdup(token);  was here before
        if (df->nb_rows == 0) {
            df->column_types[i] = detect_type(token);
        }
        row[i] = fill_row(token, df->column_types[i]);
        token = strtok(NULL, separator);
    }
    for (int i = 0; i < df->nb_columns; i++) {
        df->data[i] = realloc(df->data[i], sizeof(void *) * (df->nb_rows + 1));
        df->data[i][df->nb_rows] = row[i];
    }
    df->nb_rows++;
}

dataframe_t *initialize_dataframe_from_file(FILE *file,
    const char *separator)
{
    char line[MAX_LINE_LENGTH];
    int nb_columns = 0;
    char **column_names = NULL;
    dataframe_t *df;

    if (!fgets(line, sizeof(line), file))
        return NULL;
    line[strcspn(line, "\n")] = '\0';
    nb_columns = count_columns(line, separator);
    column_names = get_column_names(line, separator, nb_columns);
    if (!column_names)
        return NULL;
    df = init_dataframe(nb_columns, column_names);
    return df;
}

dataframe_t *init_dataframe(int nb_columns, char **column_names)
{
    dataframe_t *df = malloc(sizeof(dataframe_t));

    if (!df)
        return NULL;
    df->nb_columns = nb_columns;
    df->nb_rows = 0;
    df->column_names = column_names;
    df->column_types = malloc(sizeof(column_type_t) * nb_columns);
    df->data = malloc(sizeof(void **) * nb_columns);
    if (!df->column_types || !df->data) {
        free(df);
        return NULL;
    }
    for (int i = 0; i < nb_columns; i++) {
        df->column_types[i] = UNDEFINED;
        df->data[i] = NULL;
    }
    return df;
}
