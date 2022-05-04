#include <iostream>

// Name: Jaryd Meek
//

// Write any functions you need here!

void testFunc9(int *ptr) {
        NULL;
    }

void testFunc11(int &ref) {
        NULL;
    }

void testFunc14(int &inputParameter, int *outputParameter) {
        *outputParameter = inputParameter;
    }

class TestClass {

    private:
        int test_var_;


    public:
        TestClass(int var) {
            test_var_= var;
        }

        int get_test_var() const {
            return test_var_;
        }

        int operator+(const TestClass &temp) {
            return get_test_var() + temp.get_test_var();
        }
        bool operator==(const TestClass &temp) {
            if (get_test_var() == temp.get_test_var()) {
                return true;
            } else {
                return false;
            }
        }
};

int main() {
    // Add as many prints to cout as you need to answer the questions.
    // Leave them in your code when you turn it in.
    // If you have lines of code that cause errors that test the questions,
    // leave this code in your file but comment it out.
    
    // 1) Declare an int

    int test = 0;

    // 2) Declare a pointer to that int

    int *pointer = &test;

    // 3) Increment the int via the pointer

    (*pointer)++;

    // 4) Declare a reference to your int

    int &ref = test;

    // 5) Increment the int via the reference

    ref++;

    // 6) When you increment the int via the variable declared in #1, which
    // variables will be modified to see the changes? (the pointer , reference or both?)
    // Answer: reference

    // 7) When you increment the int via the pointer declared in #2, which
    // variables will be modified to see the changes?
    // Answer: pointer

    // 8) When you increment the int via the reference declared in #4, which
    // variables will be modified to see the changes?
    // Answer: both

    // 9) Write a function that takes an int * parameter. How would you pass the 
    // variable from #1 into this function? (write the function header and function call below)
    
    testFunc9(&test);

    // 10) Can you pass your reference from #4 to the function from #9 without accessing its address?
    // Answer: No


    // 11) Write a function that takes an int & parameter. How would you pass the 
    // variable from #1 into this function? (write the function header and call below)
    
    testFunc11(test);

    // 12) Can you pass your pointer from #2 to the function from #11 without dereferencing it?
    // Answer: No

    // 13) Can you pass your reference from #4 to the function from #11?
    // Answer: Yes

    // 14) Write a function that takes one const reference input parameter and one pointer
    // output parameter. The function should fill in the value of the output parameter based
    // on the value of the input parameter. (what it does exactly is up to you).
    // Call your function 3 times below. Be sure to include output as necessary to be sure
    // your function works as described.
    int input14a = 42;
    int output14a = 20;
    std::cout << "Function Call 1" << std::endl;
    std::cout << "Input Parameter and Output Parameter before function: input: " << input14a << " output: " << output14a << std::endl;
    testFunc14(input14a, &output14a);
    std::cout << "Input Parameter and Output Parameter after function: input: " << input14a << " output: " << output14a << std::endl;
    std::cout << "----\n" << std::endl;

    int input14b = 12;
    int output14b = 689;
    std::cout << "Function Call 2" << std::endl;
    std::cout << "Input Parameter and Output Parameter before function: input: " << input14b << " output: " << output14b << std::endl;
    testFunc14(input14b, &output14b);
    std::cout << "Input Parameter and Output Parameter after function: input: " << input14b << " output: " << output14b << std::endl;
    std::cout << "----\n" << std::endl;

    int input14c = 68;
    int output14c = 1245667;
    std::cout << "Function Call 1" << std::endl;
    std::cout << "Input Parameter and Output Parameter before function: input: " << input14c << " output: " << output14c << std::endl;
    testFunc14(input14c, &output14c);
    std::cout << "Input Parameter and Output Parameter after function: input: " << input14c << " output: " << output14c << std::endl;
    std::cout << "----\n" << std::endl;
    

    // 15) What is/are the difference(s) between output parameters and return values?
    // Answer: Return values are a single object being returned while output parameters are changing a variable at a pointer passed to the function as a parameter. This means while you can only have one return object, you can have theoretically infinity output parameters

    // 16) Create a custom class with at least one private field/class attribute. Overload the == and + operator for this class
    // such that == can be used to compare the objects of the class and + can be used to add
    // 2 objects of the class together. Implement an appropriate constructor for your class.
    // When you overload these operators, the resulting return value should make sense.
    // Instantiate at least 2 objects of this class and perform the == and + operations on them.
    // hint: for operator+, the function signature when implemented as a member function of the Object class is:
    // Object operator+(const Object &other)
    // Answer: TestClass below is the class
    TestClass test1(10);
    TestClass test2(20);
    int output1 = test1+test2;
    bool output2 = test1 == test2;
    
    std::cout << "Adding test1 and test2: " << output1 << std::endl;
    std::cout << "Comparing test1 and test2: " << output2 << std::endl;
}
