#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class LoginFrom{
	public:
	 string username, password;
    LoginFrom(string email,string pass){
    	username=email;
    	password=pass;
	}
void userReg(){

    ifstream inputFile("login.txt");
    if (!inputFile) {
        cout << "Error opening file" << endl;
        return ;
    }
    bool userExists = false;
    string line;
    string str =username+password;
    while (inputFile >> line ) {
	    	
        if (line == str) {
            userExists = true;
            break;
        }
    }
    inputFile.close();
    if (userExists) {
        cout << "Login SuccessFully" << endl;
        return ;
    }

    ofstream outputFile("login.txt", ios::app);
    if (!outputFile) {
        cout << "Error opening file" << endl;
        return ;
    }
    outputFile << username << "" << password << endl;
    outputFile.close();
    cout << "userCreate Successfully" << endl;
};
};

int main() {
	 string username;
    string password;
	cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
	LoginFrom Logic(username,password);
	Logic.userReg();
   
    return 0;
}


