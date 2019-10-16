/*
Samuel Ellenhorn
2295046
CPSC 350
10/1/19
*/

#ifndef GENSTACK_H
#define GENSTACK_H
#include <iostream>
#include <exception>
using namespace std;

class stackEmpty: public exception
{
  virtual const char* what() const throw()
  {
    return "The Stack is Empty";
  }
};

class resizeError: public exception
{
  virtual const char* what() const throw()
  {
    return "resize error";
  }
};



template <class T>
class GenStack {

private:
    int top;
    int cap;
    T * arr;

    void resize() {
        T * brr = new T[cap*2];
        if (brr == nullptr){
            throw resizeError();
        }

        for(int i = 0;i<cap; i++)
            brr[i] = arr[i];

        delete [] arr;
        arr = brr;
        cap = 2 * cap;
    }

public:
    GenStack(){
        top = -1;
        cap=8;
        arr = new T[cap];
        for(int i = 0;i<cap; i++){
            arr[i] = 0;
        }
    }


    bool isEmpty(){
        for(int i = 0;i<cap; i++){
            if (top == -1)
                return true;
            else
                return false;
        }
    }
    bool isFull(){
        if (top==cap) {
            resize();
            return true;
        }
        else
            return false;

    }



    void push(T val){
        if(isFull()){
            resize();
        }
        else{
            top++;
            arr[top]=val;
        }
    }

    T pop() {
        if(isEmpty()){
            cout<<"Stack UnderFlow"<<endl;
            return 0;
        }
        else{
            T popValue = arr[top];
            arr[top]= T();
            top--;
            return popValue;
        }
    }

    int count(){
        return(top+1);
    }

    T peek(int pos){
        if(isEmpty()){
            cout<<"Stack UnderFlow"<<endl;
            throw stackEmpty();
        }
        else{
            return arr[pos];
        }
    }

    T peek(){
        return peek(top);
    }

    void change(int pos,  char val){
        arr[pos] = val;
        cout<<"Value changed at the location: "<<pos<<endl;
    }

    void display(){
        cout<<"All values in the Stack are"<<endl;
        for (int i=top;i>=0;i--){
            cout<<arr[i]<<endl;
        }
    }



};


#endif
