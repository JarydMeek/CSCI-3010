#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Circle.h"



TEST_CASE ( "Get Center", "[getCenter]") {
  Point center = Point();
  center.x = 0;
  center.y = 0;
  Circle test = Circle(center, 10);
  Point ret = test.get_center();
  REQUIRE( ret.x == 0 );
  REQUIRE( ret.y == 0 );

  Point center2 = Point();
  center2.x = 1;
  center2.y = 2;
  Circle test2 = Circle(center2, 1);
  Point ret2 = test2.get_center();
  REQUIRE( ret2.x == 1 );
  REQUIRE( ret2.y == 2 );
}

TEST_CASE ( "Overlaps", "[Overlaps]") {
  Point center = Point();
  center.x = 0;
  center.y = 0;
  Circle test = Circle(center, 10);

  Point center2 = Point();
  center2.x = 1;
  center2.y = 2;
  Circle test2 = Circle(center2, 1);

  Point center3 = Point();
  center3.x = 10;
  center3.y = 10;
  Circle test3 = Circle(center3, 1);

  REQUIRE(test.Overlaps(test2) == true );

  REQUIRE(test2.Overlaps(test3) == false);
}


TEST_CASE ( "Calculate Area", "[CalculateArea]") {
  Point center = Point();
  center.x = 0;
  center.y = 0;
  Circle test = Circle(center, 10);
  REQUIRE( test.CalculateArea() == 314 );
}

TEST_CASE ( "Expand", "[Expand]") {
  Point center = Point();
  center.x = 0;
  center.y = 0;
  Circle test = Circle(center, 10);
  test.Expand();
  REQUIRE( test.get_radius() == 11 );
  test.Expand();
  REQUIRE( test.get_radius() == 12 );
  test.Expand();
  REQUIRE( test.get_radius() == 13 );
}

TEST_CASE ( "Shrink", "[Shrink]") {
  Point center = Point();
  center.x = 0;
  center.y = 0;
  Circle test = Circle(center, 10);
  test.Shrink();
  REQUIRE( test.get_radius() == 9 );
  test.Shrink();
  REQUIRE( test.get_radius() == 8 );
  test.Shrink();
  REQUIRE( test.get_radius() == 7 );

  Point center2 = Point();
  center2.x = 0;
  center2.y = 0;
  Circle test2 = Circle(center2, 0);
  test2.Shrink();
  REQUIRE( test2.get_radius() == 0 );
}