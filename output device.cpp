#include<iostream>
using namespace std;

class output_device{
private:
    string buffer="0000";
public:
    void write(){
        string s;
        cin>>s;
        buffer=s;

    }
    void clear(){
        buffer="0000"
    }

    string getOutput(){
        return buffer;
    }

};
