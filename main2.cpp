#include <iostream>

using namespace std;

struct Nodo {
    int num;
    struct Nodo* sig;
};

typedef struct Nodo* Tlista;

void insertNodoInicio(Tlista& cabeza, int dato) {
	
    Tlista x = new struct Nodo;
    x->num = dato;

    if (cabeza == NULL) {
    	
        x->sig = x;
        cabeza = x;
        
    } else {
    	
        Tlista y = cabeza;
        
        while (y->sig != cabeza) {
            y = y->sig;
        }
        y->sig = x;
        x->sig = cabeza;
        cabeza = x;
    }
}

void insertNodoFinal(Tlista& cabeza, int dato) {
	
    Tlista x = new struct Nodo;
    x->num = dato;

    if (cabeza == NULL) {
        x->sig = x;
        cabeza = x;
        
    } else {
    	
        Tlista y = cabeza;
        while (y->sig != cabeza) {
        	
            y = y->sig;
        }
        y->sig = x;
        x->sig = cabeza;
    }
}

void insertNodoEspacio(Tlista& cabeza, int dato, int pos) {
	
    if (pos <= 0) {
    	
        insertNodoInicio(cabeza, dato);
        return;
    }

    Tlista x = new struct Nodo;
    x->num = dato;

    Tlista y = cabeza;

    for (int i = 1; i < pos - 1 && y != NULL; i++) {
    	
        y = y->sig;
    }

    if (y == NULL) {
    	
        cout << "Lo siento, posicion no encontrada" << endl;
        return;
    }

    x->sig = y->sig;
    y->sig = x;
}

void buscarNodo(Tlista cabeza, int dato) {
	
    Tlista x = cabeza;
    int i = 0, band = 0;

    if (cabeza != NULL) {
        do {
            if (x->num == dato) {
            	
                cout << endl << "Se encontro en la posicion: " << i;
                band = 1;
            }
            
            x = x->sig;
            i++;
        } while (x != cabeza);
    }

    if (band == 0) {
        cout << endl << "Numero no encontrado" << endl;
    }
}

void eliminarNodo(Tlista& cabeza, int n) {
	
    if (cabeza != NULL) {
        Tlista ant = cabeza;
        Tlista x = cabeza->sig;

        do {
            if (x->num == n) {
            	
                ant->sig = x->sig;
                if (x == cabeza) {
                    cabeza = ant;
                }
                
                delete x;
                cout << endl << "Numero eliminado exitosamente";
                return;
            }

            ant = x;
            x = x->sig;
        } while (x != cabeza);

        cout << endl << "No se encontro el numero a borrar";
        
    } else {
    	
        cout << endl << "La lista esta vacia, no se puede borrar ningun numero";
    }
}

void mostrarListaActual(Tlista cabeza) {
	
    Tlista x = cabeza;

    if (cabeza != NULL) {
    	
        do {
        	
            cout << x->num << " ";
            x = x->sig;
            
        } while (x != cabeza);
    }

    cout << endl;
}

int main() {
	
    Tlista cabeza = NULL;
    int valor;
    int opc;
    int forma;

    do {
        cout << endl << endl << "------ Menu de opciones -------" << endl << endl;
        cout << "1. Insertar datos" << endl;
        cout << "2. Buscar datos" << endl;
        cout << "3. Borrar datos" << endl;
        cout << "4. Mostrar lista actual" << endl;
        cout << "0. Salir" << endl << endl;
        cout << "Ingrese la opcion: ";
        cin >> opc;

        switch (opc) {
        case 1:
        	
            cout << endl << "Escoja la forma de insertar datos:" << endl << endl;
            cout << "1. Agregar al inicio" << endl;
            cout << "2. Agregar al final" << endl;
            cout << "3. Agregar en un espacio especifico" << endl;
            cout << "0. Regresar al men� anterior" << endl << endl;
            cin >> forma;

            switch (forma) {
            case 1:
                do {
                    cout << endl << "Escriba un numero a ingresar (0 para salir): ";
                    cin >> valor;

                    if (valor != 0) {
                        insertNodoInicio(cabeza, valor);
                    }

                    cout << endl << endl;

                } while (valor != 0);
                break;

            case 2:
                do {
                    cout << endl << "Escriba un numero a ingresar (0 para salir): ";
                    cin >> valor;

                    if (valor != 0) {
                        insertNodoFinal(cabeza, valor);
                    }

                    cout << endl << endl;
                } while (valor != 0);

                break;

            case 3:
                int pos;
                cout << endl << "Escriba un numero a ingresar (diferente a 0):";
                cin >> valor;

                if (valor != 0) {
                    cout << endl << "Escriba la posicion en donde desea ingresar el numero: ";
                    cin >> pos;

                    insertNodoEspacio(cabeza, valor, pos);

                    break;
                } else {
                    cout << endl << "Numero invalido.";
                }
                break;

            case 0:
                cout << endl << "Regresando al menu anterior" << endl;
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
            }
            break;

        case 2:
            cout << endl << "Que numero desea encontrar: ";
            cin >> valor;
            buscarNodo(cabeza, valor);
            break;

        case 3:
            cout << endl << "Que numero desea borrar: ";
            cin >> valor;
            eliminarNodo(cabeza, valor);
            break;

        case 4:
            cout << endl << "--- Lista actual --- " << endl;
            mostrarListaActual(cabeza);
            cout << endl;
            break;
        }

    } while (opc != 0);

    return 0;
}

