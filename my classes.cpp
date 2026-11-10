#include<iostream>
using namespace std;


class memory{
private:
    string bytes[16][16];
public:
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


    string read (string s){
        int adrss[2];
        string code;
        for(int i=0;i<2;i++){
            adrss[i]=hexa_transelator(s[i]);
        }

        code=bytes[adrss[0]][adrss[1]];

        return code;
    }


    void write(string s,string s1){
        int adrss[2];
        for(int i=0;i<2;i++){
            adrss[i]=hexa_transelator(s[i]);
        }
        bytes[adrss[0]][adrss[1]]=s1;
    }
    void clear(){
        for(int x=0;x<16;x++){
            for(int y=0;y<16;y++){
                bytes[x][y]="00";
        }
    }
    }

};
