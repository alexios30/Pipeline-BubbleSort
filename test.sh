#!/bin/bash

./bubblesort > output.txt

if grep -q "11 12 22 25 34 64 90" output.txt; then
    echo "Test réussi ✅"
    exit 0
else
    echo "Test échoué ❌"
    cat output.txt
    exit 1
fi
