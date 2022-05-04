#include <iostream>
#include "Earth.h"

// Names:
//Jaryd Meek

using namespace std;

int main(int argc, char **argv){
    // 0) Implement your Earth's constructor in Earth.cpp
    //done

    // 1) Get an instance of your earth object
    Earth& earth1 = Earth::GetInstance();

    // 2) Get another instance of your earth object
    Earth& earth2 = Earth::GetInstance();

    // 3) Test to see if the two Earth instances from #1 and #2 are stored at the same
    // location in memory.
    if (&earth1 == &earth2) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    // 3) Call IncreasePopulation from one of your Earth instances. Can you see this change
    // from your other Earth instance?
    //YES
    earth1.IncreasePopulation();
    cout << earth1.get_population() << endl;

    cout << earth2.get_population() << endl;

    // 4) Create a public field in your Earth object. Do you need an instance of an Earth object
    // to access this field?
    // Yes

    //cout << Earth::test << endl;

	return 0;
}
