#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

template <typename T>
class SingleLinkedList {
private:
    Node<T>* head;

public:
    SingleLinkedList() : head(nullptr) {}

    void addNode(T data, const char* position) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = nullptr;

        if (position == nullptr || (*position != 'h' && *position != 't')) {
            std::cout << "Invalid position. Use 'head' or 'tail'." << std::endl;
            delete newNode;
            return;
        }

        if (head == nullptr) {
            head = newNode;
        } else {
            if (*position == 'h') {
                newNode->next = head;
                head = newNode;
            } else {
                Node<T>* current = head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }
    }

    void displayList() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    int countList() {
        int count = 0;
        Node<T>* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void deleteNode(T delVal) {
        Node<T>* temp = head;
        Node<T>* previous = nullptr;

        if (temp != nullptr && temp->data == delVal) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != delVal) {
            previous = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Value not found." << std::endl;
            return;
        }

        previous->next = temp->next;
        delete temp;
        std::cout << "Value " << delVal << " deleted." << std::endl;
    }

    void deleteFirst() {
        if (head == nullptr) {
            std::cout << "Linked List Empty, nothing to delete." << std::endl;
            return;
        }

        Node<T>* temp = head;
        head = head->next;
        std::cout << "Deleted: " << temp->data << std::endl;
        delete temp;
    }

    SingleLinkedList<T> appendLists(const SingleLinkedList<T>& list2) {
        SingleLinkedList<T> result;

        Node<T>* current = head;
        while (current != nullptr) {
            result.addNode(current->data, "tail");
            current = current->next;
        }

        current = list2.head;
        while (current != nullptr) {
            result.addNode(current->data, "tail");
            current = current->next;
        }

        return result;
    }

    ~SingleLinkedList() {
        Node<T>* current = head;
        Node<T>* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};

template <typename T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    void addNode(T data, const char* position) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (position == nullptr || (*position != 'h' && *position != 't')) {
            std::cout << "Invalid position. Use 'head' or 'tail'." << std::endl;
            delete newNode;
            return;
        }

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            if (*position == 'h') {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } else {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    void swapElements2() {
        if (head == nullptr || head->next == nullptr || head->data == tail->data) {
            return;
        }

        Node<T>** p = find(head, tail);
        Node<T>* Node1 = p[0];
        Node<T>* Node2 = p[1];

        if (Node1 == head) {
            head = Node2;
        } else if (Node2 == head) {
            head = Node1;
        }

        if (Node1 == tail) {
            tail = Node2;
        } else if (Node2 == tail) {
            tail = Node1;
        }

        Node<T>* temp;
        temp = Node1->next;
        Node1->next = Node2->next;
        Node2->next = temp;

        if (Node1->next != nullptr) {
            Node1->next->prev = Node1;
        }

        if (Node2->next != nullptr) {
            Node2->next->prev = Node2;
        }

        temp = Node1->prev;
        Node1->prev = Node2->prev;
        Node2->prev = temp;

        if (Node1->prev != nullptr) {
            Node1->prev->next = Node1;
        }

        if (Node2->prev != nullptr) {
            Node2->prev->next = Node2;
        }

        delete[] p;
    }

    void displayList() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void ReversedisplayList() {
        Node<T>* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }

    ~DoubleLinkedList() {
        Node<T>* current = head;
        Node<T>* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
    }

private:
    Node<T>** find(Node<T>* head, Node<T>* tail) {
        Node<T>* N1 = head;
        Node<T>* N2 = tail;

        Node<T>** result = new Node<T>*[2];
        result[0] = N1;
        result[1] = N2;
        return result;
    }
};

int main() {
    SingleLinkedList<int> singleLinkedList1;
    singleLinkedList1.addNode(6, "tail");
    singleLinkedList1.addNode(4, "head");
    singleLinkedList1.addNode(9, "tail");
    singleLinkedList1.addNode(2, "tail");
    singleLinkedList1.addNode(3, "tail");
    singleLinkedList1.addNode(55, "tail");

    std::cout << "singleLinkedList1: ";
    singleLinkedList1.displayList();
    std::cout << "Count: " << singleLinkedList1.countList() << std::endl;

    SingleLinkedList<int> singleLinkedList2;
    singleLinkedList2.addNode(45, "head");
    singleLinkedList2.addNode(38, "tail");
    singleLinkedList2.addNode(24, "tail");
    singleLinkedList2.addNode(12, "tail");
    singleLinkedList2.addNode(8, "tail");
    singleLinkedList2.addNode(61, "tail");

    std::cout << "singleLinkedList2: ";
    singleLinkedList2.displayList();
    std::cout << "Count: " << singleLinkedList2.countList() << std::endl;

    singleLinkedList1.deleteNode(55);
    singleLinkedList1.deleteFirst();
    std::cout << "singleLinkedList1 after deletion: ";
    singleLinkedList1.displayList();

    SingleLinkedList<int> result = singleLinkedList1.appendLists(singleLinkedList2);
    std::cout << "Appended List: ";
    result.displayList();

    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.addNode(2, "tail");
    doubleLinkedList.addNode(5, "tail");
    doubleLinkedList.addNode(3, "head");
    doubleLinkedList.addNode(10, "tail");

    std::cout << "doubleLinkedList: ";
    doubleLinkedList.displayList();
    std::cout << "Reversed Display: ";
    doubleLinkedList.ReversedisplayList();

    doubleLinkedList.swapElements2();
    std::cout << "After Swap: ";
    doubleLinkedList.displayList();

    return 0;
}
