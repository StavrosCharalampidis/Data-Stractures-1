#include <iostream>
#include <vector>

// Singleton pattern
class Singleton {
private:
    Singleton() {}
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
};

// Factory Method pattern
class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a square." << std::endl;
    }
};

class ShapeFactory {
public:
    virtual Shape* createShape() = 0;
};

class CircleFactory : public ShapeFactory {
public:
    Shape* createShape() override {
        return new Circle();
    }
};

class SquareFactory : public ShapeFactory {
public:
    Shape* createShape() override {
        return new Square();
    }
};

// Observer pattern
class Observer {
public:
    virtual void update() = 0;
};

class Subject {
private:
    std::vector<Observer*> observers;
public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update();
        }
    }
};

class ConcreteObserver : public Observer {
public:
    void update() override {
        std::cout << "Subject state changed, updating observer." << std::endl;
    }
};

// Strategy pattern
class SortStrategy {
public:
    virtual void sort(std::vector<int>& data) = 0;
};

class QuickSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) override {
        quicksort(data, 0, data.size() - 1);
    }

private:
    void quicksort(std::vector<int>& data, int low, int high) {
        if (low < high) {
            int partitionIndex = partition(data, low, high);
            quicksort(data, low, partitionIndex - 1);
            quicksort(data, partitionIndex + 1, high);
        }
    }

    int partition(std::vector<int>& data, int low, int high) {
        int pivot = data[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; ++j) {
            if (data[j] < pivot) {
                ++i;
                std::swap(data[i], data[j]);
            }
        }

        std::swap(data[i + 1], data[high]);
        return i + 1;
    }
};


class Context {
private:
    SortStrategy* strategy;
public:
    Context(SortStrategy* strategy) : strategy(strategy) {}

    void setStrategy(SortStrategy* newStrategy) {
        strategy = newStrategy;
    }

    void performSort(std::vector<int>& data) {
        strategy->sort(data);
    }
};

int main() {
    // Singleton Pattern
    Singleton& singletonInstance = Singleton::getInstance();

    // Factory Method Pattern
    ShapeFactory* circleFactory = new CircleFactory();
    ShapeFactory* squareFactory = new SquareFactory();

    Shape* circle = circleFactory->createShape();
    Shape* square = squareFactory->createShape();

    // Observer Pattern
    ConcreteObserver observer;
    Subject subject;
    subject.addObserver(&observer);

    // Strategy Pattern
    Context context(new QuickSort);
    std::vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    // Demonstrate the patterns
    std::cout << "Singleton Pattern" << std::endl;
    // Use the singletonInstance as needed

    std::cout << "\nFactory Method Pattern" << std::endl;
    circle->draw();
    square->draw();

    std::cout << "\nObserver Pattern" << std::endl;
    subject.notifyObservers();

    std::cout << "\nStrategy Pattern" << std::endl;
    context.performSort(data);
    for (int i = 0; i < 11; i++) {
        std::cout << " " << data[i];
    }
    std::cout << "\n" << std::endl;

    // Cleanup
    delete circleFactory;
    delete squareFactory;
    delete circle;
    delete square;
    return 0;
}
