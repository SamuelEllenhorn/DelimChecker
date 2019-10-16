/*
Samuel Ellenhorn
2295046
CPSC 350
10/1/19
*/

#include <iostream>
#include <fstream>
#include "GenStack.h"
#include "DelimCheck.h"
using namespace std;


int main(int argc, char** argv){

    if(argc < 2) {
        cout<<"Need a file name"<<endl;
        return 0;
    }
    string fileName = argv[1];
    DelimCheck checker;
    string answer = "Yes";

    while(answer == "Yes") {
        ifstream fin(fileName);

        if (!fin){
            cout<<"Not valid file"<< endl;
            return 0;
        }

        int errorLineNum = checker.areParanthesisBalanced(fin);
        if(errorLineNum == -1) {
            cout<<"Delimiters are balanced"<<endl;
            cout<<"Would you like to analyze another file?(Yes/No)"<<endl;
            cin>>answer;
            if (answer == "Yes")
            {
                cin>>fileName;
            }
        }
        else{
            cout << "Error on line: " << errorLineNum << endl;
            cout<<"Delimiters are not balanced"<<endl;
            answer = "No";
        }

        fin.close();
    }

    return 0;

}
