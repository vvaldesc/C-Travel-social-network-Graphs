#include <iostream>
#include <string>
#include <cstdlib>

#include "RSV.h"
using namespace std;

// Muestra el menu por pantalla y devuelve una opcion elegida.
int menu() {

	int opcion;

	do {
		cout << endl;
		cout << "______________ MENU PRINCIPAL ______________" << endl << endl;

		cout << "     1. Insertar ciudad                        " << endl;
		cout << "     2. Insertar viaje (crear arco)            " << endl;
		cout << "     3. Mostrar ciudades                       " << endl;
		cout << "     4. Grado de todos los vértices (ciudades) " << endl;
		cout << "     5. Adyacentes                             " << endl;
		cout << "     6. Mostrar todo                           " << endl;
		cout << "     7. Mostrar destinos desde una ciudad      " << endl;

		cout << "     0. Finalizar.                         " << endl;
		cout << "                        Opcion:  ";
		cin >> opcion;
		cin.ignore();

	} while ((opcion < 0) || (opcion > 8));

	return opcion;
}
int main() {
	RSV *r=new RSV();
	string origen,destino;


	// TODO crear la rsv
	bool terminar = false;
	int opcion;

	while (!terminar) {
		opcion = menu();

		switch (opcion) {
		case 1:
			cout<< "Introduce ciudad a añadir" << endl;
			cin >>origen;
			r->insertarCiudad(origen);
			break;
		case 2:
			cout<< "Introduce origen" << endl;
			cin >>origen;
			cout<< "Introduce destino" << endl;
			cin >>destino;
			r->insertarViaje(origen, destino);
			break;
		case 3:
			r->mostrarCiudades();
			break;
		case 4:
			r->grado();
			break;
		case 5:
			cout<< "Introduce origen" << endl;
			cin >>origen;
			cout<< "Introduce destino" << endl;
			cin >>destino;
			if(r->existeViaje(origen,destino)){
				cout<< "Son adyacentes" << endl;
			}
			else{
				cout << "No son adyacentes" << endl;
			}
			break;
		case 6:
			r->mostrarTodo();
			break;
		case 7:
			cout<< "Introduce ciudad" << endl;
			cin >>origen;
			r->destino(origen);
			break;
		case 0:
			delete r;
			terminar = true;
			break;

		default:
			break;

		}
	}


	return 0;
}

