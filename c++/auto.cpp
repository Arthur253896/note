#include <iostream>
#include <vector>
using namespace std;
// int main    (){
//     vector<int> v;
//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(3);
//     for(auto i:v){
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     string s("hello world");
//     for(auto c:s)
//     c='t';
//     cout<<s<<endl;//结果为hello world
//     for(auto &c:s)
//     c='t';
//     cout<<s<<endl;//结果为ttttttttt
//     return 0;
// }
int main(){
    vector<int> v;
    for(int i=0;i<10;i++){
        v.push_back(10-i);
    }
    cout<<v[4]<<endl;
    return 0;
}