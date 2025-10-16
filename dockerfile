FROM debian:bookworm

RUN apt-get update && apt-get install -y gcc bash

WORKDIR /app
COPY . .

RUN gcc -o bubblesort bubblesort.c

CMD ["./test.sh"]