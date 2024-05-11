#ifndef XMLDOCUMENT_HPP
#define XMLDCOMENT_HPP
#include "Node.hpp"

class XMLDocument {
private:
	// Function operating modes, use the constant names and not the values in the code
	const int ADD = 100;	// Mode addition, adds the value to the beginning of the set
                                // as allowed by the specific function (with or without repetition)
	const int OVR = 200;	// Mode overwrite, if it already exists, replaces the value, if not, just add it.
	const int APD = 300;	// Mode append, appends the value to the end of the set as
                                // allowed by the specific function (with or without repetition)
	const int DEL = 400;	// Mode delete, if the value exists, it is deleted instead
	
	// Node content location type
	const int BEG = 10;		// Content is displayed before children of node, just after the opening tag.
	const int END = 20;		// Content is displayed after children of node, just before the closing tag.

    // Nodo seleccionado para uso de configuraciones del XML
    Node *pSelect = nullptr;
    // Jerarquía
    Node *pRoot = nullptr;
    
    // Métodos privados-auxiliares
public:
	// Public functions
	int   Root (char *pName);
	bool  Select (int id); // Método de selección de nodo para uso de otros métodos
	int   Child (char *pName);
	int   Child (char *pName, char *pContent);
    // Preguntar sobre el significado de key
	bool  EditAttribute (char *pKey, char *pValue, int mode);
	bool  EditContent (char *pContent, int mode);


	bool  SwitchContentPosition ();
	bool  SetBalanced ();
	bool  Delete ();
	char* ViewTree ();
	char* ViewNode ();
	char* ViewXML ();
	bool  Save (char *pFilename);

    // Implementaciones de los métodos publicos
    int Root (char *pName) {
        return 0;
    }

    /*
    *
    */
    bool Select (int id) {
        return false;
    }

    /*
    *
    */
    int Child (char *pName, char *pContent) {
        return 0;
    }

    /*
    *
    */
    int Child (char *pName) {
        return 0;
    }

    /*
    *
    */
    bool  EditAttribute (char *pKey, char *pValue, int mode) {
        return false;
    }

    /*
    *
    */
    bool  EditContent (char *pContent, int mode) {
        return false;
    }

    /*
    *
    */
    bool  SwitchContentPosition () {
        return false;
    }

    /*
    *
    */
    bool  SetBalanced () {
        return false;
    }

    /*
    *
    */
    bool  Delete () {
        return false;
    }

    /*
    *
    */
    char *ViewTree () {
        return "Hola Mundo";
    }

    /*
    *
    */
    char *ViewNode () {
        return "Hola Mundo";
    }

    /*
    *
    */
    char *ViewXML () {
        return "Hola Mundo";
    }
    
    /*
    *
    */
    bool  Save (char *pFilename) {
        return "Hola Mundo";
    }

};

#endif