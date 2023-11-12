

/*
 * cripto.cpp
 *
 *  Autor:Víctor Valdés Cobos vvaldesc@alumnos.unex.es
 *  Fecha: 15 Mayo 2022
 */


#include "graph.h"
#include "RSV.h"
#include <fstream>
#include <iostream>


using namespace std;



RSV::RSV() {
	mviajes = new Graph <string>;
	cargarCiudades();
	cargarViajes();

}



// opción 1
void RSV::insertarCiudad(string ciudad) {
	mviajes->insertNode(ciudad);
}

void RSV::cargarCiudades() {
	ifstream ifs;
	string ciudad;
	ifs.open("ciudades.csv");
	if(ifs.is_open()){
		while(!ifs.eof()){
			getline(ifs,ciudad);
			if(!ifs.eof()){
				insertarCiudad(ciudad);
			}

		}
		ifs.close();
	}
	else{
		cout << "el fichero no se ha abierto." << endl;
	}
}

void RSV::cargarViajes() {
	ifstream ifs;
	string origen,destino;
	ifs.open("viajes.csv");
	if(ifs.is_open()){
		while(!ifs.eof()){
			getline(ifs,origen,';');
			if(!ifs.eof()){
				getline(ifs,destino);
				insertarViaje(origen,destino);
			}

		}
		ifs.close();
	}
	else{
		cout << "el fichero no se ha abierto." << endl;
	}
}

bool RSV::pertenece(ListaPI<string> *l, string ciudad) {
	bool enc=false;
	string c;
	l->moverInicio();
	while(!l->enFin() and !enc){
		l->consultar(c);
		if (c==ciudad){
			enc = true;
		}
		l->avanzar();
	}
	return enc;
}

// opción 2
void RSV::insertarViaje(string cOrigen, string cDestino) {
	if(!existeViaje(cOrigen,cDestino)){
		mviajes->insertEdge(cOrigen,cDestino);
	}
}

bool RSV::existeViaje(string ciudad1,string ciudad2) {
	bool enc = false;
	ListaPI<string> *adj = new ListaPI<string>();
	mviajes->adjacents(ciudad1, adj);
	enc=pertenece(adj,ciudad2);
	delete adj;
	return enc;
}

void RSV::mostrar(ListaPI<string> *l) {
	l->moverInicio();
	string c;
	while(!l->enFin()){
		l->consultar(c);
		cout<<c<<endl;
	}
}

void RSV::mostrarTodo() {
	ListaPI<string> *lc = new ListaPI<string>();
	mviajes->nodes(lc);
	string c,a;
	lc->moverInicio();
	while(!lc->enFin()){
		ListaPI<string> *adj = new ListaPI<string>();
		lc->consultar(c);
		cout << "Adyacentes de " << c << ":"<< endl;
		mviajes->adjacents(c, adj);
		adj->moverInicio();
		while(!adj->enFin()){
			adj->consultar(a);
			cout << a << endl;
			adj->avanzar();
		}
		delete adj;
		lc->avanzar();
		cout << "\n" << endl;
	}
	delete lc;
}

void RSV::grado() {
	ListaPI<string> *lc = new ListaPI<string>();
	string c;int i=0;
	mviajes->nodes(lc);
	lc->moverInicio();
	while(!lc->enFin()){
		ListaPI<string> *adj = new ListaPI<string>();
		i=0;
		lc->consultar(c);
		mviajes->adjacents(c, adj);
		adj->moverInicio();
		while(!adj->enFin()){
			i++;
			adj->avanzar();
		}
		delete adj;
		cout << c << " " << i << endl;
		lc->avanzar();
	}
	delete lc;
}

RSV::~RSV() {
	delete this->mviajes;
}

void RSV::mostrarCiudades() {
	ListaPI<string> *adj = new ListaPI<string>();
	string c;
	mviajes->nodes(adj);
	adj->moverInicio();
	while(!adj->enFin()){
		adj->consultar(c);
		cout << c << endl;
		adj->avanzar();
	}
	delete adj;
}

void RSV::destino (string ciudad){
	ListaPI<string> *lv = new ListaPI<string>();
	string c;
	recorridoProfundidad(ciudad,lv);
	lv->moverInicio();
	while(!lv->enFin()){
		lv->consultar(c);
		cout << c << endl;
		lv->avanzar();
	}
	delete lv;
}

void RSV::recorridoProfundidad(string ciudad,ListaPI<string>*lv) {
	ListaPI<string> *adj = new ListaPI<string>();
	string cv,a,c;
	mviajes->adjacents(ciudad, adj);
	adj->moverInicio();
	lv->insertar(ciudad);
	while(!adj->enFin()){
		adj->consultar(a);
		if(pertenece(lv, a)){
			//cout << ciudad << endl;
		}
		else{
			recorridoProfundidad(a,lv);
		}
		adj->avanzar();
	}
	delete adj;
}
