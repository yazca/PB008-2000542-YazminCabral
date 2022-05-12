#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include<stdlib.h>

using namespace std;
void agendar();
void modificar();
void eliminar();
void lista();
void guardar();

int alta = 1, * hora, * minuto, *cantidad;
double * total, * subtotal;

float * precio;
string* nombre, * tratamiento, * descripcion;

int main()
{
	int menu;
	int salir = 0;
	while (salir == 0) {
		cout << "\t-----Citas dentales-----\n 1.-Agendar cita\n 2.-Modificar cita\n 3.-Eliminar cita\n 4.-Lista de citas vigentes\n 5.-Limpiar pantalla\n 6.-Salir\n";
		cin >> menu;
		switch (menu)
		{
		case 1: //agendar cita
			agendar();
			break;

		case 2: //modificar cita
			modificar();
			break;

		case 3: //eliminar cita
			eliminar();
			break;

		case 4: //lista de citas vigentes
			lista();
			break;

		case 5: //Limpiar pantalla
			system("cls");
			break;

		case 6: //salir
			guardar();
			exit(1);
			break;

		default:
			break;
		}
	}
}

void agendar() {

	cout << "\nEscriba la cantidad de registros que desea generar: ";
	cin >> alta;
	nombre = new string[alta];
	tratamiento = new string[alta];
	descripcion = new string[alta];
	precio = new float[alta];
	cantidad = new int[alta];
	subtotal = new double[alta];
	total = new double[alta];
	hora = new int[alta];
	minuto = new int[alta];

	for (int i = 0; i < alta; i++)
	{
		cout << "No. de cita: " << i+1;
		cout << "\nIngrese el nombre del paciente: ";
		while (getchar() != '\n');
		getline(cin, nombre[i]);
		cout << "\nIngrese la hora del tratamiento: ";
		cin >> hora[i];
		while(hora[i] > 23 or hora[i]<0)
		{
			cout << "\nIngrese una hora valida: ";
			cin >> hora[i];
		}


		cout << "\nIngrese los minutos: ";
		cin >> minuto[i];
		while (minuto[i]>59 or minuto[i]<0)
		{
			cout << "\nIngrese minutos validos: ";
			cin >> minuto[i];
		}

		while (getchar() != '\n');
		cout << "\nEscriba el nombre del tratamiento: ";
		getline(cin, tratamiento[i]);
		cout << "\nDescriba el tratamiento: ";
		getline(cin, descripcion[i]);
		cout << "\nIngrese la cantidad de tratamiento: ";
		cin >> cantidad[i];
		cout << "\nIngrese el precio unitario del tratamiento: ";
		cin >> precio[i];
		subtotal[i] = cantidad[i] * precio[i];
		total[i] = subtotal[i] + (subtotal[i] * .16);
		cout << "\nEl subtotal es: " << subtotal[i];
		cout << "\nEl total es: " << total[i]<<endl<<endl;
	}
}

void modificar() {
	int j, opcion;
	cout << "\nIngrese el numero de cita que desea modificar: ";
	cin >> j;
	j = j - 1;
	if (j < alta and j>=0)
	{
		cout << "\n¿Que desea modificar? 1.-Nombre 2.-Tratamiento 3.-Descripcion 4.-Precio unitario 5.-Cantidad 6.-Hora\n";
		cin >> opcion;
		switch (opcion)
		{
		case 1: 
			while (getchar() != '\n');
			cout<<"\nIngrese el nuevo nombre: ";
			getline(cin, nombre[j]);
			break;
		case 2: 
			while (getchar() != '\n');
			cout << "\nIngrese el nuevo tratamiento: ";
			getline(cin, tratamiento[j]);
			break;
		case 3: 
			while (getchar() != '\n');
			cout << "\nEscriba el nuevo tratamiento: ";
			getline(cin, descripcion[j]);
			break;
		case 4:
			cout << "\nIngrese el nuevo precio unitario: ";
			cin >> precio[j];
			subtotal[j] = cantidad[j] * precio[j];
			total[j] = subtotal[j] + (subtotal[j] * .16);
			break;
		case 5:
			cout << "\nIngrese la nueva cantidad: ";
			cin>>cantidad[j];
			subtotal[j] = cantidad[j] * precio[j];
			total[j] = subtotal[j] + (subtotal[j] * .16);
			break;
		case 6:
			cout << "\nIngrese la nueva hora del tratamiento: ";
			cin >> hora[j];
			while (hora[j] > 23 or hora[j] < 0)
			{
				cout << "\nIngrese una hora valida: ";
				cin >> hora[j];
			}


			cout << "\nIngrese los nuevos minutos: ";
			cin >> minuto[j];
			while (minuto[j] > 59 or minuto[j] < 0)
			{
				cout << "\nIngrese minutos validos: ";
				cin >> minuto[j];
			}

			
			break;
		default:
			break;
		}
		cout << "\t---Dato modificado correctamente---\n\n";
	}
	else
	{
		cout << "\nIngrese un numero de cita valido\n";
		system("pause");
	}
}

