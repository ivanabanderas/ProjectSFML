#include "BubbleSort.h"
BubbleSortOption::BubbleSortOption()
    : window(VideoMode(800, 600), "Bubble Sort"),
      isEnteringArray(true),
      windowWidth(800), windowHeight(600) {

    if (!font.loadFromFile("C:\\Users\\bande\\CLionProjects\\Proyecto\\Ethnocentric Rg.ttf")) {
        cerr << "Error: No se pudo cargar la fuente.\n";
        exit(-1);
    }

    prompt.setFont(font);
    prompt.setString("1. Ingrese numeros separados\n  (max.10) por espacios \n2. Presione Enter");
    prompt.setCharacterSize(30);
    prompt.setFillColor(Color(140,82,155));
    prompt.setPosition(10, 20);

    userInput.setFont(font);
    userInput.setCharacterSize(25);
    userInput.setFillColor(Color(240,38,110));
    userInput.setPosition(10, 190);
}

void BubbleSortOption::run() {
    handleInput();
    bubbleSort();
}


void BubbleSortOption::handleInput() {
    string inputText;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return;
            }

            if (event.type == Event::TextEntered) {
                if (event.text.unicode == '\b' && !inputText.empty()) {
                    inputText.pop_back();
                }
                else if (event.text.unicode == '\r') {
                    istringstream iss(inputText);
                    int num;
                    while (iss >> num && numbers.size() < 10) {
                        numbers.push_back(num);
                    }
                    isEnteringArray = false;
                    return;
                }
                else if (event.text.unicode < 128 && inputText.size() < 100) {
                    inputText += static_cast<char>(event.text.unicode);
                }
            }
        }

        userInput.setString(inputText);
        window.clear(Color(20,20,30));
        window.draw(prompt);
        window.draw(userInput);
        window.display();
    }
}

void BubbleSortOption::drawArray(const vector<int>& array, int highlightedIndex, int comparisonIndex) {
    window.clear(Color(20,20,30));

    float spacing = static_cast<float>(windowWidth) / array.size();
    for (size_t i = 0; i < array.size(); ++i) {
        Text numberText;
        numberText.setFont(font);
        numberText.setString(std::to_string(array[i]));
        numberText.setCharacterSize(30);
        numberText.setFillColor(Color::White);


        float xPos = i * spacing + (spacing / 2) - (numberText.getLocalBounds().width / 2);
        float yPos = windowHeight / 2 - numberText.getLocalBounds().height / 2;

        if (static_cast<int>(i) == highlightedIndex) {
            numberText.setFillColor(Color(240,38,110));
        } else if (static_cast<int>(i) == comparisonIndex) {
            numberText.setFillColor(Color(4,242,253)); //
        }

        numberText.setPosition(xPos, yPos);
        window.draw(numberText);
    }

    window.display();
}

void BubbleSortOption::bubbleSort() {
    for (size_t i = 0; i < numbers.size(); ++i) {
        for (size_t j = 0; j < numbers.size() - i - 1; ++j) {
            drawArray(numbers, j, j + 1);
            std::this_thread::sleep_for(chrono::milliseconds(200)); // Pausa para visualizar el proceso

            if (numbers[j] > numbers[j + 1]) {
                std::swap(numbers[j], numbers[j + 1]);
                drawArray(numbers, j, j + 1);
                std::this_thread::sleep_for(chrono::milliseconds(200));
            }
        }
    }

    // Mostrar el array ordenado
    drawArray(numbers);
    this_thread::sleep_for(chrono::seconds(2));
}
