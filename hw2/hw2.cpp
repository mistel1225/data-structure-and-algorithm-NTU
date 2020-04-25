#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
	ifstream fin("CriteoSearchData");
	string x;
	string y;
	int j=0, datacnt=0, error=0;
	while(getline(fin, x, '\n')){
		j++;
		cout<<"******************************************************\ndata number:"<<j<<endl;
		y.clear();
		for(int i=0; i<x.length(); i++){
        	if(x[i]=='\t'){
				if(!y.empty())datacnt++;
				cout<<y<<'\t';
              	y.clear();
          	}
          	else{
              	y+=x[i];
          	}
      	}
		if(!y.empty()){
			cout<<y<<"\n";
			datacnt++;
		}
		if(datacnt==22){
			cout<<"error:datacnt is 22"<<endl;error++;
		}
		datacnt=0;
	}
	cout<<"total error number:"<<error<<endl;

	return 0;
}
