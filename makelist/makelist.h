#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <cstddef>

// Define a template class for a singly linked list
template <typename Item_Type>
class Single_Linked_List {
private:
    // Define a nested struct for a node in the linked list
    struct Node {
        Item_Type data;   // Data stored in the node
        Node* next;       // Pointer to the next node

        // Constructor for creating a node with data and optional next node
        Node(const Item_Type& item, Node* next_node = nullptr)
            : data(item), next(next_node) {}
    };

    Node* head;           // Pointer to the first (head) node
    Node* tail;           // Pointer to the last (tail) node
    size_t num_items;     // Number of items in the linked list

public:
    // Constructor to initialize an empty linked list
    Single_Linked_List();

    // Destructor to clean up memory when the linked list is destroyed
    ~Single_Linked_List();

    // Function to insert an item at the front (head) of the linked list
    void push_front(const Item_Type& item);

    // Function to insert an item at the back (tail) of the linked list
    void push_back(const Item_Type& item);

    // Function to remove the first item (head) from the linked list
    void pop_front();

    // Function to remove the last item (tail) from the linked list
    void pop_back();

    // Function to access the data of the first item (head) in the linked list
    Item_Type& front();

    // Function to access the data of the first item (head) in the linked list (const version)
    const Item_Type& front() const;

    // Function to access the data of the last item (tail) in the linked list
    Item_Type& back();

    // Function to access the data of the last item (tail) in the linked list (const version)
    const Item_Type& back() const;

    // Function to check if the linked list is empty
    bool empty() const;

    // Function to insert an item at a specific index in the linked list
    void insert(size_t index, const Item_Type& item);

    // Function to remove an item at a specific index in the linked list
    bool remove(size_t index);

    // Function to find the index of the first occurrence of a specific item in the linked list
    size_t find(const Item_Type& item) const;

    // Function to get the number of items in the linked list
    size_t size() const;

    // Function to clear the linked list and release memory
    void clear();

    // Nested Iterator class to iterate over the linked list
    class Iterator {
    public:
        // Constructor to initialize the iterator with a node
        Iterator(Node* node);

        // Overloaded pre-increment operator to move to the next node
        Iterator& operator++();

        // Overloaded inequality operator to check if two iterators are not equal
        bool operator!=(const Iterator& other) const;

        // Overloaded dereference operator to access the data of the current node
        Item_Type& operator*();

    private:
        Node* current;  // Pointer to the current node
    };

    // Function to get an iterator pointing to the beginning of the linked list
    Iterator begin();

    // Function to get an iterator pointing to the end of the linked list
    Iterator end();
};

#endif // SINGLE_LINKED_LIST_H