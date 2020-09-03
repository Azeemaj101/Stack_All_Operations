#include <iostream>
using namespace std;

class Node
{
public:
    int Data;
    Node *Next;
};

class Stack_LinkList
{
public:
    Node *Stack;
    Stack_LinkList()
    {
        Stack = NULL;
    }

    void Push(int Data)
    {
        Node *NewNode;
        NewNode = (Node *)malloc(sizeof(Node));
        NewNode->Data = Data;
        if (Stack == NULL)
        {
            NewNode->Next = NULL;
        }
        else
        {
            NewNode->Next = Stack;
        }
        Stack = NewNode;
    }
    void Display()
    {
        if (Stack == NULL)
        {
            cout << "Stack is Empty\n";
        }

        Node *t;
        t = Stack;
        while (t != NULL)
        {
            cout << t->Data << " ";
            t = t->Next;
        }
    }
    void Peek()
    {
        if (Stack == NULL)
        {
            cout << "Stack is Empty\n";
        }
        else
        {
            cout << "Peek Value is = " << Stack->Data << "\n";
        }
    }
    int Pop()
    {
        Node *t;
        t = Stack;
        int itm;
        if (Stack == NULL)
        {
            // cout << "Stack is Empty\n";
            return -1;
        }
        else
        {
            itm = Stack->Data;
            Stack = Stack->Next;
            free(t);
            return itm;
        }
    }
    void Delete_Stack()
    {
        if (Stack == NULL)
        {
            cout << "Stack is Empty\n";
        }
        else
        {
            while (Stack != NULL)
            {
                Pop();
            }
        }
    }
};

int main()
{
    Stack_LinkList Obj;
    bool Goto = true;
    int sel, size, TS = 0;
    while (Goto == true)
    {
        system("CLS");
        system("color 03");
        cout << "\t\t\t\tTotal Size of Stack is Unlimited"
             << " & "
             << "Filled " << TS << "\n\n\n";
        cout << "Press 1 For Push\n";
        cout << "Press 2 For Pop\n";
        cout << "Press 3 For View All Stack\n";
        cout << "Press 4 For View Peek Value\n";
        cout << "Press 5 For Delete All Stack\n";
        cout << "Press 6 For Exit\n";
        cin >> sel;
        switch (sel)
        {
        case 1:
        {
            int val, cond;
            cout << "How Meny values do you want to push\n";
            cin >> size;
            TS = TS + size;
            for (int i = 1; i <= size; i++)
            {
                cout << "Enter Number for Push " << i << endl;
                cin >> val;
                Obj.Push(val);
            }
            system("PAUSE");
            break;
        }
        case 2:
        {
            int vl = Obj.Pop();
            if (vl != -1)
            {
                cout << "POP Value is = " << vl << endl;
                TS--;
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
            cout<<"Stack List is = ";
            Obj.Display();
            cout<<"\n";
            system("PAUSE");
            break;
        }
        case 4:
        {
            Obj.Peek();
            system("PAUSE");
            break;
        }
        case 5:
        {
            Obj.Delete_Stack();
            TS = 0;
            system("PAUSE");
            break;
        }
        case 6:
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