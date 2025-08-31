#pragma once

#include <string>
#include <vector>

class personaje {
public:
    // --- Atributos ---
    std::string nombre;
    int vida;
    int vidaMaxima;
    int ataqueBase;
    int defensa;

    // --- Metodos (las acciones que puede hacer) ---

    // Constructor: Se llama al crear un nuevo objeto personaje
    personaje(std::string nombre, int vida, int ataque, int defensa);

    // Ataques del Xenomorfo
    void atacarConGarras(personaje &objetivo, std::vector<std::string> &logDeBatalla);
    void atacarConCola(personaje &objetivo, std::vector<std::string> &logDeBatalla);
    void atacarConMordida(personaje &objetivo, std::vector<std::string> &logDeBatalla);

    // Ataque de Ripley
    void ataqueEnemigo(personaje &objetivo, std::vector<std::string> &logDeBatalla);

    // Métodos de utilidad
    void recibirDanio(int danio);
    bool estaVivo();

    // Método de visualización para Ncurses
    void mostrarEstado(int y, int x);
};


