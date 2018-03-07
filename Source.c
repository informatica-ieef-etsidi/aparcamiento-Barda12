#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void main() {
	system("color 5F");
	char opcion;
	int p1, m1, p2, m2;
	char leave;
	p1 = 0;
	p2 = 0;
	while (1) {
		printf("Seleccione una de las siguientes opciones:\n R - Reservar plaza.\n A - Abandonar plaza.\n E - Estado del aparcamiento.\n");
		scanf("%c", &opcion);
		switch (opcion) {
		case 'R':
			if (p1==0) {
				p1 = 1;
				printf("Por favor introduzca su matricula:\t");
				scanf("%d", &m1);
				printf("Ha realizado correctamente su reserva.\n");
			}
			else if(p2 == 0) {
				p2 = 1;
				printf("Por favor introduzca su matricula:\t");
				scanf("%d", &m2);
				printf("Ha realizado correctamente su reserva.\n");
			}
			else {
				printf("Lo sentimos, el parking esta al completo.\n");
			}
			break;
		case 'A':
			printf("Por favor, introduzca su plaza:\t");
			scanf("%c",&leave);
			switch (leave) {
			case'1':
				p1 = 0;
				printf("Ha abandonado la plaza 1 correctamente.\n");
				break;
			case'2':
				p2 = 0;
				printf("Ha abandonado la plaza 2 correctamente.\n");
				break;
			}
			break;
		case 'E':
			if (p1 == 0 && p2 == 0) {
				printf("El parking esta vacio\n");
			}
			 if (p1 == 1) {
				printf("La plaza 1 esta ocupada, matricula: %d\n",m1);
			}
			 if (p2 == 1) {
				printf("La plaza 2 esta ocupada, matricula: %d\n", m2);
			}
			 if (p1 == 0) {
				printf("La plaza 1 esta libre.\n", m1);
			}
			 if (p2 == 0) {
				printf("La plaza 2 esta libre.\n", m1);
			}
			break;
	
		}
		system("pause");
	}
}