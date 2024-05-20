#include "column.h"

// Crée une colonne avec le titre spécifié
Column* create_column(const char* title) {
    Column* column = (Column*)malloc(sizeof(Column));
    if (!column) {
        fprintf(stderr, "impossible d'allouer la memoire pour la colonne\n");
        return NULL;
    }
    column->title = strdup(title);
    if (!column->title) {
        fprintf(stderr, " impossible d'allouer la memoire pour le titre de colonne\n");
        free(column);
        return NULL;
    }
    column->data = NULL;
    column->type = -1;
    column->num_rows = 0;
    return column;
}

// Supprime une colonne et libère la mémoire associée
void delete_column(Column** column) {
    if (column && *column) {
        free((*column)->title);
        free(*column);
        *column = NULL;
    }
}

