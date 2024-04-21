#include <stdio.h>
#include "column.h"

int main() {
    // Créer une collonne avec un titre
    COLUMN *mycol = create_column("Colonne n°1");
    if (mycol == NULL) {
        printf("Erreur lors de la création de la colonne.\n");
        return 1; // Return 1 permet de mettre le code erreur
    }

    // Il faut maintenant insérer les différentes valeures saisies dans le tableau
    int values[] = {5, 3, 8, 3, 10};
    size_t num_values = sizeof(values) / sizeof(values[0]);

    // On précise s'il y a une erreur d'insertion de la valeur dans le tableau
    for (size_t i = 0; i < num_values; i++) {
        if (!insert_value(mycol, values[i])) {
            printf("Une erreur est survenue pendant l'insertion de la valeur %d.\n", values[i]);
        }
    }

    // Afficchage de tout le contenu de la colonne
    printf("Affichage de la colonne :\n");
    print_col(mycol);

    // Compter le nombre d'occurrences d'une valeur
    int search_value = 3;
    int count = count_value(mycol, search_value);
    printf("Le nombre d'occurrences de %d est : %d\n", search_value, count);

    // Libérer la mémoire de la colonne
    delete_column(&mycol);

    if (mycol == NULL) {
        printf("La mémoire de la colonne a été libérée.\n");
    } else {
        printf("Erreur lors de la libération de la mémoire de la colonne.\n");
    }

    return 0;
}


// Il y a une erreur qui  s'affiche lors du premier test

// L'objectif est que les tests soient concluants pour toutes les autres fonctions des deux parties du projet C
