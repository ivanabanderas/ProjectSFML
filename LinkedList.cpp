#include "LinkedList.h"

Node::Node(int value) : data(value), next(nullptr) {}

LinkedListOption::LinkedListOption()
    : head(nullptr), window(VideoMode(800, 600), "Linked List"), isEntering(false), isDeleting(false) {
    if (!font.loadFromFile("C:\\Users\\bande\\CLionProjects\\Proyecto\\Ethnocentric Rg.ttf")) {
        cerr << "Error: No se pudo cargar la fuente.\n";
    }

    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(Color(140, 82, 155));
    text.setPosition(10, 10);
    text.setString("1. Presiona un numero y Enter\n   para agregar un nodo\n2. Presiona 'E' para eliminar\n   un nodo.\n3. Presiona Esc para salir");

    userInput.setFont(font);
    userInput.setCharacterSize(25);
    userInput.setFillColor(Color(4,242,253));
    userInput.setPosition(10, 200);
}

void LinkedListOption::handleInput() {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        }

        if (event.type == Event::KeyPressed) {
            if (event.key.code == Keyboard::Escape) {
                window.close();
            }
            if (event.key.code == Keyboard::E) {
                isDeleting = true;
                isEntering = false;
                userInput.setString("");
                text.setString("Ingrese el valor a eliminar\ny presione Enter:");
            }
        }

        if (event.type == Event::TextEntered) {
            char typedChar = static_cast<char>(event.text.unicode);
            if (isdigit(typedChar) && userInput.getString().getSize() < 10) {
                userInput.setString(userInput.getString() + typedChar);
            } else if (typedChar == '\r') {
                try {
                    int value = stoi(userInput.getString().toAnsiString());
                    if (isDeleting) {
                        remove(value);
                        text.setString("Nodo eliminado\nPresione otro comando.");
                    } else {
                        insert(value);
                        text.setString("Nodo agregado\nPresione otro comando.");
                    }
                    userInput.setString("");
                    isDeleting = false;
                } catch (exception&) {
                    text.setString("Entrada invalida");
                }
            }
        }
    }
}

void LinkedListOption::insert(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    Text nodeText;
    nodeText.setFont(font);
    nodeText.setCharacterSize(25);
    nodeText.setFillColor(Color(240, 38, 110));
    nodeText.setString(to_string(value));
    nodeText.setPosition(100 + nodeTexts.size() * 70, 300);
    nodeTexts.push_back(nodeText);
}

void LinkedListOption::remove(int value) {
    if (!head) return;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        Node* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }
        if (current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // Actualizar visualización de nodos
    nodeTexts.clear();
    vector<int> values = toVector();
    for (size_t i = 0; i < values.size(); ++i) {
        Text nodeText;
        nodeText.setFont(font);
        nodeText.setCharacterSize(25);
        nodeText.setFillColor(Color(240, 38, 110));
        nodeText.setString(to_string(values[i]));
        nodeText.setPosition(100 + i * 50, 300);
        nodeTexts.push_back(nodeText);
    }
}

vector<int> LinkedListOption::toVector() const {
    vector<int> values;
    Node* current = head;
    while (current) {
        values.push_back(current->data);
        current = current->next;
    }
    return values;
}

void LinkedListOption::draw() {
    window.draw(text);
    window.draw(userInput);

    // Dibujar nodos
    for (const auto& nodeText : nodeTexts) {
        window.draw(nodeText);
    }
}

void LinkedListOption::run() {
    while (window.isOpen()) {
        handleInput();
        window.clear();
        draw();
        window.display();
    }
}
