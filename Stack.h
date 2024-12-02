//
// Created by bande on 01/12/2024.
//
#ifndef STACK_H
#define STACK_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>

using namespace std;
using namespace sf;


class StackOption{
    private:
        void handleInput();
        void drawStack();

    public:
        StackOption();
        void run();
        void push(int value);
        void pop();
        bool isEmpty();
        RenderWindow window;
        Font font;
        Text text;
        Text userInput;
        stack<int> pila;
        string input;
};
#endif //STACK_H
