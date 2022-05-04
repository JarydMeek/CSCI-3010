/**
Jaryd Meek
HW 2
This program runs unit tests and time testing for the 3 data structures.
*/


#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
//Include neccessary files
#include "catch.hpp"
#include "Linear.hpp"
#include "Tree.hpp"
#include "HashMap.hpp"

//Include helpful libraries
#include <fstream> //file io
#include <chrono> //timing
#include <cstdlib>  //random

//Struct for testing non-standard data.
struct test {
    float val = 0;

    //constructor to make life easier
    test(float val) {
        this->val = val;
    }

    //overload
    bool operator==(const test& other) const { return this->val == other.val; }
    bool operator!=(const test& other) const { return this->val != other.val; } 
    bool operator>(const test& other) const { return this->val > other.val; }
    bool operator<(const test& other) const { return this->val < other.val; }
};


//Overloading Hash function for struct
//Logic came from here for this
//https://en.cppreference.com/w/cpp/utility/hash
template<>
struct std::hash<test>{
    std::size_t operator()(test const& other) const noexcept {
        return std::hash<float>{}(other.val);
    }
};

//-------------------------
//General Unit Testing
//-------------------------

//Linear Tests (3x data types)
TEST_CASE ( "Linear", "[testLinear]") {    
    SECTION("Linear Int Tests") {
        Linear<int> testVector;

        //InsertElement & getElementAtIndex
        testVector.insertElement(2);
        REQUIRE(testVector.getElementAtIndex(0) == 2);
        testVector.insertElement(3);
        REQUIRE(testVector.getElementAtIndex(1) == 3);
        testVector.insertElement(4);
        REQUIRE(testVector.getElementAtIndex(2) == 4);

        //search
        REQUIRE(testVector.search(2) == true);
        REQUIRE(testVector.search(420) == false);
        REQUIRE(testVector.search(4) == true);

        //deleteElement
        testVector.deleteElement(2);
        REQUIRE(testVector.search(2) == false);
        REQUIRE(testVector.getElementAtIndex(0) == 3);
    }

    SECTION("Linear Double Tests") {
        Linear<double> testVector;

        //InsertElement
        testVector.insertElement(2.0);
        REQUIRE(testVector.getElementAtIndex(0) == 2.0);
        testVector.insertElement(3.0);
        REQUIRE(testVector.getElementAtIndex(1) == 3.0);
        testVector.insertElement(4.0);
        REQUIRE(testVector.getElementAtIndex(2) == 4.0);

        //search
        REQUIRE(testVector.search(2.0) == true);
        REQUIRE(testVector.search(420.0) == false);
        REQUIRE(testVector.search(4.0) == true);

        //deleteElement
        testVector.deleteElement(2.0);
        REQUIRE(testVector.search(2.0) == false);
        REQUIRE(testVector.getElementAtIndex(0) == 3.0);
    }

    SECTION("Linear Custom Object Tests") {
        Linear<test> testVector;

        //InsertElement
        test tempTest(2.0);
        testVector.insertElement(tempTest);
        REQUIRE(testVector.getElementAtIndex(0).val == 2.0);
        test tempTest2(3.0);
        testVector.insertElement(tempTest2);
        REQUIRE(testVector.getElementAtIndex(1).val == 3.0);
        test tempTest3(4.0);
        testVector.insertElement(tempTest3);
        REQUIRE(testVector.getElementAtIndex(2).val == 4.0);


        //search
        test tempTest4(420.0);
        REQUIRE(testVector.search(tempTest2) == true);
        REQUIRE(testVector.search(tempTest4) == false);
        REQUIRE(testVector.search(tempTest) == true);

        //deleteElement
        testVector.deleteElement(tempTest);
        REQUIRE(testVector.search(tempTest) == false);
        REQUIRE(testVector.getElementAtIndex(0).val == 3.0);
    }
    
}

