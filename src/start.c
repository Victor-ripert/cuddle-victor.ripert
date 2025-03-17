/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** e
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "dataframe.h"

dataframe_t *df_read_csv(const char *filename, const char *separator)
{
    FILE *file = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];
    dataframe_t *df;

    if (!file) {
        perror("Error opening file");
        return NULL;
    }
    df = initialize_dataframe_from_file(file, separator);
    if (!df) {
        fclose(file);
        return NULL;
    }
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        add_row_to_dataframe(df, line, separator);
    }
    fclose(file);
    return df;
}

void print_dataframe(dataframe_t *df)
{
    const char *type_names[] = {"BOOL", "INT", "UINT", "FLOAT",
        "STRING", "UNDEFINED"};

    printf("Dataframe (%d rows, %d columns):\n", df->nb_rows, df->nb_columns);
    for (int i = 0; i < df->nb_columns; i++)
        printf("%s (%s)\t", df->column_names[i],
            type_names[df->column_types[i]]);
    printf("\n");
    for (int i = 0; i < df->nb_rows; i++) {
        for (int j = 0; j < df->nb_columns; j++)
            printf("%s\t", (char *)df->data[j][i]);
        printf("\n");
    }
}

void write_csv_row(int fd, dataframe_t *dataframe, int row)
{
    for (int j = 0; j < dataframe->nb_columns; j++) {
        dprintf(fd, "%s", (char *)dataframe->data[j][row]);
        if (j < dataframe->nb_columns - 1)
            dprintf(fd, ",");
    }
}

int df_write_csv(dataframe_t *dataframe, const char *filename)
{
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1 || !dataframe)
        return 84;
    for (int i = 0; i < dataframe->nb_columns; i++) {
        dprintf(fd, "%s", dataframe->column_names[i]);
        if (i < dataframe->nb_columns - 1)
            dprintf(fd, ",");
    }
    if (dataframe->nb_rows > 0)
        dprintf(fd, "\n");
    for (int i = 0; i < dataframe->nb_rows; i++) {
        write_csv_row(fd, dataframe, i);
        if (i < dataframe->nb_rows - 1)
            dprintf(fd, "\n");
    }
    close(fd);
    return 0;
}

void free_dataframe(dataframe_t *df)
{
    for (int i = 0; i < df->nb_columns; i++) {
        for (int j = 0; j < df->nb_rows; j++)
            free(df->data[i][j]);
        free(df->data[i]);
        free(df->column_names[i]);
    }
    free(df->data);
    free(df->column_names);
    free(df->column_types);
    free(df);
}
