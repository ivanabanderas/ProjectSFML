//
// Created by bande on 29/11/2024.
//
#include "InsertionSort.h"

InsertionSortOption::InsertionSortOption()
    : window(VideoMode(800, 600), "Insertion Sort"),
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

void InsertionSortOption::run() {
    handleInput();
    insertionSort();
}

void InsertionSortOption::handleInput() {
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

void InsertionSortOption::drawArray(const vector<int>& array, int insert) {
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

        if (static_cast<int>(i) == insert) {
            numberText.setFillColor(Color(240,38,110));
        }

        numberText.setPosition(xPos, yPos);
        window.draw(numberText);
    }

    window.display();
}

void InsertionSortOption::insertionSort() {
    for (size_t i = 0; i < numbers.size(); ++i) {
        int key = numbers[i];
        size_t j = i - 1;
        while (j < numbers.size() && numbers[j] > key) {
            drawArray(numbers, j+1);
            this_thread::sleep_for(chrono::milliseconds(200));
            numbers[j+1] = numbers[j];
            j--;
        }
        numbers[j+1] = key;
        drawArray(numbers, j+1);
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    drawArray(numbers, -1);
    this_thread::sleep_for(chrono::seconds(2));
}