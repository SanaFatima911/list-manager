#include <iostream>
#include <string>

using namespace std;

class List {
private:
    struct Node {
        string data;
        Node* next;
    };
    Node* head;
    int size;

public:
    List() : head(0), size(0) {}

    ~List() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int push(const string& value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = 0;
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        return ++size;  // Increment size and return it
    }

    bool erase(int index) {
          if (index <= 0 || index > size) {
        std::cout << "Error: Index out of range" << std::endl;
        return false;
    }
    if (head == 0) {
        std::cout << "Error: List is empty" << std::endl;
        return false;
    }
        if (index <= 0 || index > size) return false;  // Adjust condition for 1-based index
        Node* temp = head;
        if (index == 1) {
            head = head->next;
            delete temp;
        } else {
            Node* prev = 0;
            for (int i = 1; temp != 0 && i < index; i++) {
                prev = temp;
                temp = temp->next;
            }
            if (temp) {
                prev->next = temp->next;
                delete temp;
                 cout << "Item removed successfully!" << endl;
            }
        }
        size--;
        return true;
    }

    bool remove(const string& value) {
        if (head == 0) {
        std::cout << "Error: List is empty" << std::endl;
        return false;
    }
    Node* temp = head;
    while (temp != 0 && temp->data != value) {
        temp = temp->next;
    }
    if (temp == 0) {
        std::cout << "Error: Value not found" << std::endl;
        return false;
    }
        
        Node* prev = 0;

        while (temp && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp) return false;

        if (!prev) {
            head = head->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
        size--;
        cout << "Item removed successfully!" << endl;
        return true;
    }

    bool empty() const {
        return head == 0;
    }

    void print() const {
        Node* current = head;
        int index = 1;  // Start index from 1
        while (current) {
            cout << index << ": " << current->data << endl;
            current = current->next;
            index++;
        }
    }

    int getSize() const {
        return size;
    }
};

