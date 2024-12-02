#include "LinearSearch.h"
int linearSearch(const vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) return i;
    }
    return -1;
}

LinearSearchOption::LinearSearchOption()
    : window(sf::VideoMode(800, 600), "Linear Search"),
      isEnteringArray(true) {
    if (!font.loadFromFile("C:\\Users\\bande\\CLionProjects\\Proyecto\\Ethnocentric Rg.ttf")) {
        cerr << "Error: No se pudo cargar la fuente.\n";
        exit(-1);
    }

    displayText.setFont(font);
    displayText.setCharacterSize(30);
    displayText.setFillColor(sf::Color(240, 38, 110));
    displayText.setPosition(20, 200);
    resultMessage = "1. Ingrese numeros separados \n   un espacio \n2.presione enter \n3.Presione Esc para salir";
}


void LinearSearchOption::run() {
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::TextEntered) {
                handleInput(event);
            }
            else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                window.close();
                return;
            }
        }

        draw();
    }
}

// Manejar la entrada del usuario
void LinearSearchOption::handleInput(Event event) {
    if (event.text.unicode == '\b') { // Backspace
        if (!userInput.isEmpty())
            userInput.erase(userInput.getSize() - 1, 1);
    } else if (event.text.unicode == '\r') {
        if (isEnteringArray) {
            // Guardar el array ingresado
            istringstream iss(userInput.toAnsiString());
            int num;
            while (iss >> num)
                array.push_back(num);

            // Preparar mensaje para ingresar el número a buscar
            resultMessage = "Array ingresado: " + userInput.toAnsiString() + "\nIngresa el numero a buscar:";
            isEnteringArray = false; // Cambiar a modo búsqueda
        } else {
            // Realizar búsqueda
            int target = stoi(userInput.toAnsiString());
            int index = linearSearch(array, target);
            resultMessage = to_string(target) +
                            (index != -1 ? " encontrado en indice " + to_string(index)
                                         : " no encontrado.");
            userInput.clear();
            isEnteringArray = true; // Regresar al modo de entrada del array
            array.clear(); // Limpiar el array para la próxima entrada
        }
        userInput.clear();
    } else if (event.text.unicode < 128) {
        userInput += event.text.unicode;
    }
}

// Dibujar en pantalla
void LinearSearchOption::draw() {
    displayText.setString(resultMessage + "\n\nEntrada: " + userInput.toAnsiString());
    window.clear(sf::Color(20,20,30));
    window.draw(displayText);
    window.display();
}