#pragma once

#include <string>
#include <vector>

class Personaje {
public:
    std::string nombre;
    int vida;
    int vidaMaxima;
    int ataqueBase;
    int defensa;

    Personaje(std::string nombre, int vida, int ataque, int defensa);

    void atacarConGarras(Personaje &objetivo, std::vector<std::string> &logDeBatalla);
    void atacarConCola(Personaje &objetivo, std::vector<std::string> &logDeBatalla);
    void atacarConMordida(Personaje &objetivo, std::vector<std::string> &logDeBatalla);

    void ataqueEnemigo(Personaje &objetivo, std::vector<std::string> &logDeBatalla);

    void recibirDanio(int danio);
    bool estaVivo();
    void mostrarEstado(int y, int x);

private:
    void ejecutarAtaque(Personaje &objetivo, int danoModificador, int danoAleatorioExtra, const std::string& nombreAtaque, std::vector<std::string> &log);
};
