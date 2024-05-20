#include "cdataframe.h"

// Crée un CDataFrame avec un nombre spécifié de colonnes
CDataFrame* create_cdataframe(int num_columns) {
    // Alloue de la mémoire pour le CDataFrame
    CDataFrame* dataframe = (CDataFrame*)malloc(sizeof(CDataFrame));
    if (!dataframe) {
        fprintf(stderr, "impossible d'allouer la memoire pour le CDataFrame\n");
        return NULL;
    }

    // Alloue de la mémoire pour le tableau de colonnes
    dataframe->columns = (Column**)malloc(num_columns * sizeof(Column*));
    if (!dataframe->columns) {
        fprintf(stderr, "impossible d'alloueer la memoire pour les colonnes\n");
        free(dataframe);
        return NULL;
    }
    dataframe->num_columns = num_columns;
    return dataframe;
}

// Supprime un CDataFrame et libère la mémoire
void delete_cdataframe(CDataFrame** dataframe) {
    if (dataframe && *dataframe) {
        // Supprime chaque colonne
        for (int i = 0; i < (*dataframe)->num_columns; ++i) {
            delete_column(&((*dataframe)->columns[i]));
        }
        free((*dataframe)->columns);
        free(*dataframe);
        *dataframe = NULL;
    }
}

// Affiche le contenu d'un CDataFrame
void display_cdataframe(CDataFrame* dataframe) {
    if (!dataframe) {
        fprintf(stderr, "Erreur : CDataFrame vide\n");
        return;
    }

    printf("DataFrame avec %d colonnes :\n", dataframe->num_columns);

    // Affiche les titres des colonnes
    for (int i = 0; i < dataframe->num_columns; ++i) {
        printf("%-15s", dataframe->columns[i]->title);
    }
    printf("\n");

    // Affiche les données ligne par ligne
    int num_rows = dataframe->columns[0]->num_rows;
    for (int row = 0; row < num_rows; ++row) {
        for (int col = 0; col < dataframe->num_columns; ++col) {
            // Affiche les données en fonction du type de la colonne
            if (dataframe->columns[col]->type == 0) {
                printf("%-15d", ((int*)dataframe->columns[col]->data)[row]);
            } else if (dataframe->columns[col]->type == 1) {
                if (col == 1) {
                    printf("%-15s", ((char(*)[11])dataframe->columns[col]->data)[row]);
                } else if (col == 4) {
                    printf("%-15s", ((char(*)[3])dataframe->columns[col]->data)[row]);
                } else {
                    printf("%-15c", ((char*)dataframe->columns[col]->data)[row]);
                }
            } else if (dataframe->columns[col]->type == 2) {
                printf("%-15f", ((float*)dataframe->columns[col]->data)[row]);
            }
        }
        printf("\n");
    }
}
