#include <iostream>
#include <string>
using namespace std;
//PRACT
#define MIN(x, y) (x > y? y : x)
#define MAX(x, y) (x > y? x : y)
#define SQ(x) (x**2)
#define POW(x, y) (x**y)
#define PAR(x) (x%2==0? true : false)
#define NEPAR(x) (x%2==0? false : true)

struct Student {
    string name;
    string surname;
    string fname;
    int marks[10]{ 0 };
};

void Initialise(Student& s) {
    cout << "Enter name: ";
    cin >> s.name;
    cout << "Enter surname: ";
    cin >> s.surname;
    cout << "Enter fname: ";
    cin >> s.fname;
    for (int i = 0; i < 10; i++) {
        cout << "Enter " << i + 1 << " mark: ";
        cin >> s.marks[i];
    }
}

void Show(Student s) {
    cout << "Name: " << s.name << endl;
    cout << "Surname: " << s.surname << endl;
    cout << "Fname: " << s.fname << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Mark " << i + 1 << ": " << s.marks[i] << ", ";
    }
    cout << endl;
}

int avg(Student s) {
    int ss = 0;
    for (int i = 0; i < 10; i++) {
        ss += s.marks[i];
    }
    return ss / 10.0;
}

Student* addS(Student* ss, int& size) {
    Student* newS = new Student[size + 1];
    for (int i = 0; i < size; i++) {
        newS[i] = ss[i];
    }

    Initialise(newS[size]);
    delete[] ss;
    size++;
    return newS;
}

void ShowSS(Student* ss, int size) {
    for (int i = 0; i < size; i++) {
        cout << "_________________" << endl;
        cout << "Student " << i + 1 << endl;
        Show(ss[i]);
        cout << "_________________" << endl;
    }
}

void ShowBorzhnyk(Student* ss, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 10; j++) {
            if (ss[i].marks[j] == 0) {
                Show(ss[i]);
                break;
            }
        }
    }
}

int mainSTD() {
    int size = 1;

    Student* ss = new Student[size];
    Initialise(ss[0]);
    ss = addS(ss, size);
    ShowSS(ss, 2);
    return 0;
}

//DZ
// EX 1

struct Book {
    string name;
    string author;
    string edition;
    string genre;
};

void editBook(Book& b) {
    cout << "Enter name: ";
    cin >> b.name;
    cout << "Enter author: ";
    cin >> b.author;
    cout << "Enter edition: ";
    cin >> b.edition;
    cout << "Enter genre: ";
    cin >> b.genre;
}

void ShowBook(Book b) {
    cout << "Name: " << b.name << "; " << "Author: " << b.author << "; " << "Edition: " << b.edition << "; " << "Genre: " << b.genre << endl;
}

void ShowBooks(Book books[10]) {
    for (int i = 0; i < 10; i++) {
        cout << "Book " << i + 1 << endl;
        ShowBook(books[i]);
        cout << "_____________" << endl;
    }
}

void SearchBookByAuthor(Book books[10], string a) {
    for (int i = 0; i < 10; i++) {
        if (books[i].author == a) {
            cout << "Book " << i + 1 << endl;
            ShowBook(books[i]);
        }
    }
}

void SearchBookByName(Book books[10], string n) {
    for (int i = 0; i < 10; i++) {
        if (books[i].name == n) {
            cout << "Book " << i + 1 << endl;
            ShowBook(books[i]);
        }
    }
}

void SortByName(Book books[10]) {
    for (int i = 1; i < 10; i++) {
        Book k = books[i];
        int j = i - 1;
        while (j >= 0 && (int)tolower(books[j].name[0]) > (int)k.name[0]) {
            books[j + 1] = books[j];
            j -= 1;
        }
        books[j + 1] = k;
    }
    ShowBooks(books);
}

void SortByAuthor(Book books[10]) {
    for (int i = 1; i < 10; i++) {
        Book k = books[i];
        int j = i - 1;
        while (j >= 0 && (int)tolower(books[j].author[0]) > (int)k.author[0]) {
            books[j + 1] = books[j];
            j -= 1;
        }
        books[j + 1] = k;
    }
    ShowBooks(books);
}

void SortByEdition(Book books[10]) {
    for (int i = 1; i < 10; i++) {
        Book k = books[i];
        int j = i - 1;
        while (j >= 0 && (int)tolower(books[j].edition[0]) > (int)k.edition[0]) {
            books[j + 1] = books[j];
            j -= 1;
        }
        books[j + 1] = k;
    }
    ShowBooks(books);
}

int mainBK() {

    Book books[10];
    books[0] = { "b", "b", "b", "b" };
    books[1] = { "a", "a", "a", "a" };
    books[2] = { "d", "d", "d", "d" };
    books[3] = { "c", "c", "c", "c" };
    books[4] = { "h", "h", "h", "h" };
    books[5] = { "t", "t", "t", "t" };
    books[6] = { "j", "j", "j", "j" };
    books[7] = { "g", "g", "g", "g" };
    books[8] = { "r", "r", "r", "r" };
    books[9] = { "y", "y", "y", "y" };

    while (true) {
        int action;
        cout << "Enter action: " << endl;
        cout << "1 - edit book" << endl;
        cout << "2 - show books" << endl;
        cout << "3 - search book by author" << endl;
        cout << "4 - search book by name" << endl;
        cout << "5 - sort books by name" << endl;
        cout << "6 - sort books by author" << endl;
        cout << "7 - sort books by edition" << endl;
        cout << "8 - quit" << endl;
        cin >> action;

        int book;
        string n;
        switch (action) {
        case 8:
            return 0;
        case 1:
            cout << "Select book: ";
            cin >> book;
            editBook(books[book-1]);
            break;
        case 2:
            ShowBooks(books);
            break;
        case 3:
            cout << "Enter author: ";
            cin >> n;
            SearchBookByAuthor(books, n);
            break;
        case 4:
            cout << "Enter name: ";
            cin >> n;
            SearchBookByName(books, n);
            break;
        case 5:
            SortByName(books);
            break;
        case 6:
            SortByAuthor(books);
        case 7:
            SortByEdition(books);
        default:
            cout << "Invalid command";
            return 1;
        }
    }

    return 0;
}

