#include <iostream>
#include <string>
#include "list.h"

using namespace std;

// Function to add an item to the list
void add_item(List& items) {
    string item;
    cout << "Enter item to add: ";
    cin >> item;
    items.push(item);
    cout << "Item added successfully!" << endl;
}

// Function to remove an item from the list by index
void remove_item_by_index(List& items) {
    int index;
    cout << "Enter index to remove: ";
    cin >> index;
    items.erase(index);
   
}

// Function to remove an item from the list by value
void remove_item_by_value(List& items) {
    string value;
    cout << "Enter value to remove: ";
    cin >> value;
    items.remove(value);
    
}

// Function to display all items in the list
void display_items(const List& items) {
    if (items.empty()) {
        cout << "List is empty!" << endl;
    } else {
        items.print();
    }
}

int main() {
    List items;
    int choice;
    while (true) {
        cout << "1. Add item" << endl;
        cout << "2. Remove item by index" << endl;
        cout << "3. Remove item by value" << endl;
        cout << "4. Display items" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                add_item(items);
                break;
            case 2:
                remove_item_by_index(items);
                break;
            case 3:
                remove_item_by_value(items);
                break;
            case 4:
                display_items(items);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

