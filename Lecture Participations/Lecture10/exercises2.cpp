#include <iostream>
#include <string>
#include <vector>

// Names:
// Jaryd Meek
// Noah Nguyen

using namespace std;


// we'd like to write a function that is applicable to many types but
// we don't want to copy paste everything

// For example, here is a templated Add function
template <typename T>
T Add(T v1, T v2) {
    return v1 + v2;
}

// 6) implement a templated version of AddToValues, "AddToValues2".

template <typename T>
vector<T> AddToValues2(vector<T> v1, T v2) {
    for (int x = 0; x < v1.size(); x++) {
            v1[x] = v1[x] + v2;
        }
        return v1;
}


struct testStruct
{
    int test = 0;
    testStruct operator+(const testStruct& other) {
         testStruct temp;
         temp.test = this->test + other.test;
         return temp;
      }
};

int main() {
    // 7) call AddToValues2, passing in an int vector and another int.
    vector<int> intVector2 = vector<int>();
    intVector2.push_back(0);
    intVector2.push_back(1);
    intVector2.push_back(2);
    intVector2.push_back(3);

    vector<int> newIntVector2 = AddToValues2(intVector2, 10);


    // 8) compile this file to object code
    // g++ -Wall -std=c++17 exercises2.cpp -c
    // then run: nm -C exercises2.o | grep "AddToValues2"
    // How many versions of the AddToValues2 function are in the
    // compiled object code? Copy + paste the relevant lines here:
    //1 time
    //0000000000000178 T std::__1::vector<int, std::__1::allocator<int> > AddToValues2<int>(std::__1::vector<int, std::__1::allocator<int> >, int)

    // 9) call AddToValues2, passing in a vector of a non-int type and a value that you can add
    // successfully to the elements

    vector<double> doubleVector = vector<double>();
    doubleVector.push_back(0.1);
    doubleVector.push_back(1.1);
    doubleVector.push_back(2.1);
    doubleVector.push_back(3.1);

    vector<double> newDoubleVector = AddToValues2(doubleVector, 10.1);

    // 10) compile this file to object code
    // g++ -Wall -std=c++17 exercises2.cpp -c
    // then run: nm -C exercises2.o | grep "AddToValues2"
    // How many versions of the AddToValues2 function are in the
    // compiled object code? Copy + paste the relevant lines here:

    //2 versions
    //00000000000003e8 T std::__1::vector<double, std::__1::allocator<double> > AddToValues2<double>(std::__1::vector<double, std::__1::allocator<double> >, double)
    //0000000000000264 T std::__1::vector<int, std::__1::allocator<int> > AddToValues2<int>(std::__1::vector<int, std::__1::allocator<int> >, int)

    // 11) Experiment to find calls to this function that you would like to work but that do
    // not yet work. for each function call that doesn't work, comment about what type of 
    // error is produced.
    
    //vector<double> newDoubleVector = AddToValues2(doubleVector, 10); doesn't work
    //passing in a vector of doubles, then trying to add an int.
    //Compile time error for no matching function

    // 12) Create a struct that has an int field. Instantiate a vector of these structs.
    // Instantiate another instance of this struct.

    vector<testStruct> testStructVec = vector<testStruct>();
    testStruct testStructTemp = testStruct();
    testStructTemp.test = 0;
    testStructVec.push_back(testStructTemp);

    testStruct testStructObj = testStruct();
    testStructObj.test = 10;
    
    // 13) Call AddToValues2 w/ the vector of structs and single struct from #12
    // Is there an error? If yes, what is it?
    //
    // Answer: Yes, error: no viable overloaded '+='

    vector<testStruct> newTestStructVec = AddToValues2(testStructVec, testStructObj);


    // 14) If there was an error, attempt to fix it.

    //Fixed by overloading + operator in struct

    
}

