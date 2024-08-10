/* program to check binary number and finding the ones compliment of binary*/

#include <iostream>
#include <string>
using namespace std;
class binary{
    private:
    string s;
    public:
    void read();
    void chk_bin();
    void display();
    void ones();
};
void binary :: read(){
    cout<<"Enter a number"<<s<<endl;
    cin>>s;
}
void binary :: chk_bin(){
    for(int i = 0; i<s.length(); i++){
        if(s.at(i)!= '0' && s.at(i)!= '1'){
             cout<<"incorrect binary format"<<endl;
             exit(0);
        }
    }
}

void binary :: ones(){
    for(int i = 0; i<s.length(); i++){
      if(s.at(i)=='0'){
          s.at(i) = '1';
      }
      else{
          s.at(i) = '0';
      }
    }   
}
void binary :: display(){
   cout<<"Ones compliment of the binary number is : ";
    for(int i = 0; i<s.length(); i++){
        cout<<s.at(i);
    }
}
int main() {
    binary check;
    check.read();
    check.chk_bin();
    check.ones();
    check.display();

    return 0;
}
