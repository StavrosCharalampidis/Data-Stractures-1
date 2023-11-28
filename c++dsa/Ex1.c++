#include <iostream>
#include <string>

template <typename T>
class SortStrategy {
public:
    virtual void sort(LinkedList<T>& list) = 0;
    virtual ~SortStrategy() {}
};

template <typename T>
class AscendingSortStrategy : public SortStrategy<T> {
public:
    void sort(LinkedList<T>& list) override {
        // Implement ascending order sorting logic
        // (e.g., using bubble sort for simplicity)
        // This logic can be customized based on the sorting algorithm you prefer.
        bool swapped;
        Node<T>* ptr1;
        Node<T>* lptr = nullptr;

        if (list.getHead() == nullptr)
            return;

        do {
            swapped = false;
            ptr1 = list.getHead();

            while (ptr1->getNext() != lptr) {
                if (ptr1->getData() > ptr1->getNext()->getData()) {
                    list.swapNodes(ptr1, ptr1->getNext());
                    swapped = true;
                }
                ptr1 = ptr1->getNext();
            }
            lptr = ptr1;
        } while (swapped);
    }
};

template <typename T>
class DescendingSortStrategy : public SortStrategy<T> {
public:
    void sort(LinkedList<T>& list) override {
        // Implement descending order sorting logic
        // (e.g., using bubble sort for simplicity)
        bool swapped;
        Node<T>* ptr1;
        Node<T>* lptr = nullptr;

        if (list.getHead() == nullptr)
            return;

        do {
            swapped = false;
            ptr1 = list.getHead();

            while (ptr1->getNext() != lptr) {
                if (ptr1->getData() < ptr1->getNext()->getData()) {
                    list.swapNodes(ptr1, ptr1->getNext());
                    swapped = true;
                }
                ptr1 = ptr1->getNext();
            }
            lptr = ptr1;
        } while (swapped);
    }
};

template <typename T>
class ListObserver {
public:
    virtual void onListModified(const LinkedList<T>& list) = 0;
    virtual ~ListObserver() {}
};
//? ^^


