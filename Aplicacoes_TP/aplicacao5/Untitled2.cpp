#include <iostream>
#include <string>

using namespace std;

bool verificador(const string& nome){
	for(char c : nome){
		 if(!isalpha(c) && !isspace(c)){
		 	return false;
		 }
	}
	return true;
}
void set_name(){
	
	string extern name_ex;
	bool extern na;
	cin >> name_ex;
	na = verificador(name_ex);
}