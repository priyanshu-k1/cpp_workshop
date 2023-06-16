#include<iostream>
using namespace std;

int len(int num){
    int digits = 0;
    while (num > 0) {
        num /= 10;
        digits++;
    }
    return digits;
}

int largest(int num){
    int digit,largest=0;
    while(num!=0){
        digit=num%10;
        if(digit>largest){
            largest=digit;
        }
        num/=10;
    }
    return largest;
}

int smallest(int num){
   int digit,smallest,size=len(num),arr[size],i=0;
   while(num!=0){
        digit=num%10;
        arr[i]=digit;
        i++;
        num/=10;
   }
   smallest=arr[0];
   for(int i=0;i<size;i++){
        if(arr[i]<smallest){
            smallest=arr[i];
        }
   }
   return smallest;
}

int main(){
    int num;
    cout<<"Enter any number\n:";
    cin >> num;
    cout<<"--< "<<smallest(num)<<" , "<<largest(num)<<">--\n";

return 0;
}