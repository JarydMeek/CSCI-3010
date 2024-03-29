#ifndef ANIMAL_H
#define ANIMAL_H

// Name(s):
// Jaryd Meek

class Animal {
public:
	Animal(std::string sound):
	sound_(sound)
	{}

	std::string MakeSound() const {return sound_; }

	void Race(Animal &opponent);

	virtual int GetSpeed() { return 0; };

private:
	std::string sound_;
};

class Reptile : public Animal {
public:
	Reptile(std::string sound):
	Animal(sound + " rawr!")
	{}

	int GetSpeed() { return 2; };

};

// Define your animals here.
// Define one class that inherits from Animal and
// one class that inherits from a child class of Animal

class Doggo : public Animal {
public:
	Doggo(std::string sound):
	Animal(sound + " bonk!")
	{}

	int GetSpeed() { return 69; };

};


class Puppo : public Doggo {
public:
	Puppo(std::string sound):
	Doggo(sound + " tiny bonk!")
	{}

	int GetSpeed() { return 6; };

};

#endif  // ANIMAL_H
