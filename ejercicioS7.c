#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 5

void limpiarSaltoLinea(char texto[]) {
    int i = 0;

    while (texto[i] != '\n' && texto[i] != '\0') {
        i++;
    }

    texto[i] = '\0';
}

int sonIguales(char *a, char *b) {
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return 0;
        }
        i++;
    }

    return (a[i] == '\0' && b[i] == '\0');
}

int esNombreValido(char texto[]) {
    int i;

    if (texto[0] == '\0') {
        return 0;
    }

    for (i = 0; texto[i] != '\0'; i++) {
        if (!isalpha(texto[i]) && texto[i] != ' ') {
            return 0;
        }
    }

    return 1;
}

void leerNombre(char mensaje[], char destino[]) {
    int valido = 0;

    do {
        printf("%s", mensaje);
        fgets(destino, 50, stdin);
        limpiarSaltoLinea(destino);

        if (esNombreValido(destino)) {
            valido = 1;
        } else {
            printf("\n  [!] Entrada invalida. Ingrese solo letras.\n\n");
        }

    } while (valido == 0);
}

float leerFloatPositivo(char mensaje[]) {
    char entrada[50];
    float valor;
    char extra;
    int correcto;

    do {
        printf("%s", mensaje);
        fgets(entrada, 50, stdin);

        correcto = sscanf(entrada, "%f %c", &valor, &extra);

        if (correcto != 1) {
            printf("\n  [!] Entrada invalida. Debe ingresar solo un numero.\n\n");
        } else if (valor <= 0) {
            printf("\n  [!] El valor debe ser mayor que 0.\n\n");
        } else {
            return valor;
        }

    } while (1);
}

float leerFloatNoNegativo(char mensaje[]) {
    char entrada[50];
    float valor;
    char extra;
    int correcto;

    do {
        printf("%s", mensaje);
        fgets(entrada, 50, stdin);

        correcto = sscanf(entrada, "%f %c", &valor, &extra);

        if (correcto != 1) {
            printf("\n  [!] Entrada invalida. Debe ingresar solo un numero.\n\n");
        } else if (valor < 0) {
            printf("\n  [!] El valor no puede ser negativo.\n\n");
        } else {
            return valor;
        }

    } while (1);
}

int leerEnteroNoNegativo(char mensaje[]) {
    char entrada[50];
    int valor;
    char extra;
    int correcto;

    do {
        printf("%s", mensaje);
        fgets(entrada, 50, stdin);

        correcto = sscanf(entrada, "%d %c", &valor, &extra);

        if (correcto != 1) {
            printf("\n  [!] Entrada invalida. Debe ingresar solo un numero entero.\n\n");
        } else if (valor < 0) {
            printf("\n  [!] La cantidad no puede ser negativa.\n\n");
        } else {
            return valor;
        }

    } while (1);
}

int leerEnteroConservando(char mensaje[]) {
    char entrada[50];
    int valor;
    char extra;
    int correcto;

    do {
        printf("%s", mensaje);
        fgets(entrada, 50, stdin);

        correcto = sscanf(entrada, "%d %c", &valor, &extra);

        if (correcto != 1) {
            printf("\n  [!] Entrada invalida. Debe ingresar solo un numero entero.\n\n");
        } else if (valor < -1) {
            printf("\n  [!] Ingrese -1 para conservar o un numero mayor o igual a 0.\n\n");
        } else {
            return valor;
        }

    } while (1);
}

float leerFloatConservando(char mensaje[]) {
    char entrada[50];
    float valor;
    char extra;
    int correcto;

    do {
        printf("%s", mensaje);
        fgets(entrada, 50, stdin);

        correcto = sscanf(entrada, "%f %c", &valor, &extra);

        if (correcto != 1) {
            printf("\n  [!] Entrada invalida. Debe ingresar solo un numero.\n\n");
        } else if (valor < 0) {
            printf("\n  [!] Ingrese 0 para conservar o un valor mayor que 0.\n\n");
        } else {
            return valor;
        }

    } while (1);
}

int leerOpcion(char mensaje[]) {
    char entrada[50];
    int valor;
    char extra;
    int correcto;

    do {
        printf("%s", mensaje);
        fgets(entrada, 50, stdin);

        correcto = sscanf(entrada, "%d %c", &valor, &extra);

        if (correcto != 1) {
            printf("\n  [!] Entrada invalida. Debe ingresar solo un numero entero.\n\n");
        } else {
            return valor;
        }

    } while (1);
}

