#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Fonction pour trier les entiers
void bubbleSortInt(int arr[], int n, int ascending) {
    int i, j, temp;
    int swapped;
    
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        
        for (j = 0; j < n - i - 1; j++) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        
        if (swapped == 0) {
            break;
        }
    }
}

// Fonction pour trier les chaînes de caractères
void bubbleSortString(char *arr[], int n, int ascending) {
    int i, j;
    char *temp;
    int swapped;
    
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        
        for (j = 0; j < n - i - 1; j++) {
            int comparison = strcmp(arr[j], arr[j + 1]);
            
            if ((ascending && comparison > 0) || (!ascending && comparison < 0)) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        
        if (swapped == 0) {
            break;
        }
    }
}

// Fonction pour afficher un tableau d'entiers
void printArrayInt(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Fonction pour afficher un tableau de chaînes
void printArrayString(char *arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("\"%s\" ", arr[i]);
    }
    printf("\n");
}

// Fonction pour tester le tri d'entiers croissant
void testTriEntiersCroissant() {
    int nombres[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42};
    int n = sizeof(nombres) / sizeof(nombres[0]);
    
    printf("=== TEST TRI ENTIERS CROISSANT ===\n");
    printf("Avant tri : ");
    printArrayInt(nombres, n);
    
    bubbleSortInt(nombres, n, 1);
    
    printf("Après tri : ");
    printArrayInt(nombres, n);
    printf("\n");
}

// Fonction pour tester le tri d'entiers décroissant
void testTriEntiersDecroissant() {
    int nombres[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42};
    int n = sizeof(nombres) / sizeof(nombres[0]);
    
    printf("=== TEST TRI ENTIERS DECROISSANT ===\n");
    printf("Avant tri : ");
    printArrayInt(nombres, n);
    
    bubbleSortInt(nombres, n, 0);
    
    printf("Après tri : ");
    printArrayInt(nombres, n);
    printf("\n");
}

// Fonction pour tester le tri de chaînes croissant
void testTriStringsCroissant() {
    char *phrases[] = {
        "Le chat mange sa nourriture",
        "Une belle journée ensoleillée", 
        "Programming is fun",
        "Bonjour tout le monde",
        "123 est un nombre",
        "Apple pie recipe",
        "Zebra crossing"
    };
    int n = sizeof(phrases) / sizeof(phrases[0]);
    
    printf("=== TEST TRI STRINGS CROISSANT ===\n");
    printf("Avant tri :\n");
    printArrayString(phrases, n);
    
    bubbleSortString(phrases, n, 1);
    
    printf("Après tri :\n");
    printArrayString(phrases, n);
    printf("\n");
}

// Fonction pour tester le tri de chaînes décroissant
void testTriStringsDecroissant() {
    char *phrases[] = {
        "Le chat mange sa nourriture",
        "Une belle journée ensoleillée",
        "Programming is fun", 
        "Bonjour tout le monde",
        "123 est un nombre",
        "Apple pie recipe",
        "Zebra crossing"
    };
    int n = sizeof(phrases) / sizeof(phrases[0]);
    
    printf("=== TEST TRI STRINGS DECROISSANT ===\n");
    printf("Avant tri :\n");
    printArrayString(phrases, n);
    
    bubbleSortString(phrases, n, 0);
    
    printf("Après tri :\n");
    printArrayString(phrases, n);
    printf("\n");
}

// Programme principal qui lance tous les tests
int main() {
    printf("=== PROGRAMME DE TEST BUBBLE SORT ===\n\n");
    
    testTriEntiersCroissant();
    testTriEntiersDecroissant();
    testTriStringsCroissant();
    testTriStringsDecroissant();
    
    printf("=== TOUS LES TESTS TERMINES ===\n");
    return 0;
}