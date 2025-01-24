#include <iostream>
#include <string>
using namespace std;
int stoi (char c) { return c - '0'; }
int main(){
    int i=0,j=0,l=1,n=0,z=0;
	string nums;
	cout << "Please Enter Numbers And Split Them With ',': \n";
	cin >> nums;
	int len= nums.length();
	for(i=0;i<len;i++){//bugs hunt here
		if(nums[i+1]==' '){
			cout << "Please Enter Numbers Correctly!\nLike:\n1,2,3,4\nYou Have Space ' ' Between Your Numbers!\n";
	    	system("pause");
	    	return 0;	
		}
		if (nums [0]==','){
			cout << "Please Enter Numbers Correctly!\nLike:\n1,2,3,4\nYou Have ',' Insted of first number!\n";
	    	system("pause");
	    	return 0;
		}
		if (nums[i]>='0'&&nums[i]<='9'&&nums[i+1]=='-'){
			cout << "Please Enter Numbers Correctly!\nLike:\n1,2,3,4\nYou Have Something Like This '1-1' Between Your Numbers!\n";
	    	system("pause");
	    	return 0;}	
		if (nums[i]=='-'&&nums[i+1]=='-'){
			cout << "Please Enter Numbers Correctly!\nLike:\n1,2,3,4\nYou Have '--' Between Your Numbers!\n";
	    	system("pause");
	    	return 0;}
		if (nums[i]==','&&nums[i+1]==','){
	    	cout << "Please Enter Numbers Correctly!\nLike:\n1,2,3,4\nYou Have ',,' Between Your Numbers!\n";
	    	system("pause");
	    	return 0;
		}
		if (!(nums[i]>='0'&&nums[i]<='9'||nums[i]==','||nums[i]=='-')){
			cout << "Please Enter Numbers Correctly!\nLike:\n1,2,3,4\nYou Enter Incorrect Charcter Like:\n'a,A,~,etc'\n";
	    	system("pause");
	    	return 0;	
		}
		if (nums[i]==','&&nums[i+1]=='\0'){
			cout << "Please Enter Numbers Correctly!\nLike:\n1,2,3,4\nYou Have Something Like ', ,' Between Your Numbers Or In End You Have','\nReenter Your Numbers\n";
	    	system("pause");
	    	return 0;
		}
	}
    for(i=1;i<=len;i++){//count number
		if(nums[i]==','){
    		l++;
		}
	}
	int num[l];
	bool isNegative = false;
	for (z=0,i=0;i<len;i++)//this cycle convert string to number and save number to N[] array
	{
	  if (nums[i] == '-') {
            isNegative = true;
            continue;
        }

        if (nums[i] == ',') {
            if (isNegative) 
				j = -j;
            num[z++] = j;
            j = 0;
            isNegative = false;
            continue;
        }

        n = stoi(nums[i]);
        j = j * 10 + n;

        if (i == len - 1) {
            if (isNegative)
			j = -j;  
            num[z] = j;
        }
    }    
	for (int i = 0; i < l - 1; i++)//number sort!
        for (int j = 0; j < l - i - 1; j++)
            if (num[j] > num[j + 1]) {
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
    int f[l];        
	for(i=0;i<l;i++){// frequncy calculate here
		for(z=0,j=0;j<l;j++)
			if(num[i]==num[j])
				z++;
		f[i]=z;
	  	z=0;
}	
	for (i=0;i<l;i++){//printer
		if(num[i]==num[i+1])
		continue;
		cout << "F["<<num[i]<<"]="<<f[i]<<endl;}
	system("pause");
	return 0;
	}