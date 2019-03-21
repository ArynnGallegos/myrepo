#include <iostream>
#include "contact.h"

using namespace std;

int main()
{
   Phone phone1("cell", "111-111-1111");
   Email email1("","");
   Phone phone2("","0123456789");
   
   phone1.print();
   cout<<"-----------------------\n";
   
   phone2.set_contact();
   phone2.print();
   
   
   /*email1.set_contact();
   email1.print();
   cout<<"-----------------------\n";*/
   
   Email email2("work", "aogalleg@usc.edu");
   email2.print();

}
