
#include "contact.h"
#include <algorithm>
#include <string>
#include <sstream>
// TODO: Add needed libraries! 

Email::Email(string type, string email_addr){
    // TODO: Complete me!
    this->type = type;
    this->email_addr = email_addr;
}


void Email::set_contact(){
    // TODO: Do not change the prompts!
	 string t;
	 string address;
    cout << "Enter the type of email address: ";
    cin>>t;
    this->type = t;
    cout << "Enter email address: ";
    cin>>address;
    this->email_addr = address;
}


string Email::get_contact(string style){
    // Note: We have default argument in declaration and not in definition!
    if (style=="full")
	    return "(" + type + ") " + email_addr;
    else 
        return email_addr;
}


void Email::print(){
    // Note: get_contact is called with default argument
	cout << get_contact("full") << endl;
}


Phone::Phone(string type, string num){
    // TODO: It is possible that num includes "-" or not, manage it!
    // TODO: Complete this method!
    // Note: We don't want to use C++11! stol is not valid!
    // The code has been covered in the discussion session

    /* Note: Understand your own TA's bug!
     * This code has a bug, can you understand why?
    long int area_code = atoi(num.substr(0, 3).c_str());
    long int  number = atoi(num.substr(3).c_str()); 
    this->phone_num = area_code*10000000 + number; 
    */
    long int area_code;
    long int num2;
    long int num3;
    this->type = type;
    num.erase(remove(num.begin(), num.end(), '-'), num.end()); 
    area_code = atoi(num.substr(0,3).c_str());
    num2 = atoi(num.substr(3,3).c_str());
    num3 = atoi(num.substr(6,4).c_str());
    
    long int final_num = area_code*10000000 + num2*10000 + num3;
    
    this->phone_num = final_num;   
    
}


void Phone::set_contact(){
    // TODO: Complete this method
    // Use the same prompts as given!
    string t;
    string number;
    long int area_code, num2, num3;
	cout <<"Enter the type of phone number: ";
	cin>>t;
	this->type = t;
	cout << "Enter the phone number: ";
	cin>>number;
	number.erase(remove(number.begin(), number.end(), '-'), number.end()); 
    area_code = atoi(number.substr(0,3).c_str());
    num2 = atoi(number.substr(3,3).c_str());
    num3 = atoi(number.substr(6).c_str());
    
    long int final_num = area_code*10000000 + num2*10000 + num3;
    
    this->phone_num = final_num;
}


string Phone::get_contact(string style){
    // TODO: Complete this method, get hint from Email 
    // The code has been covered in discussion session 

    /* Note: Understand your own TA's bug!
     * This code has a bug, can you understand it!
    int x1 = (phone_num/10000000);
	int x2 = ((phone_num)/10000)%1000;
	int x3 = phone_num%10000;
    */ 
    stringstream s;
    s<<this->phone_num;
    string phone = s.str();
    if(style == "full")
    {
      return "(" + type + ") " + phone.substr(0,3) + "-" + phone.substr(3,3) + '-' + phone.substr(6);
    }
}


void Phone::print(){
    // Note: get_contact is called with default argument
	cout << get_contact("full") << endl;
}


