/***Datos administrativos************************
 * Nombre del archivo: String.hpp
 * Tipo de archivo: Encabezadp 'hpp'
 * Proyecto: Librería String PO1
 * Autores: Bryan Londoño, Owen Torres y Yosimar Montenegro
 * Empresa: Tecnológico de Costa Rica - Escuela de IC
 ***Descripción**********************************
 * Este archivo se hizo con el objetivo de crear una librería string
 * que tenga las funcionalidades de la original pero reducida
 * contiene funciones muy importantes en la vida de un programador
 ***Version**************************************
 * 1.0 | 04-03-2024 23:50 | Yosimar M, Owen T y Bryan L
 ************************************************/
#include <fstream>
#ifndef STRING_H
#define STRING_H

/***Nombre************************************************
 * String
 ***Descripción*******************************************
 * Esta clase es una versión reducida de la librería string
 * original de C++
 ***Atributos*********************************************
 * char *paCadena
 *** Metodos**********************************************
 * String()
 * copiarCadena()
 * caracterEn()
 * contarCaracter()
 * ultimoIndice()
 * cambiarCadena()
 * len()
 * leng()
 * split()
 * concatenarEn()
 * concatenar()
 * concatenarCadenas()
 * reemplazarEn()
 * reemplazarOcurrencias()
 * guardarEnArchivo()
 * leerArchivo()
 ***********************************************************/
class String {
private:
	char* paCadena = nullptr;
	
	/*****Nombre***************************************
	* copiarCadena
 	*****Descripción**********************************
	* hace una copia la cadena en memoria
 	*****Retorno**************************************
 	* vacío
 	*****Entradas*************************************
 	* Una cadena de caracteres para copiar
 	**************************************************/
	void copiarCadena(const char *pFuente) {
        	if (pFuente != nullptr) {
            		int largo = 0;
            		while (pFuente[largo] != '\0') {
				++largo;
			} // fin pFuente != nullptr
            		paCadena = new char[largo + 1];

            		for (int i = 0; i <= largo; ++i) {
                		paCadena[i] = pFuente[i];
            		} // fin i <= largo
        	} else {
            		paCadena = nullptr;
        	} // fin else
	} // copiarCadena()

public:
	/*****Nombre***************************************
	* String 
 	*****Descripción**********************************
	* Es el constructor de la clase
 	*****Retorno**************************************
 	* Llama a la función que copia en memoria la cadena
 	*****Entradas*************************************
 	* Una cadena de caracteres
 	**************************************************/
	String(const char *pCadena) : paCadena(nullptr) {
		copiarCadena(pCadena);
	}

	/*****Nombre***************************************
	* ~String
 	*****Descripción**********************************
	* Elimina el puntero de la cadena del objeto
 	*****Retorno**************************************
 	* vacío
 	*****Entradas*************************************
 	* vacío
 	**************************************************/
	~String() {
		delete[] paCadena;
	}

	/*****Nombre***************************************
	* mostrarCadena
 	*****Descripción**********************************
	* Método accesor para la cadena del objeto
 	*****Retorno**************************************
 	* La cadena de caracteres actual del objeto
 	*****Entradas*************************************
 	* vacío
 	**************************************************/
	char* mostrarCadena() {
		return paCadena;
	}

	/*****Nombre***************************************
	* len
 	*****Descripción**********************************
	* Cuenta la cantidad de caracteres dentro de la
	* cadena actual
 	*****Retorno**************************************
 	* Cantidad entera de los caracteres de la cadena
 	*****Entradas*************************************
 	* vacío
 	**************************************************/
	int len() const{
		int largo = 0; // Indice-Contador
		while (paCadena[largo] != '\0') {
			++largo;
		} // paCadena[largo] != '\0'
		return largo;

	} // len

	/*****Nombre***************************************
	* leng
 	*****Descripción**********************************
	* Cuenta la cantidad de caracteres dentro de la
	* cadena pasada como parametro
 	*****Retorno**************************************
 	* Cantidad entera de los caracteres de la cadena
	* ingresada
 	*****Entradas*************************************
 	* Cadena de caracteres
 	**************************************************/
	int leng(char* cadena) {
		int largo = 0;
		while (cadena[largo] != '\0') {
			++largo;
		} // cadena[largo] != '\0'
		return largo;
	}

	/*****Nombre***************************************
	* cambiarCadena
 	*****Descripción**********************************
	* Borra el puntero de la memoria y hace una copia
	* de la nueva cadena
 	*****Retorno**************************************
 	* vacío
 	*****Entradas*************************************
 	* cadena nueva para reemplazar
 	**************************************************/
	void cambiarCadena(const char *pCadenaNueva) {
		delete[] this->paCadena;
		copiarCadena(pCadenaNueva);
	}


