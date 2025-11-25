
#include <iostream>
#include "keyStore.h"

int main()
{
    std::cout << "Welcome to Karls Keys" << std::endl;
    std::cout << "An attempt at a key value database" << std::endl;
    KeyStore k("Ks keys");

    vector<string> options= {"Get (input key)", "Put (string key, int value )", 
    "Begin Transaction", "Rollback", 
    "Commit", "See staging", 
    "See system", "Take a break (exit)"};
    int op;
    string key; 
    int val;

    cout <<  "Pick the given index" << endl;
    for(int i = 0; i < options.size(); i++){
        cout << i + 1 << ". " << options[i] << endl;
    }


    int cont = true;
    while(cont){

        cin >> op ;

        switch(op){
            case 1:
                cout << "Enter Key: "; 
                cin >> key;
                cout << endl;
                cout << "Key: "<< key<<", Value: " << k.get(key) << endl;
                break;
            case 2:
                cout << "Enter Key: "; 
                cin >> key;
                cout << endl;
                cout << "Enter Value: ";
                cin >> val;
                cout << endl;
                k.put(key, val);
                break;
            case 3:
                k.begin_transaction();
                break;
            case 4: 
                k.rollback();
                break;
            case 5:
                k.commit();
                break;
            case 6: 
                k.printStaging();
                break;
            case 7:
                k.printSysInfo();
                break;
            case 8: 
                cont = false;
                break; 
        }
    }

    std::cout << "Thank you for using Karls key store:)" << std::endl;
    
}