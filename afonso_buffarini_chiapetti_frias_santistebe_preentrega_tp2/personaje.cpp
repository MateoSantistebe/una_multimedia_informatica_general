#include "personaje.h"
#include <iostream>
#include <cstdlib>     
#include <ncurses.h>   
#include <vector>
#include <string>

using namespace std;

// Implementacion del Constructor
personaje::personaje(std::string n, int v, int a, int d) {
    nombre = n;
    vidaMaxima = v;
    vida = vidaMaxima; // Empieza con la vida al máximo
    ataqueBase = a;
    defensa = d;
}

// Implementacion del metodo para recibir daño
void personaje::recibirDanio(int danio) {
    vida -= danio;
    // Evitamos que la vida sea negativa
    if (vida < 0) {
        vida = 0;
    }
}

// Revisa si el personaje sigue vivo
bool personaje::estaVivo() {
    return vida > 0;
}

// Muestra el estado actual (nombre y vida) usando Ncurses
void personaje::mostrarEstado(int y, int x) {
   
    mvprintw(y, x, "%-10s | Vida: %3d / %3d", this->nombre.c_str(), this->vida, this->vidaMaxima);
}

// --- Implementacion de los Ataques ---

void personaje::atacarConGarras(personaje &objetivo, vector<string> &logDeBatalla) {
    int danoAleatorio = rand() % 4; // Daño extra de 0 a 3
    int danoTotal = this->ataqueBase - 5 + danoAleatorio; // Ataque rápido pero débil
    int danoReal = danoTotal - objetivo.defensa;
    if (danoReal < 1) danoReal = 1; // Mínimo 1 de daño

    objetivo.recibirDanio(danoReal);
    
    // to_string convierte un número a un string para poder concatenarlo
    string mensaje = this->nombre + " ataca con sus garras e inflige " + to_string(danoReal) + " de daño.";
    logDeBatalla.push_back(mensaje);
}

void personaje::atacarConCola(personaje &objetivo, vector<string> &logDeBatalla) {
    int danoAleatorio = rand() % 6; // Daño extra de 0 a 5
    int danoTotal = this->ataqueBase + danoAleatorio; // Daño normal
    int danoReal = danoTotal - objetivo.defensa;
    if (danoReal < 1) danoReal = 1;

    objetivo.recibirDanio(danoReal);

    string mensaje = this->nombre + " golpea con su cola e inflige " + to_string(danoReal) + " de daño.";
    logDeBatalla.push_back(mensaje);
}

void personaje::atacarConMordida(personaje &objetivo, vector<string> &logDeBatalla) {
    int chance = rand() % 100; // Un número entre 0 y 99
    if (chance < 80) { // 80% de probabilidad de acertar
        int danoAleatorio = rand() % 8; // Daño extra de 0 a 7
        int danoTotal = this->ataqueBase + 10 + danoAleatorio; // Ataque fuerte
        int danoReal = danoTotal - objetivo.defensa;
        if (danoReal < 1) danoReal = 1;

        objetivo.recibirDanio(danoReal);

        string mensaje = this->nombre + " muerde ferozmente e inflige " + to_string(danoReal) + " de daño!";
        logDeBatalla.push_back(mensaje);
    } else {
        // El ataque falla
        string mensaje = this->nombre + " intenta morder, pero " + objetivo.nombre + " lo esquiva!";
        logDeBatalla.push_back(mensaje);
    }
}

void personaje::ataqueEnemigo(personaje &objetivo, vector<string> &logDeBatalla) {
    int danoAleatorio = rand() % 7; // Daño extra de 0 a 6
    int danoTotal = this->ataqueBase + danoAleatorio;
    int danoReal = danoTotal - objetivo.defensa;
    if (danoReal < 1) danoReal = 1;

    objetivo.recibirDanio(danoReal);

    string mensaje = this->nombre + " dispara el lanzallamas e inflige " + to_string(danoReal) + " de daño.";
    logDeBatalla.push_back(mensaje);
}