	/*****Nombre***************************************
	 * caracterEn
 	*****Descripción**********************************
	 * Busca indicar que caracter encontro en la posicion que le demos
 	*****Retorno**************************************
 	* La letra en la que esta la posicion que le fue dada
 	*****Entradas*************************************
 	* Una cadena de caracteres
 	**************************************************/
	char caracterEn(int pos){
	       if (pos > len()){
		 return '\0';
	       } // pos > len()
	       return paCadena[pos];
	}

	/*****Nombre***************************************
	 * indefinido
 	*****Descripción**********************************
	 * Busca comparar un String con otro String usando ==
	 * Sobrecargando el operador ==
 	*****Retorno**************************************
 	* Un True si son iguales sino un False
 	*****Entradas*************************************
 	* Una cadena de caracteres
 	**************************************************/
    bool operator==(const String& otro) const {
    	if (paCadena == nullptr && otro.paCadena == nullptr) {
        		return true;
    	} else if (paCadena != nullptr && otro.paCadena != nullptr) {
        		int i = 0;
        		while (paCadena[i] != '\0' && otro.paCadena[i] != '\0') {
            		if (paCadena[i] != otro.paCadena[i]) {
                			return false;
            		}
                	i++;
        		} // paCadena[i] != '\0' && otro.paCadena[i] != '\0'
        		return paCadena[i] == '\0' && otro.paCadena[i] == '\0';
    	} else {
        		return false;
     	} // fin paCadena == nullptr && otro.paCadena == nullptr
	}


	/*****Nombre***************************************
	 * split
 	*****Descripción**********************************
	 * Este retorna un arreglo de cadenas separadas por el parametro que se le haya pasado
 	*****Retorno**************************************
 	* Retonar una cadena separada
 	*****Entradas*************************************
 	* Un caracter
 	**************************************************/
	String** split(char separador){
		 int ind = 0;
		 int indR = 0;
		 String **pRes = new String*[len()]; //creo la matriz con el largo de la cadena donde se almacenaran al final las sublistas
		 char *pTempList = new char[len()]; //creo una lista de caracteres para ir guardando las sublistas
		 for(int i = 0; i < len(); i++){
	            if(paCadena[i] == separador){
		    	pTempList[ind] = '\0'; //aqui le damos al ultimo indice el valor nulo
			pRes[indR] = new String(pTempList); //aqui le pasamos a la matriz su subcadena
			indR ++;
			ind = 0; 
		    } else {
			pTempList[ind] = paCadena[i];
			ind++;
		    }		
		}
		pTempList[ind] = '\0';
        	pRes[indR] = new String(pTempList);
		indR++;
        	return pRes; // Devolvemos la matriz 
	}

	/*****Nombre***************************************
	 * reemplazarOcurrencias
 	*****Descripción**********************************
	 * Se le envia un caracter el cual va a buscar en la cadena original para cambiar esa parte por otra que se le haya dado
 	*****Retorno**************************************
 	* La cadena original con las modificaciones ya hechas
 	*****Entradas*************************************
 	* Una lista de caracteres una de anterior y otra para el nuevo caracter
 	**************************************************/
	String* reemplazarOcurrencias(char* anterior, char* nuevo) {
    		int largo = len();
    		int largo_Anterior = leng(anterior);
    		int largo_Nuevo = leng(nuevo);	
    		char *pResultado = new char[largo * largo_Nuevo]; 
    		int indice2 = 0;
    		int i = 0;

   		//recorremos la cadena hasta que ya no hayan mas valores para reemplazar
    		while (i < largo - largo_Anterior + 1) {
        		bool iguales = true;
        		// aqui buscamos ver si el caracter de la cadena es igual al que buscamos 
			// sino es asi quebramos el ciclo 
        		for (int j = 0; j < largo_Anterior; j++) {
            			if (paCadena[i + j] != anterior[j]) {
                			iguales = false;
                			break;
            			}
        		}
        		if (iguales) {
            		// si hay una igual pues lo agregamos a resultado
            	    	    for (int j = 0; j < largo_Nuevo; j++) {
                       	         pResultado[indice2] = nuevo[j];
		                 indice2++;
            	     	    }
            	    	    i += largo_Anterior;
        		} else { // sino vamos escribiendo la parte del String que queda igual
            	     	    pResultado[indice2] = paCadena[i];
	    	     	    indice2++;
	    	            i++;
        		} // fin (iguales)
    		} // fin i < largo - largo_Anterior + 1

    		// tambien volvemos a escribir la parte del String pero la que
    		// no se pudo captar en el primer bucle
		for (; i < largo; ++i) {
        	    pResultado[indice2++] = paCadena[i];
    		}

	
    		pResultado[indice2] = '\0'; 

    		cambiarCadena(pResultado);

   
    		return this;
	} // fin reemplazarOcurrencias