//Tree Tests (3x data types)
TEST_CASE ( "Tree", "[testTree]") {    
    SECTION("Tree Int Tests") {
        Tree<int> testTree(3);

        //InsertElement
        testTree.insertElement(1);
        testTree.insertElement(4);
        testTree.insertElement(0);
        testTree.insertElement(2);

        //Search
        REQUIRE(testTree.search(2) == true);
        REQUIRE(testTree.search(420) == false);
        REQUIRE(testTree.search(4) == true);

        //deleteElement
        testTree.deleteElement(2);
        REQUIRE(testTree.search(2) == false);
        REQUIRE(testTree.search(3) == true);
        REQUIRE(testTree.search(4) == true);
        REQUIRE(testTree.search(0) == true);
        REQUIRE(testTree.search(1) == true);
    }
    SECTION("Tree Double Tests") {
        Tree<int> testTree(3.0);

        //InsertElement
        testTree.insertElement(1.0);
        testTree.insertElement(4.0);
        testTree.insertElement(0.0);
        testTree.insertElement(2.0);

        //Search
        REQUIRE(testTree.search(2.0) == true);
        REQUIRE(testTree.search(420.0) == false);
        REQUIRE(testTree.search(4.0) == true);

        //deleteElement
        testTree.deleteElement(2.0);
        REQUIRE(testTree.search(2.0) == false);
        REQUIRE(testTree.search(3.0) == true);
        REQUIRE(testTree.search(4.0) == true);
        REQUIRE(testTree.search(0.0) == true);
        REQUIRE(testTree.search(1.0) == true);
    }
    SECTION("Tree Custom Object Tests") {
        test testStruct(3.0);
        Tree<test> testTree(testStruct);

        //InsertElement
        testTree.insertElement(test(1.0));
        testTree.insertElement(test(4.0));
        testTree.insertElement(test(0.0));
        testTree.insertElement(test(2.0));

        //Search
        REQUIRE(testTree.search(test(2.0)) == true);
        REQUIRE(testTree.search(test(420.0)) == false);
        REQUIRE(testTree.search(test(4.0)) == true);

        //deleteElement
        testTree.deleteElement(testStruct);
        REQUIRE(testTree.search(test(3.0)) == false);
        REQUIRE(testTree.search(test(2.0)) == true);
        REQUIRE(testTree.search(test(4.0)) == true); 
        REQUIRE(testTree.search(test(0.0)) == true);
        REQUIRE(testTree.search(test(1.0)) == true);
    }
}

