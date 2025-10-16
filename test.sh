#!/bin/bash

echo "=== Test d'intégration BubbleSort ==="

# Test 1: Compilation
echo "Test 1: Compilation..."
gcc -o bubblesort bubblesort.c
if [ $? -eq 0 ]; then
    echo "✓ Compilation OK"
else
    echo "✗ Erreur de compilation"
    exit 1
fi

# Test 2: Exécution (plus de scanf, donc pas de timeout nécessaire)
echo "Test 2: Exécution du programme..."
./bubblesort > output.txt 2>&1

if [ $? -eq 0 ]; then
    echo "✓ Programme exécuté sans erreur"
else
    echo "✗ Erreur d'exécution"
    cat output.txt
    exit 1
fi

# Test 3: Vérifications spécifiques
echo "Test 3: Vérification des résultats..."

# Vérifier le tri croissant des entiers
if grep -q "11 12 22 25 34 42 50 64 76 88 90" output.txt; then
    echo "✓ Tri entiers croissant OK"
else
    echo "✗ Tri entiers croissant échoué"
fi

# Vérifier le tri décroissant des entiers  
if grep -q "90 88 76 64 50 42 34 25 22 12 11" output.txt; then
    echo "✓ Tri entiers décroissant OK"
else
    echo "✗ Tri entiers décroissant échoué"
fi

# Vérifier qu'il y a bien des tests de strings
if grep -q "TEST TRI STRINGS" output.txt; then
    echo "✓ Tests de tri de chaînes détectés"
else
    echo "✗ Tests de tri de chaînes manquants"
fi

echo "Test 4: Affichage de la sortie complète..."
echo "--- Début sortie ---"
cat output.txt
echo "--- Fin sortie ---"

# Nettoyage
rm -f bubblesort output.txt

echo "🎉 Tests terminés !"
exit 0