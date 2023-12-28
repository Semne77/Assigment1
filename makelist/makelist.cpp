#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <limits>
#include "makelist.h" // Assuming "makelist.h" contains the declaration of Single_Linked_List class.

// Implementation of member functions

// Constructor for Single_Linked_List class
template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor for Single_Linked_List class
template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    clear();
}

// Push an item to the front of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    // Implementation here
    Node* new_node = new Node(item, head);
    head = new_node;
    if (!tail) {
        tail = new_node;
    }
    num_items++;
}

// Push an item to the back of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    // Implementation here
    Node* new_node = new Node(item, nullptr);
    if (!head) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    num_items++;
}

// Pop an item from the front of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    // Implementation here
    if (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
        num_items--;
        if (!head) {
            tail = nullptr;
        }
    }
}

// Pop an item from the back of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    // Implementation here
    if (head) {
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            num_items = 0;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
            num_items--;
        }
    }
}

// Get and return the front element of the list
template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::front() {
    if (head) {
        return head->data;
    }
    throw std::logic_error("List is empty.");
}

// Get and return the front element of the list (const version)
template <typename Item_Type>
const Item_Type& Single_Linked_List<Item_Type>::front() const {
    if (head) {
        return head->data;
    }
    throw std::logic_error("List is empty.");
}

// Get and return the back element of the list
template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::back() {
    if (tail) {
        return tail->data;
    }
    throw std::logic_error("List is empty.");
}

// Get and return the back element of the list (const version)
template <typename Item_Type>
const Item_Type& Single_Linked_List<Item_Type>::back() const {
    if (tail) {
        return tail->data;
    }
    throw std::logic_error("List is empty.");
}

// Check if the list is empty
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return num_items == 0;
}

// Insert an item at a specified index
template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    // Implementation here
    if (index < 0 || index > num_items) {
        throw std::out_of_range("Invalid index.");
    }
    if (index == 0) {
        push_front(item);
    } else if (index == num_items) {
        push_back(item);
    } else {
        Node* current = head;
        for (size_t i = 1; i < index; i++) {
            current = current->next;
        }
        Node* new_node = new Node(item, current->next);
        current->next = new_node;
        num_items++;
    }
}

// Remove an item at a specified index
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    // Implementation here
    if (index < 0 || index >= num_items || !head) {
        return false;
    }
    if (index == 0) {
        pop_front();
    } else {
        Node* current = head;
        for (size_t i = 1; i < index; i++) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        num_items--;
    }
    return true;
}

// Find the position of an item in the list
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    // Implementation here
    Node* current = head;
    size_t pos = 0;
    while (current) {
        if (current->data == item) {
            return pos;
        }
        current = current->next;
        pos++;
    }
    return num_items; // Item not found
}

// Get and return the size of the list
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::size() const {
    return num_items;
}

// Clear the entire list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::clear() {
    while (head) {
        pop_front();
    }
}

// Return an iterator pointing to the beginning of the list
template <typename Item_Type>
typename Single_Linked_List<Item_Type>::Iterator Single_Linked_List<Item_Type>::begin() {
    return Iterator(head);
}

// Return an iterator pointing to the end of the list
template <typename Item_Type>
typename Single_Linked_List<Item_Type>::Iterator Single_Linked_List<Item_Type>::end() {
    return Iterator(nullptr);
}

// Implementation of Iterator member functions

// Constructor for Iterator class
template <typename Item_Type>
Single_Linked_List<Item_Type>::Iterator::Iterator(Node* node) : current(node) {}

// Increment operator for the iterator
template <typename Item_Type>
typename Single_Linked_List<Item_Type>::Iterator& Single_Linked_List<Item_Type>::Iterator::operator++() {
    if (current) {
        current = current->next;
    }
    return *this;
}

// Inequality operator for comparing iterators
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}

// Dereference operator for the iterator
template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::Iterator::operator*() {
    if (current) {
        return current->data;
    }
    throw std::logic_error("Iterator is at end.");
}


