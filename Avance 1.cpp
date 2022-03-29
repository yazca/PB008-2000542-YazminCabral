#include <iostream>
using namespace std;
int main()
{
	//variables
	int menu;
	int salir=1;
	char nombre[100];
	char tratamiento[100];
	char descripcion[100];
	int hora;
	int put; //precio unitario tratamiento
	int pu; //precio unitario
	int cantidad;
	int total;
	//indices
	int i=1;
	int bus = 1; //indice para buscar en un arreglo
	int obj=1; //objetivo al buscar
	//arreglos
	string nom_cita[100];
	string tra_cita[100];
	string des_cita[100];
	int hora_cita[100];
	int put_cita[100];
	int pu_cita[100];
	int can_cita[100];
	int total_cita[100];

	//usar cin.get no funciona por alguna razon (el programa empieza a darle enter a todo) por lo tanto lo deje con cin

	do 
	{
		system("cls");
		cout << "Ingrese que quiere hacer:"<<endl;
		cout << "1.Agendar cita" << endl << "2.Modificar cita" << endl << "3.Eliminar cita" << endl << "4.Mostrar lista de citas vigentes" << endl << "5.limpiar pantalla" <<endl<< "6.salir"<<endl;
		cin >> menu;


		switch (menu)
		{
		case 1: //Agendar cita
			cout << "Numero de cita: " << i<<endl;
			cout << "Ingrese su nombre"<<endl;
			cin >> nombre;
			nom_cita[i] = nombre;

			cout << "Ingrese su tratamiento"<<endl;
			cin >> tratamiento;
			tra_cita[i] = tratamiento;

			cout<<"Escriba la descripcion"<<endl;
			cin >> descripcion;
			des_cita[i] = descripcion;

			cout << "Ingrese la hora"<<endl;
			cin >> hora;
			hora_cita[i] = hora;

			cout << "Ingrese el precio unitario del tratamiento"<<endl;
			cin >> put;
			put_cita[i] = put;

			cout << "Ingrese el precio unitario" << endl;
			cin >> pu;
			pu_cita[i] = pu;

			cout << "Ingrese la cantidad de tratamiento" << endl;
			cin >> cantidad;
			can_cita[i] = cantidad;

			cout << "Ingrese el total" << endl;
			cin >> total;
			total_cita[i] = total;

			i++;
			
			break;

		case 2: //Modificar cita
			cout << "Ingrese su numero de cita"<<endl;
			cin >> obj;
			for (bus = 1; bus < i; bus++)
			{
				if (nom_cita[bus] == nom_cita[obj])
				{
					cout << "Que desea modificar?" << endl << "1.Nombre\n2.Tratamiento\n3.descripcion\n4.hora\n5.Precio unitario del tratamiento\n6.Precio unitario\n7.Cantidad de tratamiento\n8.Total\n9.Cancelar";
					cin >> menu;
					switch (menu)
					{
					case 1:
						cout << "Ingrese el nuevo nombre";
						cin >> nombre;
						nom_cita[obj] = nombre;
						break;
					case 2:
						cout << "Ingrese el nuevo tratamiento";
						cin >> tratamiento;
						tra_cita[obj] = tratamiento;
						break;
					case 3:
						cout << "Ingrese la nueva descripcion";
						cin >> descripcion;
						des_cita[obj] = descripcion;
						break;
					case 4:
						cout << "Ingrese la nueva hora";
						cin >> hora;
						hora_cita[obj] = hora;
						break;
					case 5:
						cout << "Ingrese el nuevo precio unitario del tratamiento";
						cin >> put;
						put_cita[obj] = put;
						break;
					case 6:
						cout << "Ingrese el nuevo precio unitario";
						cin >> pu;
						pu_cita[obj] = pu;
						break;
					case 7:
						cout << "Ingrese la nueva cantidad de tratamiento";
						cin >> cantidad;
						can_cita[obj] = cantidad;
						break;
					case 8:
						cout << "Ingrese el nuevo total";
						cin >> total;
						total_cita[obj] = total;
						break;
					case 9:

						break;
					default:
						break;
					}
				
				}
				else
				{
					cout << "cita no encontrada"<<endl;
					system("pause");
				}
			}
			break;
		case 3: //Eliminar cita
			break;
		case 4: //lista de citas
			for (bus = 1; bus < i; bus++)
			{
				cout << bus << ".- Nombre: " << nom_cita[bus] << " Tratamiento: " << tra_cita[bus] << " Descripcion: " << des_cita[bus] << " Hora: " << hora_cita[bus] << "Precio unitario del tratamiento: " << put_cita[bus] << " Precio unitario: " << pu_cita[bus] << " Cantidad del tratamiento" << can_cita[bus] << " Total: " << total_cita[bus] << endl;
				
			}
			system("pause");
			break;
		case 5: //limpiar pantalla
			break;
		case 6: //salir
			salir = 2;
			break;
		default:
			break;
		}

	} 
	while (salir == 1);
}