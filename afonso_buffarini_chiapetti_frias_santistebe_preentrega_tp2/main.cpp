#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>

#include "personaje.h"
#include "personaje.cpp"
#include "funciones.h"
#include "funciones.cpp"

using namespace std;

// Funciones
void jugarAventura();
bool iniciarBatalla();
void mostrarLog(const vector<string> &log);

int main() {
    srand(time(0));

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    if (has_colors() == TRUE) {
        start_color();
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
    }
    attron(COLOR_PAIR(1));

    bool jugando = true;
    int opcion;

    while (jugando) {
        do {
            mostrarMenuPrincipal();
            opcion = getch() - '0';
        } while (opcion < 1 || opcion > 4);

        switch (opcion) {
            case 1: jugarAventura(); break;
            case 2: mostrarOpciones(); break;
            case 3: mostrarCreditos(); break;
            case 4: jugando = false; break;
        }
    }

    attroff(COLOR_PAIR(1));
    endwin();
    cout << "Gracias por jugar!" << endl;
    return 0;
}

void jugarAventura() {
    limpiarYDibujarMarco();
    mvprintw(5, 4, "Tu letargo ha terminado. Un cascaron metalico ha aterrizado en tu mundo.");
    mvprintw(6, 4, "Sientes el calor de nuevas presas... nuevas oportunidades para expandir la colmena.");
    esperarEnter(8);

    limpiarYDibujarMarco();
    mvprintw(5, 4, "Una de las criaturas se acerca a tus crias. Es el momento perfecto.");
    mvprintw(6, 4, "Te aferras a su rostro, implantando la semilla de una nueva era.");
    esperarEnter(8);

    limpiarYDibujarMarco();
    mvprintw(5, 4, "Viajas dentro del anfitrion, en el corazon de su nave. Sientes el frio del metal a tu alrededor.");
    mvprintw(6, 4, "El momento de nacer se acerca...");
    esperarEnter(8);
    

    limpiarYDibujarMarco();
    mvprintw(5, 4, "Solo queda una. La mas fuerte. La mas resistente. Ripley.");
    mvprintw(6, 4, "Ha activado la autodestruccion de la nave. Quiere aniquilarte junto con este lugar.");
    mvprintw(7, 4, "La encuentras en su camino a la capsula de escape. Es hora de terminar la caceria.");
    esperarEnter(9);

    bool ganoBatalla = iniciarBatalla();

    if (ganoBatalla) {
        limpiarYDibujarMarco();
        mvprintw(5, 4, "Ripley yace derrotada. Su voluntad se quebro, pero su cuerpo servira a un proposito mayor.");
        mvprintw(6, 4, "La arrastras hacia el nido mientras la nave se desintegra a tu alrededor.");
        esperarEnter(8);
        limpiarYDibujarMarco();
        mvprintw(5, 4, "Escapas en la capsula de escape. La presa final esta asegurada.");
        mvprintw(8, 4, "¡GANASTE! La colmena sobrevivira.");
        esperarEnter(10);
    } else {
        limpiarYDibujarMarco();
        mvprintw(5, 4, "La humana es mas fuerte de lo que parecia. Logra expulsarte al vacio del espacio.");
        mvprintw(6, 4, "Flotas a la deriva, congelandote en la oscuridad infinita.");
        mvprintw(8, 4, "GAME OVER.");
        esperarEnter(10);
    }
}

bool iniciarBatalla() {
    personaje jugador("Xenomorfo", 300, 22, 5);
    personaje enemigo("Ripley", 250, 18, 8);
    
    vector<string> logDeBatalla;
    logDeBatalla.push_back("¡El Xenomorfo se interpone en el camino de Ripley!");
    
    int eleccion;

    while (jugador.estaVivo() && enemigo.estaVivo()) {
        do {
            limpiarYDibujarMarco();
            mvprintw(1, 40, "[ BATALLA FINAL ]"); // Título específico para la batalla

            jugador.mostrarEstado(3, 4);
            enemigo.mostrarEstado(4, 4);
            
            mostrarLog(logDeBatalla);

            mvprintw(15, 4, "¡Tu turno! Elige un ataque:");
            mvprintw(16, 4, "1. Garras (Rapido, daño bajo)");
            mvprintw(17, 4, "2. Cola (Normal, daño medio)");
            mvprintw(18, 4, "3. Mordida (Poderoso, puede fallar)");
            mvprintw(20, 4, "Selecciona una opcion: ");
            
            refresh();
            eleccion = getch() - '0';

        } while (eleccion < 1 || eleccion > 3);

        switch (eleccion) {
            case 1: jugador.atacarConGarras(enemigo, logDeBatalla); break;
            case 2: jugador.atacarConCola(enemigo, logDeBatalla); break;
            case 3: jugador.atacarConMordida(enemigo, logDeBatalla); break;
        }

        if (!enemigo.estaVivo()) break;

        logDeBatalla.push_back("¡Ripley contraataca con su lanzallamas!");
        enemigo.ataqueEnemigo(jugador, logDeBatalla);
    }

    limpiarYDibujarMarco();
    mvprintw(1, 40, "[ FIN DE LA BATALLA ]");
    mostrarLog(logDeBatalla);
    
    if (jugador.estaVivo()) {
        mvprintw(12, 4, "¡VICTORIA! ¡Has derrotado a Ripley!");
    } else {
        mvprintw(12, 4, "¡DERROTA! Ripley te ha vencido.");
    }
    esperarEnter(14);
    return jugador.estaVivo();
}

void mostrarLog(const vector<string> &log) {
    mvprintw(7, 4, "--- Registro de Batalla ---");
    int inicio = log.size() > 4 ? log.size() - 4 : 0;
    int linea = 8;
    for (size_t i = inicio; i < log.size(); ++i) {
        // Se usa %s y .c_str() para imprimir strings de forma segura
        mvprintw(linea, 4, "- %s", log[i].c_str());
        linea++;
    }
    mvprintw(linea, 4, "---------------------------");
}