int buscarProducto(char nombres[][50], int total, char *objetivo) {
    int i;

    for (i = 0; i < total; i++) {
        if (sonIguales(nombres[i], objetivo)) {
            return i;
        }
    }

    return -1;
}

void mostrarProductos(char nombres[][50], float tiempos[], float recursos[],
                      int cantidades[], int total) {
    int i;

    if (total == 0) {
        printf("\n  (No hay productos registrados)\n");
        return;
    }

    printf("\n  %-20s %-15s %-15s %-10s\n",
           "Nombre", "Tiempo(min)", "Recursos", "Cantidad");

    for (i = 0; i < total; i++) {
        printf("  %-20s %-15.2f %-15.2f %-10d\n",
               nombres[i], tiempos[i], recursos[i], cantidades[i]);
    }
}

void ingresarProducto(char nombres[][50], float tiempos[], float recursos[],
                      int cantidades[], int *total) {
    char nombre[50];
    int i;

    if (*total >= MAX) {
        printf("\n  [!] Ya se alcanzo el maximo de %d productos.\n", MAX);
        return;
    }

    leerNombre("\n  Nombre del producto: ", nombre);

    if (buscarProducto(nombres, *total, nombre) != -1) {
        printf("\n  [!] Ya existe un producto con ese nombre.\n");
        return;
    }

    tiempos[*total] = leerFloatPositivo("  Tiempo de fabricacion por unidad (minutos): ");
    recursos[*total] = leerFloatPositivo("  Recursos por unidad: ");
    cantidades[*total] = leerEnteroNoNegativo("  Cantidad demandada: ");

    i = 0;
    while (nombre[i] != '\0' && i < 49) {
        nombres[*total][i] = nombre[i];
        i++;
    }

    nombres[*total][i] = '\0';

    (*total)++;

    printf("\n  [OK] Producto registrado correctamente.\n");
}

void editarProducto(char nombres[][50], float tiempos[], float recursos[],
                    int cantidades[], int total) {
    char objetivo[50];
    char nuevoNombre[50];
    int idx;
    int i;
    float val;
    int ival;

    if (total == 0) {
        printf("\n  [!] No hay productos para editar.\n");
        return;
    }

    leerNombre("\n  Nombre del producto a editar: ", objetivo);

    idx = buscarProducto(nombres, total, objetivo);

    if (idx == -1) {
        printf("\n  [!] Producto no encontrado.\n");
        return;
    }

    printf("\n  Editando: %s\n", nombres[idx]);

    do {
        printf("  Nuevo nombre o Enter para conservar '%s': ", nombres[idx]);
        fgets(nuevoNombre, 50, stdin);
        limpiarSaltoLinea(nuevoNombre);

        if (nuevoNombre[0] == '\0') {
            break;
        }

        if (!esNombreValido(nuevoNombre)) {
            printf("\n  [!] Entrada invalida. Ingrese solo letras.\n\n");
        }

    } while (nuevoNombre[0] != '\0' && !esNombreValido(nuevoNombre));

    if (nuevoNombre[0] != '\0') {
        i = 0;

        while (nuevoNombre[i] != '\0' && i < 49) {
            nombres[idx][i] = nuevoNombre[i];
            i++;
        }

        nombres[idx][i] = '\0';
    }

    printf("\n");

    val = leerFloatConservando("  Nuevo tiempo de fabricacion. Ingrese 0 para conservar: ");
    if (val > 0) {
        tiempos[idx] = val;
    }

    val = leerFloatConservando("  Nuevos recursos. Ingrese 0 para conservar: ");
    if (val > 0) {
        recursos[idx] = val;
    }

    ival = leerEnteroConservando("  Nueva cantidad demandada. Ingrese -1 para conservar: ");
    if (ival >= 0) {
        cantidades[idx] = ival;
    }

    printf("\n  [OK] Producto actualizado.\n");
}

