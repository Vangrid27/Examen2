#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

const int TOTAL = 50;

// arreglo de frases
string palabras[TOTAL] = {
    "perro", "   Gato", "SOL", "agua clara", "  cielo azul  ", "tigre", "Elefante", "raton",
    "leon", "jirafa", "computadora", "C++", "clase de programacion", "   codigo limpio   ",
    "variable", "123", "Suma", "123abc", "if else", "Funcion strtok()", "El arbol",
    "espacio exterior", "Marte", "Universo", "planeta Tierra", "satelite natural",
    "123sol", "luz solar", "Nube", "atmosfera", "C++", "C++", "c++", "  C++  ", "c++",
    "C++", "c++", "c++3", "C++ISTA", "programador c++", "Camino", "caminar", "corriendo",
    "Corre", "jugar futbol", "123 calle", " final", "Centro", "norte", "sur"
};

// quita espacios al inicio y final
string limpiar(string s) {
    int inicio = s.find_first_not_of(' ');
    int fin = s.find_last_not_of(' ');
    if (inicio == -1 || fin == -1) return "";
    return s.substr(inicio, fin - inicio + 1);
}

// Buscar palabra con espacios antes
void buscarAnimal() {
    for (int i = 0; i < TOTAL; i++) {
        string limpio = limpiar(palabras[i]);
        if (limpio == "Gato") {
            cout << "\n+--------+" << endl;
            cout << "| Animal |" << endl;
            cout << "+--------+" << endl;
            cout << "| " << limpio << "   |" << endl; // se asume fijo 6 letras
            cout << "+--------+\n" << endl;
            break;
        }
    }
}

// funcion para buscar lenguaje en minusculas y convertir
void encabezadoLenguaje() {
    for (int i = 0; i < TOTAL; i++) {
        string limpio = limpiar(palabras[i]);
        if (limpio == "c++") {
            cout << "Lenguaje encontrado (convertido a encabezado): C++" << endl;
        }
    }
}

// verificar si alguna palabra es numero puro
void verificarNumerico() {
    for (int i = 0; i < TOTAL; i++) {
        string limpio = limpiar(palabras[i]);
        bool esNumero = true;
        for (int j = 0; j < limpio.length(); j++) {
            if (!isdigit(limpio[j])) {
                esNumero = false;
                break;
            }
        }
        if (esNumero && limpio.length() > 0) {
            cout << "Numero detectado sin conversion: " << limpio << endl;
        }
    }
}

// buscar frase y extraer lo visible
void parteVisibleAgua() {
    for (int i = 0; i < TOTAL; i++) {
        string limpio = limpiar(palabras[i]);
        if (limpio.find("agua") != string::npos) {
            int espacio = limpio.find(' ');
            if (espacio != string::npos && espacio + 1 < limpio.length()) {
                cout << "Parte visible del agua: " << limpio.substr(espacio + 1) << endl;
                break;
            }
        }
    }
}

// detectar combinacion letras o numeros y validar si es solo letras
void esAlfabetico() { 
    for (int i = 0; i < TOTAL; i++) {
        string limpio = limpiar(palabras[i]);
        bool tieneLetras = false;
        bool tieneNumeros = false;
        for (int j = 0; j < limpio.length(); j++) {
            if (isalpha(limpio[j])) tieneLetras = true;
            if (isdigit(limpio[j])) tieneNumeros = true;
        }
        if (tieneLetras && tieneNumeros) {
            bool soloLetras = true;
            for (int j = 0; j < limpio.length(); j++) {
                if (!isalpha(limpio[j])) {
                    soloLetras = false;
                    break;
                }
            }
            cout << "Texto '" << limpio << "' solo letras? " << (soloLetras ? "Si" : "No") << endl;
        }
    }
}

// funcion para detectar todos los que inicien con C++ en cualquier forma
void normalizarLenguaje() {
    for (int i = 0; i < TOTAL; i++) {
        string s = limpiar(palabras[i]);
        string copia = s;
        transform(copia.begin(), copia.end(), copia.begin(), ::tolower);
        if (copia.find("c++") == 0) {
            cout << "Lenguaje normalizado: C++ (desde '" << s << "')" << endl;
        }
    }
}

// funcion para detectar frase pacifica y alterarla
void alternarCielo() {
    for (int i = 0; i < TOTAL; i++) {
        string limpio = limpiar(palabras[i]);
        if (limpio == "cielo azul") {
            for (int j = 0; j < limpio.length(); j++) {
                if (isalpha(limpio[j])) {
                    limpio[j] = (j % 2 == 0) ? toupper(limpio[j]) : tolower(limpio[j]);
                }
            }
            cout << "Frase alternada: " << limpio << endl;
            break;
        }
    }
}

// Buscar menciones a dividir cadenas
void encontrarStrtok() {
    for (int i = 0; i < TOTAL; i++) {
        size_t pos = palabras[i].find("strtok");
        if (pos != string::npos) {
            cout << "Funcion strtok detectada en posicion " << pos << " de la cadena: " << palabras[i] << endl;
            break;
        }
    }
}

// limpiar espacios finales
void limpiarResiduos() {
    for (int i = 0; i < TOTAL; i++) {
        string limpio = limpiar(palabras[i]);
        if (palabras[i] != limpio) {
            cout << "Frase original: '" << palabras[i] << "' -> Limpia: '" << limpio << "'" << endl;
        }
    }
}

// detectar frase aparentemente vacia
void recuperarTitulo() {
    for (int i = 0; i < TOTAL; i++) {
        string limpio = limpiar(palabras[i]);
        if (limpio == "C++" && palabras[i] != "C++") {
            cout << "\n==========================" << endl;
            cout << "      TITULO PRINCIPAL     " << endl;
            cout << "        "    << limpio << endl;
            cout << "==========================\n" << endl;
            break;
        }
    }
}

int main() {
    buscarAnimal();
    encabezadoLenguaje();
    verificarNumerico();
    parteVisibleAgua();
    esAlfabetico();
    normalizarLenguaje();
    alternarCielo();
    encontrarStrtok();
    limpiarResiduos();
    recuperarTitulo();
    return 0;
}