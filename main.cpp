#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long long hashing[1000][1000];
map <string, long long> dict1;
map <long long, string> dict2;
long long numberOfElements, numberOfSits;

void unions()
{
    cout << "Please insert the number of first set you want to union" << endl;
    long long first;
    cin >> first;
    cout << "Please insert the number of second set you want to union" << endl;
    long long second;
    cin >> second;
    first--, second--;
    bool tmam = false;
    cout << "{";
    long long counterforprinting = 0;
    for(int i = 0; i < numberOfElements; i++)
    {
        long long x = hashing[first][i] | hashing[second][i];
        if(x == 1)
        {
            counterforprinting++;
            if(counterforprinting != 1)
                cout << ", ";
            cout << dict2[i];
            tmam = true;
        }
    }
    cout << "}" << endl;
    if(!tmam)
        cout << "Inserted sets doesn't exist" << endl;
    cout << endl;
}
void intersect()
{
    cout << "Please insert the number of first set you want to intersect" << endl;
    long long first;
    cin >> first;
    cout << "Please insert the number of second set you want to intersect" << endl;
    long long second;
    cin >> second;
    first--, second--;
    bool tmam = false;
    cout << "{";
    long long counterforprinting = 0;
    for(int i = 0; i < numberOfElements; i++)
    {
        long long x = hashing[first][i] & hashing[second][i];
        if(x == 1)
        {
            counterforprinting++;
            if(counterforprinting != 1)
                cout << ", ";
            cout << dict2[i];
            tmam = true;
        }
    }
    cout << "}" << endl;
    if(!tmam)
        cout << "Inserted sets doesn't exist" << endl;
    cout << endl;
}
void complement()
{
    cout << "Please insert the number of set you want to complement" << endl;
    long long first;
    cin >> first;
    first--;
    bool tmam = false;
    cout << "{";
    long long counterforprinting = 0;
    for(int i = 0; i < numberOfElements; i++)
    {
        long long x = 1-hashing[first][i];
        if(x == 1)
        {
            counterforprinting++;
            if(counterforprinting != 1)
                cout << ", ";
            cout << dict2[i];
            tmam = true;
        }
    }
    cout << "}" << endl;
    if(!tmam)
        cout << "Inserted sets doesn't exist" << endl;
    cout << endl;
}

void problem1()
{

    cout << "Please Enter the number of elements in the universal set" << endl;
    cin >> numberOfElements;
    for(long long i = 0; i < numberOfElements; i++)
    {
        if(i==0)
            cout << "Please Insert the " << i+1 << "st element";
        else if(i==1)
            cout << "Please Insert the " << i+1 << "nd element";
        else if(i==2)
            cout << "Please Insert the " << i+1 << "rd element";
        else
            cout << "Please Insert the " << i+1 << "th element";
        cout << endl;
        string x;
        cin >> x;
        dict1[x] = i;
        dict2[i] = x;
    }
    cout << "bool... Now, please insert the number of subsets" << endl;
    cin >> numberOfSits;
    for(long long i = 0; i < numberOfSits; i++)
    {
        long long setSize;
        if(i==0)
            cout << "Please insert the number of elements in the " << i + 1 << "st set";
        else if(i==1)
            cout << "Please insert the number of elements in the " << i + 1 << "nd set";
        else if(i==2)
            cout << "Please insert the number of elements in the " << i + 1 << "rd set";
        else
            cout << "Please insert the number of elements in the " << i + 1 << "th set";
        cout << endl;
        cin >> setSize;
        for(long long j = 0; j < setSize; j++)
        {
            if(j==0)
                cout << "Please Insert the " << i+1 << "st element";
            else if(j==1)
                cout << "Please Insert the " << i+1 << "nd element";
            else if(j==2)
                cout << "Please Insert the " << i+1 << "rd element";
            else
                cout << "Please Insert the " << i+1 << "th element";
            string buffer;
            cin >> buffer;
            hashing[i][dict1[buffer]] = 1;
        }
    }
    cout << "Great! Now please insert the whatever you want to do" << endl;
    cout << "If you want to union sets press 1" << endl;
    cout << "If you want to intersect sets press 2" << endl;
    cout << "If you want to complement a set press 3" << endl;
    cout << "If you want to exit press 4" << endl;
    long long choice;
    cin >> choice;
    while(choice != 4)
    {
        if(choice == 1)
            unions();
        else if(choice == 2)
            intersect();
        else if(choice == 3)
            complement();
        else
        {
            cout << "Stop long longing, enter a right choice" << endl;
        }
        cout << "If you want to union sets press 1" << endl;
        cout << "If you want to intersect sets press 2" << endl;
        cout << "If you want to complement a set press 3" << endl;
        cout << "If you want to exit press 4" << endl;
        cin >> choice;
    }
}
int getbit(int number,int pos){

    int x;

    x=((1<<pos)&number);
if(x!=0){
    x=1;
}

    return x;

}

int setbit(int number,int pos){

    int x;
    x=((1<<pos)|number);
    return x;

}
int clearbit(int number,int pos){

    int x;
    x=((~(1<<pos))&number);
    return x;

}


int updatebit(int number,int pos,bool value){
int x;

 if(value){
     x=setbit(number,pos);
 }
 else {
     x= clearbit(number,pos);
 }
    return x;

}
void problem2()
{
    int choice;
    cout << "insert the number of part you want to solve" << endl;
    cin >> choice;
    cout << "insert the number you want to process and the position" << endl;
    int num, pos;
    cin >> num >> pos;
    if(choice == 1)
        cout << getbit(num, pos);
    else if(choice == 2)
        cout << setbit(num, pos);
    else if(choice == 3)
        cout << clearbit(num, pos);
    else if(choice == 4){
        bool op;
        cout << "Enter the opartion you want" << endl;
        cin >> op;
        cout << updatebit(num, pos, op);
    }
}
int count_ones(unsigned int number){

    int count=0;

    while (number!=0){

        if((number&(1))!=0){
            count++;
        }
        number=number>>1;

    }

    return count;
}

int find_single_number(){

    int n,number=0,f=0,a[100000];
    cin>>n;
    for (int i = 0; i <  n; ++i) {
        cin>>a[i];
    }

    for (int i = 0; i < n; i++) {
        number=number^a[i];
    }
    return number;

}
void problem3()
{
    int choice;
    cout << "insert the number of part you want to solve" << endl;
    cin >> choice;
    if(choice == 1){
        unsigned int x;
        cin >> x;
        cout << count_ones(x);
    }
    else if(choice == 2)
        cout << find_single_number();
}
int main()
{
    int choice;
    cout << "insert the number of problem you want to solve" << endl;
    cin >> choice;
    if(choice == 1)
        problem1();
    else if(choice == 2)
        problem2();
    else if(choice == 3)
        problem3();
    cout << "Thank you" << endl;
    return 0;
}