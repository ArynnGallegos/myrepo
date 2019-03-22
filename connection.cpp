#include "connection.h"

Connection::Connection(){
    // I'm already done! 
    set_connection();
}


Connection::~Connection(){
    // TODO: Complete me!
    delete birthdate;
    delete email;
    delete phone;
}


Connection::Connection(string fname, string lname, \
        string bdate, string email, string phone){
    // TODO: Complete this method!
    // phone and email strings are in full version
   this->f_name = fname;
   this->l_name = lname;
   this->birthdate = new Date(bdate);
   //email: 
   string type1 = email.substr(1,email.rfind(')') - 1);
   email = email.substr(email.rfind(')') + 1);
   this->email = new Email(type1,email);
   //phone:
   string type2 = phone.substr(1,phone.rfind(')')-1);
   phone = phone.substr(phone.rfind(')')+2);
   this->phone = new Phone(type2,phone);
    
    
}


Connection::Connection(string filename){
    // TODO: Complete this method!
    set_connection(filename);
}


void Connection::set_connection(){
    // prompts for the information of the user
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    // TODO: complete this method!
    string temp;
    string type;

    cout << "First Name: ";
    std::getline (std::cin,f_name);
	cout << "Last Name: ";
    std::getline (std::cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline (std::cin,temp);
    birthdate = new Date(temp);
    
    cout << "Type of email address: ";
    std::getline (std::cin, type);
    cout << "Email address: ";
    std::getline (std::cin,temp);
    email = new Email(type,temp);

    cout << "Type of phone number: ";
    std::getline (std::cin, type);
    cout << "Phone number: ";
    std::getline (std::cin, temp);
    phone = new Phone(type,temp);
}


void Connection::set_connection(string filename){
    // TODO: Complete this method!
    // Look at connection_template files as examples.     
    // Phone number in files can have '-' or not.
    string temp, type;
    // Open the file <filename>
    ifstream infile;
    infile.open (filename.c_str());
    // Line #1: first name and last name
    string tt;
    std::getline(infile, tt);
    int l = tt.length();
    int index = tt.find(',');
    l_name = tt.substr(0,index);
    f_name = tt.substr(index+2,l-index-2);
    // Line #2: date of birth in string format
    std::getline(infile, temp);
    birthdate = new Date(temp);
    //Line #3: (email type) email
    std::getline(infile, temp);
    type = temp.substr(1,temp.rfind(')') - 1);
    temp = temp.substr(temp.rfind(')') + 1);
    email = new Email(type,temp);
    //Line #4: (phone type) phone number
    std::getline(infile, temp);
    type = temp.substr(1,temp.rfind(')') - 1);
    temp = temp.substr(temp.rfind(')') + 2);
    phone = new Phone(type, temp);    
}


bool Connection::operator==(const Connection& rhs){
    // TODO: Complete this method!
    // Note: Difference to Lab is that from now on the combination of fname-lname is unique for any connection
    if ( (this->f_name == rhs.f_name) && 
         (this->l_name == rhs.l_name))
        return true;
    else
        return false;
}


bool Connection::operator!=(const Connection& rhs){ 
    // TODO: Complete this method!
    return !(*this == rhs);
}


void Connection::print_connection(){
    // Already implemented for you! Do not change!
	cout << l_name <<", " << f_name << endl;
	birthdate->print_date("Month D, YYYY");
    email->print();
    phone->print();
}

