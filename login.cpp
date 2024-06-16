#include <iostream>
#include <fstream>

using namespace std;

class Login{
    //atributes
    string user,password,email;
    string searchUser,searchPassword,searchEmail;

    //files
    fstream file;

    //Functions
public:
    void fLogin();
    void fRegister();
    void fForgot();
}objLogin;

int main() {

    cout << "\n\t MENU" << endl;
    cout << "\n\t 1 - LOGIN"<< endl;
    cout << "\n\t 2 - REGISTER"<< endl;
    cout << "\n\t 3 - FORGOT"<< endl;
    cout << "\n\t 4 - EXIT"<< endl;

    char choice;
    cin >> choice;

    switch(choice){

        case '1':
            cin.ignore();
            objLogin.fLogin();
            break;
        case '2':
            cin.ignore();
            objLogin.fRegister();
            break;
        case '3':
            cin.ignore();
            objLogin.fForgot();
            break;
        case '4':
            return 0;
            break;

        default:
            cin.ignore();
            cout << "Invalid choice";
    }
}

void Login::fLogin() {

    cout << "\n\t LOGIN" <<endl;
    cout << "\n enter your user name"<<endl;
    cin >> searchUser;
    cin.ignore();
    cout << "\n enter your password"<<endl;
    cin >> searchPassword;
    cin.ignore();

    file.open("login.txt" , ios :: in );
    getline(file,user,'*');
    getline(file,email,'*');
    getline(file,password,'\n');

    while(!file.eof()){
        if(user == searchUser){
            if(password == searchPassword){
                cout << "congratulations" << endl;
            }
            else{
                cout << "INVALID FORGOT YOUR ACCOUNT" << endl;
            }
        }
        getline(file,user,'*');
        getline(file,email,'*');
        getline(file,password,'\n');
    }
    file.close();
}

void Login::fForgot() {
    cout << "\n\tFORGOT PASSWORD"<< endl;
    cout << "\nenter your user"<<endl;
    getline(cin,searchUser);
    cout << "\nenter your email"<<endl;
    getline(cin,searchEmail);

    file.open("login.txt" , ios :: in);
    getline(file,searchUser,'*');
    getline(file,searchEmail,'*');
    getline(file,password,'\n');

    while(!file.eof()){
        if(user == searchUser){
            if(email == searchEmail){
                cout<<"congratulations";
            }
        }
        getline(file,searchUser,'*');
        getline(file,searchEmail,'*');
        getline(file,password,'\n');
    }
    file.close();


}

void Login::fRegister() {
    cout<<"\n\tREGISTER"<<endl;
    cout<<"\nenter your user"<<endl;
    getline(cin,user);
    cout<<"\nenter your email"<< endl;
    getline(cin,email);
    cout<<"\nenter your password"<<endl;
    getline(cin,password);

    bool flag = true;

    file.open("login.txt" , ios :: in);
    getline(file,searchUser,'*');
    getline(file,searchEmail,'*');
    getline(file,password,'\n');
    while(!file.eof()){
        if(user == searchUser){
            cout << "user invalid" << endl;
            flag = false;
        }
        if(email == searchEmail){
            cout << "email invalid" << endl;
            flag = false;
        }
        getline(file,searchUser,'*');
        getline(file,searchEmail,'*');
        getline(file,password,'\n');
    }
    file.close();

    if(flag){
        file.open("login.txt", ios :: out | ios :: app);
        file<<user<<"*"<<email<<"*"<<password<<endl;
        file.close();
    }
}
