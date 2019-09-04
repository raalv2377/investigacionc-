#include <iostream>
#include <fstream>
#include <array>
#include "TelefonoMovil.cpp"
using namespace std;

// Funcion utilizada para evaluar si la opcion escogida es valida
bool rangoCorrecto(int valor) {
    return 0<=valor && valor<=9;
}

// Function used to represent the Menu Section of the program
    // Returns users choice
int menuSelection(int& option) {

    cout << "Enter a number from the menu" << endl;
    cout << "1. Cargar datos de archivo\n"
         << "2. Almacenar datos en archivo\n"
         << "3. Valor de inventario\n"
         << "4. Valor de inventario para marca modelo particular\n"
         << "5. Mostrar cantidad disponible para marca-modelo particular\n"
         << "6. Añadir a inventario\n"
         << "7. Vender Telefono\n"
         << "8. Mostrar inventario en orden alfabetico marca modelo\n"
         << "0. Salir\n"
         << endl;

    do {
        cin >> option;

        if (!rangoCorrecto(option)) {
            cout << "Number option must be between 0 and 8" << endl;
        }

    } while (!rangoCorrecto(option));
    return option;
}

// Reads file, extracts data for variables, then creates a new phone and adds it to the array
void opcion1(string& fileName, ifstream& input, int& index, TelefonoMovil telefono[], bool& flag) {

    // Temp values to facilitate Telefono creation
    string marca;
    string modelo;
    string precio;
    string inventario;
    cout << "Por favor provea el nombre del archivo junto a su extension \'.dat\'" << endl;
        cin >> fileName;
        input.open(fileName); // Metele Try-Catch para cuando el file no exista
        while(getline(input, marca)){
            getline(input, modelo);
            getline(input, precio);
            getline(input, inventario);
            telefono[index] = TelefonoMovil(marca, modelo, precio, inventario);
            index++;
        }
    flag = true;
    input.close();
}

// Writes telefono data into same file ase read (?) with data separated by space
void opcion2(string fileName,ofstream& output,int index,TelefonoMovil telefono[]) {
    output.open(fileName); // Wrong. Actualizar contenido en el mismo archivo
        for(int i = 0; i <= index; i++) {
            output << telefono[i].getMarca() << " " << telefono[i].getModelo()
            << " " << telefono[i].getPrecio() << " " << telefono[i].getInventario() << endl;
        }
    output.close();
}

// Returns the value of the amount of phones in the inventory
int opcion3(int index, TelefonoMovil telefono[]) {
    int suma = 0;
        for(int i = 0; i <= index; i++) {
            suma += telefono[i].getInventario() * telefono[i].getPrecio();
        }
        return suma;
}

int opcion5(int index, TelefonoMovil telefono[]) {
    // opcion5(index, telefono);
        string marcaBuscar;
        string modeloBuscar;
        int suma = 0;
        cout << "Por favor provee la Marca y el Modelo del telefono"
            <<  " que desea buscar. Cada entrada separada por un pulso al \'enter\'." << endl;
        cin >> marcaBuscar;
        cin >> modeloBuscar;

        for(int i = 0; i <= index; i++) {
            if(telefono[index].getMarca().compare(marcaBuscar)
                &&  telefono[index].getModelo().compare(modeloBuscar)) {
                    suma++;
                }
        }
        cout << "La cantidad de " << marcaBuscar << " " << modeloBuscar << "es: " << endl;
        return suma;
}

int main()
{

    TelefonoMovil telefono[100];
    int index = 0; // Index used for telefono array
    int option; // used for menu
    bool flag = false; // Used to allow option 2. If option 1 was already accessed
    string fileName;
    ifstream input; // File to read from
    ofstream output; // File to write to

    menuSelection(option);

    switch (option)
    {
        // Preguntar al profe que hacer si el archivo no existe
    case 1: // Cargar datos
        opcion1(fileName, input, index, telefono, flag);
        break;

    case 2: // Almacenar datos
        if(!flag) cout << "Option 1 has not been used." << endl;
        else opcion2(fileName, output, index, telefono);
        break;

    case 3: // Suma de Inventario
        cout << opcion3(index, telefono) << endl;
        break;

    case 4: // Valor de Inventario para marca-modelo particular
        // Multiplica inventorio por precio de marca-modelo
        break;

    case 5: //Mostrar cantidad disponible para marca-modelo particular
        cout << opcion5(index, telefono) << endl;
        break;

    case 6: // Añadir a Inventario
        break;

    case 7: // Vender telefono
        break;

    case 8:
        break;
    
    case 0:
        break;
    }

    return 0;
}