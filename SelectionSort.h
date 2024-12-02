//
// Created by bande on 28/11/2024.
//
#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>

using namespace std;
using namespace sf;

class SelectionSortOption {
public:
    SelectionSortOption();
    void run();

private:
    RenderWindow window;
    Font font;
    Text prompt;
    Text userInput;
    vector<int> numbers;
    int windowWidth, windowHeight;
    bool isEnteringArray;

    void handleInput();
    void selectionSort();
    void drawArray(const vector<int> &array, int minIndex);
};

#endif //SELECTIONSORT_H