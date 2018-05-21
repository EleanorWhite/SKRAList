#include "skralist.hpp"
#include <iostream>


void assert(bool b) 
{
    if (!b) { throw(1); }
}



int main() {

   Skralist* skrl = new Skralist();
   
   // push 1-10
   for (int i = 0; i < 10; ++i) {
       skrl->pushElem(i);
       assert(skrl->head() == i);
   }
   std::cout << "Successfully pushed 0-9\n";
  
   // check all 10 elems are there
   for (int i = 0; i < 10; ++i) {
       assert(skrl->getElem(i) == (9-i));
   }
   std::cout << "Successfully checked that 0-9 are in list\n";

   return 0;

}
