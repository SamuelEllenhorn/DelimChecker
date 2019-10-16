#ifndef DELIMCHECK_H
#define DELIMCHECK_H
#include "GenStack.h"
using namespace std;

class DelimCheck{

private:

    char complement(char x) {
        if (x == '(')
            return ')';
        else if (x == ')') {
            return '(';
        }
        else if (x == '{') {
            return '}';
        }
        else if (x == '}') {
            return '{';
        }
        else if (x == ']') {
            return '[';
        }
        else if (x == '[') {
            return ']';
        }
        return x;
    }

public:

    int areParanthesisBalanced(istream & in) {
        int lineCounter = 1;
        GenStack<char> s;
        char x, y;

        in >> noskipws;

        // Traversing the Expression
        while(in >> x)//EXTRACTS CHAR FROM STREAM, if you hit end of file char state of stream = false yielding a break in the while loop
        {
            if (x=='('||x=='['||x=='{')
            {
                // Push the element in the stack
                s.push(x);
                continue;
            }


            switch (x)
            {
            case ')':

                // Store the top element in a
                if (s.isEmpty())
                   return lineCounter;
                y = s.pop();
                if (y=='{' || y=='[') {
                    cout << "Expected " <<  complement(y) << " but got " << ')' << endl;
                    return lineCounter;
                }
                break;

            case '}':

                if (s.isEmpty())
                    return lineCounter;
                // Store the top element in b
                y = s.pop();
                if (y=='(' || y=='[') {
                    cout << "Expected " <<  complement(y) << " but got " << '}' << endl;
                    return lineCounter;
                }
                break;

            case ']':

                if (s.isEmpty())
                    return lineCounter;
                // Store the top element in c
                y = s.pop();

                if (y =='(' || y == '{'){
                    cout << "Expected " <<  complement(y) << " but got " << ']' << endl;
                    return lineCounter;
                }
                break;
            case '\n':
                ++lineCounter;
            }
        }

        // Check Empty Stack
        if(s.isEmpty()){
            return -1; // return -1 if no error found
        } else {
            cout<<"Reached end of file missing "<< complement(s.peek())<<endl;
            return lineCounter;
        }

    }

    bool areParanthesisBalanced(string expr)
    {
        GenStack<char> s;
        char x;

        // Traversing the Expression
        for (int i=0; i<expr.length(); i++)
        {
            x = expr[i];
            if (x=='('||x=='['||x=='{')
            {
                // Push the element in the stack
                s.push(x);
                continue;
            }

            // IF current current character is not opening
            // bracket, then it must be closing. So stack
            // cannot be empty at this point.
            if (s.isEmpty())
               return false;

            switch (x)
            {
            case ')':

                // Store the top element in a
                x = s.pop();
                if (x=='{' || x=='[')
                    return false;
                break;

            case '}':

                // Store the top element in b
                x = s.pop();
                if (x=='(' || x=='[')
                    return false;
                break;

            case ']':

                // Store the top element in c
                x = s.pop();

                if (x =='(' || x == '{')
                    return false;
                break;
            }
        }

        // Check Empty Stack
        return s.isEmpty();
    }

};

#endif
