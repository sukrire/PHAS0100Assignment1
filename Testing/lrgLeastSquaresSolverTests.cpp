#include "catch.hpp"
#include "lrgCatchMain.h"
#include "lrgLinearDataCreator.h"
#include <iostream>
#include <vector>


TEST_CASE( "create a class", "[Linear Data Creator]") {
  DataImporter test1(5,5,5);
  std::vector<std::pair<double, double> >var1 = test1.GetData();
    REQUIRE( var1[0].first == 0);
}

TEST_CASE( "check size of returned X_Y", "[Linear Data Creator]") {
   DataImporter test2(1,1,100);
   std::vector<std::pair<double, double> >var2 = test2.GetData();
     REQUIRE(var2.size() == 100);
 }

TEST_CASE( "check mean of X_Y", "[Linear Data Creator]") {
   DataImporter test3(1,0,100);
   std::vector<std::pair<double, double> >var3 = test3.GetData();
   int avg;
   int sumTotal = 0;
     for(int k=0; k < 100; ++k){
         sumTotal += var3[k].first;
     }
     avg = sumTotal / var3.size();
     REQUIRE(avg == 51);
}