#include <bits/stdc++.h>
using namespace std;

int main(void){
    string jon;
    string doc;

    cin >> jon >> doc;

    if(strcmp(jon.c_str(),doc.c_str()) > 0){
        cout << "no" << endl;
    }
    else{
        cout << "go" << endl;
    }
}