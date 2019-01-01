#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main(){
	cout << "Hello!\n";
	ifstream file("data");
	string currLine;
	int lineCount = 0;
	int twoCount = 0;
	int threeCount = 0;
  vector<pair<char,int>> charList;
	vector<string> strList;
	if(file.is_open()){
    while(getline(file, currLine)){
    strList.push_back(currLine);
    charList.clear();
    lineCount++;
    for(int i=0; i<currLine.size(); i++){
      char c = *(currLine.c_str()+i);
      bool found = false;
      for(int j=0; j < charList.size(); j++){
        if(charList[j].first==c) {
				  charList[j].second++;
					found=true;
					break;
				}
      }
			if(!found)
        charList.push_back(pair<char,int>(c,1));
      //cout << c;
    }
    //cout << endl;
		bool two = false;
		bool three = false;
		for(int i=0; i < charList.size(); i++){
      char c = charList[i].first;
      int count = charList[i].second;
			if(count == 2 && !two) {
        two = true;
				cout << "(" << c << ") Two! ";
      } else if(count == 3 && !three) {
        three = true;
				cout << "(" << c << ") Three! ";
      }
		}
		if(two || three)
		  cout << "\nList :" << currLine << endl;
		if(two)
      twoCount++;
		if(three)
      threeCount++;
		}
	}
	cout << "Number of lines: " << lineCount
					<< "\nTwo: " << twoCount
					<< "\nThree: " << threeCount
					<< "\nChecksum: " 
					<< twoCount * threeCount
					<< endl;

	bool found = false;
	pair<int,int> f;

	for(int i=0; i < strList.size() && !found; i++) {
    for(int j=i+1; j < strList.size(); j++) {
      int miss = 0;
      for(int k=0; k < strList[i].size(); k++) {
        if(*(strList[i].c_str()+k) !=
				  *(strList[j].c_str()+k)) {
				  miss++;
					if(miss>1)
				    break;
				}
			}
      if(miss==1) {
        f.first = i;
				f.second = j;
				found = true;
				break;
			}
		}
	}
  if(found) {
    cout << "Found at " << f.first
      << " and " << f.second
			<< ":\n"
			<< strList[f.first] << endl
			<< strList[f.second] << endl;
	}
	return 0;
}
