#include<iostream>
using namespace std;

int main() {
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5-i; j++){
            cout<<"  ";
        }

        for(int j=i; j<=(2*i-1); j++){
            cout<<j<<" ";
        }

        for(int k=(2*i-2); k>=i; k--){
            cout<<k<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"----------------------"<<endl;
    cout<<endl;

    /*Inverted full pyramid*/
    for(int i=5; i>=1; i--){
        
        for(int j=i; j<5; j++){
            cout<<"  ";
        }
        
        for(int k=(2*i-1); k>0; k--){
            cout<<"*"<<" ";
        }
        cout<<endl;

    }

    cout<<endl;
    cout<<"----------------------"<<endl;
    cout<<endl;

    /*Print Pascal's triangle*/
     for (int i = 0; i < 6; i++) {

        for(int j=6-i; j>0; j--){
            cout<<"  ";
        }

        int val = 1;
        for (int k = 0; k <= i; k++) {
            cout << val <<"   ";
            val = val * (i - k) / (k + 1);
        }
        cout << endl;
    }
    cout<<endl;
    cout<<"----------------------"<<endl;
    cout<<endl;

    /*Half pyramid of alphabets*/

    for(int i=0; i<6; i++){/*Remember, this is a flow control loop,  always*/
        char temp = 'A'; /*Variable scope initializes temp to A in each iteration*/
        for(int j=0; j<=i; j++){
            cout<< temp <<" ";
            temp = (char)(temp + 1);
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"----------------------"<<endl;
    cout<<endl;

    for(int i=0; i<=6; i++){
        
        for(int j=1; j<=6-i; j++){
            cout<<"  ";
        }

        int t = 0;
        char temp = 'A';
        for(int k=1; k<=i+1; k++){
            cout<<temp<<"   ";
            temp++;
        }

        // for(int k=(2*i-2); k>=i; k--){
        //     cout<<temp<<" ";
        //     temp = (char)(temp+k);
        // }
        cout<<endl;
    }


}