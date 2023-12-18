#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura para el empleado
struct Empleado {
    char nombre[50];
    float salario;
    char departamento[50];
};

// Prototipos de funciones
void agregarEmpleado(struct Empleado *empleados, int *numEmpleados);
void mostrarEmpleados(struct Empleado *empleados, int numEmpleados);
void buscarEmpleado(struct Empleado *empleados, int numEmpleados, const char *nombre);
void modificarEmpleado(struct Empleado *empleados, int numEmpleados, const char *nombre);
void eliminarEmpleado(struct Empleado *empleados, int *numEmpleados, const char *nombre);

int main() {
    struct Empleado empleados[100];  // Puedes ajustar el tamaño según tus necesidades
    int numEmpleados = 0;
    int opcion;
    char nombreBuscar[50];

    do {
        printf("\n--- Sistema de Registro de Empleados ---\n");
        printf("1. Agregar Empleado\n");
        printf("2. Mostrar Empleados\n");
        printf("3. Buscar Empleado\n");
        printf("4. Modificar Empleado\n");
        printf("5. Eliminar Empleado\n");
        printf("0. Salir\n");

        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarEmpleado(empleados, &numEmpleados);
                break;
            case 2:
                mostrarEmpleados(empleados, numEmpleados);
                break;
            case 3:
                printf("Ingrese el nombre del empleado a buscar: ");
                scanf(" %[^\n]s", nombreBuscar);
                buscarEmpleado(empleados, numEmpleados, nombreBuscar);
                break;
            case 4:
                printf("Ingrese el nombre del empleado a modificar: ");
                scanf(" %[^\n]s", nombreBuscar);
                modificarEmpleado(empleados, numEmpleados, nombreBuscar);
                break;
            case 5:
                printf("Ingrese el nombre del empleado a eliminar: ");
                scanf(" %[^\n]s", nombreBuscar);
                eliminarEmpleado(empleados, &numEmpleados, nombreBuscar);
                break;
            case 0:
                printf("Saliendo del programa. ¡Hasta luego!\n");
                break;
            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
        }

    } while (opcion != 0);

    return 0;
}

void agregarEmpleado(struct Empleado *empleados, int *numEmpleados) {
    if (*numEmpleados < 100) {  // Verifica que no se exceda el límite de empleados
        struct Empleado nuevoEmpleado;

        printf("Ingrese el nombre del empleado: ");
        scanf(" %[^\n]s", nuevoEmpleado.nombre);

        printf("Ingrese el salario del empleado: ");
        scanf("%f", &nuevoEmpleado.salario);

        printf("Ingrese el departamento del empleado: ");
        scanf(" %[^\n]s", nuevoEmpleado.departamento);

        empleados[*numEmpleados] = nuevoEmpleado;
        (*numEmpleados)++;

        printf("Empleado agregado con éxito.\n");
    } else {
        printf("No se pueden agregar más empleados. El límite ha sido alcanzado.\n");
    }
}

void mostrarEmpleados(struct Empleado *empleados, int numEmpleados) {
    if (numEmpleados > 0) {
        printf("\nLista de Empleados:\n");
        for (int i = 0; i < numEmpleados; i++) {
            printf("Nombre: %s\n", empleados[i].nombre);
            printf("Salario: %.2f\n", empleados[i].salario);
            printf("Departamento: %s\n\n", empleados[i].departamento);
        }
    } else {
        printf("No hay empleados registrados.\n");
    }
}

void buscarEmpleado(struct Empleado *empleados, int numEmpleados, const char *nombre) {
    for (int i = 0; i < numEmpleados; i++) {
        //strcpy(empleados[i].nombre,nombre);
        if (strcmp(empleados[i].nombre, nombre) == 0) {
            printf("\nEmpleado encontrado:\n");
            printf("Nombre: %s\n", empleados[i].nombre);
            printf("Salario: %.2f\n", empleados[i].salario);
            printf("Departamento: %s\n", empleados[i].departamento);
            return;
        }
    }

    printf("\nEmpleado no encontrado.\n");
}

void modificarEmpleado(struct Empleado *empleados, int numEmpleados, const char *nombre) {
    for (int i = 0; i < numEmpleados; i++) {
        if (strcmp(empleados[i].nombre, nombre) == 0) {
            printf("Ingrese el nuevo salario del empleado: ");
            scanf("%f", &empleados[i].salario);

            printf("Ingrese el nuevo departamento del empleado: ");
            scanf(" %[^\n]s", empleados[i].departamento);

            printf("\nEmpleado modificado con éxito.\n");
            return;
        }
    }

    printf("\nEmpleado no encontrado. No se puede modificar.\n");
}

void eliminarEmpleado(struct Empleado *empleados, int *numEmpleados, const char *nombre) {
    for (int i = 0; i < *numEmpleados; i++) {
        if (strcmp(empleados[i].nombre, nombre) == 0) {
            // Elimina el empleado moviendo los elementos restantes en el array
            for (; i < *numEmpleados - 1; i++) {
                empleados[i] = empleados[i + 1];
            }

            (*numEmpleados)--;
            printf("\nEmpleado eliminado con éxito.\n");
            return;
        }
    }

    printf("\nEmpleado no encontrado. No se puede eliminar.\n");
}
