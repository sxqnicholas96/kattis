#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N,numaddr,interval,first,last,i,counter;
	string roadname,buffer,line,num;
	char plus;
	vector<int> digits;

	cin >> N;cin.get();

	while(N--){
		counter = 0;
		digits.clear();
		digits.assign(10,0);
		getline(cin,roadname);
		cin >> numaddr >> buffer;cin.get();
		cout << roadname << endl;

		while(counter != numaddr){
			getline(cin,line);
			stringstream ss(line);
			if(line[0] == '+'){
				ss >> plus;
				ss >> first >> last >> interval;
				for(i=first;i<=last;i += interval){
					stringstream ss1;
					string lol;
					ss1 << i;
					ss1 >> lol;
					for(auto it: lol){	
						digits[it-'0']++;
					}
					counter++;
				}
			}
			else{
				ss >> num;
				for(auto it: num){
					digits[it-'0']++;
				}
				counter++;

			}
		}
		cout << numaddr << (numaddr == 1 ? " address":" addresses") << endl;
		int sum = 0;
		for(i=0;i<digits.size();i++){
			cout << "Make " << digits[i] << " digit " << i << endl;
			sum += digits[i];
		}	
		cout << "In total " << sum << (sum == 1 ?" digit":" digits") << endl;

	}
}