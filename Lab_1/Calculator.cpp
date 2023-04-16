#include <sstream>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

int main ()
{
  string input;
  getline(cin, input);
  
  input.erase(0,1);
  input.erase(input.size() - 1);
  
  char temp[input.length() + 1];
  strcpy(temp, input.c_str());
  int j = 0;
  
  string num[4];
  
  for(int i = 0; i < input.length(); i++){
	if(temp[i] == ' '){
  		j++;
		continue;
	}
	else if(temp[i] == '+' || temp[i] == '-' || temp[i] == '*' || temp[i] == '/'){
		num[j] = temp[i];
	}
	else{
		num[j] += temp[i];
	} 
  }
  
  int x = 0;
  int y = 0;
  
  stringstream a(num[0]);
  stringstream b(num[2]);
  
  a >> x;
  b >> y;
  int val = 0;
  
  if(num[1] == "+"){
  	val = x + y;
  	cout<< input << " = " << val;
  }
  else if(num[1] == "-"){
  	val = x - y;
  	cout<< input << " = " << val;
  }
  else if(num[1] == "*"){
  	val = x * y;
  	cout<< input << " = " << val;
  }
  else if(num[1] == "/"){
  	val = floor(x / y);
  	cout<< input << " = " << val;
  }
  return 0;
}
