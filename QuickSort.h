//
// Created by bande on 30/11/2024.
//
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace sf;

class QuickSortOption{
public:
    QuickSortOption();
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
    void drawArray(const vector<int>& array, int pivot);
    int pivote(vector<int>& array, int left, int right);
    void quickSort(vector<int>& array, int left, int right);
};



#endif //QUICKSORT_H