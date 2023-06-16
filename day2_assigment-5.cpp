#include<iostream>
using namespace std;

int extract_and_sum(int num){
    int digit,sum=0;
    while(num!=0){
        digit=num%10;
        num/=10;
        sum+=digit;
    }
    return sum;
}

int main(){
    int range,largest=0,largestnum=0;
    cout<<"Enter the range\n: ";
    cin >> range;
    for(int i=1;i<=range;i++){
        if(extract_and_sum(i)>largest){
                largest=extract_and_sum(i);
                largestnum=i;
        }
    }
    cout<<"From 1 to"<<range<<" "<<largestnum<<" has the largest digit sum";
return 0;
}