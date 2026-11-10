#include<iostream>
using namespace std;

class registers{
private:
    string bytes[16];

    int hexa_transelator(char c){
        if(c=='0'){
            return 0;
        }
        else if(c=='1'){
            return 1;
        }
        else if(c=='2'){
            return 2;
        }
        else if(c=='3'){
            return 3;
        }
        else if(c=='4'){
            return 4;
        }
        else if(c=='5'){
            return 5;
        }
        else if(c=='6'){
            return 6;
        }
        else if(c=='7'){
            return 7;
        }
        else if(c=='8'){
            return 8;
        }
        else if(c=='9'){
            return 9;
        }
        else if(c=='A'){
            return 10;
        }
        else if(c=='B'){
            return 11;
        }
        else if(c=='C'){
            return 12;
        }
        else if(c=='D'){
            return 13;
        }
        else if(c=='E'){
            return 14;
        }
        else if(c=='F'){
            return 15;
        }
        return 0;
    }

public:
    string read(string s){
        string code;
        int adrss;
        adrss=hexa_transelator(s[0]);
        code=bytes[adrss];
        return code;
    }

    void write(string s,string s1){
        int adrss;
        adrss=hexa_transelator(s[0]);
        bytes[adrss]=s1;
    }

    void clear()){
        for(int i=0;i<16;i++){
            bytes[i]="00";
        }
    }



};
