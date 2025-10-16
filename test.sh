#!/bin/bash
# filepath: c:\Users\alexi\BUT3\QualiteDev\test.sh

echo "=== Test d'intégration BubbleSort ==="

# Test 1: Vérifier que le programme compile
echo "Test 1: Compilation..."
gcc -o bubblesort bubblesort.c
if [ $? -eq 0 ]; then
    echo "✓ Compilation OK"
else
    echo "✗ Erreur de compilation"
    exit 1
fi

# Test 2: Lancer le programme avec des entrées et vérifier qu'il ne crash pas
echo "Test 2: Exécution du programme..."
echo -e "1\n1\n3" | timeout 10s ./bubblesort > output.txt 2>&1
if [ $? -eq 0 ]; then
    echo "✓ Programme exécuté sans erreur"
else
    echo "✗ Erreur d'exécution ou timeout"
    exit 1
fi

# Test 3: Vérifier qu'on a bien une sortie de tri
echo "Test 3: Vérification du résultat..."
if grep -q "11 12 22 25 34 42 50 64 76 88 90" output.txt; then
    echo "✓ Tri croissant fonctionne"
else
    echo "✗ Le tri ne fonctionne pas comme attendu"
    echo "Contenu de la sortie:"
    cat output.txt
    exit 1
fi

# Nettoyage
rm -f bubblesort output.txt

echo "🎉 Tous les tests d'intégration passent !"
exit 0