//HashMap Tests (3x data types)
TEST_CASE ( "HashMap", "[testHashMap]") {    
    SECTION("HashMap Int Tests") {
        HashMap<int> testHashMap;

        //InsertElement
        testHashMap.insertElement(1);
        testHashMap.insertElement(4);
        testHashMap.insertElement(0);
        testHashMap.insertElement(2);
        testHashMap.insertElement(3);

        //Search
        REQUIRE(testHashMap.search(2) == true);
        REQUIRE(testHashMap.search(420) == false);
        REQUIRE(testHashMap.search(4) == true);

        //deleteElement
        testHashMap.deleteElement(2);
        REQUIRE(testHashMap.search(2) == false);
        REQUIRE(testHashMap.search(3) == true);
        REQUIRE(testHashMap.search(4) == true);
        REQUIRE(testHashMap.search(0) == true);
        REQUIRE(testHashMap.search(1) == true);
    }

    SECTION("HashMap Double Tests") {
        HashMap<double> testHashMap;

        //InsertElement
        testHashMap.insertElement(1.0);
        testHashMap.insertElement(4.0);
        testHashMap.insertElement(0.0);
        testHashMap.insertElement(3.0);
        testHashMap.insertElement(2.0);

        //Search
        REQUIRE(testHashMap.search(2.0) == true);
        REQUIRE(testHashMap.search(420.0) == false);
        REQUIRE(testHashMap.search(4.0) == true);

        //deleteElement
        testHashMap.deleteElement(2.0);
        REQUIRE(testHashMap.search(2.0) == false);
        REQUIRE(testHashMap.search(3.0) == true);
        REQUIRE(testHashMap.search(4.0) == true);
        REQUIRE(testHashMap.search(0.0) == true);
        REQUIRE(testHashMap.search(1.0) == true);
    }

    SECTION("HashMap Custom Object Tests") {
        test testStruct(3.0);
        HashMap<test> testHashMap;

        //InsertElement
        testHashMap.insertElement(testStruct);
        testHashMap.insertElement(test(1.0));
        testHashMap.insertElement(test(4.0));
        testHashMap.insertElement(test(0.0));
        testHashMap.insertElement(test(2.0));

        //Search
        REQUIRE(testHashMap.search(test(2.0)) == true);
        REQUIRE(testHashMap.search(test(420.0)) == false);
        REQUIRE(testHashMap.search(test(4.0)) == true);

        //deleteElement
        testHashMap.deleteElement(testStruct);
        REQUIRE(testHashMap.search(test(3.0)) == false);
        REQUIRE(testHashMap.search(test(2.0)) == true);
        REQUIRE(testHashMap.search(test(4.0)) == true); 
        REQUIRE(testHashMap.search(test(0.0)) == true);
        REQUIRE(testHashMap.search(test(1.0)) == true);
    }   
}

//-------------------------
//Timing Testing
//-------------------------


//Linear Timing Testing

//Results:
//First: ~100 ns avg
//Last: ~190,000 ns avg
//Random: ~150,000 ns avg (varies wildly)

//trackers for time (averaging out the three data types)
int firstLinear = 0;
int lastLinear = 0;
int randomLinear = 0;

//Linear time testing (3x data types)
TEST_CASE ( "LinearTiming", "[timeLinear]") {   
    SECTION("Linear Integer Timing Tests") {
        srand((unsigned)time(0));
        Linear<int> testLinearInt;
        std::ifstream infile("testFiles/integers.csv");

        int a, count = 0;
        while (infile >> a) {
            testLinearInt.insertElement(a);
            count ++;
        }

        //First item
            auto start = std::chrono::high_resolution_clock::now();
            testLinearInt.getElementAtIndex(0);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            firstLinear += duration.count();
            

        //Last Item
            start = std::chrono::high_resolution_clock::now();
            testLinearInt.getElementAtIndex(count);
            stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            lastLinear += duration.count();

        //Random Item
            start = std::chrono::high_resolution_clock::now();
            testLinearInt.getElementAtIndex((rand()%count));
            stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            randomLinear += duration.count();
            
    }

    SECTION("Linear Double Timing Tests") {
        srand((unsigned)time(0));
        Linear<double> testLinearDouble;
        std::ifstream infile("testFiles/decimals.csv");

        int a, count = 0;
        while (infile >> a) {
            testLinearDouble.insertElement(a);
            count ++;
        }

        //First item
            auto start = std::chrono::high_resolution_clock::now();
            testLinearDouble.getElementAtIndex(0);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            firstLinear += duration.count();
            

        //Last Item
            start = std::chrono::high_resolution_clock::now();
            testLinearDouble.getElementAtIndex(count);
            stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            lastLinear += duration.count();

        //Random Item
            start = std::chrono::high_resolution_clock::now();
            testLinearDouble.getElementAtIndex((rand()%count));
            stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            randomLinear += duration.count();
            
    }

    SECTION("Linear String Timing Tests") {
        //Add to int
        srand((unsigned)time(0));
        Linear<std::string> testLinearString;
        std::ifstream infile("testFiles/strings.csv");

        std::string a;
        int count = 0;
        while (infile >> a) {
            testLinearString.insertElement(a);
            count ++;
        }

        //First item
            std::string item = testLinearString.getElementAtIndex(0);
            auto start = std::chrono::high_resolution_clock::now();
            testLinearString.search(item);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            firstLinear += duration.count();
            

        //Last Item
            item = testLinearString.getElementAtIndex(count);
            start = std::chrono::high_resolution_clock::now();
            testLinearString.search(item);
            stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            lastLinear += duration.count();

        //Random Item
        
            item = testLinearString.getElementAtIndex((rand()%count));
            start = std::chrono::high_resolution_clock::now();
            testLinearString.search(item);
            stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            randomLinear += duration.count();

            std::cout << "\nResults for Linear:" << std::endl;
            std::cout << "The duration to find first item is " << firstLinear/3 << " nanoseconds" << std::endl;
            std::cout << "The duration to find last item is " << lastLinear/3 << " nanoseconds" << std::endl;
            std::cout << "The duration to find random item is " << randomLinear/3 << " nanoseconds" << std::endl;
            
    }            
}

