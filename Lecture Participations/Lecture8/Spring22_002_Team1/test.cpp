#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions_to_implement.cpp"
#include <vector>

TEST_CASE ( "Sign of int", "[sign]") {
  REQUIRE( Sign(0) == 1 );
  REQUIRE( Sign(1) == 1 );
  REQUIRE( Sign(-10) == -1 );
  REQUIRE( Sign(-1000000) == -1 );
  REQUIRE( Sign(100000) == 1 );
}

TEST_CASE("Sum of vector", "[sum]"){

	SECTION("checking with {1,2,3,5,6,7,8,10}"){
		std::vector<int> v{1,2,3,5,6,7,8,10};
		std::vector<int> unchanged{1,2,3,5,6,7,8,10};
		int testv1 = Sum(v);

		REQUIRE(testv1 == 42);
		REQUIRE( v == unchanged );
	}
}


TEST_CASE ( "Join vectors", "[join]") {
	std::vector<std::string> test{"This", "Is", "A", "Test"};

  	REQUIRE( Join(test, " ") == "This Is A Test" );
}

TEST_CASE("RemoveTwos", "[RemoveTwos]"){
	REQUIRE( RemoveTwos(16) == 1 );
}