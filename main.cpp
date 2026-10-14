#include <iostream>
#include <cstring>
using namespace std;

class String {
    char* _data;
    int _capacity;
    int _length;

public:
    String() {
        _capacity = 80;
        _length = 0;
        _data = new char[_capacity + 1];
        _data[0] = '\0';
    }

    String(int size) {
        if (size < 0) {
            size = 0;
        }

        _capacity = size;
        _length = 0;
        _data = new char[_capacity + 1];
        _data[0] = '\0';
    }

    String(const char* str) {
        if (str == nullptr) {
            str = "";
        }

        _length = strlen(str);
        _capacity = _length;
        _data = new char[_capacity + 1];

        for (int i = 0; i <= _length; i++) {
            _data[i] = str[i];
        }
    }

    String(const String& other) {
        _capacity = other._capacity;
        _length = other._length;
        _data = new char[_capacity + 1];

        for (int i = 0; i <= _length; i++) {
            _data[i] = other._data[i];
        }
    }

    ~String() {
        delete[] _data;
    }

    void Input() {
        char buffer[1024];

        cout << "Enter string: ";
        cin.getline(buffer, 1024);

        _length = strlen(buffer);

        if (_length > _capacity) {
            _length = _capacity;
        }

        for (int i = 0; i < _length; i++) {
            _data[i] = buffer[i];
        }

        _data[_length] = '\0';
    }

    void Print() {
        cout << "Data: " << _data << endl;
        cout << "Length: " << _length << endl;
        cout << "Capacity: " << _capacity << endl;
    }
};

int main() {
    String s1;
    s1.Print();
    cout << endl;

    String s2(256);
    s2.Print();
    cout << endl;

    char str[256];

    cout << "enter string: ";
    cin.getline(str, 256);

    String s3(str);
    s3.Print();
    cout << endl;

    String s4(s3);
    s4.Print();
    cout << endl;

    s1.Input();
    s1.Print();

}