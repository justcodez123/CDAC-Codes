#include<iostream>
#include<stdexcept>
using namespace std;

template<class T>

T division(T num, T deno){
    if(deno == 0){
        throw runtime_error ("Cant divide by zero");
    }    
    else{
        T result = num/deno;
        return result;
    }
}


int main() {
    try{
        double result = division<double>(10, 0.03);
        cout<<"Result of "<< 10.0 << " / " 
        << 0.03 << " is: "<<result<<endl;
    }
    catch(runtime_error& e){
        cout<<"Exception caught: "<<e.what()<<endl;
    }
}
