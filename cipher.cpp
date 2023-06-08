#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    
    string message;
    cout << "Enter the message you would like to encode" << endl;
    getline(cin, message);
    
    for(size_t i{0}; i < message.length(); ++i){
        char substr = message.at(i);
        if(isalpha(substr)){
            int posAlpha=alphabet.find(substr);
            string secretLetter = key.substr(posAlpha, 1);
            message.replace(i, 1, secretLetter);
        }
    }
    
    cout<< "\nThe message is being encoded...\n"<< endl;
    
    cout<< "Your secret message is: " + message <<endl;
    
    cout<< "\nReversing the encoding...\n" << endl;
    
    for(size_t i{0}; i < message.length(); ++i){
        char substr = message.at(i);
        if(isalpha(substr)){
            int posKey=key.find(substr);
            string secretLetter = alphabet.substr(posKey, 1);
//            cout<< secretLetter+ " " << posAlpha<<endl;
            message.replace(i, 1, secretLetter);
        }
    }
    
    cout << "Your decoded message is: " + message;
    
    cout << endl;
    return 0;
}