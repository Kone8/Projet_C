#ifndef COLUMN_H
#define COLUMN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Taille pour la réallocation d'espace dans le tableau
#define REALOC_SIZE 256

// Structure définie afin de pouvoir représenter une colonne
typedef struct {
    char* title;  // Titre de la colonne
    int* data;  // Tableau d'entiers pour les données du tableau
    size_t physical_size;  // Taille physique du tableau
    size_t logical_size;  // Taille logique du tableau
} COLUMN;

// Prototype de plusieures fonctions afin de pouvoir gérer une colonne

COLUMN* create_column(const char* title) {
    // Il faut allouer la memoire afin de pouvoir créeer une nouvelle colonne
    COLUMN* col = (COLUMN*)malloc(sizeof(COLUMN));
    if (col == NULL) {
        // Si l'allocation échoue, retourner NULL
        return NULL;
    }
    // Il faut allouer de la mémoire pour le titre et le copier
    col->title = strdup(title);
    if (col->title == NULL) {
        // Utilisation de free, comme ca si la copie échoue, on pourra libérer la mémoire de la colonne
        free(col);
        return NULL;
    }

    // Initialiser le tableau de données à NULL
    col->data = NULL;
    col->physical_size = 0;
    col->logical_size = 0;

    // Retourner le pointeur vers la colonne créée
    return col;
}

int insert_value(COLUMN* col, int value);

void delete_column(COLUMN** col) {
    if (col == NULL || *col == NULL) {
        // Si le pointeur est déjà NULL, il n'y a rien a faire de plus donc return
        return;
    }

    // On peut libérer la structure du tableau en commencant par le titre puis les données et enfin la structure

    // Libérer le titre de la colonne
    if ((*col)->title != NULL) {
        free((*col)->title);
    }

    // Libérer le tableau de données
    if ((*col)->data != NULL) {
        free((*col)->data);
    }

    // Libérer la structure de la colonne
    free(*col);

    // Mettre le pointeur de la colonne à NULL afin de pouvoir eviter les acces qui ne sont pas corrects
    *col = NULL;
}

void print_col(const COLUMN* col) {
    // Il faut d'abbord vérifier si le pointeur vers la colonne est NULL
    if (col == NULL) {
        printf("Erreur : La colonne est NULL.\n");
        return;
    }

    // Afficher le titre de la colonne
    printf("Titre de la colonne : %s\n", col->title);

    // Vérifier si la colonne est vide
    if (col->data == NULL || col->logical_size == 0) {
        printf("La colonne '%s' est vide.\n", col->title);
        return;
    }

    // Afficher les valeurs de la colonne avec leurs index
    for (size_t i = 0; i < col->logical_size; i++) {
        printf("[%zu] %d\n", i, col->data[i]);
    }
}


int count_value(const COLUMN* col, int value) {
    // Vérifier si le poiinteur de la collonne est NULL
    if (col == NULL) {
        return 0; // Pas de collonne, donc pas d'occurrences
    }

    // mettre un IF car si la collonne n'a pas de données ou est vide il n'y a logiquement aucune occurrence
    if (col->data == NULL || col->logical_size == 0) {
        return 0;
    }

    int count = 0; // Permettre de pouvoir compter le nombres d'occurences

    // Parcourir la colonne pour compter les occurrences
    for (size_t i = 0; i < col->logical_size; i++) {
        if (col->data[i] == value) {
            count++; // Incrémenter le compteur d'occurences si la valeur correspond
        }
    }

    return count; // Retourner le nombre total d'occurrencees.
}

/**
 * @goal Obtenir la valeur à une certaine position donnée dans une colonne.
 * @parameter 1 :   col Pointeur vers la colonne du tableau
 * @parameter 2 : index qui est la position dans le tableau à chercher.
 * @return Valeur à cette position ou -1 si hors limites
 */
int get_value(const COLUMN* col, size_t index);

/**
 * @goal Compter le nombre de valeurs supérieures à x dans une colonne.
 * @parameter 1 : col Pointeur vers la colonne
 * @parameter 2 : Valeur seuil.
 * @return Nombre de valeurs supérieures à x
 */
int count_greater_than(const COLUMN* col, int x);

/**
 * @goal Compter le nombre de valeurs inférieures à x dans une colonne.
 * @parameter 1 : col Pointeur vers la colonne
 * @parameter  2 : x Valeur seuil
 * @return Nombre de valeurs inférieures à x
 */
int count_less_than(const COLUMN* col, int x);

#endif // COLUMN_H
