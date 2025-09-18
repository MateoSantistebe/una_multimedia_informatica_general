#include <iostream>
#include <ncurses.h>
#include "funciones.h"

using namespace std;

void dibujarLogoWeyland() {
    int start_y = 5;
    int start_x = 60;

    mvprintw(start_y, start_x - 10, "WEYLAND-YUTANI CORP");
    mvprintw(start_y + 2, start_x - 22, "WWWWWWWWWWWW            WWWWWWWWWWWW");
    mvprintw(start_y + 3, start_x - 20, "W            W          W            W");
    mvprintw(start_y + 4, start_x - 18, "W             W        W             W");
    mvprintw(start_y + 5, start_x - 16, "W              W      W              W");
    mvprintw(start_y + 6, start_x - 14, "W               W    W               W");
    mvprintw(start_y + 7, start_x - 12, "W                W  W                W");
    mvprintw(start_y + 8, start_x - 11, "W                 WW                 W");
    mvprintw(start_y + 9, start_x - 12, "W                W  W                W");
    mvprintw(start_y + 10, start_x - 14, "W               W    W               W");
    mvprintw(start_y + 11, start_x - 16, "W              W      W              W");
    mvprintw(start_y + 12, start_x - 18, "W             W        W             W");
    mvprintw(start_y + 13, start_x - 20, "W            W          W            W");
    mvprintw(start_y + 14, start_x - 22, "WWWWWWWWWWWW            WWWWWWWWWWWW");
    mvprintw(start_y + 17, start_x - 12, "BUILDING BETTER WORLDS");
}

void limpiarYDibujarMarco() {
    clear();
    box(stdscr, 0, 0);
    mvprintw(1, 40, "[ TERMINAL WEYLAND-YUTANI ]");
    refresh();
}

void mostrarMenuPrincipal() {
    limpiarYDibujarMarco();
    dibujarLogoWeyland();
    mvprintw(25, 52, "1. Jugar");
    mvprintw(26, 52, "2. Opciones");
    mvprintw(27, 52, "3. Créditos");
    mvprintw(28, 52, "4. Salir");
    mvprintw(30, 52, "Selecciona una opcion: ");
    refresh();
}

void mostrarOpciones() {
    limpiarYDibujarMarco();
    mvprintw(1, 40, "[ OPCIONES ]");
    mvprintw(5, 6, "Dificultad: PESADILLA");
    mvprintw(6, 6, "Resolucion: 120x40");
    mvprintw(7, 6, "Graficos: ASCII ULTRA RETRO");
    mvprintw(8, 6, "Sonido: DESACTIVADO");
    mvprintw(9, 6, "Modo inmersivo: ON");
    mvprintw(10, 6, "Autosave: DESACTIVADO");
    esperarEnter(12);
}

void mostrarCreditos() {
    limpiarYDibujarMarco();
    mvprintw(1, 40, "[ CREDITOS ]");
    mvprintw(4, 6, "TRABAJO PRACTICO 1 - INFORMATICA GENERAL");
    mvprintw(6, 6, "Grupo: Nostromo");
    mvprintw(7, 6, "Integrantes: ");
    mvprintw(8, 8, "- Gaston Afonso");
    mvprintw(9, 8, "- Magali Frias");
    mvprintw(10, 8, "- Pablo Chiappetti");
    mvprintw(11, 8, "- Mateo Santistebe");
    mvprintw(12, 8, "- Nicolas Buffarini");
    esperarEnter(14);
}

void esperarEnter(int y) {
    mvprintw(y, 6, "Presiona cualquier tecla para continuar...");
    refresh();
    getch();
}