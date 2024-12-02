#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using namespace sf;

class LinearSearchOption {
public:
    LinearSearchOption();
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

int linearSearch(const vector<int>& arr, int target);

#endif // LINEARSEARCH_H