void eliminarProducto(char nombres[][50], float tiempos[], float recursos[],
                      int cantidades[], int *total) {
    char objetivo[50];
    int idx;
    int i;
    int j;

    if (*total == 0) {
        printf("\n  [!] No hay productos para eliminar.\n");
        return;
    }

    leerNombre("\n  Nombre del producto a eliminar: ", objetivo);

    idx = buscarProducto(nombres, *total, objetivo);

    if (idx == -1) {
        printf("\n  [!] Producto no encontrado.\n");
        return;
    }

    for (i = idx; i < *total - 1; i++) {
        j = 0;

        while (nombres[i + 1][j] != '\0' && j < 49) {
            nombres[i][j] = nombres[i + 1][j];
            j++;
        }

        nombres[i][j] = '\0';

        tiempos[i] = tiempos[i + 1];
        recursos[i] = recursos[i + 1];
        cantidades[i] = cantidades[i + 1];
    }

    (*total)--;

    printf("\n  [OK] Producto eliminado.\n");
}

void calcularProduccion(char nombres[][50], float tiempos[], float recursos[],
                        int cantidades[], int total) {
    float tiempoTotal = 0.0f;
    float recursosTotal = 0.0f;
    float limTiempo;
    float limRecursos;
    int i;

    if (total == 0) {
        printf("\n  [!] No hay productos registrados.\n");
        return;
    }

    printf("\n  RESUMEN DE PRODUCCION\n");
    printf("  %-20s %-15s %-15s\n",
           "Producto", "Tiempo total", "Recursos total");

    for (i = 0; i < total; i++) {
        float t = tiempos[i] * cantidades[i];
        float r = recursos[i] * cantidades[i];

        printf("  %-20s %-15.2f %-15.2f\n", nombres[i], t, r);

        tiempoTotal = tiempoTotal + t;
        recursosTotal = recursosTotal + r;
    }

    printf("\n  Tiempo total requerido: %.2f minutos\n", tiempoTotal);
    printf("  Recursos totales necesarios: %.2f unidades\n", recursosTotal);

    limTiempo = leerFloatNoNegativo("\n  Ingrese el tiempo disponible en la fabrica (minutos): ");
    limRecursos = leerFloatNoNegativo("  Ingrese los recursos disponibles en la fabrica: ");

    printf("\n  VERIFICACION\n");

    if (tiempoTotal <= limTiempo && recursosTotal <= limRecursos) {
        printf("  [OK] La fabrica PUEDE cumplir con la demanda.\n");
    } else {
        printf("  [X] La fabrica NO puede cumplir con la demanda.\n");

        if (tiempoTotal > limTiempo) {
            printf("      Exceso de tiempo: %.2f minutos\n",
                   tiempoTotal - limTiempo);
        }

        if (recursosTotal > limRecursos) {
            printf("      Exceso de recursos: %.2f unidades\n",
                   recursosTotal - limRecursos);
        }
    }
}

int main() {
    char nombres[MAX][50];
    float tiempos[MAX];
    float recursos[MAX];
    int cantidades[MAX];
    int total = 0;
    int opcion;

    printf("  SISTEMA DE OPTIMIZACION DE PRODUCCION\n");
    printf("  Fabrica de Componentes Electronicos\n");

    do {
        printf("\nMENU PRINCIPAL\n");
        printf("  1. Ingresar producto\n");
        printf("  2. Mostrar productos\n");
        printf("  3. Editar producto\n");
        printf("  4. Eliminar producto\n");
        printf("  5. Calcular y verificar produccion\n");
        printf("  6. Salir\n");

        opcion = leerOpcion("Seleccione una opcion: ");

        switch (opcion) {
            case 1:
                ingresarProducto(nombres, tiempos, recursos, cantidades, &total);
                break;

            case 2:
                mostrarProductos(nombres, tiempos, recursos, cantidades, total);
                break;

            case 3:
                editarProducto(nombres, tiempos, recursos, cantidades, total);
                break;

            case 4:
                eliminarProducto(nombres, tiempos, recursos, cantidades, &total);
                break;

            case 5:
                calcularProduccion(nombres, tiempos, recursos, cantidades, total);
                break;

            case 6:
                printf("\n  Saliendo del sistema. Hasta luego.\n");
                break;

            default:
                printf("\n  [!] Opcion invalida. Intente de nuevo.\n");
        }

    } while (opcion != 6);

    return 0;
}