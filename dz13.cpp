#include "iostream"
using namespace std;

template <typename T> class Matrix {
private:
	T** arr;
public:
	int x = 0;
	int y = 0;

	Matrix(int rows, int columns) : x(rows), y(columns){
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
	inline void InputData() {
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				cout << "Enter value" << "[" << i+1 << "][" << j+1 <<"]" << ": ";
				cin >> arr[i][j];
			}
		}
	}
	inline void InputRandom() {
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				arr[i][j] = T((rand() % 100) + ((rand() % 2000) / 1000.0));
			}
		}
	}
	inline void Print()const {
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
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

	inline T getDeterminant() {
		if (x != y) return NULL;
		if (x == 1) return arr[0][0];
		if (x == 2) {
			return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0]; // started to create an algo for math matrix division but it would take much more time
		}
		else {
			T res = T(0);
			for (int col = 0; col < x; ++col) {
				T** sub = new T * [x];
				for (int l = 0; l < x; l++) {
					sub[l] = new T[x];
				}
				for (int i = 1; i < x; ++i) {
					int subcol = 0;
					for (int j = 0; j < x; ++j) {
						if (j == col) continue;
						sub[i - 1][subcol++] = arr[i][j];
					}
				}
			int sign = (col % 2 == 0) ? 1 : -1;
			res += sign * arr[0][col] * getDeterminant(sub, x - 1);
			}
			return res;
		}
	}
	Matrix operator+(const Matrix& other) {
		if (other.x != this->x || other.y != this->y) {
			return Matrix();
		}
		else {
			Matrix m(x,y);
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					m.arr[i][j] = this->arr[i][j] + other.arr[i][j];
				}
			}
			return m;
		}
	}
	Matrix operator-(const Matrix& other) {
		if (other.x != this->x || other.y != this->y) {
			return Matrix();
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
	Matrix operator*(const Matrix& other) {
		if (this->y != other.x) {
			return Matrix();
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
	Matrix operator/(T num) {
		Matrix m(x, y);
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				m.arr[i][j] = arr[i][j]/num;
			}
		}
		return m;
	}
	T Max() {
		T max = arr[0][0];
		for (int i = 0; i < x; i++) {
			for (j = 0; j < y; j++) {
				if (arr[i][j] > max) max = arr[i][j];
			}
		}
		return max;
	}
	T Min() {
		T min = arr[0][0];
		for (int i = 0; i < x; i++) {
			for (j = 0; j < y; j++) {
				if (arr[i][j] < min) min = arr[i][j];
			}
		}
		return min;
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
	srand(time(NULL));

}
