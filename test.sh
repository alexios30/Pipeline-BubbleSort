#!/bin/bash

# Fournir toutes les entrées nécessaires au programme
# 1 -> menu principal : entiers
# 1 -> tri croissant
# \n -> appuyer sur entrée pour continuer
# 3 -> quitter
printf "1" | ./bubblesort > output.txt

if grep -q "11 12 22 25 34 64 50 42 76 88 90" output.txt; then
    echo "Test réussi ✅"
    exit 0
else
    echo "Test échoué ❌"
    cat output.txt
    exit 1
fi
