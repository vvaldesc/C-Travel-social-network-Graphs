

/*
 * cripto.cpp
 *
 *  Autor:Víctor Valdés Cobos vvaldesc@alumnos.unex.es
 *  Fecha: 15 Mayo 2022
 */



#ifndef RSV_H_
#define RSV_H_


#include "listapi.h"
#include "graph.h"

#include <iostream>
using namespace std;

class RSV {

private:
	Graph <string> *mviajes;

	// PRE  = { }
	// POST = { }
	// DESC:  Interpreta los datos del archivo "ciudades.csv" para su posterior
	//	inserción en el sistema.
	// COMPL: O(n)
	void cargarCiudades();

	// PRE  = { }
	// POST = { }
	// DESC:  Interpreta los datos del archivo "viajes.csv" para su posterior
	//	inserción en el sistema.
	// COMPL: O(n)
	void cargarViajes();

	// PRE  = { }
	// POST = { }
	// DESC:  Comprueba si la ciudad pertenece a la lista.
	// COMPL: O(n)
	bool  pertenece      (ListaPI<string>*l,string ciudad);

	//Desc: Hace un recorrido en profundidad en el grafo
	//Pre:
	//Post: {}
	//Compl: O(log n)
	void recorridoProfundidad(string ciudad,ListaPI<string>*lv);

	//Desc: Muestra los datos de una lista pasada por parámetro
	//Pre:
	//Post: {}
	//Compl: O(n)
	void mostrar (ListaPI<string>*l);


	// TODO atributo



public:

	RSV        ();
	~RSV        ();

	//Desc: Inserta una ciudad en la estructura grafo
	//Pre: {}
	//Post: {Nombre del nodo pasado por parámetro}
	//Compl: O(1)
	void  insertarCiudad		(string ciudad);

	//Desc: Inserta un viaje en la estructura grafo para conectar dos ciudades
	//Pre: {}
	//Post: {Destino y orígen pasado parámetro}
	//Compl: O(1)
	void  insertarViaje      (string cOrigen, string cDestino);

	//Desc: Comprueba si existe el viaje
	//Pre: {}
	//Post: {}
	//Compl: O(n2)
	bool  existeViaje      (string ciudad1,string ciudad2);



	//Desc: Muestra los datos de la estructura
	//Pre:
	//Post: {}
	//Compl: O(n3)
	void mostrarTodo ();

	//Desc: Inserta una ciudad en la estructura grafo
	//Pre:
	//Post: {}
	//Compl: O(n2)
	void mostrarCiudades ();

	//Desc: Muestra la cada nodo del grafo junto a su grado
	//Pre:
	//Post: {}
	//Compl: O(n3)
	void grado ();

	//Desc: Muestra todas las ciudades a las que puedes ir desde la pasada por parámetro
	//Pre:
	//Post: {}
	//Compl: O(n)
	void destino (string ciudad);

};


#endif /* RSV_H_ */
