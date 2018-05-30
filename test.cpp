#include "skralist.hpp"
#include <iostream>


void assert(bool b) 
{
    if (!b) { throw(1); }
}



int main() {

   Skralist* skrl = new Skralist();
   
   int numTest = 30;

   // push 0-numTest
   for (int i = 0; i < numTest; ++i) {
       skrl->pushElem(i);
       assert(skrl->head() == i);
   }
   std::cout << "Successfully pushed 0-" << (numTest-1) << "\n";
  
   // check all 10 elems are there
   for (int i = 0; i < numTest; ++i) {
       assert(skrl->getElem(i) == ((numTest-1)-i));
   }
   std::cout << "Successfully checked that 0-" << (numTest-1) << " are in list\n";

   int j = numTest;
   for (auto it = skrl->begin(); it != skrl->end(); ++it) {
       j--;
       assert(*it == j);
   }
   std::cout << "Successfully checked that 0-" << (numTest-1) << " were iterated through\n";


   for (int i = numTest-1; i >= 0; --i) {
       assert(skrl->pop() == i);
   }
   std::cout << "Successfully checked that 0-" << (numTest-1) << " were popped\n";


   // push 0-numTest
   for (int i = 0; i < numTest; ++i) {
       skrl->pushElem(i);
       assert(skrl->head() == i);
   }
   std::cout << "Successfully pushed 0-" << (numTest-1) << "\n";

   for (int i = 0; i < numTest; ++i) {
       Skralist copySkrl = *skrl;
       copySkrl.drop(i);
       assert(copySkrl.head() == (numTest-i-1));
       //assert(copySkrl->size == numTest-i);
   }
   std::cout << "Successfully tested drop\n";

   return 0;

}
