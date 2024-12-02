#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>

using namespace std;
using namespace sf;

class InsertionSortOption {
public:
    InsertionSortOption();
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
    void drawArray(const vector<int>& array, int insert);
    void insertionSort();

};

#endif
