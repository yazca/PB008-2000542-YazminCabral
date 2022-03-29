
#include <iostream>
#include <conio.h>
#include <stdio.h>


using namespace std;

struct citas {

	char nombre[50];
	char hora[6];
	char tratamiento[50];
	char descripcion[100];
	float precio;


};

int main()
{
	int opcion = 1;
	int menu = 1;
	int i = 0;
	int j = 0;

	struct citas cita[3];

	while (menu == 1)
	{
		system("cls");
		printf("\t----PAGINA DE CITAS----\n");
		printf("\t1.Agendar cita\n \t2.Modificar cita\n \t3.Eliminar cita\n \t4.Lista de citas\n \t5.Salir\n");
		scanf_s("%d", &opcion);
		switch (opcion)
		{
		case 1:
			if (i < 3)
			{
				printf("\nNumero de cita: %d", (i + 1));
				printf("\nIngrese el nombre del paciente:\n");
				cin.ignore();
				cin.getline(cita[i].nombre, 50, '\n');

				printf("\nIngrese la hora del tratamiento: \n");
				
				cin.getline(cita[i].hora, 6, '\n');

				printf("\n Nombre del tratamiento: \n");
				
				cin.getline(cita[i].tratamiento, 50, '\n');

				printf("\n Defina el tratamiento: \n");
				
				cin.getline(cita[i].descripcion, 100, '\n');

				printf("\nPrecio del tratamiento: \n");
				scanf_s("%f", &cita[i].precio);
				i++;
			}
			else
			{
				printf("\nya se ingresaron todas las citas posibles");
			}
			break;

		case 2:
			printf("\nopcion todavia no habilitada\n");
			system("pause");
			break;

		case 3:
			printf("\nopcion todavia no habilitada\n");
			system("pause");
			break;

		case 4:
			if (i >= 1)
			{
				for (j = 0; j < i; j++)
				{
					printf("\nNumero de cita: %d", (j + 1));
					cout<<" Nombre del paciente: "<<cita[j].nombre;
					cout << " Hora del tratamiento: " << cita[j].hora;
					cout << " Tratamiento: " << cita[j].tratamiento;
					cout << " Descripcion: " << cita[j].descripcion;
					cout << " Precio: " << cita[j].precio<<endl;
				}
				system("pause");
			}
			else {
				printf("\nIngrese datos\n");
				system("pause");
			}
			break;

		case 5:
			exit(0);
			break;

		default:
			printf("opcion no valida\n");
			system("pause");
			break;
		}
	}

}
