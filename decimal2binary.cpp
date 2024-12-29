#include<iostream>
#include<string>

std::string decimal2binary(int s){
	std::string ans;
	while(s>1){
		if(s%2==1) ans.push_back('1');
		else ans.push_back('0');
		s/=2;
	}
	s==1?ans.push_back('1'):ans.push_back('0');
	int i=0,j=ans.size()-1;
	while(i<j){
	    std::swap(ans[i],ans[j]);
	    i++;
	    j--;
	}
	return ans;
}


int main(){
	int s;
	std::cout<<"Enter decimal value=";
	std::cin>>s;
	std::cout<<decimal2binary(s);
	return 0;
}