// Main function

int main() {
    Single_Linked_List<std::string> my_list; // Create a singly linked list of strings

    while (true) {
        // Display the menu options
        std::cout << "Single Linked List Menu:\n";
        std::cout << "1. Push Front\n";
        std::cout << "2. Push Back\n";
        std::cout << "3. Pop Front\n";
        std::cout << "4. Pop Back\n";
        std::cout << "5. Front\n";
        std::cout << "6. Back\n";
        std::cout << "7. Is Empty?\n";
        std::cout << "8. Insert\n";
        std::cout << "9. Remove\n";
        std::cout << "10. Find\n";
        std::cout << "11. Size\n";
        std::cout << "12. Clear\n";
        std::cout << "13. Print Full List\n";
        std::cout << "14. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        // Read the user's choice
        if (!(std::cin >> choice)) {
            // Handle invalid input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice. Please try again.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                // Push an item to the front of the list
                std::string item; // Use std::string for input
                std::cout << "Enter item to push front: ";
                std::cin >> item;
                my_list.push_front(item);
                break;
            }
            case 2: {
                // Push an item to the back of the list
                std::string item; // Use std::string for input
                std::cout << "Enter item to push back: ";
                std::cin >> item;
                my_list.push_back(item);
                break;
            }
            case 3:
                // Pop an item from the front of the list
                my_list.pop_front();
                break;
            case 4:
                // Pop an item from the back of the list
                my_list.pop_back();
                break;
            case 5:
                // Get and print the front element
                try {
                    std::cout << "Front: " << my_list.front() << std::endl;
                } catch (const std::logic_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 6:
                // Get and print the back element
                try {
                    std::cout << "Back: " << my_list.back() << std::endl;
                } catch (const std::logic_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 7:
                // Check if the list is empty
                std::cout << "Is Empty: " << (my_list.empty() ? "Yes" : "No") << std::endl;
                break;
            case 8: {
                // Insert an item at a specified index
                size_t index;
                std::string item; // Use std::string for input
                std::cout << "Enter index to insert at: ";
                std::cin >> index;
                std::cout << "Enter item to insert: ";
                std::cin >> item;
                try {
                    my_list.insert(index, item);
                } catch (const std::out_of_range& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 9: {
                // Remove an item at a specified index
                size_t index;
                std::cout << "Enter index to remove: ";
                std::cin >> index;
                bool removed = my_list.remove(index);
                if (removed) {
                    std::cout << "Item removed successfully.\n";
                } else {
                    std::cout << "Invalid index or list is empty.\n";
                }
                break;
            }
            case 10: {
                // Find the position of an item in the list
                std::string item; // Use std::string for input
                std::cout << "Enter item to find: ";
                std::cin >> item;
                size_t pos = my_list.find(item);
                if (pos != my_list.size()) {
                    std::cout << "Item found at position " << pos << std::endl;
                } else {
                    std::cout << "Item not found in the list.\n";
                }
                break;
            }
            case 11:
                // Get and print the size of the list
                std::cout << "Size: " << my_list.size() << std::endl;
                break;
            case 12:
                // Clear the entire list
                my_list.clear();
                std::cout << "List cleared.\n";
                break;
            case 13:
                // Print the full list with a comma between items
                std::cout << "Full List: ";
                {
                    bool first = true; // Flag to track the first item
                    for (Single_Linked_List<std::string>::Iterator it = my_list.begin(); it != my_list.end(); ++it) {
                        if (!first) {
                            std::cout << ", "; // Add a comma if it's not the first item
                        } else {
                            first = false; // Set the flag to false after the first item
                        }
                        std::cout << *it;
                    }
                }
                std::cout << std::endl;
                break;
            case 14:
                // Exit the program
                std::cout << "Exiting program.\n";
                return 0;
            default:
                // Handle invalid choice
                std::cout << "Invalid choice. Please try again.\n";
        }
        // Clear input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}