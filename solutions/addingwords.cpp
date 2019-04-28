#include <bits/stdc++.h>
using namespace std;
 
int main(void){
    string str, def_str = "def", clear_str = "clear", str1, str2;
    unordered_map< string, int > umap1;
    unordered_map< int, string> umap2;
    char ch;
    int num, sum=0;
    int all_known=1;
    int plus_or_minus=0;    // 1 for plus, 0 for minus
 
    while( cin >> str){
        if( str == clear_str){
            umap1.clear();
            umap2.clear();
        }
        else if( str == def_str){
            cin >> str >> num;
            if( umap1.find(str) != umap1.end())
                umap2.erase( umap1[str]); // umap 2 needs to be cleaned up. using it to check for validity
 
                umap1[str] = num;   // can leave redundant entries for umap1. not using it to check for validity. lazy.
                umap2[num] = str;
        }
        else{   // calculate
            cin >> str; // guaranteed at least 1 starting term
            if( umap1.find(str) == umap1.end())
                all_known=0;
            else
                sum += umap1[str];
            cout << str << " ";
            cin >> str;
 
            while( str != "="){
                cout << str << " ";
 
                plus_or_minus = str=="+"?1:0;
                cin >> str;
                if( umap1.find(str) == umap1.end())
                    all_known=0;
                else{
                    if(plus_or_minus)   // 1 for plus, 0 for minus
                        sum += umap1[str];
                    else
                        sum -= umap1[str];
                }
                cout << str << " ";
                cin >> str;
            }
            if( !all_known || umap2.find(sum) == umap2.end())
                cout << "= unknown" << endl;
            else
                cout << "= " << umap2[sum] << endl;
        }
        // reset
        sum = 0;
        all_known = 1;
    }
    return 0;
}
