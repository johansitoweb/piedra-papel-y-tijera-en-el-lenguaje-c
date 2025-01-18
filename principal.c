#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char jugador, computadora;
    int opcion;

    // Inicializamos el generador de números aleatorios
    srand(time(NULL));

    printf("¡Bienvenido al juego de Piedra, Papel o Tijera!\n");

    do {
        // Pedimos al jugador su elección
        printf("Elige tu jugada (1: Piedra, 2: Papel, 3: Tijera): ");
        scanf("%d", &opcion);

        // Validamos la entrada del jugador
        while (opcion < 1 || opcion > 3) {
            printf("Opción inválida. Ingresa 1, 2 o 3: ");
            scanf("%d", &opcion);
        }

        // Convertimos la opción numérica a un caracter para facilitar la comparación
        switch (opcion) {
            case 1:
                jugador = 'P';
                break;
            case 2:
                jugador = 'A';
                break;
            case 3:
                jugador = 'T';
                break;
        }

        // La computadora elige aleatoriamente
        int eleccion_computadora = rand() % 3 + 1;
        switch (eleccion_computadora) {
            case 1:
                computadora = 'P';
                break;
            case 2:
                computadora = 'A';
                break;
            case 3:
                computadora = 'T';
                break;
        }

        printf("Tu elección: %c\n", jugador);
        printf("Eleccion de la computadora: %c\n", computadora);

        // Determinamos el ganador
        if (jugador == computadora) {
            printf("¡Empate!\n");
        } else if ((jugador == 'P' && computadora == 'T') ||
                   (jugador == 'A' && computadora == 'P') ||
                   (jugador == 'T' && computadora == 'A')) {
            printf("¡Ganaste!\n");
        } else {
            printf("¡Perdiste!\n");
        }

        printf("¿Quieres jugar otra vez? (1: Sí, 2: No): ");
        scanf("%d", &opcion);
    } while (opcion == 1);

    printf("¡Gracias por jugar!\n");

    return 0;
}