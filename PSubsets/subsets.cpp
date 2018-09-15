/*
	Jimmy Yuan
	Programming Assignment 1 Problem 1
	This program takes in a sequence of numbers and then outputs all of the subsets that those numbers can make

*/

#include <iostream>
#include <vector>

using namespace std;

void getNum(vector<string> &nums){
	string s;
	bool check;
	//Loops until a valid set of numbers is given
	do{
		check=true;
		//Gets the numbers separated by a comma or space
		cout<<"Enter the sequence with a comma or space separating each number: ";
		getline(cin,s);
		//Checks that the only thing entered are integers,commas or spaces
		for(int i=0;i<s.length();i++){
				if((s[i]>57||s[i]<48)&&(s[i]!=44&&s[i]!=32&&s[i]!=45)){
					check=false;
					cout<<"Not a Valid Input"<<endl;
					i=s.length();
				}
				//If a '-' sign is input the next char must be a number
				if(s[i]==45&&(s[i+1]>57||s[i+1]<47)){
					check=false;
					cout<<"Not a Valid Input1"<<endl;
					i=s.length();
				}
		}
	}while(check==false);
	
	string digits;
	char c;
	
	//Eliminates the repeat numbers
	for(int i=0;i<=s.length();i++){
		check=true;
		//This addeds the last number to nums if it isn't a repeat
		if(i==s.length()){
			for(int i=0;i<nums.size();i++){
				if(nums[i]==digits){
					check=false;
					break;
				}
			}
			if(check){
				nums.push_back(digits);
			}
		}
		//gets the string of numbers since they are separated by commas or spaces
		else if((s[i]>=48&&s[i]<=57)||s[i]==45){
			c=s[i];
			digits+=c;
		}
		//If there is a space or comma, the number is compared to the numbers already added to check if it is a repeat. If it isn't a repeat it is added to nums.
		else{
			for(int i=0;i<nums.size();i++){
				if(nums[i]==digits){
					check=false;
					break;
				}
			}
			if(check){
				nums.push_back(digits);
			}
			digits="";
		}		
	}
	
	return;
}

//Prints the subsets in size order
void print(vector<string> &all,int length){
	vector<string> sorted;
	int comma=0;
	string s;
	//Outputs the empty set
	cout<<"{}"<<endl;
	//The subsets are sorted using the amount of commas
	for(int i=0;i<length;i++){
		for(int k=0;k<all.size();k++){
			s=all[k];
			comma=0;
			//If the amount of commas is equal to i it is added to sorted
			for(int n=0;n<all[k].length();n++){
				if(s[n]==44){
					comma+=1;
				}
			}
			if(comma==i){
				sorted.push_back(all[k]);
			}
		}
	}
	//Outputs all of the subsets on their own line and doesn't repeat the empty set if there are no elements
	if(sorted[0]!=""){
		for(int i=0;i<sorted.size();i++){
			cout<<"{"<<sorted[i]<<"}"<<endl;
		}
	}
}

//Gets all of the subsets recursively
void getSets(vector<string> incl,vector<string> nums,vector<string>& all){
	string s;
	char c=',';
	//If nums is empty then this branch of the recursion is complete
	if(nums.size()!=0){
		bool same=false;
		//Loops though all the numbers in nums and incl to check that they aren't repeats
		for(int i=0;i<nums.size();i++){
			same=false;
			for(int k=0;k<incl.size();k++){
				if(incl[k]==nums[i]){
					same=true;
				}
			}
			if(same==false){
				s="";
				//Adds all of the numbers of incl separated by commas to a string and then adds nums[i] to get the new subset.Then the new subset is stored in all.
				for(int k=0;k<incl.size();k++){
					string s1=incl[k];
					s+=s1;
					s+=c;
				}
				s+=nums[i];
				all.push_back(s);
				s="";
			}
		}
		//Recursively calls itself to get the subsets with more elements
		for(int i=0;i<nums.size();i++){
			same=false;
			for(int k=0;k<incl.size();k++){
				if(nums[i]==incl[k]){
					same=true;
				}
			}
			if(same==false){
				s=nums[i];
				//Includes num[i] to incl before recursively calling itself
				incl.push_back(s);
				vector<string> holder;
				//Copies all elements of nums except those at i or before.This prevents repeat subsets with different ordered subsets.
				for(int k=i+1;k<nums.size();k++){
					holder.push_back(nums[k]);
				}
				//Recursively calls itself including nums[i] and with holder since it contains shortened version of nums
				getSets(incl,holder,all);
				//Deletes the last element of incl to recursively call itself with other numbers included and i excluded
				incl.pop_back();
			}		
		}
	}
}

int main(){
	vector<string> nums;
	//Gets the numbers
	getNum(nums);
	vector<string> all;
	vector<string> incl;
	//Gets all of the subsets
	getSets(incl,nums,all);
	//Outputs all of the subset by element size
	print(all,nums.size());
	return 0;
}
