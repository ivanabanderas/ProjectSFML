    //
    // Created by bande on 01/12/2024.
    //

#include "Queue.h"
QueueOption::QueueOption()
    : window(VideoMode(800, 600), "Queue") {

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

void QueueOption::run() {
    while (window.isOpen()) {
        handleInput();

        window.clear();
        window.draw(text);
        window.draw(userInput);
        drawQueue();
        window.display();
    }
}

void QueueOption::handleInput() {
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
                dequeueVal();
            }
            else if (event.key.code == Keyboard::Enter && !input.empty()) {
                try {
                    int value = stoi(input);
                    enqueueVal(value);
                    input.clear();
                }
                catch (const exception &e) {
                    cerr << "Error: Entrada invalida\n";
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

void QueueOption::enqueueVal(int value) {
    fila.push(value);
}

void QueueOption::dequeueVal() {
    if (!fila.empty()) {
        fila.pop();
    }
}

bool QueueOption::isEmpty() {
    return fila.empty();
}
void QueueOption::drawQueue() {
    queue<int> tempqueue = fila;
    int offset = 0;
    const int maxVisible = 15;

    // Dibujar elementos de la cola
    while (!tempqueue.empty() && offset < maxVisible * 60) {
        RectangleShape rectangle(Vector2f(60, 40));
        rectangle.setPosition(50 + offset, 250);
        rectangle.setFillColor(Color(4, 242, 253));
        window.draw(rectangle);

        Text valueText;
        valueText.setFont(font);
        valueText.setString(to_string(tempqueue.front()));
        valueText.setCharacterSize(25);
        valueText.setFillColor(Color::White);
        valueText.setPosition(50 + offset, 255);
        window.draw(valueText);

        tempqueue.pop();
        offset += 70;
    }

    if (!fila.empty()) {
        Text frontText;
        frontText.setFont(font);
        frontText.setString("I");
        frontText.setCharacterSize(20);
        frontText.setFillColor(Color(240, 38, 110));
        frontText.setPosition(70, 300);
        window.draw(frontText);
        RectangleShape arrow(Vector2f(10, 10));
        arrow.setPosition(70, 290);
        arrow.setFillColor(Color(240, 38, 110));
        window.draw(arrow);
    }

    // Dibujar flecha para el final
    if (offset > 0) {
        Text endText;
        endText.setFont(font);
        endText.setString("F");
        endText.setCharacterSize(20);
        endText.setFillColor(Color(240, 38, 110));
        endText.setPosition(50 + offset - 70, 300);
        window.draw(endText);

        RectangleShape arrow(Vector2f(10, 10));
        arrow.setPosition(70 + offset - 70, 290);
        arrow.setFillColor(Color(240, 38, 110));
        window.draw(arrow);
    }
}
