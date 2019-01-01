#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
  int fab[1000][1000] = {0};
	int claim[1000][1000] = {0};
	int nrList[1400] = {0};
  
  fstream file("data");
	int nr, x, y, w, h;
	string t;
	if(file.is_open()) {
    while(!file.eof()) {
      getline(file, t, '#');
      file >> nr;
      getline(file, t, '@');
      file >> x;
      getline(file, t, ',');
      file >> y;
      getline(file, t, ':');
      file >> w;
      getline(file, t, 'x');
      file >> h;
      getline(file, t);
      
			cout << nr << endl;
			for(int i=x-1; i < x-1+w; i++)
        for(int j=y-1; j < y-1+h; j++) {
          fab[i][j]++;
          if(claim[i][j] == 0)
            claim[i][j] = nr;
					else {
            nrList[claim[i][j]]++;
						nrList[nr]++;
				  }
				}

    }
	}
	int count = 0;
	for(int i = 0; i < 1000; i++)
    for(int j = 0; j < 1000; j++) {
      if(fab[i][j] > 1)
        count++;
		}
	cout << "Square inches of fabric: "
    << count << endl;

  int claimNr;
	for(claimNr=1; claimNr <= nr; claimNr++)
    if(nrList[claimNr]==0)
      break;
	cout << "Claim Number: " << claimNr << endl;

	//cout << nr << x << y << w << h << endl;
	cout << "Somehow made it through...\n";
	return 0;
}
