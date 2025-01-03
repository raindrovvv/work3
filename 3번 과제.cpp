#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

template <typename T>
class SimpleVector {
private:
	T* arr;        // ���� �迭
	int currentSize;  // ���� ���� ����
	int currentCapacity;  // ���� �迭 ũ��

public:
    // ������
    SimpleVector() : currentSize(0), currentCapacity(10) {
        arr = new T[currentCapacity];
    }

    // �뷮�� ������ �� �ִ� ������ �߰�
    SimpleVector (int capacity) : currentSize(0), currentCapacity(capacity) {
        arr = new T[currentCapacity];
    }

    // �Ҹ���
    ~SimpleVector() {
        delete[] arr;
    }

    // �� �� ���� �߰�
    void push_back(const T& value) {
        if (currentSize < currentCapacity) {
            arr[currentSize] = value;
            ++currentSize;
        }
        else {
           //cout << "�迭�� ���� á���ϴ�!" << endl;
        }
    }

    // �� �� ���� ����
    void pop_back() {
        if (currentSize > 0) {
            --currentSize;
        }
        else {
            //cout << "�迭�� ��� �ֽ��ϴ�!" << endl;
        }
    }

    // ������ ���� ��ȯ
    int size() const {
        return currentSize;
    }

	// �迭 ũ�� ��ȯ
    int capacity() const {
        return currentCapacity;
    }
};

int main() {
    SimpleVector<int> intVector(20);
    SimpleVector<string> stringVector;
    cout << "---�ʱ� ����---" << endl;
    cout << "intVector�� �뷮: " << intVector.capacity() << endl;
    cout << "intVector�� ���� ����: " << intVector.size() << endl;
    cout << "stringVector�� �뷮: " << stringVector.capacity() << endl;
    cout << "stringVector�� ���� ����: " << stringVector.size() << endl;

    cout << "\n---�� �߰�---" << endl;
    intVector.push_back(100);
    intVector.push_back(100);
    intVector.push_back(100);
    stringVector.push_back("Hello");
    stringVector.push_back("Hello");
    stringVector.push_back("Hello");

    cout << "intVector�� �뷮: " << intVector.capacity() << endl;
    cout << "intVector�� ���� ����: " << intVector.size() << endl;
    cout << "stringVector�� �뷮: " << stringVector.capacity() << endl;
    cout << "stringVector�� ���� ����: " << stringVector.size() << endl;

    cout << "\n---�� ����---" << endl;
    intVector.pop_back();
    intVector.pop_back();
    stringVector.pop_back();

    cout << "intVector�� �뷮: " << intVector.capacity() << endl;
    cout << "intVector�� ���� ����: " << intVector.size() << endl;
    cout << "stringVector�� �뷮: " << stringVector.capacity() << endl;
    cout << "stringVector�� ���� ����: " << stringVector.size() << endl;
}
