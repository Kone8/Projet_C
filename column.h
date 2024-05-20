#ifndef COLUMN_H
#define COLUMN_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Structure représentant une colonne dans un dataframe

typedef struct {
    char* title; // Titre de la colonne
    void* data; // Données de la colonne
    int type; // Type de données de la colonne (0 = entier, 1 = caractère, 2 = flottant)
    int num_rows; // Nombre de lignes dans la colonne
} Column;

// Fonction pour créer une colonne avec un titre
Column* create_column(const char* title);

//Fonction servant à supprimer une colonne et libérer la mémoire allouée
void delete_column(Column** column);

#endif /* COLUMN_H */

