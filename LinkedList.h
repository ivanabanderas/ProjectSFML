#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

struct Node {
    int data;
    Node* next;

    Node(int value); // Constructor del nodo
};

class LinkedListOption {
private:
    Node* head;
    RenderWindow window;
    Font font;
    Text text;
    vector<Text> nodeTexts;
    Text userInput;
    bool isEntering;
    bool isDeleting;

public:
    LinkedListOption();
    void insert(int value);
    void remove(int value);
    vector<int> toVector() const;
    void run();
    void handleInput();
    void draw();
};

#endif //LINKEDLIST_H