template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    SortStrategy<T>* sortStrategy;
    std::vector<ListObserver<T>*> observers;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}


    void setSortStrategy(SortStrategy<T>* strategy) {
        sortStrategy = strategy;
    }

    // Attach an observer
    void attachObserver(ListObserver<T>* observer) {
        observers.push_back(observer);
    }

    // Notify observers about list modifications
    void notifyObservers() const {
        for (auto observer : observers) {
            observer->onListModified(*this);
        }
    }


    // Function to add a node to the list
    void addNode(const T& data, const std::string& position) {
        Node<T>* newNode = new Node<T>(data);

        if (position == "head") {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
            if (tail == nullptr) {
                tail = newNode;
            }
        } else if (position == "tail") {
            newNode->prev = tail;
            if (tail != nullptr) {
                tail->next = newNode;
            }
            tail = newNode;
            if (head == nullptr) {
                head = newNode;
            }
        } else {
            std::cerr << "Invalid position. Use 'head' or 'tail'.\n";
            delete newNode;
        }
    }

    // Function to add a node to a descending order sorted list
    void addDescending(const T& data) {
        Node<T>* newNode = new Node<T>(data);

        if (head == nullptr || data > head->data) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
            if (tail == nullptr) {
                tail = newNode;
            }
        } else {
            Node<T>* current = head;
            while (current->next != nullptr && data < current->next->data) {
                current = current->next;
            }

            newNode->next = current->next;
            newNode->prev = current;

            if (current->next != nullptr) {
                current->next->prev = newNode;
            }

            current->next = newNode;

            if (newNode->next == nullptr) {
                tail = newNode;
            }
        }
    }

    // Function to display the list
    void displayList() const {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Function to count the number of elements in the list
    int countList() const {
        int count = 0;
        Node<T>* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Function to delete a node with a specific value
    void deleteNode(const T& value) {
        Node<T>* current = head;
        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        if (current == nullptr) {
            std::cerr << "Value not found in the list.\n";
            return;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }

        delete current;
    }

    // Function to delete the first node
    void deleteFirst() {
        if (head == nullptr) {
            std::cerr << "List is empty.\n";
            return;
        }

        Node<T>* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
    }

    // Function to append two sorted lists
    LinkedList<T> appendLists(const LinkedList<T>& list1, const LinkedList<T>& list2) const {
        LinkedList<T> result;

        Node<T>* current1 = list1.head;
        Node<T>* current2 = list2.head;

        while (current1 != nullptr && current2 != nullptr) {
            if (current1->data > current2->data) {
                result.addNode(current1->data, "tail");
                current1 = current1->next;
            } else {
                result.addNode(current2->data, "tail");
                current2 = current2->next;
            }
        }

        while (current1 != nullptr) {
            result.addNode(current1->data, "tail");
            current1 = current1->next;
        }

        while (current2 != nullptr) {
            result.addNode(current2->data, "tail");
            current2 = current2->next;
        }

        return result;
    }

    // Function to swap the first and last elements in a single linked list
    void swapElements1() {
        if (head == nullptr || head->next == nullptr) {
            std::cerr << "List has less than two elements.\n";
            return;
        }

        Node<T>* first = head;
        Node<T>* last = tail;

        head = last;
        last->next = first->next;
        last->prev = nullptr;

        first->next = nullptr;
        first->prev = tail;

        if (last->next != nullptr) {
            last->next->prev = first;
        }

        tail = first;
    }

    // Function to swap the first and last elements in a double linked list
    void swapElements2() {
        if (head == nullptr || head->next == nullptr) {
            std::cerr << "List has less than two elements.\n";
            return;
        }

        Node<T>* first = head;
        Node<T>* last = tail;

        head = last;
        last->next = first->next;
        last->prev = nullptr;

        first->next = nullptr;
        first->prev = tail;

        if (last->next != nullptr) {
            last->next->prev = first;
        }

        tail = first;
    }

    // Function to display the list in reverse order
    void ReversedisplayList() const {
        Node<T>* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList<int> singleList;
    LinkedList<int> doubleList;

    // Add nodes to single linked list
    singleList.addNode(5, "head");
    singleList.addNode(10, "tail");
    singleList.addNode(7, "tail");
    
    // Display single linked list
    std::cout << "Single Linked List: ";
    singleList.displayList();
    

    // Create sorting strategies
    SortStrategy<int>* ascendingSortStrategy = new AscendingSortStrategy<int>();
    SortStrategy<int>* descendingSortStrategy = new DescendingSortStrategy<int>();

    // Set sorting strategy for lists
    singleList.setSortStrategy(ascendingSortStrategy);
    //doubleList.setSortStrategy(descendingSortStrategy);
    std::cout << "sort dp Double Linked List: ";
    singleList.displayList();

    // Add nodes to double linked list
    doubleList.addNode(3, "head");
    doubleList.addNode(8, "tail");
    doubleList.addNode(12, "tail");

    // Display double linked list
    std::cout << "Double Linked List: ";
    doubleList.displayList();

    // Add nodes to single linked list in descending order
    singleList.addDescending(15);
    singleList.addDescending(2);

    // Display single linked list
    std::cout << "Single Linked List (Descending): ";
    singleList.displayList();

    // Count nodes in double linked list
    std::cout << "Number of elements in Double Linked List: " << doubleList.countList() << std::endl;

    // Delete node with value 10 from single linked list
    singleList.deleteNode(10);
    std::cout << "Single Linked List after deleting node with value 10: ";
    singleList.displayList();

    // Delete first node from double linked list
    doubleList.deleteFirst();
    std::cout << "Double Linked List after deleting the first node: ";
    doubleList.displayList();

    // Append two sorted lists
    LinkedList<int> appendedList = singleList.appendLists(singleList, doubleList);
    std::cout << "Appended List: ";
    appendedList.displayList();

    // Swap first and last elements in single linked list
    //singleList.swapElements1();
    std::cout << "Single Linked List after swapping first and last elements: ";
    singleList.displayList();

    // Swap first and last elements in double linked list
    //doubleList.swapElements2();
    std::cout << "Double Linked List after swapping first and last elements: ";
    doubleList.displayList();

    // Display double linked list in reverse order
    std::cout << "Double Linked List in Reverse Order: ";
    doubleList.ReversedisplayList();

    return 0;
}