//Struct
//1
struct Car {
    string color;
    string model;
    union number {
        int num;
        char word[8]; //strcpy_s
    } n;
    bool isNum;
};

bool setNumber(int value, int& des) {
    if (value >= 10000 && value <= 99999) {
        des = value;
        return true;
    }
    else {
        cout << "Error: 'a' must be a 5-digit number." << endl;
        return false;
    }
}

void editCar(Car& c) {
    cout << "Enter color: ";
    cin >> c.color;
    cout << "Enter model: ";
    cin >> c.model;
    int choice;
    cout << "Enter number type (1-num, 2-word): ";
    cin >> choice;

    switch (choice) {
    case 1: {
        int n;
        cout << "Enter num: ";
        cin >> n;
        if (setNumber(n, c.n.num)) {
            c.isNum = true;
        }
        else {
            c.isNum = false;
        }
        break;
    }
    case 2: {
        char w[8];
        cout << "Enter word: ";
        cin >> w;
        strcpy_s(c.n.word, 8, w);
        c.isNum = false;
        break;
    }
    default:
        cout << "Invalid choice. Setting default number to 10000." << endl;
        setNumber(10000, c.n.num);
        c.isNum = true;
        break;
    }
}


void ShowCar(Car c) {
    cout << "Model: " << c.model << endl;
    cout << "Color: " << c.color << endl;
    cout << "Number: ";
    if (c.isNum) cout << c.n.num << endl;
    else cout << c.n.word << endl;
}

void ShowCars(Car *cc) {
    for (int i = 0; i < 10; i++) {
        cout << "Car " << i + 1 << endl;
        ShowCar(cc[i]);
        cout << "_________________" << endl;
    }
}

int FindCarByNumber(Car* cc, short int n) {
    if (n < 10000 || n > 99999) {
        cout << "Invalid number" << endl;
        return -1;
    }
    for (int i = 0; i < 10; i++) {
        if (cc[i].isNum && cc[i].n.num == n) {
            ShowCar(cc[i]);
            return i;
        }
    }
    return -1;
}

int FindCarByNumber(Car* cc, const char n[8]) {
    for (int i = 0; i < 10; i++) {
        if (!cc[i].isNum && strcmp(cc[i].n.word, n) == 0) {
            ShowCar(cc[i]);
            return i;
        }
    }
    return -1;
}
//2
struct LivingEntity {
    int speed;
    enum type { BIRD = 1, ANIMAL = 2, HUMAN = 3 };
    string tp;
    string color;
    union characteristics {
        int flight_vel;
        bool artiodactyl;
        int IQ;
    } charact;
};

void WriteInfo(LivingEntity& l) { // or edit
    cout << "Enter speed: ";
    cin >> l.speed;
    cout << "Enter color: ";
    cin >> l.color;
    int a;
    cout << "Enter type: " << endl;
    cout << "1 - bird" << endl;
    cout << "2 - animal" << endl;
    cout << "3 - human" << endl;
    cin >> a;

    switch (a)
    {
    case l.type::BIRD:
        l.tp = "b";
        cout << "Enter flight velocity: ";
        cin >> l.charact.flight_vel;
        break;
    case l.type::ANIMAL:
        l.tp = "a";
        cout << "Enter  if artiodactyl (0 - no, 1 - yes): ";
        cin >> l.charact.artiodactyl;
        break;
    case l.type::HUMAN:
        l.tp = "h";
        cout << "Enter IQ: ";
        cin >> l.charact.IQ;
        break;
    default:
        break;
    }
}

void ShowInfo(LivingEntity l) {
    cout << "Speed: " << l.speed << endl;
    cout << "Type : ";
    if (l.tp == "b") {
        cout << "bird" << endl;
        cout << "Flight velocity" << l.charact.flight_vel << endl;
    }
    else if (l.tp == "a") {
        cout << "animal" << endl;
        string art = l.charact.artiodactyl ? "true" : "false";
        cout << "Artiodactyl: " << art << endl;
    }
    else if (l.tp == "h") {
        cout << "human" << endl;
        cout << "IQ: " << l.charact.IQ << endl;
    }
}

void ShowALL(LivingEntity *ll) { // default size - 10
    for (int i = 0; i < 10; i++) {
        cout << "Entity " << i + 1 << endl;
        ShowInfo(ll[i]);
        cout << "_____________" << endl;
    }
}

int SearchByCharac(LivingEntity *ll, string c, int val) {
    for (int i = 0; i < 10; i++) {
        if (c == "flight_velocity") {
            if (ll[i].charact.flight_vel == val) {
                ShowInfo(ll[i]);
                return 0;
            }
        }
        else if (c == "artiodactyl") {
            if (ll[i].charact.artiodactyl == val) {
                ShowInfo(ll[i]);
                return 0;
            }
        }
        else if (c == "IQ") {
            if (ll[i].charact.IQ == val) {
                ShowInfo(ll[i]);
                return 0;
            }
        }
    }
    return -1;
}

int main()
{
    
}
