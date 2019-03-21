#include <iostream>
#include "connection.h"

using namespace std;

int main()
{
   Connection c1;
   c1.print_connection();
   cout<<"------------------------\n";
   
   c1.set_connection("networkDB.db");
   c1.print_connection();
   
   return 0;
}
