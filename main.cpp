#include <SFML/Graphics.hpp>
#include "menu.h"
#include "LinearSearch.h"
#include "BinarySearch.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"

using namespace sf;
using namespace std;

int main() {
    RenderWindow window(VideoMode(800, 600), "Proyecto SFML");
    window.setFramerateLimit(60);

    Font font;
    if (!font.loadFromFile("C:\\Users\\bande\\CLionProjects\\Proyecto\\Ethnocentric Rg.ttf")) {
        throw runtime_error("Error al cargar la fuente");
    }


    vector<string> mainMenuOptions = {
        "Algoritmos de Busqueda",
        "Algoritmos de Ordenamiento",
        "Estructuras Lineales",
        "Estructuras No Lineales",
        "Salir"
    };

    Menu mainMenu("MENU", mainMenuOptions);

    vector<string> searchMenuOptions = {
        "Linear Search",
        "Binary Search",
        "Regresar"
    };
    Menu searchMenu("BUSQUEDA", searchMenuOptions);

    vector<string> sortMenuOptions = {
        "Bubble Sort",
        "Selection Sort",
        "Insertion Sort",
        "Merge Sort",
        "Quick Sort",
        "Regresar"
    };
    Menu sortMenu("ORDENAMIENTO", sortMenuOptions);

    vector<string> linearMenuOptions = {
    "Pilas",
    "Filas",
    "Listas enlazadas",
    "Salir"
    };
    Menu linearMenu("Lineales", linearMenuOptions);

    vector<string> nonlinearMenuOptions = {
        "AVL",
        "Dijkstra",
        "Grafos",
        "Salir"
        };
    Menu nonlinearMenu("NO LINEALES", nonlinearMenuOptions);

    vector<string> graphsMenuOptions = {
        "DFS",
        "BFS",
        "Salir"
        };
    Menu graphsMenu("GRAFOS", graphsMenuOptions);

    MenuState currentState = MenuState::MainMenu;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (currentState == MenuState::MainMenu) {
                mainMenu.handleInput(event);
            }
            else if (currentState == MenuState::AlgoritmosBusqueda) {
                searchMenu.handleInput(event);
            }
            else if (currentState == MenuState::AlgoritmosOrdenamiento) {
                sortMenu.handleInput(event);
            }
            else if (currentState == MenuState::EstructurasLineales) {
                linearMenu.handleInput(event);
            }
            else if (currentState == MenuState::EstructurasNoLineales) {
                nonlinearMenu.handleInput(event);
            }
            else if (currentState == MenuState::Grafos) {
                graphsMenu.handleInput(event);
            }
        }

        if (currentState == MenuState::MainMenu) {
            mainMenu.draw(window);
        }
        else if (currentState == MenuState::AlgoritmosBusqueda) {
            searchMenu.draw(window);
        }
        else if (currentState == MenuState::AlgoritmosOrdenamiento) {
            sortMenu.draw(window);
        }
        else if (currentState == MenuState::EstructurasLineales) {
            linearMenu.draw(window);
        }
        else if (currentState == MenuState::EstructurasNoLineales) {
            nonlinearMenu.draw(window);
        }
        else if (currentState == MenuState::Grafos) {
            graphsMenu.draw(window);
        }

        if (mainMenu.isEnterPressed()) {
            switch (mainMenu.getSelectedIndex()) {
                case 0:
                    currentState = MenuState::AlgoritmosBusqueda;
                break;
                case 1:
                    currentState = MenuState::AlgoritmosOrdenamiento;
                break;
                case 2:
                    currentState = MenuState::EstructurasLineales;
                break;
                case 3:
                    currentState = MenuState::EstructurasNoLineales;
                break;
                case 4: // Salir
                    currentState = MenuState::Exit;
                window.close();
                break;
            }
            mainMenu.setEnterPressed(false); // Resetear el estado de Enter
        }

        if (searchMenu.isEnterPressed()) {
            switch (searchMenu.getSelectedIndex()) {
                case 0:{
                    LinearSearchOption option;
                    option.run();
                    currentState = MenuState::AlgoritmosBusqueda;
                    break;
                }
                case 1: {
                    BinarySearchOption option;
                    option.run();
                    currentState = MenuState::AlgoritmosBusqueda;
                    break;
                }
                case 2: // Regresar al menú principal
                    currentState = MenuState::MainMenu;
                break;
                default:
                    break;
            }
            searchMenu.setEnterPressed(false);
        }
        if (sortMenu.isEnterPressed()) {
            switch (sortMenu.getSelectedIndex()) {
                case 0:{  //Bubble Sort
                    BubbleSortOption option;
                    option.run();
                    currentState = MenuState::AlgoritmosOrdenamiento;
                    break;
                }
                case 1: { //selection sort
                    SelectionSortOption option;
                    option.run();
                    currentState = MenuState::AlgoritmosOrdenamiento;
                    break;
                }
                case 2: { //insertion sort
                    InsertionSortOption option;
                    option.run();
                    currentState = MenuState::AlgoritmosOrdenamiento;
                    break;
                }
                case 3: { //merge sort
                    MergeSortOption option;
                    option.run();
                    currentState = MenuState::AlgoritmosOrdenamiento;
                    break;
                }
                case 4: { //quick sort
                    QuickSortOption option;
                    option.run();
                    currentState = MenuState::AlgoritmosOrdenamiento;
                    break;
                }
                case 5: {
                    // Regresar al menú principal
                    currentState = MenuState::MainMenu;
                    break;
                }
                default:
                    break;
            }
            sortMenu.setEnterPressed(false);
        }
        if (linearMenu.isEnterPressed()) {
            switch (linearMenu.getSelectedIndex()) {
                case 0: { //Stacks
                    StackOption option;
                    option.run();
                    currentState = MenuState::EstructurasLineales;
                    break;
                }
                case 1: {//Queues
                    QueueOption option;
                    option.run();
                    currentState = MenuState::EstructurasLineales;
                    break;
                }
                case 2: { //Linked list
                    LinkedListOption option;
                    option.run();
                    currentState = MenuState::EstructurasLineales;
                    break;
                }
                case 3: {
                    // Regresar al menú principal
                    currentState = MenuState::MainMenu;
                    break;
                }
                default:
                    break;
            }
            linearMenu.setEnterPressed(false);
        }

        if (nonlinearMenu.isEnterPressed()) {
            switch (nonlinearMenu.getSelectedIndex()) {
                case 0: { //AVL
                    currentState = MenuState::EstructurasNoLineales;
                    break;
                }
                case 1: { //DIJKSTRA
                    currentState = MenuState::EstructurasNoLineales;
                    break;
                }
                case 2: { //GRAFOS
                    currentState = MenuState::Grafos;
                    break;
                }
                case 3: {
                    // Regresar al menú principal
                    currentState = MenuState::MainMenu;
                    break;
                }
                default:
                    break;
            }
            linearMenu.setEnterPressed(false);
        }

        if (graphsMenu.isEnterPressed()) {
            switch (graphsMenu.getSelectedIndex()) {
                case 0: { // DFS
                    currentState = MenuState::Grafos;
                    break;
                }
                case 1: { // BFS
                    currentState = MenuState::Grafos;
                    break;
                }
                case 2: {
                    currentState = MenuState::EstructurasNoLineales;
                    break;
                }
                default:
                    break;
            }
            graphsMenu.setEnterPressed(false);
        }


    }

    return 0;
}

