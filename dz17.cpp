#include <iostream>
#include <exception>
#include <type_traits>
using namespace std;
//1
class exepshon : public exception {
private:
    string message;
public:
    exepshon(const string& mes) : message(mes) {}

    const char* what() const noexcept override {
        cout << "OH NO" << endl;
        return message.c_str();
    }
};

class matrixIncompatible : public exepshon {
public:
    matrixIncompatible() : exepshon("Number of rows does not equal to the number of columns") {}
};

class ZeroDiv : public exepshon {
public:
    ZeroDiv() : exepshon("Zero Division Error") {}
};

class matrixBounds : public exepshon {
public:
    matrixBounds() : exepshon("Out of bounds Error") {}
};

class WrongType : public exepshon {
public: 
    WrongType() : exepshon("Matrix cannot have string or char values") {}
};

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
    int numElems = 0;
public:

    List(int s)
    {
        head = tail = nullptr;
        size = s;
    }

    void AddToHead(int value)
    {
        try {
            if (numElems == size) {
                throw exepshon("Overflow");
            }
            Node* newNode = new Node(value, head, nullptr);
            if (IsEmpty())
            {
                head = tail = newNode;
            }
            head->prev = newNode;
            head = newNode;
            numElems++;
        }
        catch (exepshon& ex) {
            cout << ex.what() << endl;
        }
    }

    void AddToTail(int value)
    {   try {
            if (numElems == size) {
                throw exepshon("Overflow");
            }
            Node* newNode = new Node(value,nullptr, tail);
            if (head == nullptr)
            {
                head = tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
            numElems++;
        }
        catch (exepshon& ex) {
            cout << ex.what() << endl;
        }
    }

    bool IsEmpty()const{
        return head == nullptr;
    }

    void Show()const {
        for (Node* i = head; i != nullptr; i = i->next)
        {
            cout << i->data << " ";
        }cout << "\n";
    }

    void Clear() {
        try {
            if (head == nullptr) {
                throw exepshon("List is empty");
            }
            while (head != nullptr)
            {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            head = tail = nullptr;
            numElems = 0;
        }
        catch (exepshon& ex) {
            cout << ex.what() << endl;
        }
    }

    void DeleteFromTail() {
        if (IsEmpty()) return;
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
        numElems--;
    }

    ~List()
    {
		Clear();
    }
};

//2
template <typename T> class Matrix {
public:
	T** arr;
	int x = 0;
	int y = 0;
public:
	Matrix(int rows, int columns) : x(rows), y(columns){
        checkType();
		arr = new T*[x];
		for (int i = 0; i < x; i++) {
			arr[i] = new T[y];
		}
	}
	Matrix() : Matrix(0,0){}
	Matrix(const Matrix& other) {
		x = other.x;
		y = other.y;

		arr = new T * [x];
		for (int i = 0; i < x; ++i) {
			arr[i] = new T[y];
			for (int j = 0; j < y; ++j) {
				arr[i][j] = other.arr[i][j];
			}
		}
	}
public:

	inline void Print()const {
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	} 

    inline void checkType() {
        try {
            if (is_same<T, char>::value || is_same<T, std::string>::value) {
                throw WrongType();   
            }
        }
        catch (WrongType& ex) {
            cout << ex.what() << endl;
        }
    }

    T* operator[](int row) {
        try {
            if (row < 0 || row >= x) {
                throw matrixBounds();
            }
            return arr[row];
        }
        catch(matrixBounds& ex) {
            cout << ex.what() << endl;
        }
    }

	Matrix& operator=(const Matrix& other) {
		if (this == &other) return *this;

		if (arr != nullptr) {
			for (int i = 0; i < x; ++i) {
				delete[] arr[i];
			}
			delete[] arr;
		}

		x = other.x;
		y = other.y;
		arr = new T * [x];
		for (int i = 0; i < x; ++i) {
			arr[i] = new T[y];
			for (int j = 0; j < y; ++j) {
				arr[i][j] = other.arr[i][j];
			}
		}

		return *this;
	}

	Matrix operator+(const Matrix& other) {
		try {
            if (other.x != this->x || other.y != this->y) {
			    throw matrixIncompatible();
            }
            Matrix m(x,y);
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    m.arr[i][j] = this->arr[i][j] + other.arr[i][j];
                }
            }
            return m;
        }
        catch (matrixIncompatible& ex) {
            cout << ex.what() << endl;
            return Matrix();
        }
	}

	Matrix operator-(const Matrix& other) {
        try {
            if (other.x != this->x || other.y != this->y) {
			    throw matrixIncompatible();
            }
            else {
                Matrix m(x, y);
                for (int i = 0; i < x; i++) {
                    for (int j = 0; j < y; j++) {
                        m.arr[i][j] = this->arr[i][j] - other.arr[i][j];
                    }
                }
                return m;
            }
        }
		catch (matrixIncompatible& ex) {
            cout << ex.what() << endl;
            return Matrix();
        }
	}

	Matrix operator*(const Matrix& other) {
        try {
            if (this->y != other.x) {
                throw matrixIncompatible();
            }
            else {
                Matrix m(this->x, other.y);
                for (int i = 0; i < m.x; i++) {
                    for (int j = 0; j < m.y; j++) {
                        T sum = T(0); 
                        for (int k = 0; k < this->y; k++) {
                            sum += (this->arr[i][k] * other.arr[k][j]);
                        }
                        m.arr[i][j] = sum;
                    }
                }
                return m;
            }
        }
        catch (matrixIncompatible& ex) {
            cout << ex.what() << endl;
            return Matrix();
        }
		
	}

	Matrix operator/(T num) {
        try {
            if (num == 0) {
                throw ZeroDiv();
            }
            Matrix m(x, y);
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    m.arr[i][j] = arr[i][j]/num;
                }
            }
            return m;
        }
        catch (ZeroDiv& ex) {
            cout << ex.what() << endl;
            return Matrix();
        }
	}

	~Matrix() {
		if (arr != nullptr) {
			for (int i = 0; i < x; i++) {
				delete[] arr[i];
			}
			delete[] arr;
		}
	}
};
 
int main() {
    Matrix<float> mat(2, 2);
    mat[0][0] = 2.2;
    mat.Print();
    Matrix<float> mat2(3,5);
    mat2[0][3] = 1.2;
    Matrix<float> mat3 = mat*mat2;

    // List list(5);
	// list.AddToHead(10);
	// list.AddToTail(5);
	// list.AddToHead(3);
    // list.AddToTail(4);
	// list.AddToHead(2);
    // list.DeleteFromTail();
    // list.AddToHead(2);
    // list.AddToHead(2);
    // list.Clear();
    // list.DeleteFromTail();
    // list.Clear();

    // list.Show();
}

