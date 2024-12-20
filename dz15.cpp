#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
	Node* prev;
    Node(int value, Node* next, Node * prev) : data(value), next(next), prev(prev) {}
};

class List {
    Node* head;
	Node* tail;
    int size = 0;
    int grow = 1;
    int upper = -1;
public:
    List()
    {
        head = tail = nullptr;
    }
    void AddToHead(int value)
    {
        Node* newNode = new Node(value, head, nullptr);
        if (IsEmpty())
        {
			head = tail = newNode;
        }
        head->prev = newNode;
		head = newNode;
        size+=grow;
        upper++;
    }
    void AddToTail(int value)
    {
        Node* newNode = new Node(value,nullptr, tail);
        if (head == nullptr)
        {
			head = tail = newNode;
		}
        else {
            tail->next = newNode;
			tail = newNode;
        }
        size+=grow;
        upper++;
    }
    void DeleteFromTail()
    {
        if (IsEmpty())return;
        if (head->next == nullptr)
        {
			delete head;
            head = tail = nullptr;
            return;
        }
        Node* beforeLast = tail->prev;
        beforeLast->next = nullptr;
		delete tail;
		tail = beforeLast;
        size--;
        upper--;
    }

    int GetSize()const
    {
        return size;
    }

    void SetSize(int siz, int gro = 1)
    {
        if (siz < size){
            FreeExtra();
            upper = siz - 1;
        }
        size = siz;
        grow = gro;
    }

    int GetUpperBound()
    {
        return upper;
    }

    Node* GetAt(int index)
    {
        int j = 0;
        for (Node* i = head; i != nullptr; i = i->next){
            if (j == index){
                return i;
            }
            ++j;
        }
        return nullptr;
    }

    bool SetAt(int index, int data)
    {
        if (index > size - 1) return false;
        int j = 0;
        for (Node* i = head; i != nullptr; i = i->next){
            if (j == index){
                i->data = data;
                return true;
            }
            ++j;
        }
    }

    void InsertAt(int data, int index)
    {
        int j = 0;
        for (Node* i = head; j < size; i = i->next){
            if (index == 0){
                AddToHead(data);
                return;
            }
            if (j == index){
                Node* newNode = new Node(data, i, i->prev);
                i->prev->next = newNode;
                i->prev = newNode;
                size++;
                upper++;
                return;
            }
            ++j;
        }
    }

    void RemoveAt(int index)
    {
        int j = 0;
        if (index > size - 1) return;
        for (Node* i = head; j < size; i = i->next){
            if (j == index){
                if (index == 0){
                    head = head->next;
                    head->prev = nullptr;
                    delete i;
                    size--;
                    upper--;
                    return;
                }
                if (index == size - 1){
                    tail = tail->prev;
                    tail->next = nullptr;
                    delete i;
                    size--;
                    upper--;
                    return;
                }
                if (i != nullptr){
                    i->prev->next = i->next;
                    i->next->prev = i->prev;
                    delete i;
                    size--;
                    upper--;
                    return;
                }
            }
            ++j;
        }
    }

    int* GetData(){
        int* arr = new int[size];
        int j = 0;
        for (Node* i = head; i != nullptr; i = i->next){
            arr[j] = i->data;
            ++j;
        }
        return arr;
    }

    int operator[](int index){
        if (index > size - 1) return 0;
        int j = 0;
        for (Node* i = head; i != nullptr; i = i->next){
            if (j == index){
                return i->data;
            }
            ++j;
        }
    }

    void FreeExtra(){
        int j = 0;
        for (Node* i = head; j < size; i = i->next){
            ++j;
            if (j > upper){
                if (i != nullptr){        
                    Node* temp = i;
                    i = i->next;
                    delete temp;
                }
                size--;
            }
        }
    }

    bool IsEmpty()const
    {
        return head == nullptr;
    }
    void Show()const
    {
        for (Node* i = head; i != nullptr; i = i->next)
        {
            cout << i->data << " ";
        }cout << "\n";
    }

    void Clear() { // Remove all
        FreeExtra();
        while (head != nullptr)
        {
			Node* temp = head;
			head = head->next;
			delete temp;
        }
		head = tail = nullptr;
        size = 0;
        upper = -1;
    }

    void Append(List& other){
        if (IsEmpty()){
            head = other.head;
            tail = other.tail;
            upper = other.upper;
            size = other.size;
        }
        else {
            tail->next = other.head;
            other.head->prev = tail;
            tail = other.tail;
            size += other.size;
            upper += other.upper;
        }
    }

    List& operator=(List& other){
        Clear();
        Append(other);
        return *this;
    }

    ~List()
    {
		Clear();
    }
};

int main()
{
    List list;
	list.AddToHead(10);
	list.AddToHead(10);
	list.AddToHead(10);
	list.AddToHead(10);
    list.Show();
	list.DeleteFromTail();
    list.AddToTail(77);
    list.AddToTail(75);
    list.AddToTail(73);
	list.Show();

}
