#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

char encryptLetter(char l, int keyA, int keyB){
	int letterNumber = l - 'a';
	letterNumber *= keyA;
	letterNumber += keyB;
	if(letterNumber > 25){
		letterNumber = letterNumber % 26;
	}
	char newLetter = letterNumber + 'a';
	return newLetter;
}

string encrypt(string text, int keyA, int keyB){
	string result = string();
	for(int a=0; a<text.length(); a++){
		result += encryptLetter(text[a], keyA, keyB);
	}
	return result;
}

int main(){
	ifstream dane("tekst.txt");
	string slowo;
	vector<string> zad1;
	vector<string> zad2;
	while(dane >> slowo){
	
		//zad1
		if(slowo[0] == 'd' && slowo[slowo.length()-1] == 'd'){
			zad1.push_back(slowo);
		}
		//zad2
		if(slowo.length() >= 10){
			zad2.push_back(slowo);
		}
	}
	
	cout << "75.1: " << endl;
	for(int a=0; a<zad1.size(); a++){
		cout << zad1[a] << endl;
	}
	
	cout << "75.2: " << endl;
	for(int a=0; a<zad2.size(); a++){
		cout << encrypt(zad2[a], 5, 2) << endl;
	}
}
