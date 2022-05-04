#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Names:
// Jaryd Meek
// Noah Nguyen


// 1) implement two functions, AddToValues(std::vector<int> v1, int v2)
// and AddToValues(std::vector<double> v1, double v2)

    vector<int> AddToValues (vector<int> v1, int v2) {
        for (int x = 0; x < v1.size(); x++) {
            v1[x] += v2;
        }
        return v1;
        }

    vector<double> AddToValues (vector<double> v1, double v2) {
        for (int x = 0; x < v1.size(); x++) {
            v1[x] += v2;
        }
        return v1;
        }
    // 2) Do your AddToValues functions have return values? why/ why not?
    // Answer:
    //Yes, Vectors are pass by vectors

int main() {
    // 3) Instantiate an int vector
    vector<int> intVector = vector<int>();
    intVector.push_back(0);
    intVector.push_back(1);
    intVector.push_back(2);
    intVector.push_back(3);


    // 4) call AddToValues, passing in your int vector and another int.
    vector<int> newIntVector = AddToValues(intVector, 10);


    // 5) compile this file to object code
    // g++ -std=c++17 -Wall exercises.cpp -c

    // then run the command: nm -C exercises.o | grep "AddToValues"
    // How many versions of the AddToValues function are in the
    // compiled object code? Copy + paste the relevant lines here:
    //2 versions
    //0000000000000108 T AddToValues(std::__1::vector<double, std::__1::allocator<double> >, double)
    //0000000000000000 T AddToValues(std::__1::vector<int, std::__1::allocator<int> >, int)
    //
    // If the -C flag isn't working, you can omit it and still complete the exercise--this flag
    // makes the output easier to read but isn't strictly necessary
}
