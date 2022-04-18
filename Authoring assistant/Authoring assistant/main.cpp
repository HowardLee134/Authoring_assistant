// main.cpp
//  Created by Howard Lee on 4/11/22.
// C++ project Authoring assistant
#include <iostream>
#include <string>
using namespace std;

int GetNumOfNonWSCharacters(string s){
    int count =0;
    for(int i=0; i< s.size(); i++){
        if (s.at(i) !=' '){
            count ++;
        }
    }
    return count;
}
int GetNumOfWords(string s){
    int words = 0;
    for(int i=0; s[i]!='\0'; i++){
        if(i!=0 && s[i-1]!=' ' && s[i] == ' ' )
            words++;
        }
        words++;
        return words;
}

int FindText(string s, string sub){
    int M = sub.length();
    int N = s.length();

    int Count = 0;
    int j =0;

    for (int i = 0; i <= N - M; i++){
        for (j = 0; j < M; j++)
            if (s[i+j] != sub[j])
                break;

        if (j == M){
            Count++;
        }
    }
    return Count;
}

string ReplaceExclamation(string s){
    string newS = "";
    for(int i=0; s[i]!='\0'; i++){
        if(s[i] == '!'){
    newS += '.';
        }
        else{
    newS += s[i];
        }
    }
    return newS;
}

string ShortenSpace(string s){
    string newS = "";
    for(int i=0; s[i]!='\0'; i++){
        if(s[i] != ' ')
            newS += s[i];
        else if(i!=0 && s[i-1]!=' ' && s[i]==' ')
            newS += s[i];
        }
        return newS; //returning new string.
    }

void PrintMenu(string s){
    char option;
    while(1){
        cout << "MENU" << endl;
        cout << "c - Number of non-whitespace characters" << endl;
        cout << "w - Number of words" << endl;
        cout << "f - Find text" << endl;
        cout << "r - Replace all !'s" << endl;
        cout << "s - Shorten spaces" << endl;
        cout << "q - Quit" << endl;
        cout <<endl;
        cout << "Choose an option:"<<endl;
        cin >> option;

        if(option == 'q'){
            break;
        }
        
        else if(option == 'c'){
            cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(s) << endl<<endl;
        }
        
        else if(option == 'w'){
            cout << "Number of words: " << GetNumOfWords(s) << endl << endl;
        }
        
        else if(option == 'f'){
            string sub;
            cin.ignore();
            cout << "Enter a word or phrase to be found:" << endl;
            getline(cin, sub);
            cout << "\"" <<sub << "\"" << " instances: " << FindText(s, sub) << endl <<endl;
        }
        
        else if(option == 'r'){
            cout << "Edited text: " << ReplaceExclamation(s) << endl << endl;
        }
        
        else if(option == 's'){
            cout << "Edited text: " << ShortenSpace(s) << endl << endl;
        }
    }
}
    int main(){
    string s;

    cout << "Enter a sample text:" << endl<<endl;
    getline(cin, s);

    cout << "You entered: " << s << endl<<endl;
    PrintMenu(s);
    return 0;
}

