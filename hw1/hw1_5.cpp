#include <cstdlib>
#include <iostream>
#include <fstream>
//#include <fstream.h>
using namespace std;


class GCD{
	public:
		void swap();
		GCD(){
			ans = new unsigned int;
			cnt = new unsigned int;
		}
		int GCD_def(const unsigned int m,const unsigned int n);
		int GCD_reverse(const unsigned int m,const unsigned int n);
		int GCD_binary(const unsigned  int m,const unsigned int n);
		int GCD_euclid(const unsigned int m,const unsigned int n);
		unsigned int x, y;
		unsigned int *ans, *cnt;
};

void GCD::swap(){
	unsigned int tmp = x;
	x = y;
	y = tmp;
}

int GCD::GCD_def(const unsigned int m,const unsigned int n){
	/*ans = new unsigned int;
	cnt = new unsigned int;*/
	*ans = 1;
	*cnt = 0;
	for(unsigned int i=1; i<=x; i++){
		if(x%i==0&&y%i==0)
			*ans = i;
		(*cnt)++;
	}

	//cout<<"Case ("<<m<<", "<<n<<"): GCD-By-Def = "<<*ans<<", taking "<<*cnt<<" iterations"<<endl;
	/*delete ans;
	delete cnt;*/
	return *cnt;
}

int GCD::GCD_reverse(const unsigned int m,const unsigned int n){
	/*ans = new unsigned int;
        cnt = new unsigned int;*/
        *ans = 1;
        *cnt = 0;
        for(unsigned int i=x; i>=1; i--){
                (*cnt)++;
		if(x%i==0&&y%i==0){
                        *ans = i;
			break;
		}
        }
        //cout<<"Case ("<<m<<", "<<n<<"): GCD-By-Reverse-Search = "<<*ans<<", taking "<<*cnt<<" iterations"<<endl;
        /*delete ans;
        delete cnt;*/
        return *cnt;
}

int GCD::GCD_binary(const unsigned int a, const unsigned int b){
	/*ans = new unsigned int;
	cnt = new unsigned int;*/
	unsigned int n = x, m = y;
	*ans = 1;
	*cnt = 0;
	while(n!=0&&m!=0){
		(*cnt)++;
		if(n%2==0&&m%2==0){
			*ans = *ans * 2;
			n /= 2;
			m /= 2;
		}
		else if(n%2==0&&m%2!=0)
			n /= 2;
		else if(n%2!=0&&m%2==0)
			m /= 2;
		if(n>m){
			unsigned int tmp = n;
			n = m;
			m = tmp;
		}
		m = m-n;
	}
        //cout<<"Case ("<<a<<", "<<b<<"): GCD-By-Binary = "<<(*ans)*n<<", taking "<<*cnt<<" iterations"<<endl;
	/*delete ans;
	delete cnt;*/
	return *cnt;
}

int GCD::GCD_euclid(const unsigned int a, const unsigned int b){
	/*cnt = new unsigned int;*/
	*ans = 1;
	*cnt = 0;
	unsigned int n = x,  m = y;
	while(m%n!=0){
		(*cnt)++;
		unsigned int tmp=n;
		n = m%n;
		m = tmp;
	}
        //cout<<"Case ("<<a<<", "<<b<<"): GCD-By-Euclid = "<<n<<", taking "<<*cnt<<" iterations"<<endl;
	/*delete cnt;*/
	return *cnt;
}


int main(){	
	unsigned int m=1, n=1;
	ifstream fin("input.txt");
	ofstream fout("output1.txt");
        ofstream fout2("output2.txt");
        ofstream fout3("output3.txt");
        ofstream fout4("output4.txt");
	GCD test;
	while(1){
		fin>>m;
		if(!m) break;
		fin>>n;
		test.x = m;
		test.y = n;
		if(test.x > test.y)
			test.swap();
		fout<<test.GCD_def(m, n)<<endl;
		//test.GCD_reverse(m, n);
		//test.GCD_binary(m, n);
		//test.GCD_euclid(m, n);
	}
	fin.seekg(ios_base::beg);
	fout.close();
        while(1){
                fin>>m;
                if(!m) break;
                fin>>n;
                test.x = m;
                test.y = n;
                if(test.x > test.y)
                        test.swap();
                fout2<<test.GCD_reverse(m, n)<<endl;
                //test.GCD_reverse(m, n);
                //test.GCD_binary(m, n);
                //test.GCD_euclid(m, n);
        }
	fin.seekg(ios_base::beg);
	fout2.close();
	while(1){
                fin>>m;
                if(!m) break;
                fin>>n;
                test.x = m;
                test.y = n;
                if(test.x > test.y)
                        test.swap();
                fout3<<test.GCD_binary(m, n)<<endl;
                //test.GCD_reverse(m, n);
                //test.GCD_binary(m, n);
                //test.GCD_euclid(m, n);
        }
	fin.seekg(ios_base::beg);
	fout3.close();
        while(1){
                fin>>m;
                if(!m) break;
                fin>>n;
                test.x = m;
                test.y = n;
                if(test.x > test.y)
                        test.swap();
                fout4<<test.GCD_euclid(m, n)<<endl;
                //test.GCD_reverse(m, n);
                //test.GCD_binary(m, n);
                //test.GCD_euclid(m, n);
        }
	fin.close();
	fout4.close();
}
