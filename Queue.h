//
// Created by bande on 01/12/2024.
//
#ifndef QUEUES_H
#define QUEUES_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>

using namespace std;
using namespace sf;

class QueueOption {
    private:
        void handleInput();
        void drawQueue();
    public:
        QueueOption();
        void run();
        void enqueueVal(int value);
        void dequeueVal();
        bool isEmpty();
        RenderWindow window;
        Font font;
        Text text;
        Text userInput;
        queue<int> fila;
        string input;
};



#endif //QUEUES_H