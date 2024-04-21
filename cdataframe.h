
#ifndef UNTITLED3_CDATAFRAME_H
#define UNTITLED3_CDATAFRAME_H
// Structure du CDataframe selon la méthode du  tableau de colonnes
typedef struct {
    COLUMN** columns; // Tableau de pointeurs vers des colonnes
    unsigned int num_columns; // Nombre de colonnes actuelles
    unsigned int capacity; // Capacité maximale du tableau de colonnes
} DATAFRAME;

// Prototype permettant de pouvoir créer un CDataframe avec une capacité initiale
/**
 * @goal Créer un CDataframe avec une capacité initiale donnée.
 * @parameter initial_capacity Capacité initiale du tableau de colonnes
 * @return Pointeur vers le CDataframe créé ou NULL en cas d'erreur
 */
DATAFRAME* create_dataframe(unsigned int initial_capacity);

// Prototype permettant d' ajouter une colonne au CDataframe
/**
 * @goal Ajouter une colonne à un CDataframe.
 * @parameter df Pointeur vers le CDataframe
 * @parameter col Pointeur vers la colonne à ajouter
 * @return 1 si la colonne a été ajoutée avec succès, 0 sinon
 */
int add_column(DATAFRAME* df, COLUMN* col);

// Prototype pour récupérer une collonne par son titre
/**
 * @goal Récupérer une colonne d'un CDataframe par son titre.
 * @parameter df Pointeur vers le CDataframe
 * @parameter title Titre de la colonne à chercher
 * @return Pointeur vers la colonne ou NULL si non trouvée
 */
COLUMN* get_column_by_title(const DATAFRAME* df, const char* title);

// Prototype pour afficher le contenu du CDataframe
/**
 * @goal Afficher le contenu d'un CDataframe.
 * @parameter df Pointeur vers le CDataframe
 */
void print_dataframe(const DATAFRAME* df);

// Prototype pour libérer la mémoire du CDataframe
/**
 * @goal Libérer la mémoire allouée pour un CDataframe.
 * @parameter df Pointeur vers le pointeur du CDataframe (pour le mettre à NULL après suppression)
 */
void delete_dataframe(DATAFRAME** df);

// Prototype pour compter le nombre de valeurs d'un type quelconque dans le CDataframe
/**
 * @goal Compter le nombre de valeurs d'un certain type dans un CDataframe.
 * @parameter df Pointeur vers le CDataframe
 * @parameter column_type Type de colonne (ENUM_TYPE)
 * @return Nombre total de valeurs de ce type dans le dataframe
 */
unsigned int count_values_by_type(const DATAFRAME* df, ENUM_TYPE column_type);

// Prototype pour obtenir le nombre de colonnes dans le CDataframe
/**
 * @goal Obtenir le nombre de colonnes dans un CDataframe.
 * @parameter df Pointeur vers le CDataframe
 * @return Nombre de colonnes actuelles dans le dataframe
 */
unsigned int get_number_of_columns(const DATAFRAME* df);

#endif //UNTITLED3_CDATAFRAME_H
