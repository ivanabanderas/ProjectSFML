#ifndef MERGESORT_H
#define MERGESORT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>

using namespace std;
using namespace sf;

class MergeSortOption {
    public:
        MergeSortOption();
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
        void drawArray(const vector<int>& array, int left, int right, int mid = -1);
        void merge(int left, int mid, int right);
        void mergeSort(int left, int right);
};
#endif
