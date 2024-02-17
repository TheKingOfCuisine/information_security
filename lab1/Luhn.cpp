#include <string.h>
#include <iostream>
#include <conio.h>
#include <list>
#include <array>
using namespace std;
class Luhn{
    public:
    void check(list<int> l){
        int sum = 0;
        int control;
        auto iter = l.begin();
        for (int i =1; i<= l.size();i++){
            if (i%2!=0){
                if (2*(*iter)>9){
                    sum+= 2*(*iter)-9;
                }else{
                    sum+= 2*(*iter);
                }
            }else{
                sum+= *iter;
            }
            iter++;
        }
        if (sum%10==0){
            cout<<"Card number is valid"<<endl;
        }else{
            cout<<"Card number is not valid"<<endl;
        }
    }
    list<int> getNum(string s){
        list<int> l;
        for (auto c: s){
            l.push_back(c-'0');
        }
        return l;
        //nums->push_back(5);
    }
    
};
int main(){
    Luhn *test = new Luhn();
   list<int> li = test->getNum("5062821234567892");
   
    test->check(li);
    getchar();

}