#include <iostream>
using namespace std;

class Stack
{
public:
    int Capacity;
    int Top;
    int *Array;
};
class Stack_Operations
{
public:
    Stack *stack;
    Stack_Operations()
    {
        stack = NULL;
    }
    void Creat_Stack(int cap)
    {
        stack = (Stack *)malloc(sizeof(Stack));
        stack->Top = -1;
        stack->Capacity = cap;
        stack->Array = (int *)malloc(sizeof(int) * cap);
    }
    int isFull()
    {
        if (stack->Top == stack->Capacity - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int isEmpty()
    {
        if (stack->Top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int push(int itm)
    {
        if (!isFull())
        {
            stack->Top = stack->Top + 1;
            stack->Array[stack->Top] = itm;
            return 1;
        }
        else
        {
            cout << "Stack is Full\n";
            return 0;
        }
    }
    int pop()
    {
        int itm;
        if (!isEmpty())
        {
            itm = stack->Array[stack->Top];
            stack->Top = stack->Top - 1;
            return itm;
        }
        return -1;
    }
};

int main()
{
    Stack_Operations Obj;
    bool Goto = true;
    int sel, size;
    system("CLS");
    system("color 05");
    cout << "Stack Size = ";
    cin >> size;
    Obj.Creat_Stack(size);
    while (Goto == true)
    {
        system("CLS");
        system("color 03");
        cout<<"\t\t\t\tTotal Size of Stack is "<<size<<" & "<< "Filled "<<Obj.stack->Top+1<<"\n\n\n";
        cout << "Press 1 for Push\n";
        cout << "Press 2 for Pop\n";
        cout << "Press 3 for Exit\n";
        cin >> sel;
        switch (sel)
        {
        case 1:
        {
            int val, cond;
            for (int i = 1; i <= size; i++)
            {
                cout << "Enter Number for Push " << i << endl;
                cin >> val;
                cond = Obj.push(val);
                if (!cond)
                {
                    break;
                }
            }
            system("PAUSE");
            break;
        }
        case 2:
        {
            int vl = Obj.pop();
            if (vl != -1)
            {
                cout << "POP Value is = " << vl << endl;
            }
            else
            {
                cout << "Stack is Empty\n";
            }
            system("PAUSE");
            break;
        }
        case 3:
        {
            Goto = false;
            break;
        }
        default:
        {
            cout << "Wrong Key ";
            system("PAUSE");
            break;
        }
        }
    }
}
