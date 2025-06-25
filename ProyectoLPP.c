/*
======================
GESTOR DE TAREAS SIMPLE EN C
======================

Este programa permite al usuario:
- Ingresar tareas y sus descripciones.
- Marcar tareas como completadas.
- Mostrar un resumen con su estado.

Límites:
- Máximo de 100 tareas.
- Nombres de tarea hasta 99 caracteres.
- Descripciones hasta 199 caracteres.

Instrucciones:
1. Ejecuta el programa.
2. Ingresa la cantidad de tareas.
3. Para cada tarea, escribe el nombre y la descripción.
4. Luego, elige si deseas marcarla como completada.

*/
#include <stdio.h>

#include <string.h>

#define MAX_TAREAS 100

void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void aladir_tarea(char l_tareas[][100], char l_descripciones[][200], int i) {
    char t[100];
    char d[200];

    printf("ingrese tarea: ");
    fgets(t, sizeof(t), stdin);
    t[strcspn(t, "\n")] = '\0';
    printf("ingrese descripcion de tarea: ");
    fgets(d, sizeof(d), stdin);
    d[strcspn(d, "\n")] = '\0';
    strcpy(l_tareas[i], t);
    strcpy(l_descripciones[i], d);
}
int main() {
    char buffer[10];
    int c = 0;
    printf(" Cuantas tareas quiere ingresar?: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &c);  // Convertimos el texto leído a número
    char l_tareas[MAX_TAREAS][100];
    char l_descripciones[MAX_TAREAS][200];
    int l_estado[MAX_TAREAS] = {0};
    for (int i = 0; i < c; i++) {
        printf("\nTarea #%d\n", i + 1);
        aladir_tarea(l_tareas, l_descripciones, i);
    }
    for (int i = 0; i < c; i++) {
        char respuesta[10];
        printf("\nQuiere marcar la tarea \"%s\" como completada? (s/n): ", l_tareas[i]);
        fgets(respuesta, sizeof(respuesta), stdin);

        if (respuesta[0] == 's' || respuesta[0] == 'S') {
            l_estado[i] = 1;
        }
    }
    printf("\nResumen de tareas:\n");
    for (int i = 0; i < c; i++) {
        printf("Tarea: %s | Descripcion: %s | Estado: %s\n",
               l_tareas[i],
               l_descripciones[i],
               l_estado[i] ? "Completada" : "Pendiente");
    }
    return 0;
}