void eliminar() {

	int i, k;
	cout << "\nIngrese el numero de la cita que desea eliminar: ";
	cin >> k;
	if (k < alta and k >= 0)
	{
		for (i = k; i < alta; i++)
		{
			nombre[i-1] = nombre[i];
			tratamiento[i-1] = tratamiento[i];
			descripcion[i-1] = descripcion[i];
			precio[i-1] = precio[i];
			cantidad[i-1] = cantidad[i];
			total[i-1] = total[i];
			hora[i-1] = hora[i];
			minuto[i-1] = minuto[i];
			subtotal[i-1] = subtotal[i];
		}
		alta = alta - 1;
		cout << "\t---Cita eliminada---\n\n";
	}
	else
	{
		cout << "\nIngrese un numero de cita calido\n";
		system("pause");
	}


}
void lista() {
	int i;
	for (i = 0; i < alta; i++)
	{
		cout << "No. de cita: " << i+1<<endl;
		cout << "Nombre del paciente: " << nombre[i]<<endl;
		if (hora[i] == 0 and minuto[i]==0) {
			cout << "Hora del tratamiento: " <<  "00:00" << endl;
		}
		else if (hora[i] == 0)
		{
			if (minuto[i] < 10) {
				cout << "Hora del tratamiento: " << "00:0" << minuto[i] << endl;
			}
			else {
				cout << "Hora del tratamiento: " << "00:" << minuto[i] << endl;
			}
			
		}
		else if(minuto[i]==0)
		{
			cout << "Hora del tratamiento: " << hora[i] << ":00" << endl;
		}
		else {
			if (minuto[i] < 10)
			{
				cout << "Hora del tratamiento: " << hora[i] << ":0" << minuto[i] << endl;
			}
			else {
				cout << "Hora del tratamiento: " << hora[i] << ":" << minuto[i] << endl;
			}
		}

		cout << "Tratamiento: " << tratamiento[i]<<endl;
		cout << "Descripcion del tratamiento: " << descripcion[i] << endl;
		cout << "Cantidad de tratamiento: " << cantidad[i] << endl;
		cout << "Precio unitario del tratamiento: " << precio[i]<<endl;
		cout << "Subtotal: " << subtotal[i] << endl;
		cout << "Total: " << total[i] << endl<<endl;
	}

}

void guardar()
{
	ofstream archivo;
	archivo.open("citas.txt", ios::out);
	if (archivo.fail())
	{
		cout << "ERROR NO SE PUDO CREAR EL ARCHIVO";
		exit(1);
	}
	
	archivo << "\t-----CITAS DENTALES-----\n";
	for (int i = 0; i < alta; i++)
	{
		archivo << "No. de cita: " << i + 1 << endl;
		archivo << "Nombre del paciente: " << nombre[i] << endl;
		if (hora[i] == 0 and minuto[i] == 0) {
			archivo << "Hora del tratamiento: " << "00:00" << endl;
		}
		else if (hora[i] == 0)
		{
			if (minuto[i] < 10) {
				archivo << "Hora del tratamiento: " << "00:0" << minuto[i] << endl;
			}
			else {
				archivo << "Hora del tratamiento: " << "00:" << minuto[i] << endl;
			}

		}
		else if (minuto[i] == 0)
		{
			archivo << "Hora del tratamiento: " << hora[i] << ":00" << endl;
		}
		else {
			if (minuto[i] < 10)
			{
				archivo << "Hora del tratamiento: " << hora[i] << ":0" << minuto[i] << endl;
			}
			else {
				archivo << "Hora del tratamiento: " << hora[i] << ":" << minuto[i] << endl;
			}
		}
		archivo << "Tratamiento: " << tratamiento[i] << endl;
		archivo << "Descripcion del tratamiento: " << descripcion[i] << endl;
		archivo << "Cantidad de tratamiento: " << cantidad[i] << endl;
		archivo << "Precio unitario del tratamiento: " << precio[i] << endl;
		archivo << "Subtotal: " << subtotal[i] << endl;
		archivo << "Total: " << total[i] << endl<<endl<<endl;
	}

}