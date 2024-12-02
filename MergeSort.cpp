#include "MergeSort.h"

MergeSortOption::MergeSortOption()
    : window(VideoMode(800, 600), "Merge Sort"),
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

void MergeSortOption::run() {
    handleInput();
    if (!numbers.empty()) {
        mergeSort(0, numbers.size() - 1);
    }
}

void MergeSortOption::handleInput() {
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
                } else if (event.text.unicode == '\r') {
                    istringstream iss(inputText);
                    int num;
                    while (iss >> num && numbers.size() < 10) {
                        numbers.push_back(num);
                    }
                    isEnteringArray = false;
                    return;
                } else if (event.text.unicode < 128 && inputText.size() < 100) {
                    inputText += static_cast<char>(event.text.unicode);
                }
            }
        }
        userInput.setString(inputText);
        window.clear(Color(20, 20, 30));
        window.draw(prompt);
        window.draw(userInput);
        window.display();
    }
}

void MergeSortOption::drawArray(const vector<int>& array, int left, int right, int mid) {
    window.clear(Color(20, 20, 30));

    float spacing = static_cast<float>(windowWidth) / array.size();
    for (size_t i = 0; i < array.size(); ++i) {
        Text numberText;
        numberText.setFont(font);
        numberText.setString(to_string(array[i]));
        numberText.setCharacterSize(30);
        numberText.setFillColor(Color::White);

        float xPos = i * spacing + (spacing / 2) - (numberText.getLocalBounds().width / 2);
        float yPos = windowHeight / 2 - numberText.getLocalBounds().height / 2;

        if (i >= static_cast<size_t>(left) && i <= static_cast<size_t>(mid)) {
            numberText.setFillColor(Color(240, 38, 110));
        } else if (i > static_cast<size_t>(mid) && i <= static_cast<size_t>(right)) {
            numberText.setFillColor(Color(38, 155, 240));
        }
        numberText.setPosition(xPos, yPos);
        window.draw(numberText);
    }
    window.display();
}

void MergeSortOption::merge(int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArray(n1), rightArray(n2);

    for (int i = 0; i < n1; i++) {
        leftArray[i] = numbers[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArray[i] = numbers[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            numbers[k] = leftArray[i];
            i++;
        } else {
            numbers[k] = rightArray[j];
            j++;
        }
        k++;
        drawArray(numbers, left, right, mid);
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    while (i < n1) {
        numbers[k] = leftArray[i];
        i++;
        k++;
        drawArray(numbers, left, right, mid);
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    while (j < n2) {
        numbers[k] = rightArray[j];
        j++;
        k++;
        drawArray(numbers, left, right, mid);
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

void MergeSortOption::mergeSort(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        drawArray(numbers, left, right, mid);
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}