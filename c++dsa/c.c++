#include <iostream>

// Node class for a single-linked list
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) : data(data), next(nullptr) {}
};

// Node class for a doubly-linked list
template <typename T>
class DoubleNode {
public:
    T data;
    DoubleNode* next;
    DoubleNode* prev;

    DoubleNode(T data) : data(data), next(nullptr), prev(nullptr) {}
};

// Singleton class for managing the list
template <typename T, template <typename> class NodeType>
class ListManager {
private:
    NodeType<T>* head;
    NodeType<T>* tail;

    ListManager() : head(nullptr), tail(nullptr) {}

public:
    static ListManager& getInstance() {
        static ListManager instance;
        return instance;
    }

    void addNodeSingle(T data, const std::string& position) {
        NodeType<T>* newNode = new NodeType<T>(data);

        if (position == "head") {
            newNode->next = head;
            head = newNode;
        } else if (position == "tail") {
            if (!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        } else {
            std::cout << "Invalid position specified." << std::endl;
        }
    }

    void addDescending(T data) {
        NodeType<T>* newNode = new NodeType<T>(data);

        if (!head || data > head->data) {
            newNode->next = head;
            head = newNode;
        } else {
            NodeType<T>* current = head;
            while (current->next && data < current->next->data) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void deleteNode(T data) {
        NodeType<T>* current = head;
        NodeType<T>* prev = nullptr;

        while (current && current->data != data) {
            prev = current;
            current = current->next;
        }

        if (!current) {
            std::cout << "Node with data " << data << " not found." << std::endl;
            return;
        }

        if (!prev) {
            // Node to be deleted is the head
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
    }

    void displayList() const {
        NodeType<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Add other list management functions here...
};

int main() {
    ListManager<int, Node> singleListManager = ListManager<int, Node>::getInstance();
     ListManager<int, Node> singleListManager1 = ListManager<int, Node>::getInstance();
    singleListManager.addDescending(3);
    singleListManager.addDescending(1);
    singleListManager.addDescending(2);
    std::cout << "Descending Single Linked List: ";
    singleListManager.displayList();

    singleListManager1.addDescending(3);
    singleListManager1.addDescending(100);
    singleListManager1.addDescending(2);

    std::cout << "Descending Single Linked List: ";
    singleListManager1.displayList();

    singleListManager.deleteNode(1);
    std::cout << "After deleting node with data 1: ";
    singleListManager.displayList();

    return 0;
}