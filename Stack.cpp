#include "Stack.h"

StackOption::StackOption()
    : window(VideoMode(800, 600), "Stacks") {

    if (!font.loadFromFile("C:\\Users\\bande\\CLionProjects\\Proyecto\\Ethnocentric Rg.ttf")) {
        cerr << "Error: No se pudo cargar la fuente.\n";
        exit(-1);
    }

    text.setFont(font);
    text.setString("1. Presione enter para agregar\n2. Presione E para eliminar\n3. Presione Esc para salir");
    text.setCharacterSize(30);
    text.setFillColor(Color(140, 82, 155));
    text.setPosition(10, 10);

    userInput.setFont(font);
    userInput.setCharacterSize(25);
    userInput.setFillColor(Color(240, 38, 110));
    userInput.setPosition(10, 190);
}

void StackOption::run() {
    while (window.isOpen()) {
        handleInput();

        window.clear();
        window.draw(text);
        window.draw(userInput);
        drawStack();
        window.display();
    }
}

void StackOption::handleInput() {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        }

        if (event.type == Event::KeyPressed) {
            if (event.key.code == Keyboard::Escape) {
                window.close();
            }
            else if (event.key.code == Keyboard::E) {
                pop();
            }
            else if (event.key.code == Keyboard::Enter && !input.empty()) {
                try {
                    int value = stoi(input);
                    push(value);
                    input.clear();
                }
                catch (const exception &e) {
                    cerr << "Error: Entrada inválida\n";
                }
            }
        }

        if (event.type == Event::TextEntered) {
            char typedChar = static_cast<char>(event.text.unicode);

            if (typedChar == '\b' && !input.empty()) {
                input.pop_back();
            }
            else if (isdigit(typedChar) && input.size() < 10) {
                input += typedChar;
            }
        }
    }

    userInput.setString("Input: " + input);
}

void StackOption::push(int value) {
    pila.push(value);
}

void StackOption::pop() {
    if (!pila.empty()) {
        pila.pop();
    }
}

bool StackOption::isEmpty() {
    return pila.empty();
}

void StackOption::drawStack() {
    stack<int> tempstack = pila;
    int offset = 0;
    const int maxVisible = 15;

    while (!tempstack.empty() && offset < maxVisible * 25) {
        RectangleShape rectangle(Vector2f(60, 40));
        rectangle.setPosition(50, 250 + offset);
        rectangle.setFillColor(Color(4, 242, 253));
        window.draw(rectangle);

        Text valueText;
        valueText.setFont(font);
        valueText.setString(to_string(tempstack.top()));
        valueText.setCharacterSize(25);
        valueText.setFillColor(Color::White);
        valueText.setPosition(55, 250 + offset);
        window.draw(valueText);

        tempstack.pop();
        offset += 25;
    }
}