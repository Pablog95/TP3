

template<class T>
Lista<T> :: Lista(){
	primero = 0;
	cantidad = 0;
}
template<class T>
bool Lista<T> :: listaVacia(){
	return (cantidad == 0);
}
template<class T>
void Lista<T> :: agregarElemento(string dato,int posicion){
	Nodo<T>* nuevo = new Nodo<T>(dato);
	if (posicion == 1){
		nuevo->cambiarSiguiente(primero);
		primero = nuevo;
	}
	else{
		Nodo<T>* anterior = obtenerNodo(posicion - 1);
		nuevo->cambiarSiguiente(anterior->obtenerSiguiente());
		anterior->cambiarSiguiente(nuevo);
	}
	cantidad++;
}
template<class T>
Nodo<T>* Lista<T>::obtenerNodo(int posicion){
	Nodo<T>* aux = primero;
	int contador = 1;
	while (contador < posicion){
		aux = aux->obtenerSiguiente();
		contador++;
	}
	return aux;
}
