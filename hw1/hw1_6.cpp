#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class GCD_BIGINT{
	public:
		int A[256]={0};
		int B[256]={0};
		int res[256]={0};
		int ans[256]={0};
		int B_is_smaller();
		void bigint_swap();
		bool is_zero();
		void divide_A_by_two();
		void divide_B_by_two();
		void bigint_sub();
		void bigint_mul();
		void mul_by_two();
};

int GCD_BIGINT::B_is_smaller(){
	for(int i=255; i>=0; i--){
		if(A[i]>B[i]){
			return 1;
			break;
		}
		else if(A[i]<B[i]){
			return 0;
			break;
		}
	}
	return 0;
}

void GCD_BIGINT::bigint_swap(){
	for(int i=255; i>=0; i--){
		int tmp = A[i];
		A[i] = B[i];
		B[i] = tmp;
	}
}

bool GCD_BIGINT::is_zero(){
	for(int i=0; i<=255; i++){
		if(A[i]){
			break;
		}
    }
    for(int i=0; i<=255; i++){
        if(B[i]){
            return 1;
            break;
        }
    }
    return 0;
}

void GCD_BIGINT::divide_A_by_two(){
	int tmp = 0;
	for(int i =255; i>=0; i--){
		tmp = tmp*10 +A[i];
		A[i] = tmp/2;
		tmp %= 2;
	}
}

void GCD_BIGINT::divide_B_by_two(){
	int tmp = 0;
	for(int i =255; i>=0; i--){
		tmp = tmp*10 +B[i];
		B[i] = tmp/2;
		tmp %=2;
	}
}

void GCD_BIGINT::bigint_sub(){
	for(int i=0; i<256; i++){
		B[i] = B[i] - A[i];
	}
	for(int i=0; i<256; i++){
		if(B[i]<0){
			B[i+1]--;
			B[i] = B[i] +10;
		}
	}
}

void GCD_BIGINT::mul_by_two(){
	for(int i=0; i<256; i++){
	        ans[i] = ans[i] * 2;
	}
	for(int i=0; i<255; i++){
		ans[i+1] += ans[i] / 10;
		ans[i] %= 10;
	}
}

void GCD_BIGINT::bigint_mul(){
	for(int i=0; i<256; i++){
		for(int j=0; j<256; j++){
			if((i+j)<256)
				res[i+j] += A[i] * ans[j];
		}
	}
	for(int i=0; i<255; i++){
        res[i+1] += res[i] /10;
        res[i] %=10;
	}
}




int main(){
	string str1, str2;
	cin>>str1>>str2;


	GCD_BIGINT GCD;
	for(unsigned int i=0; i<str1.size(); i++){
		GCD.A[i] = str1[str1.size()-i-1] -'0';
	}
	for(unsigned int i=0; i<str2.size(); i++){
		GCD.B[i] = str2[str2.size()-i-1] -'0';
	}

	if(GCD.B_is_smaller()){
		GCD.bigint_swap();
	}
	GCD.ans[0]=1;
	while(GCD.is_zero()){
		if(GCD.A[0]%2==0&&GCD.B[0]%2==0){
			GCD.mul_by_two();
			GCD.divide_A_by_two();
			GCD.divide_B_by_two();
		}
		else if(GCD.A[0]%2==0&&GCD.B[0]%2!=0){
			GCD.divide_A_by_two();
		}
		else if(GCD.A[0]%2!=0&&GCD.B[0]%2==0){
			GCD.divide_B_by_two();
		}
		if(GCD.B_is_smaller()){
			GCD.bigint_swap();
		}
		GCD.bigint_sub();
	}
	GCD.bigint_mul();

	int len=0;
	for(int i=255; i>=0; i--){
		if(GCD.res[i] != 0){
			len = i;
			break;
		}
	}
	for(int i=len; i>=0; i--){
		cout<<GCD.res[i];
	}
	cout<<endl;

}
