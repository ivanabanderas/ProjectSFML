#include "menu.h"

Menu::Menu(const string& title, const vector<string>& options)
    :  title(title), selectedIndex(0), enterPressed(false) {
    if (!font.loadFromFile("C:\\Users\\bande\\CLionProjects\\Proyecto\\Ethnocentric Rg.ttf")) {
        throw runtime_error("Error al cargar la fuente");
    }

    // Configurar las opciones del menú
    for (size_t i = 0; i < options.size(); ++i) {
        Text option;
        option.setFont(font);
        option.setString(options[i]);
        option.setCharacterSize(30);
        option.setPosition(50, 100 + i * 80); // Espaciado entre las opciones
        menuOptions.push_back(option);
    }
}

void Menu::handleInput(const Event& event) {
    if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Up) {
            selectedIndex = (selectedIndex - 1 + menuOptions.size()) % menuOptions.size();
        }
        else if (event.key.code == Keyboard::Down) {
            selectedIndex = (selectedIndex + 1) % menuOptions.size();
        }
        if (event.key.code == Keyboard::Enter) {
            enterPressed = true;
        }
    }
}


void Menu::draw(RenderWindow& window) {
    window.clear(Color(20,20,20));
    // Dibuja el título del menú
    Text titleText;
    titleText.setFont(font);
    titleText.setString(title);
    titleText.setCharacterSize(55);
    titleText.setFillColor(Color::White);
    titleText.setPosition(40, 25);
    window.draw(titleText);

    // Dibuja las opciones del menú
    for (size_t i = 0; i < menuOptions.size(); ++i) {
        if (i == selectedIndex) {
            menuOptions[i].setFillColor(Color(240,38,110)); // Resalta la opción seleccionada
        } else {
            menuOptions[i].setFillColor(Color(140,82,155));
        }
        window.draw(menuOptions[i]);
    }

    window.display();
}

int Menu::getSelectedIndex() const {
    return selectedIndex;
}

bool Menu::isEnterPressed() {
    return enterPressed;
}

void Menu::setEnterPressed(bool value) {
    enterPressed = value;
}
