#include <iostream>
using namespace std;

class IntNode;

typedef IntNode* IntNodePtr;

class IntNode
{
    private:
        int data;
        IntNodePtr link;

    public:
        IntNode(int theData, IntNodePtr theLink)
        {
            data = theData;
            link = theLink;
        }

        int getData() const
        {
            return data;
        }

        void setData(int theData)
        {
            data = theData;
        }

        IntNodePtr getLink() const
        {
            return link;
        }

        void setLink(IntNodePtr theLink)
        {
            link = theLink;
        }
};

class stack
{
    private:
        IntNodePtr top;

    public:
        stack();
        //~stack();

        bool empty() const
        {
            return (top == nullptr);
        }

        bool full() const
        {
            return false;
        }

        void push(int inData);
        int pop();
};

stack::stack()
{
    top = nullptr;
}

void stack::push(int inData)
{
    if(!full())
    {
        IntNodePtr temp = new IntNode(inData, top);
        top = temp;
    }
    else
    {
        cout << "Cannot push onto a full stack" << endl;
    }
}

int stack::pop()
{
    int value = 0;

    if(empty())
    {
        cout << "cannot pop from an empty stack" << endl;
    }
    else
    {
        value = top -> getData();
        IntNodePtr temp = top;
        top = top -> getLink();
        delete temp;
    }

    return value;
}

int main()
{
    stack st;
    st.push(23);
    st.push(67);

    int item = st.pop();
    cout << item << " was just popped off the stack" << endl;

    item = st.pop();
    cout << item << " was just popped off the stack" << endl;


    return 0;
}