	/*****Nombre***************************************
	 * concatenarCadenas
 	*****Descripción**********************************
	 * Se nos da una lista de listas en la cual iremos concatenando al final de la cadena original
 	*****Retorno**************************************
 	* La cadena original con las otras cadenas concatenadas
 	*****Entradas*************************************
 	* una lista de listas
 	**************************************************/
	String* concatenarCadenas(char** cadenas) {
    		int i = 0;
    		while (cadenas[i] != nullptr) {
        		concatenar(cadenas[i]);
        		++i;
    		} // fin (cadenas[i] != nullptr)
    		return this;
	}




	/*****Nombre***************************************
	 * concatenarEn
 	*****Descripción**********************************
	 * Concatena en el indice correspondiente la cadena
	 * que se desea sin perder caracteres
 	*****Retorno**************************************
 	* void
 	*****Entradas*************************************
 	* Una cadena de caracteres y un indice
 	**************************************************/
	void concatenarEn(char *pCadena, int indice) {
		if(pCadena == nullptr) return;

		int largo_cadena_original = len();
		int largo_cadena_nueva = leng(pCadena);
		int indice_nuevo;

	    	if (indice < 0) { // En caso de que el indice sea negativo
        		indice_nuevo = ((indice % largo_cadena_original) + largo_cadena_original) % largo_cadena_original;
    		} else {
    	   		indice_nuevo = indice % largo_cadena_original;
    		} // fin indice < 0


	    	char *pCadena_nueva = new char[largo_cadena_original + largo_cadena_nueva + 1];

        	for (int i = 0; i < indice_nuevo; ++i) { // Copiamos hasta el indice donde se concatenará
        		pCadena_nueva[i] = paCadena[i];
    		}

    		for (int i = 0; i < largo_cadena_nueva; ++i) { // Agregar la cadena en la posisión pedida
        		pCadena_nueva[indice_nuevo + i] = pCadena[i];
    		}

    		for (int i = indice_nuevo; i < largo_cadena_original; ++i) { // Agregar el resto de la cadena original después de la nueva cadena
    	    		pCadena_nueva[largo_cadena_nueva + i] = paCadena[i];
    		}

    		pCadena_nueva[largo_cadena_original + largo_cadena_nueva] = '\0';

		cambiarCadena(pCadena_nueva);
	} // fin concatenarEn

	/*****Nombre***************************************
	 * reemplazarEn
 	*****Descripción**********************************
	 * Inserta en el caracter de la posición correspondiente
	 * segun el indice pedido
 	*****Retorno**************************************
 	* vacío
 	*****Entradas*************************************
 	* Una cadena de caracteres y un indice
 	**************************************************/
	void reemplazarEn(char *pCadenaNueva, int indice) {
        	if (paCadena == nullptr || pCadenaNueva == nullptr) { // Esto es para evitar posibles errores de lectura
            		return;
        	} // fin paCadena == nullptr || pCadenaNueva == nullptr

        	int largo_cadena_original = len();
        	int largo_cadena_nueva = leng(pCadenaNueva);
        	int indice_nuevo;

        	if (indice < 0) {
            		indice_nuevo = ((indice % largo_cadena_original) + largo_cadena_original) % largo_cadena_original;
        	} else {
            		indice_nuevo = indice % largo_cadena_original;
        	} // fin indice < 0

        	char *pCadena_nueva = new char[largo_cadena_original + largo_cadena_nueva + 1];

        	for (int i = 0; i < indice_nuevo; ++i) { // Se copian los caracteres hasta el indice pedido
            		pCadena_nueva[i] = paCadena[i];
        	}

        	for (int i = 0; i < largo_cadena_nueva; ++i) { // Se copia la cadena nueva despues del indice pedido
            		pCadena_nueva[indice_nuevo + i] = pCadenaNueva[i];
        	}


        	for (int i = indice_nuevo + largo_cadena_nueva; i < largo_cadena_original; ++i) { // Se copian los caracteres restantes
            		pCadena_nueva[i] = paCadena[i - largo_cadena_nueva];
        	}

        	pCadena_nueva[largo_cadena_original + largo_cadena_nueva] = '\0';

        	cambiarCadena(pCadena_nueva);
	}

