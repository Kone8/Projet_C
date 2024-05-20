#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cdataframe.h"

#define MAX_ROWS 5

// Remplit le dataframe avec des données prédéfinies
void fill_dataframe_with_predefined_data(CDataFrame* dataframe) {
    char* titles[] = {"RANG", "NOM", "AGE", "SCORE", "Nationalite"};
    int types[] = {0, 1, 0, 2, 1}; // 0=int, 1=char, 2=float

    char* last_names[] = {"NAUCHE", "MAHREZ", "RONALDO", "SCHUMACHER", "NADAL"};
    char* nationalities[] = {"FR", "DZ", "PT", "DE", "ES"};

    // Remplit chaque colonne du dataframe avec les titres et les types prédéfinis
    for (int i = 0; i < dataframe->num_columns; ++i) {
        dataframe->columns[i] = create_column(titles[i]);
        dataframe->columns[i]->type = types[i];
        dataframe->columns[i]->num_rows = MAX_ROWS;
        switch (types[i]) {
            case 0: { // Cas pour les entiers
                int* data = (int*)malloc(MAX_ROWS * sizeof(int));
                for (int j = 0; j < MAX_ROWS; ++j) {
                    data[j] = j + 1;
                }
                dataframe->columns[i]->data = data;
                break;
            }
            case 1: { // Cas pour les caractères
                if (i == 1) { // Colonne des noms
                    char (*data)[11] = malloc(MAX_ROWS * 11 * sizeof(char));
                    for (int j = 0; j < MAX_ROWS; ++j) {
                        strncpy(data[j], last_names[j], 10);
                        data[j][10] = '\0';
                    }
                    dataframe->columns[i]->data = data;
                } else if (i == 4) { // Colonne des nationalités
                    char (*data)[3] = malloc(MAX_ROWS * 3 * sizeof(char));
                    for (int j = 0; j < MAX_ROWS; ++j) {
                        strncpy(data[j], nationalities[j], 2);
                        data[j][2] = '\0';
                    }
                    dataframe->columns[i]->data = data;
                }
                break;
            }
            case 2: { // Cas pour les flottants
                float* data = (float*)malloc(MAX_ROWS * sizeof(float));
                for (int j = 0; j < MAX_ROWS; ++j) {
                    data[j] = (float)(j * 1.1);
                }
                dataframe->columns[i]->data = data;
                break;
            }
        }
    }
}

// Remplit le dataframe avec les données saisies par l'utilisateur
void fill_dataframe_from_user_input(CDataFrame* dataframe) {
    for (int i = 0; i < dataframe->num_columns; ++i) {
        char title[50];
        printf("Entrez le titre de la colonne %d: ", i + 1);
        scanf("%s", title);
        dataframe->columns[i] = create_column(title);

        printf("Entrez le type de donnees pour la colonne %d (0=int, 1=char, 2=float): ", i + 1);
        scanf("%d", &(dataframe->columns[i]->type));

        dataframe->columns[i]->num_rows = MAX_ROWS;

        switch (dataframe->columns[i]->type) {
            case 0: { // Cas pour les entiers
                int* data = (int*)malloc(MAX_ROWS * sizeof(int));
                for (int j = 0; j < MAX_ROWS; ++j) {
                    printf("Entrez la donnee type int pour la ligne %d: ", j + 1);
                    scanf("%d", &data[j]);
                }
                dataframe->columns[i]->data = data;
                break;
            }
            case 1: { // Cas pour les caractères
                if (i == 1) { // Colonne des noms
                    char (*data)[11] = malloc(MAX_ROWS * 11 * sizeof(char));
                    for (int j = 0; j < MAX_ROWS; ++j) {
                        printf("Entrez le nom (10 caractères max) pour la ligne %d: ", j + 1);
                        scanf("%10s", data[j]);
                    }
                    dataframe->columns[i]->data = data;
                } else if (i == 4) { // Colonne des nationalités
                    char (*data)[3] = malloc(MAX_ROWS * 3 * sizeof(char));
                    for (int j = 0; j < MAX_ROWS; ++j) {
                        printf("Entrez la nationalite (en deux lettres majuscules) pour la ligne %d: ", j + 1);
                        scanf("%2s", data[j]);
                    }
                    dataframe->columns[i]->data = data;
                } else {
                    char* data = (char*)malloc(MAX_ROWS * sizeof(char));
                    for (int j = 0; j < MAX_ROWS; ++j) {
                        printf("Entrez la donnee type char pour la ligne %d: ", j + 1);
                        scanf(" %c", &data[j]);
                    }
                    dataframe->columns[i]->data = data;
                }
                break;
            }
            case 2: { // Cas pour les flottants
                float* data = (float*)malloc(MAX_ROWS * sizeof(float));
                for (int j = 0; j < MAX_ROWS; ++j) {
                    printf("Entrez la donnee type float pour la ligne %d: ", j + 1);
                    scanf("%f", &data[j]);
                }
                dataframe->columns[i]->data = data;
                break;
            }
        }
    }
}

int main() {
    int num_columns = 5;
    CDataFrame* dataframe = create_cdataframe(num_columns);

    int choice;
    printf("Choisissez les types d'entres suivantes:\n1. Initialiser le cdataframe deja defini dans le fichier \n2. Entrez les valeurs de votre propre cdataframe\n");
    scanf("%d", &choice);

    // Remplit le dataframe selon le choix de l'utilisateur
    if (choice == 1) {
        fill_dataframe_with_predefined_data(dataframe);
    } else if (choice == 2) {
        fill_dataframe_from_user_input(dataframe);
    } else {
        printf("nn\n");
        delete_cdataframe(&dataframe);
        return 1;
    }

    // Affiche le dataframe rempli
    display_cdataframe(dataframe);

    // Libère la mémoire allouée au dataframe
    delete_cdataframe(&dataframe);

    return 0;
}

