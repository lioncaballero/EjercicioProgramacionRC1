# Sistema de Optimización de Producción

## Descripción

Este proyecto corresponde a la actividad evaluativa RC1 de la asignatura **ISWZ1102 - Programación I**.

El programa fue desarrollado en lenguaje C y permite gestionar la producción de una fábrica de componentes electrónicos. El sistema registra productos, calcula el tiempo total de fabricación, calcula los recursos necesarios y verifica si la fábrica puede cumplir con la demanda según el tiempo y los recursos disponibles.

## Funcionalidades del programa

El sistema permite realizar las siguientes acciones:

1. Ingresar productos.
2. Mostrar los productos registrados.
3. Editar los datos de un producto.
4. Eliminar productos.
5. Calcular y verificar la producción.
6. Salir del sistema.

## Datos que maneja el programa

Para cada producto se registran los siguientes datos:

- Nombre del producto.
- Tiempo de fabricación por unidad en minutos.
- Recursos necesarios por unidad.
- Cantidad demandada.

Con estos datos, el programa calcula:

- Tiempo total requerido por producto.
- Recursos totales requeridos por producto.
- Tiempo total general de fabricación.
- Recursos totales generales necesarios.
- Verificación de cumplimiento de la demanda.

## Restricciones consideradas

El programa fue desarrollado considerando las restricciones de la consigna:

- No se utilizan estructuras `struct`.
- No se utilizan archivos para guardar datos permanentemente.
- Se utilizan arreglos para manejar la información.
- Se implementa búsqueda manual de productos.
- El sistema trabaja con un máximo de 5 productos.

## Validaciones implementadas

El programa incluye validaciones para evitar errores durante la ejecución:

- No permite nombres vacíos.
- No permite números ni símbolos en los nombres de productos.
- No permite letras cuando se debe ingresar un número.
- No permite tiempos de fabricación menores o iguales a cero.
- No permite recursos menores o iguales a cero.
- No permite cantidades negativas.
- No permite registrar productos duplicados.
- No permite editar o eliminar productos inexistentes.
- No permite calcular producción si no existen productos registrados.
- Valida las opciones ingresadas en el menú.

## Archivos del proyecto

El proyecto contiene el siguiente archivo principal:

- `main.c`: contiene todo el código fuente del programa.

## Compilación

Para compilar el programa en Windows usando GCC, abrir la terminal o CMD en la carpeta del proyecto y ejecutar:

```bash
gcc main.c -o produccion