	/*****Nombre***************************************
 	* Concatenar
 	*****Descripción**********************************
 	* Recibe una cadena de caracteres como parametro y 
	* la concatena al final. 
 	*****Retorno**************************************
 	* Actualiza la cadena cadena de caracteres
 	*****Entradas*************************************
 	* char* cadena
 	**************************************************/
	void concatenar(char *pCadena) {
		if(pCadena == nullptr) return;
		int largo_cadena_original = len();
		int largo_cadena_nueva = leng(pCadena);
		int indice_nuevo = largo_cadena_original + largo_cadena_nueva + 1;
		
		char *pCadena_concatenada = new char[indice_nuevo];

		for (int i = 0; i < largo_cadena_original; i++) {
			pCadena_concatenada[i]=paCadena[i];
		}
		int contador_interno=0;
		for (int i = largo_cadena_original;i< indice_nuevo;i++) {
			pCadena_concatenada[i]=pCadena[contador_interno];
			contador_interno++;
		}

		pCadena_concatenada[indice_nuevo-1]='\0';

		cambiarCadena(pCadena_concatenada);

	}

	/*****Nombre***************************************
 	* Contar Caracter
 	*****Descripción**********************************
 	* Recibe un caracter y retorna la cantidad de
	* ocurrencias dentro de la cadena de caracteres.
 	*****Retorno**************************************
 	* Un valor entero con la cantidad de ocurrencias
	* del caracter.
 	*****Entradas*************************************
 	* char caracter
 	**************************************************/
	int contarCaracter(char caracter) {
		int largo_cadena = len();
		int contador = 0;
		for (int i = 0; i < largo_cadena; i++) {
			if (paCadena[i]==caracter) contador++;
		}
		return contador;
	}

	/*****Nombre***************************************
 	* Ultimo Indice
 	*****Descripción**********************************
 	* Retorna el indice numerico de la ultima posicion
	* en la que se encuentra un caracter especifico 
	* dentro de la cadena de caracteres.
 	*****Retorno**************************************
 	* Un entero que representa el indice de la ultima
	* ocurrencia del char.
	*****Entradas*************************************
 	* char caracter
 	**************************************************/
	int ultimoIndice(char caracter) {
		int largo_cadena = len();
		int contador = 0;
		for (int i = 0; i < largo_cadena; i++) {
			if (paCadena[i]==caracter) contador=i;
		}
		return contador;
	}
	/*****Nombre***************************************
 	* Guardar en Archivo
 	*****Descripción**********************************
 	* Recibe como parametro dos cadenas de caracteres,
	* una contiene la ruta de un archivo y la otra
	* contiene el modo en el que se escribira en el
	* archivo.
 	*****Retorno**************************************
 	* Actualiza un archivo de texto 
 	*****Entradas*************************************
 	* char* ruta y char* modo
 	**************************************************/
	void guardarEnArchivo(char *pRuta,char *pModo) {

		if(pRuta == nullptr || pModo == nullptr)return;
		if(leng(pModo)!=1)return;
		if(pModo[0] != 'w' && pModo[0] != 'a') return;
		
		if(pModo[0] == 'w') {
			std::ofstream archivo(pRuta,std::ios::out);
			if(!archivo.is_open())return;

			archivo << paCadena << std::endl;
			archivo.close();

		} else {
			std::ofstream archivo(pRuta,std::ios::app);
			if(!archivo.is_open())return;

			archivo << paCadena << std::endl;
			archivo.close();
		} // fin pModo[0] == 'w'

			
		
	}
	/*****Nombre***************************************
 	* Leer Archivo
 	*****Descripción**********************************
 	* Recibe una cadena de caracteres que indica la
	* ruta del archivo de texto que se va a leer.
 	*****Retorno**************************************
 	* Actualiza la cadena de caracteres con el contenido
 	*****Entradas*************************************
 	* char* ruta
 	**************************************************/

	void leerArchivo(char *pRuta) {
		if(pRuta==nullptr)return;


		std::ifstream archivo(pRuta);
		if(!archivo.is_open())return;


		archivo.seekg(0, std::ios::end);
		int tamano_archivo= archivo.tellg();
		archivo.seekg(0, std::ios::beg);

		char *pTexto=new char[tamano_archivo +1];

		archivo.read(pTexto, tamano_archivo);
		pTexto[tamano_archivo]= '\0';

		archivo.close();

		cambiarCadena(pTexto);

		delete[] pTexto;
	}
};
#endif
