#include <iostream>

#include "Animal.h"

// Name(s): 

int main() {

  Reptile ralph("alligator");
  std::cout << ralph.MakeSound() << std::endl;

  // 1) Instantiate another animal 

  Animal test("birb");
  std::cout << test.MakeSound() << std::endl;

  // 2) Call the Race method of animal

  test.Race(ralph);

  // 3) Go to the Animal.h file and define some new subclasses of animal
  // Define one class that inherits from Animal and
  // one class that inherits from a child class of Animal
  
  //done
  

  // 4) Instantiate at least one object of each class you defined for #3
  Doggo cayde("Doggo");
  std::cout << cayde.MakeSound() << std::endl;

  Puppo lilCayde("lilDoggo");
  std::cout << lilCayde.MakeSound() << std::endl;
  
  // 5) Have a tournament between the animals that you have instantiated 
  cayde.Race(lilCayde);
  lilCayde.Race(ralph);
  ralph.Race(test);
  test.Race(cayde);


  // 6) turn in Animal.h and main.cpp on canvas
    
	return 0;
}
