#include <iostream>
#include <stdexcept>
using namespace std;

class Stack
{
private:
    int* arr;
    int size;
    int top;
public:
    Stack(int s)
    {
        if (s <= 0)
        {
            throw invalid_argument("Wrong stack size!");
        }
        size = s;
        top = -1;
        arr = new int[size];
    }

    void push(int value)
    {
        if (top == size - 1)
        {
            throw overflow_error("Stack is full!");
        }

        arr[++top] = value;
    }

    void pop()
    {
        if (top == -1)
        {
            throw underflow_error("Stack is empty!");
        }

        top--;
    }

    void show()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    try
    {
        Stack s(3);
        s.push(10);
        s.push(20);
        s.push(30);
        cout << "Stack: ";
        s.show();
        s.push(40);
    }
    catch (const exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }
}
