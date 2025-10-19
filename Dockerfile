FROM gcc:latest

WORKDIR /app

# Copier le code source
COPY bubblesort.c .
COPY test.sh .

# Compiler le programme
RUN gcc -o bubblesort bubblesort.c

# Rendre le script de test exécutable
RUN chmod +x test.sh

# Commande par défaut
CMD ["./bubblesort"]
