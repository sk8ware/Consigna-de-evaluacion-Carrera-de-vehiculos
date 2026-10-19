#include <stdio.h>

char placas[5][20];
float tiempos[5] = {0};
int ocupado[5] = {0};

void crearVehiculo() {
    int p;
    printf("Posicion de salida (0-4): ");
    scanf("%d", &p);

    if (p < 0 || p > 4) {
        printf("Posicion invalida\n");
        return;
    }
    if (ocupado[p]) {
        printf("Posicion ocupada\n");
        return;
    }

    printf("Placa: ");
    scanf("%19s", placas[p]);
    ocupado[p] = 1;
}

void mostrarVehiculos() {
    printf("\nPos  Placa       Tiempo\n");
    for (int i = 0; i < 5; i++) {
        if (ocupado[i])
            printf("%d    %-10s  %.2f\n",
                   i, placas[i], tiempos[i]);
    }
}

void ingresarTiempos() {
    for (int i = 0; i < 5; i++) {
        if (ocupado[i]) {
            do {
                printf("Tiempo de %s: ", placas[i]);
                scanf("%f", &tiempos[i]);
                if (tiempos[i] <= 0)
                    printf("Tiempo invalido\n");
            } while (tiempos[i] <= 0);
        }
    }
}

void imprimirGanador() {
    int ganador = -1;

    for (int i = 0; i < 5; i++) {
        if (ocupado[i] && tiempos[i] > 0) {
            if (ganador == -1 ||
                tiempos[i] < tiempos[ganador])
                ganador = i;
        }
    }

    if (ganador == -1)
        printf("No hay vehiculos con tiempos\n");
    else
        printf("Ganador: %s con %.2f segundos\n",
               placas[ganador], tiempos[ganador]);
}


int main() {
    int op;
    do {
        printf("\n1. Ingresar vehiculo");
        printf("\n2. Mostrar vehiculos");
        printf("\n3. Ingresar tiempos");
        printf("\n4. Mostrar ganador");
        printf("\n5. Salir\n>> ");
        scanf("%d", &op);
        switch (op) {
            case 1: crearVehiculo(); break;
            case 2: mostrarVehiculos(); break;
            case 3: ingresarTiempos(); break;
            case 4: imprimirGanador(); break;
            case 5: printf("Hasta luego\n"); break;
            default: printf("Opcion invalida\n");
        }
    } while (op != 5);

    return 0;
}
