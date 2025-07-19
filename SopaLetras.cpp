#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

const int FILAS = 10;
const int COLUMNAS = 10;

// matriz de la sopa de letras
char sopa[FILAS][COLUMNAS] = {
    {'f', 'j', 'f', 'b', 'm', 'x', 'o', 'm', 'n', 'u'},
    {'j', 'h', 's', 'x', 'a', 'o', 'n', 'r', 'o', 't'},
    {'j', 'u', 'n', 'h', 'r', 's', 'y', 'g', 'h', 'b'},
    {'b', 'w', 'l', 'e', 't', 'r', 'y', 'h', 't', 'v'},
    {'b', 'i', 'n', 'g', 'e', 'q', 'j', 'e', 'y', 'v'},
    {'x', 'x', 'w', 'u', 'l', 'a', 'q', 'x', 'p', 'l'},
    {'r', 'e', 'c', 'o', 'n', 'r', 'a', 'd', 'a', 'r'},
    {'o', 'n', 'c', 'e', 'l', 'o', 'f', 'Y', 'j', 'n'},
    {'e', 'p', 'y', 't', 'r', 'e', 't', 'o', 'z', 'f'},
    {'o', 'z', 'u', 'l', 'c', 'l', 'a', 's', 'e', 'f'}
};

// Esta funcion es para convertir a mayusculas
string aMayusculas(string str) {
    for (size_t i = 0; i < str.size(); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

// Funcion que muestra la sopa de letras
void mostrarSopa() {
    cout << "\n=== SOPA DE LETRAS ===\n";
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << sopa[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Esta funcion es para buscar palabra en una direccion especifica
bool buscarEnDireccion(const string& palabra, int fila, int col, int dirFila, int dirCol) {
    int len = palabra.length();

    // verificar si cabe en la direccion especificada
    if (fila + dirFila * (len-1) < 0 || fila + dirFila * (len-1) >= FILAS ||
        col + dirCol * (len-1) < 0 || col + dirCol * (len-1) >= COLUMNAS) {
        return false;
    }

    // compara letra
    for (int i = 0; i < len; i++) {
        char letraSopa = sopa[fila + i*dirFila][col + i*dirCol];
        if (toupper(letraSopa) != palabra[i]) {
            return false;
        }
    }
    return true;
}

// buscar palabras
void buscarPalabra(const string palabras[], int numPalabras) {
    int direcciones[8][2] = {{0,1}, {1,0}, {1,1}, {0,-1}, {-1,0}, {-1,-1}, {1,-1}, {-1,1}};

    for (int p = 0; p < numPalabras; p++) {
        string palabra = aMayusculas(palabras[p]);
        bool encontrada = false;

        for (int i = 0; i < FILAS && !encontrada; i++) {
            for (int j = 0; j < COLUMNAS && !encontrada; j++) {
                if (toupper(sopa[i][j]) == palabra[0]) {
                    for (int d = 0; d < 8 && !encontrada; d++) {
                        if (buscarEnDireccion(palabra, i, j, direcciones[d][0], direcciones[d][1])) {
                            cout << "Palabra \"" << palabras[p] << "\" encontrada en [" 
                                 << (i + 1) << "," << (j + 1) << "] direccion: ";
                            if (direcciones[d][0] == 0 && direcciones[d][1] == 1) cout << "derecha";
                            else if (direcciones[d][0] == 1 && direcciones[d][1] == 0) cout << "abajo";
                            else if (direcciones[d][0] == 1 && direcciones[d][1] == 1) cout << "diagonal abajo-derecha";
                            else if (direcciones[d][0] == 0 && direcciones[d][1] == -1) cout << "izquierda";
                            else if (direcciones[d][0] == -1 && direcciones[d][1] == 0) cout << "arriba";
                            else if (direcciones[d][0] == -1 && direcciones[d][1] == -1) cout << "diagonal arriba-izquierda";
                            else if (direcciones[d][0] == 1 && direcciones[d][1] == -1) cout << "diagonal abajo-izquierda";
                            else if (direcciones[d][0] == -1 && direcciones[d][1] == 1) cout << "diagonal arriba-derecha";
                            cout << endl;
                            encontrada = true;
                        }
                    }
                }
            }
        }

        if (!encontrada) {
            cout << "Palabra \"" << palabras[p] << "\" no encontrada." << endl;
        }
    }
}

int main() {
    // palabras x buscar
    const int numPalabras = 6;
    string palabras[numPalabras] = {"LETRA", "LUZ", "RETO", "CLASE", "RADAR", "PYTHON"};

    cout << "=== SOPA DE LETRAS ===" << endl;
    mostrarSopa();

    cout << "=== BUSCAR PALABRAS ===" << endl;
    buscarPalabra(palabras, numPalabras);

    return 0;
}