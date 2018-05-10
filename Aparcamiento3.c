#define _CRT_SECURE_NO_WARNINGS
#define NPLAZAS 10
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



struct plaza{
	int estado; // 0 - Libre / 1 - Ocupada 
	char tipo[1]; // M - Moto / C - Coche 
	char matricula[7]; // Formato de la matrícula: NNNNLLL
};

//FUNCIONES:
char menu();






char menu() {
		struct plaza aparcamiento[NPLAZAS];
		char usuario[50] = "admin", password[50] = "1234";
		char usuarioIntroducido[10], passwordIntroducido[10];
		int repite = 1;
		int plazasLibres = NPLAZAS;
		int k, l; //reservar plaza
		int intentos = 0;
		char opcion;
		int buscar, d; //buscar matricula
		char comprobacionMatricula[7];
		char matriculaIntroducida[7];
		int w; //estado parking
		int abandonarPlaza;
		int i = 0, j = 0;//comprobacion matricula
		int a, b; //comprobacion usuario y contraseña
		int opcionAbandonar;
		do {
		getchar();
		printf("Elija una de las siguientes opciones:\n\tR-Reservar plaza.\n\tA-Abandonar plaza.\n\tE-Estado del parking.\n\tB-Buscar matricula.\n\tS.Salir\n");
		scanf("%c", &opcion);
		switch (opcion) {
		case 'r':
		case'R':
			for (k = 0; k < NPLAZAS; k++) {
				if (plazasLibres == 0) {
					printf("El parking esta lleno, disculpe las molestias.\n");
					break;
				}

				else if (plazasLibres != 0) {
					if (aparcamiento[k].estado == 0) {
						printf("La plaza %d esta libre, indique el tipo de su vehiculo: coche(c) o moto(m)\n", k);
						scanf("%s", aparcamiento[k].tipo);
						printf("Ahora introduzca su matricula:\n");
						scanf("%s", aparcamiento[k].matricula);
						matriculaValida();
						for (i = 0; i < 7; i++) {
							aparcamiento[k].matricula[i] = comprobacionMatricula[i];
						}
						aparcamiento[k].estado = 1;
						printf("Ha reservado correctamente la plaza %d.\n", k);
						plazasLibres--;
						break;
					}
				}

			}
			break;
		case'a':
		case 'A':
			printf("Que plaza desea abandonar?\n");
			scanf("%d", &abandonarPlaza);
			if (aparcamiento[abandonarPlaza].estado == 0) {
				printf("La plaza %d ya esta libre\n", abandonarPlaza);
			}
			else if (aparcamiento[abandonarPlaza].estado == 1) {
				printf("Ha abandonado la plaza %d\n", abandonarPlaza);
				aparcamiento[abandonarPlaza].estado = 0;
				plazasLibres++;
			}

			break;
		case 'e':
		case 'E':
			printf("Hay libres %d plazas.\n", plazasLibres);
			for (w = 0; w < NPLAZAS; w++) {
				if (aparcamiento[w].estado == 0) {
					printf("La plaza %d esta libre.\n", w);
				}
				else if (aparcamiento[w].estado == 1) {
					printf("La plaza %d esta ocupada:\t", w);
					printf("Matricula: %s\t", aparcamiento[w].matricula);
					printf("Tipo de vehiculo: %s \n", aparcamiento[w].tipo);
				}
			}
			break;
		case 'b':
		case 'B':
			printf("Introduzca la matricula que desea buscar:   ");
			scanf("%s", matriculaIntroducida);

			for (d = 0; d < NPLAZAS; d++) {
				buscar = strcmp(matriculaIntroducida, aparcamiento[d].matricula);
				if (buscar == 0) {
					printf("El vehiculo con matricula %s se encuentra estacionado en la plaza %d\n", matriculaIntroducida, d);
				}
				else if (buscar != 0) {
					printf("La matricula %s no coincide con ninguna de las de los vehiculos estacionados\n", matriculaIntroducida);
					break;
				}
			}
			break;

		case 's':
		case'S':
			repite = 0;
			break;

		}
		fflush(stdin);
	} while (repite); fflush(stdin);
}


char matriculaValida() {
	struct plaza aparcamiento[NPLAZAS];
	char usuario[50] = "admin", password[50] = "1234";
	char usuarioIntroducido[10], passwordIntroducido[10];
	int repite = 1;
	int plazasLibres = NPLAZAS;
	int k, l; //reservar plaza
	int i = 0, j = 0, p=0;//comprobacion matricula
	int opcionAbandonar;

}




void main() {
	struct plaza aparcamiento[NPLAZAS];
	char usuario[50] = "admin", password[50] = "1234";
	char usuarioIntroducido[10], passwordIntroducido[10];
	int repite = 1;
	int plazasLibres = NPLAZAS;
	int k, l; //reservar plaza
	int intentos = 0;
	char opcion;
	int buscar, d; //buscar matricula

	char matriculaIntroducida[7];
	int w; //estado parking
	int abandonarPlaza;
	int i=0, j=0;//comprobacion matricula
	int a, b; //comprobacion usuario y contraseña
	int opcionAbandonar;
	
	for (l = 0; l < NPLAZAS; l++) {
		aparcamiento[l].estado = 0;
	}
	
	//usuario y contraseña
	do {
		printf("Introduzca el usuario:");
		scanf("%s", usuarioIntroducido); fflush(stdin);
		printf("Introduzca la contraseña:");
		scanf("%s", passwordIntroducido); fflush(stdin);
		a = strcmp(usuarioIntroducido, usuario);
		b = strcmp(passwordIntroducido, password);
		if (a == 0 && b==0) {
			printf("Usuario y contraseña correctos.\n"); fflush(stdin);
			menu();
		}
		else {
			printf("Combinacion usuario-contraseña incorreta, intente de nuevo.\n");
			intentos++;
		}
		if (intentos == 3) {
			printf("Ha superado el numero maximo de intentos.\n");
		}
	} while (intentos < 3); fflush(stdin);









}