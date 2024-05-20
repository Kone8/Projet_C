#ifndef CDATAFRAME_H
#define CDATAFRAME_H


#include "column.h"

// Structure d'un CDataFrame
typedef struct {
    Column** columns;   // Tableau de pointeurs de colonnes
    int num_columns;    // Nombre total de colonnes
} CDataFrame;

// Prototypes des fonctions pour manipuler les DataFrames
CDataFrame* create_cdataframe(int num_columns);  //créer un CDataFrame vide avec un nombre de colonnes spécifique
void delete_cdataframe(CDataFrame** dataframe);  //Supprimer un CDataFrame et (peut être) libérer la mémoire allouée
void display_cdataframe(CDataFrame* dataframe);  //afficher un CDataFrame

#endif /* CDATAFRAME_H */
