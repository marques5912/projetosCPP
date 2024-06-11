#include <iostream>
#include <fstream>

using namespace std;

//Classe login + instancia objLogin
class Login{
    //Atributos
    string userName , email , password;
    string searchName , searchEmail , searchPassword;
    fstream file; //instacia de um arquivo
    //Métodos
    public:
    void login();
    void signUp();
    void forgot();

}objLogin;


int main(){
    //variavel de leitura
    char choice;

    //Cabeçalho
    cout << "\n\tMenu";
    cout << "\n1 - Login";
    cout << "\n2 - SignUp";
    cout << "\n3 - Forgot Password";
    cout << "\n4 - Exit";
    cout << "\n Enter your choice";

    //Leitura teclado
    cin >> choice;

    switch(choice){
        case '1':
            cin.ignore(); //é usado o cin.ignore para ignorar o \n deixado pelo "enter" ao selecionar a opção desejada
            objLogin.login();
        break;

        case '2':
            cin.ignore();
            objLogin.signUp();
        break;

        case '3':
            cin.ignore();
            objLogin.forgot();
        break;

        case '4':
            return 0;
        break;

        default:
        cout << "\n invalid choice";
    }
}

void Login :: signUp(){
    //Leitura
    cout << "enter your user name :: ";
    getline(cin,userName);
    cout << "enter yout email :: ";
    getline(cin,email);
    cout << "enter yout password :: ";
    getline(cin,password);

    //Manipulação de arquivo
    //file é o nome da instancia do objeto da classe fstream (ele foi instanciado na classe login)
    //metodo open abre um arquivo,caso o mesmo não exista ele será criado
    // ios :: out --> Modo de saída, indica que o arquivo sera aberto para escrita
    // ios :: app --> Modo de adição, indica que os dados serão escritos no final do arquivo,sem sobrescrever(override) o conteudo pré existente n oarquivo
    // diferença entre \n e endl == \n insere uma nova linha e não garante que os dados do buffer de saída seja descarregado imediatamente, diferente do endl que força o descarregamento imediato dos dados,isso garante que os dados sejam mais consistente,principalmente em arquivos.
    file.open("login.txt",ios :: out | ios :: app);
    file<<userName<<"*"<<email<<"*"<<password<<endl;
    file.close();

}

void Login :: login(){
    /*
    Diferença entre o cin e o getline:
    cin é usado para ler entrada de dados ate encontrar
    um espaço em branco (espaço,tabulação ou \n)
    em casos de utilizar o cin é importante utilizar o cin.ignore para limpar os dados do buffer de entrada
    */


    cout << " \nenter your user name"<< endl;
    getline(cin,searchName);
    cout << "\nenter your password"<<endl;
    getline(cin,searchPassword);

    file.open("login.txt", ios :: in); //abre o arquivo login no modo de leitura
    getline(file,userName,'*');
    getline(file,email,'*');
    getline(file,password,'\n');
    while(!file.eof()){//file.eof() le o arquivo e retorna verdadeiro no final do arquivo,se usarmos o negador,retorna verdadeiro caso não seja o eof
        if(userName == searchName){
            if(password == searchPassword){
                cout << "\n login succesfull !!";
                cout << "\n Username :: "<<userName;
                cout <<"\n Email :: "<<email;
            }
        }

        getline(file,userName,'*');
        getline(file,email,'*');
        getline(file,password,'\n');

    }
    file.close();
}

void Login :: forgot(){
}



