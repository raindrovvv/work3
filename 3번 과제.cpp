#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

template <typename T>
class SimpleVector {
private:
	T* arr;        // 동적 배열
	int currentSize;  // 현재 원소 개수
	int currentCapacity;  // 현재 배열 크기

public:
    // 생성자
    SimpleVector() : currentSize(0), currentCapacity(10) {
        arr = new T[currentCapacity];
    }

    // 용량을 지정할 수 있는 생성자 추가
    SimpleVector (int capacity) : currentSize(0), currentCapacity(capacity) {
        arr = new T[currentCapacity];
    }

    // 소멸자
    ~SimpleVector() {
        delete[] arr;
    }

    // 맨 뒤 원소 추가
    void push_back(const T& value) {
        if (currentSize < currentCapacity) {
            arr[currentSize] = value;
            ++currentSize;
        }
        else {
           //cout << "배열이 가득 찼습니다!" << endl;
        }
    }

    // 맨 뒤 원소 제거
    void pop_back() {
        if (currentSize > 0) {
            --currentSize;
        }
        else {
            //cout << "배열이 비어 있습니다!" << endl;
        }
    }

    // 원소의 개수 반환
    int size() const {
        return currentSize;
    }

	// 배열 크기 반환
    int capacity() const {
        return currentCapacity;
    }
};

int main() {
    SimpleVector<int> intVector(20);
    SimpleVector<string> stringVector;
    cout << "---초기 설정---" << endl;
    cout << "intVector의 용량: " << intVector.capacity() << endl;
    cout << "intVector의 원소 갯수: " << intVector.size() << endl;
    cout << "stringVector의 용량: " << stringVector.capacity() << endl;
    cout << "stringVector의 원소 갯수: " << stringVector.size() << endl;

    cout << "\n---값 추가---" << endl;
    intVector.push_back(100);
    intVector.push_back(100);
    intVector.push_back(100);
    stringVector.push_back("Hello");
    stringVector.push_back("Hello");
    stringVector.push_back("Hello");

    cout << "intVector의 용량: " << intVector.capacity() << endl;
    cout << "intVector의 원소 갯수: " << intVector.size() << endl;
    cout << "stringVector의 용량: " << stringVector.capacity() << endl;
    cout << "stringVector의 원소 갯수: " << stringVector.size() << endl;

    cout << "\n---값 제거---" << endl;
    intVector.pop_back();
    intVector.pop_back();
    stringVector.pop_back();

    cout << "intVector의 용량: " << intVector.capacity() << endl;
    cout << "intVector의 원소 갯수: " << intVector.size() << endl;
    cout << "stringVector의 용량: " << stringVector.capacity() << endl;
    cout << "stringVector의 원소 갯수: " << stringVector.size() << endl;
}
