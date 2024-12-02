//
// Created by bande on 28/11/2024.
//

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;
using namespace sf;


class BinarySearchOption {
    public:
        BinarySearchOption();
        void run();

    private:
        RenderWindow window;
        Font font;
        Text displayText;
        string resultMessage;
        String userInput;
        std::vector<int> array;
        bool isEnteringArray;

        void handleInput(Event event);
        void draw();
    };

    int binarySearch(const vector<int>& arr, int target);




#endif //BINARYSEARCH_H