//BST Timing Testing


//Results:
//First: ~69 ns avg
//Last: ~1050 ns avg
//Random: ~500 ns avg

//trackers for time (averaging out the three data types)
int firstTree = 0;
int lastTree = 0;
int randomTree = 0;

//Tree time testing (3x data types)
TEST_CASE ( "TreeTiming", "[timeTree]") {   
    SECTION("Tree Integer Timing Tests") {
        srand((unsigned)time(0));
        Tree<int> testTreeInt;
        std::ifstream infile("testFiles/integers.csv");

        int a, first, randomVal = 0;

        while (infile >> a) {
            testTreeInt.insertElement(a);
            if (randomVal == 0) {
                randomVal = a;
                first = a;
            }
            if (rand() % 100 == 0) {
                randomVal = a;
            }
        }

        //First item
            auto start = std::chrono::high_resolution_clock::now();
            testTreeInt.search(first);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            firstTree += duration.count();
            

        //Last Item
            start = std::chrono::high_resolution_clock::now();
            testTreeInt.search(a);
            stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            lastTree += duration.count();

        //Random Item
            start = std::chrono::high_resolution_clock::now();
            testTreeInt.search(randomVal);
            stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            randomTree += duration.count();
            
    } 
    
    SECTION("Tree Double Timing Tests") {
        srand((unsigned)time(0));
        Tree<double> testTreeInt;
        std::ifstream infile("testFiles/decimals.csv");

        double a, first, randomVal = 0;

        while (infile >> a) {
            testTreeInt.insertElement(a);
            if (randomVal == 0) {
                randomVal = a;
                first = a;
            }
            if (rand() % 100 == 0) {
                randomVal = a;
            }
        }

        //First item
            auto start = std::chrono::high_resolution_clock::now();
            testTreeInt.search(first);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            firstTree += duration.count();
            

        //Last Item
            start = std::chrono::high_resolution_clock::now();
            testTreeInt.search(a);
            stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            lastTree += duration.count();

        //Random Item
            start = std::chrono::high_resolution_clock::now();
            testTreeInt.search(randomVal);
            stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            randomTree += duration.count();


    }

    SECTION("Tree String Timing Tests") {
        srand((unsigned)time(0));
        Tree<std::string> testTreeInt;
        std::ifstream infile("testFiles/decimals.csv");

        std::string a, first, randomVal = "";

        while (infile >> a) {
            testTreeInt.insertElement(a);
            if (randomVal == "") {
                randomVal = a;
                first = a;
            }
            if (rand() % 100 == 0) {
                randomVal = a;
            }
        }

        //First item
            auto start = std::chrono::high_resolution_clock::now();
            testTreeInt.search(first);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            firstTree += duration.count();
            

        //Last Item
            start = std::chrono::high_resolution_clock::now();
            testTreeInt.search(a);
            stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            lastTree += duration.count();

        //Random Item
            start = std::chrono::high_resolution_clock::now();
            testTreeInt.search(randomVal);
            stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            randomTree += duration.count();
            
            std::cout << "\nResults for Tree:" << std::endl;
            std::cout << "The duration to find first item is " << firstTree/3 << " nanoseconds" << std::endl;
            std::cout << "The duration to find last item is " << lastTree/3 << " nanoseconds" << std::endl;
            std::cout << "The duration to find random item is " << randomTree/3 << " nanoseconds" << std::endl;
            
    }   
}


