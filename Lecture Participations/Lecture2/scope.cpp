#include <iostream>
#include <vector>

using namespace std;
// scope: "what can we see right here"
// - what variables/functions/other can we access from inside x, where x is a function, method, etc.

// 1) what happens in c++ if you try to acces a variable out of scope?

// 2) what happens if we make everything global?


// Summary:
// pass-by-value vs. pass-by-reference
// pass-by-value: give the function a copy of the value
// pass-by-reference: give the address of the location of the value


// *************************************************


// When you are done: turn in your file on canvas

// Names (be sure to include the initial of your last name(s)!):
// Jaryd Meek
// Preston Windfeldt 
// Yun-Ping Yang
// Collin Jones


// 1) Write a function that demonstrates whether ints are pass-by-value or pass-by-reference
// (do not use pointers or c++ references in this function)
// Answer: Pass-by-value
void IntTest(int testInt) {
    testInt++;
}

// 2) Write a function that tests demonstrates whether strings (std::string) are pass-by-value or pass-by-reference
// (do not use pointers or c++ references in this function)
// Answer: Pass-by-value
void StringTest(string test) {
    test = test + "Testing";
}

// 3) Write a function that demonstrates whether arrays are pass-by-value or pass-by-reference
// recall: to initialize an array-- type name[] = {comma separated elements};
// (do not use pointers or c++ references in this function)
// Answer: Pass-by-reference
void ArrayTest(int test[]) {
    test[0] = 420;
}

// 4) Write a function that demonstrates whether vectors are pass-by-value or pass-by-reference
// Answer: Pass-by-value
void VectorTest(vector<int> test) {
    test.push_back(420);
}

int main() {
    // code to call your functions goes here.

    // you may find it useful to print out values in main as well as inside your functions
    // to appropriately demonstrate whether the given type is pass-by-value or 
    // pass-by-reference
    int testInt = 0;
    cout << "Starting Int: " << testInt << "         ";
    IntTest(testInt);
    cout << " Final Int : " << testInt << endl;

    string testString = "Yeet";
    cout << "Starting String: " << testString << "         ";
    StringTest(testString);
    cout << " Final Int : " << testString << endl;

    int testArray[1];
    testArray[0] = 2;
    cout << "Starting Array (item 0): " << testArray[0] << "         ";
    ArrayTest(testArray);
    cout << " Final Array (item 0): " << testArray[0] << endl;

    vector <int> testVector;
    testVector.push_back(0);
    cout << "Starting Vector Size: " << testVector.size() << "         ";
    VectorTest(testVector);
    cout << " Final Vector Size: " << testVector.size() << endl;
}
