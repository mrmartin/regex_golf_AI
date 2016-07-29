#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main (int argc, char * argv[]){
    if(argc!=3){
        cout << "usage: " << argv[0] << " number_of_strings repstring" << endl;
    }else{
        srand (time(NULL));
        for (int j=0;j<atoi(argv[1]);j++){
            for (int i=0;i<(rand()%4);i++)
                cout << char(97+rand()%26);
            cout << argv[2];
            for (int i=0;i<(rand()%4);i++)
                cout << char(97+rand()%26);
            cout << endl;
        }
    }
    return 0;
}