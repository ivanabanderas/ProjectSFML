#ifndef MENU_H // Inicio del include guard
#define MENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

using namespace std;
using namespace sf;


enum class MenuState {
    MainMenu,
    AlgoritmosBusqueda,
    AlgoritmosOrdenamiento,
    EstructurasLineales,
    EstructurasNoLineales,
    Grafos,
    Exit
};

// Clase Menu
class Menu {


private:
    vector<Text> menuOptions;
    Font font;
    int selectedIndex;
    string title;
    bool enterPressed;

public:
    Menu(const string& title, const vector<string>& options);
    void handleInput(const Event& event);
    void draw(RenderWindow& window);
    int getSelectedIndex() const;
    bool isEnterPressed();
    void setEnterPressed(bool value);

};

#endif // Fin del include guard