//HashMap Timing Testing


//Results:
//First: ~130 ns avg
//Last: ~4250 ns avg
//Random: ~4000 ns avg

//trackers for time (averaging out the three data types)
int firstHash = 0;
int lastHash = 0;
int randomHash = 0;

//HashMap time testing (3x data types)
TEST_CASE ( "HashMapTiming", "[timeHashMap]") {   
    SECTION("HashMap Integer Timing Tests") {
        srand((unsigned)time(0));
        HashMap<int> testHashMap;
        std::ifstream infile("testFiles/integers.csv");

        int a, first, randomVal = 0;

        while (infile >> a) {
            testHashMap.insertElement(a);
            if (randomVal == 0) {
                randomVal = a;
                first = a;
            }
            if (rand() % 100 == 0) {
                randomVal = a;
            }
        }

        //First item
            auto start = std::chrono::high_resolution_clock::now();
            testHashMap.search(first);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            firstHash += duration.count();
            

        //Last Item
            start = std::chrono::high_resolution_clock::now();
            testHashMap.search(a);
            stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            lastHash += duration.count();

        //Random Item
            start = std::chrono::high_resolution_clock::now();
            testHashMap.search(randomVal);
            stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            randomHash += duration.count();
            
    }
    
    SECTION("HashMap Double Timing Tests") {
        srand((unsigned)time(0));
        HashMap<double> testHashMap;
        std::ifstream infile("testFiles/decimals.csv");

        double a, first, randomVal = 0;

        while (infile >> a) {
            testHashMap.insertElement(a);
            if (randomVal == 0) {
                randomVal = a;
                first = a;
            }
            if (rand() % 100 == 0) {
                randomVal = a;
            }
        }

        //First item
            auto start = std::chrono::high_resolution_clock::now();
            testHashMap.search(first);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            firstHash += duration.count();
            

        //Last Item
            start = std::chrono::high_resolution_clock::now();
            testHashMap.search(a);
            stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            lastHash += duration.count();

        //Random Item
            start = std::chrono::high_resolution_clock::now();
            testHashMap.search(randomVal);
            stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            randomHash += duration.count();


    }
    

    SECTION("HashMap String Timing Tests") {
        srand((unsigned)time(0));
        Tree<std::string> testTreeInt;
        std::ifstream infile("testFiles/strings.csv");

        std::string a, first, randomVal = "";

        while (infile >> a) {
            testTreeInt.insertElement(a);
            if (randomVal == "") {
                randomVal = a;
                first = a;
            }
            if (rand() % 100 == 0) {
                randomVal = a;
            }
        }

        //First item
            auto start = std::chrono::high_resolution_clock::now();
            testTreeInt.search(first);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            firstHash += duration.count();
            

        //Last Item
            start = std::chrono::high_resolution_clock::now();
            testTreeInt.search(a);
            stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            lastHash += duration.count();

        //Random Item
            start = std::chrono::high_resolution_clock::now();
            testTreeInt.search(randomVal);
            stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            randomHash += duration.count();

            std::cout << "\nResults for HashMap:" << std::endl;
            std::cout << "The duration to find first item is " << firstHash/3 << " nanoseconds" << std::endl;
            std::cout << "The duration to find last item is " << lastHash/3 << " nanoseconds" << std::endl;
            std::cout << "The duration to find random item is " << randomHash/3 << " nanoseconds\n\n" << std::endl;
            
    }  
}