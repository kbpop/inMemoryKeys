#include <string>
#include <queue>
#include <map>

using namespace std;

class KeyStore{

    private:
        // name of the current KeyStore instance
        string name;
        
        // flag for if there is currently a transaction in progress
        bool transInProg;

        // transaction includes any sort of action a user can take
        // transactions->staging->store

        // precommit instructions
        queue<pair<string, int>> staging;

        // main state
        map<string, int> store;

    public:
        KeyStore(string name);

        // can always be called
        int get(string key);

        // can only be called during transaction
        void put(string key, int val);

        // start the transaction
        void begin_transaction();

        // end staging 
        void commit();
        void rollback();

        // system Utils
        void printStaging();
        void printSysInfo();
};

// Keystore constructor
KeyStore::KeyStore(string name){
    this->name = name;
    bool transInProg = false;
    staging = {};
    store = {};
}


/******************************************* Core Transactions *********************************************/ 
void KeyStore::begin_transaction(){

    if(transInProg){
        cout <<"First abort the currrent ongoing transaction :o"<< endl; 
        return ;
    } 
    cout << "Beginning Transaction" << endl;

    transInProg = true;
    // reset staging just in case
    staging = {};
}

// Put operation
void KeyStore::put(string key, int val){

    cout << "completing a put of key: " << key << " with val: " << val << endl;

    if(!transInProg){
        throw std::runtime_error("A transaction must be in progress to make a put request");
        return ;
    }

    staging.push({key, val});
    return ;

}

// get operation
int KeyStore::get(string key){
    cout << "completing a get of key: " << key << endl;

    // found
    if(store.count(key)){
        return store[key];
    } 

    // not found
    return NULL;
}

void KeyStore::rollback(){

    cout << "completing a rollback" << endl;

    staging = {};
    transInProg = false;
}

void KeyStore::commit(){

    cout << "Commit in progress" << endl;

    while(!staging.empty()){
        auto curr = staging.front();
        staging.pop();
        store[curr.first] = curr.second;
    }

    transInProg = false;

    cout << "Commit Completed" << endl;
    return;
}



/******************************************* system Utils *********************************************/ 
void KeyStore::printStaging(){
    auto tempQ = staging;

    while(!tempQ.empty()){
        auto curr = tempQ.front();
        tempQ.pop();
        cout << "Key: " << curr.first << ", Value: " << curr.second << endl; 
    }

    return ;
}

void KeyStore::printSysInfo(){
 
    cout << "Name: " << name << endl;
    cout << "Transaction running: (boolalpha)" << transInProg << endl;
    cout << "Size of Store: " << store.size() << endl;
    cout << endl;

    return ;
}




