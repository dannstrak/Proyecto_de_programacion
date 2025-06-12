#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VEHICULOS 100
#define LONGITUD_PLACA 10
#define LONGITUD_NOMBRE 50

typedef struct {
	char placa[LONGITUD_PLACA];
	char marca[LONGITUD_NOMBRE];
	char modelo[LONGITUD_NOMBRE];
	int anio;
	char propietario[LONGITUD_NOMBRE];
	bool activo;
} Vehiculo;

Vehiculo vehiculos[MAX_VEHICULOS];
int totalVehiculos = 0;

void registrarVehiculo() {
	if (totalVehiculos >= MAX_VEHICULOS) {
		printf("No hay espacio para m�s veh�culos.\n");
		return;
	}
	
	printf("\n--- Registrar Nuevo Veh�culo ---\n");
	
	printf("Placa: ");
	scanf("%s", vehiculos[totalVehiculos].placa);
	
	printf("Marca: ");
	scanf("%s", vehiculos[totalVehiculos].marca);
	
	printf("Modelo: ");
	scanf("%s", vehiculos[totalVehiculos].modelo);
	
	printf("A�o: ");
	scanf("%d", &vehiculos[totalVehiculos].anio);
	
	printf("Propietario: ");
	scanf("%s", vehiculos[totalVehiculos].propietario);
	
	vehiculos[totalVehiculos].activo = true;
	
	totalVehiculos++;
	printf("Veh�culo registrado exitosamente!\n");
}

void buscarVehiculo() {
	char placa[LONGITUD_PLACA];
	printf("\n--- Buscar Veh�culo ---\n");
	printf("Ingrese placa a buscar: ");
	scanf("%s", placa);
	
	for (int i = 0; i < totalVehiculos; i++) {
		if (strcmp(vehiculos[i].placa, placa) == 0) {
			printf("\nInformaci�n del Veh�culo:\n");
			printf("Placa: %s\n", vehiculos[i].placa);
			printf("Marca: %s\n", vehiculos[i].marca);
			printf("Modelo: %s\n", vehiculos[i].modelo);
			printf("A�o: %d\n", vehiculos[i].anio);
			printf("Propietario: %s\n", vehiculos[i].propietario);
			printf("Estado: %s\n", vehiculos[i].activo ? "Activo" : "Inactivo");
			return;
		}
	}
	
	printf("Veh�culo no encontrado.\n");
}

void mostrarMenu() {
	printf("\n=== SISTEMA_DE_MATRICULACION_VEHICULAR ===\n");
	printf("1. Registrar nuevo veh�culo\n");
	printf("2. Buscar veh�culo por placa\n");
	printf("3. Salir\n");
	printf("Seleccione una opci�n: ");
}

int main() {
	int opcion;
	
	while (1) {
		mostrarMenu();
		scanf("%d", &opcion);
		
		switch(opcion) {
		case 1:
			registrarVehiculo();
			break;
		case 2:
			buscarVehiculo();
			break;
		case 3:
			printf("Saliendo del sistema...\n");
			return 0;
		default:
			printf("Opci�n no v�lida. Intente nuevamente.\n");
		}
	}
	
	return 0;
}
