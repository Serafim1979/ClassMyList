#include<iostream>
#include<cstdlib>
#include<ctime>

class List
{
private:
    class Node
    {
    public:
        int data;
        Node *pNext;

        Node(int data = 0, Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node *head;
public:
    List();
    ~List();

    void my_pop_front();
    void my_push_back(int);
    int get_size(){return Size;}
    void my_clear();
    int& operator[](const int index);
    void my_push_front(int);
    void my_insert(int , int);
    void my_remove(int);
    void my_remove_range_between(int, int);
    void my_pop_back();
    void display();

};

List::List()
{
    Size = 0;
    head = nullptr;
}

List::~List()
{
    my_clear();
}

// Adding items to the end of the list
void List::my_push_back(int data)
{
    if(head == nullptr)
    {
        head = new Node(data);
    }
    else
    {
        Node *current = this->head;

        while(current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node(data);
    }
    Size++;
}

// Adding items to the top of the list
void List::my_push_front(int data)
{
    head = new Node(data, head);
    Size++;
}

// Inserting an element at the specified position
void List::my_insert(int data, int index)
{
    if(index == 0)
    {
        my_push_front(data);
    }
    else
    {
        Node *prev = this->head;
        for(int i = 0; i < index - 1; i++)
        {
            prev = prev->pNext;
        }
        Node *newNode = new Node(data, prev->pNext);
        prev->pNext = newNode;
        Size++;
    }
}

// Deleting an item at the specified position
void List::my_remove(int index)
{
    if(index == 0)
    {
        my_pop_front();
    }
    else
    {
        Node *prev = this->head;
        for(int i = 0; i < index - 1; i++)
        {
            prev = prev->pNext;
        }
        Node *toDelete = prev->pNext;
        prev->pNext = toDelete->pNext;
        delete toDelete;
        Size--;
    }
}

// Deleting the last item in the list
void List::my_pop_back()
{
    my_remove(Size - 1);
}

// Deleting the last list item between two indexes
void List::my_remove_range_between(int start_index, int end_index)
{
    for(int i = start_index; i < end_index; i++)
    {
        my_remove(i);
    }
}

int& List::operator[](const int index)
{
    int cnt = 0;
    Node *current = this->head;
    while(current != nullptr)
    {
        if(cnt == index)
        {
            return current->data;
        }
        current = current->pNext;
        cnt++;
    }
}

// Output of list items
void List::display()
{
    Node *tmp = new Node;
    tmp = head;
    while(tmp != nullptr)
    {
        std::cout << tmp->data << " " ;
        tmp = tmp->pNext;
    }
}

// Deleting the first item in the list
void List::my_pop_front()
{
    Node *temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}

// Deleting all elements
void List::my_clear()
{
    while(Size)
    {
        my_pop_front();
    }
}

int main()
{
    List lst;
    std::srand(time(NULL));

    // Adding 10 random values to the list
    for(int i = 0; i < 10; i++)
    {
        int tmp = rand() % 10;
        lst.my_push_back(tmp);
    }
    lst.display();
    std::cout << std:: endl;
    std::cout << "Size = " << lst.get_size() << std::endl;
    std::cout << std::endl;

    // Testing my_push_back
    lst.my_push_back(3);
    lst.my_push_back(4);
    lst.my_push_back(5);
    lst.display();
    std::cout << std::endl;
    std::cout << "Size = " << lst.get_size() << std::endl;
    std::cout << std::endl;

    // Testing my_push_front
    lst.my_push_front(3);
    lst.my_push_front(4);
    lst.my_push_front(5);
    lst.display();
    std::cout << std::endl;
    std::cout << "Size = " << lst.get_size() << std::endl;
    std::cout << std::endl;

    // Testing my_insert
    lst.my_insert(111, 3);
    lst.my_insert(333, 5);
    lst.my_insert(777, 9);
    lst.display();
    std::cout << std::endl;
    std::cout << "Size = " << lst.get_size() << std::endl;
    std::cout << std::endl;

    // Testing my_pop_back
    lst.my_pop_back();
    lst.display();
    std::cout << std::endl;
    std::cout << "Size = " << lst.get_size() << std::endl;
    std::cout << std::endl;

    // Testing my_pop_front
    lst.my_pop_front();
    lst.display();
    std::cout << std::endl;
    std::cout << "Size = " << lst.get_size() << std::endl;
    std::cout << std::endl;

    // Testing my_remove
    lst.my_remove(2);
    lst.my_remove(3);
    lst.my_remove(6);
    lst.display();
    std::cout << std::endl;
    std::cout << "Size = " << lst.get_size() << std::endl;
    std::cout << std::endl;

    // Testing my_remove_range_between
    lst.my_remove_range_between(3, 7);
    lst.display();
    std::cout << std::endl;
    std::cout << "Size = " << lst.get_size() << std::endl;
    std::cout << std::endl;

    // All clear List
    lst.my_clear();
    lst.display();
    std::cout << "List clear" << std::endl;
    return 0;
}
