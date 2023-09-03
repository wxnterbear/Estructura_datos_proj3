#include <iostream>

using namespace std;

struct Nodo {
	
    int num;
    struct Nodo* sig;
    struct Nodo* ant;
};

typedef struct Nodo* Tlista;

void insertNodoInicio(Tlista& cabeza, int dato) {
	
    Tlista x = new struct Nodo;
    x->num = dato;
    x->sig = NULL;
    x->ant = NULL;

    if (cabeza == NULL) {
        cabeza = x;
        
    } else {
    	
        x->sig = cabeza;
        cabeza->ant = x;
        cabeza = x;
    }
}

void insertNodoFinal(Tlista& cabeza, int dato) {
	
    Tlista x = new struct Nodo;
    x->num = dato;
    x->sig = NULL;
    x->ant = NULL;

    if (cabeza == NULL) {
        cabeza = x;
        
    } else {
    	
        Tlista y = cabeza;
        while (y->sig != NULL) {
        	
            y = y->sig;
        }
        
        x->ant = y;
        y->sig = x;
    }
}

void insertNodoEspacio(Tlista& cabeza, int dato, int pos) {
	
    if (pos <= 0) {
    	
        insertNodoInicio(cabeza, dato);
        return;
    }

    Tlista x = new struct Nodo;
    
    x->num = dato;
    x->sig = NULL;
    x->ant = NULL;

    if (cabeza == NULL) {
    	
        cabeza = x;
        return;
    }

    Tlista y = cabeza;
    int i = 1;

    while (i < pos && y != NULL) {
    	
        y = y->sig;
        i++;
    }

    if (y == NULL) {
    	
        insertNodoFinal(cabeza, dato);
        
    } else {
    	
        x->sig = y;
        x->ant = y->ant;
        if (y->ant != NULL) {
        	
            y->ant->sig = x;
            
        } else {
        	
            cabeza = x;
        }
        y->ant = x;
    }
}


void eliminarNodo(Tlista& cabeza, int dato) {
	
    Tlista x = cabeza;

    while (x != NULL) {
    	
        if (x->num == dato) {
        	
            if (x ->sig != NULL) {
            	
                x ->sig->ant = x->ant;
            }
            
            if (x->ant != NULL) {
            	
                x->ant->sig = x ->sig;
            }
            
            if (x == cabeza) {
                cabeza = x ->sig;
            }
            
            delete x;
            return; 
        }
        x = x->sig;
    }
    cout << "No se encontro el numero en la lista." << endl;
}



Tlista buscarNodo(Tlista cabeza, int dato) {
    
	Tlista x = cabeza;

    int i = 0, band = 0;

    while (x != NULL) {
        if (x->num == dato) {
            cout << endl << "Se encontro en la posicion: " << i;
            band = 1;
        }

        x = x->sig;
        i++;
    }

    if (band == 0) {
        cout << endl << endl << "\nNumero no encontrado" << endl;
    } 
}



void mostrarListaActual(Tlista cabeza) {
	
    Tlista x = cabeza;
    
    while (x != NULL) {
    	
        cout << x->num << " ";
        x = x ->sig;
    }
    cout << endl;
}

int main ()
{
	
	Tlista cabeza = NULL;
	int valor;
	int opc;
	int forma;
	
	do {
        cout << endl << endl<< "------ Menu de opciones------- " << endl<<endl;
        cout << "1. Insertar datos" <<endl;
        cout << "2. Buscar datos" <<endl;
        cout << "3. Borrar datos" <<endl;
        cout << "4. Actualizar datos" <<endl;
        cout << endl <<  "Ingrese la opcion: ";
        cin >> opc;
        
        switch (opc){
        	case 1:
        		
        		cout << endl<< "Escoja la forma de insertar datos: " <<endl<<endl;
				cout << "1. Agregar al inicio" << endl;
		        cout << "2. Agregar al final" << endl;
		        cout << "3. Agregar en un espacio especifico" << endl;
		        cout << "0. Regresar al menu anterior" << endl<<endl;	
		        cin >> forma;
		        
		        switch (forma) {
		        	
		            case 1:
		            	
		                do {
		                	
					        cout << "\nEscriba un numero a ingresar (0 para salir): ";
					        cin >> valor;
					        
					        if (valor != 0) {
					            insertNodoInicio(cabeza, valor);
					        }
					    
					        cout << endl << endl;
					    } while (valor != 0);
					    
		                break;
		            case 2:
		                do {
		                	
					        cout << "\nEscriba un numero a ingresar (0 para salir): ";
					        cin >> valor;
					        
					        if (valor != 0) {
					            insertNodoFinal(cabeza, valor);
					        }
					    
					        cout << endl << endl;
					    } while (valor != 0);
		
		                
		                break;
		            case 3:
		            	
		                int pos;
		                
		                cout << "\nEscriba un numero a ingresar (diferente a 0):";
		                cin >> valor;
		                
		                	if(valor !=0){
		                		
		                		cout << "\nEscriba la posicion en donde desea ingresar el numero: ";
		                	 	cin >> pos;
		                
		                		insertNodoEspacio(cabeza, valor, pos);
		                
		                		break; 
							
							} else{
								
								cout << "\nNumero invalido."	;
							}
							
							 
		                
		            case 0:
		                cout << "\nRegresando al menu anterior" << endl;
		                break;
		            default:
		                cout << "Opcion invalida. Intente nuevamente." << endl;
		                break;
		        }
		

                break;

            case 2:
            	
                cout << endl <<"\nQue numero desea encontrar: ";
                cin >> valor;
                buscarNodo(cabeza, valor);
                break;
                
            case 3:
            	
            	cout << endl << "Que numero desea borrar: ";
                cin >> valor;
                
                eliminarNodo(cabeza, valor);
                

                break;
                
            case 4:
			
				cout << endl << "\n---Lista actual --- " <<endl;
                mostrarListaActual(cabeza);
                cout << endl;

                break;    
			    
        }

    } while (opc != 0);
        

	
	
	system ("pause");
	return 0;


}



