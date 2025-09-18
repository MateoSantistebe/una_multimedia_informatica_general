#include "Personaje.h"
#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <vector>
#include <string>

using namespace std;

Personaje::Personaje(std::string n, int v, int a, int d) {
    nombre = n;
    vidaMaxima = v;
    vida = vidaMaxima;
    ataqueBase = a;
    defensa = d;
}

void Personaje::recibirDanio(int danio) {
    vida -= danio;
    if (vida < 0) {
        vida = 0;
    }
}

bool Personaje::estaVivo() {
    return vida > 0;
}

void Personaje::mostrarEstado(int y, int x) {
    mvprintw(y, x, "%-10s | Vida: %3d / %3d", this->nombre.c_str(), this->vida, this->vidaMaxima);
}

void Personaje::ejecutarAtaque(Personaje &objetivo, int danoModificador, int danoAleatorioExtra, const std::string& nombreAtaque, vector<string> &log) {
    int danoAleatorio = rand() % (danoAleatorioExtra + 1);
    int danoTotal = this->ataqueBase + danoModificador + danoAleatorio;
    int danoReal = danoTotal - objetivo.defensa;

    if (danoReal < 1) danoReal = 1; 

    objetivo.recibirDanio(danoReal);

   
    string mensaje = this->nombre + nombreAtaque + to_string(danoReal) + " de daño.";
    log.push_back(mensaje);
}

void Personaje::atacarConGarras(Personaje &objetivo, vector<string> &logDeBatalla) {
    ejecutarAtaque(objetivo, -5, 3, " ataca con sus garras e inflige ", logDeBatalla);
}

void Personaje::atacarConCola(Personaje &objetivo, vector<string> &logDeBatalla) {
    ejecutarAtaque(objetivo, 0, 5, " golpea con su cola e inflige ", logDeBatalla);
}

void Personaje::atacarConMordida(Personaje &objetivo, vector<string> &logDeBatalla) {
    int chance = rand() % 100;
    if (chance < 80) {
        ejecutarAtaque(objetivo, 10, 7, " muerde ferozmente e inflige ", logDeBatalla);
    } else {
        string mensaje = this->nombre + " intenta morder, pero " + objetivo.nombre + " lo esquiva!";
        logDeBatalla.push_back(mensaje);
    }
}

void Personaje::ataqueEnemigo(Personaje &objetivo, vector<string> &logDeBatalla) {
    ejecutarAtaque(objetivo, 0, 6, " dispara el lanzallamas e inflige ", logDeBatalla);
}