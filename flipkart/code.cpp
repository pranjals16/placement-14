#include <iostream>
using namespace std;
void findLargestPal(string str,string &res)
{
int dix[26]={0},i,n,odd=-1;
n=str.size();
string temp;
//find the count of each char
for(i=0;i<n;i++)
dix[str[i]-97]++;
//find the middle term there is atmost one
for(i=0;i<25;i++)
if(dix[i]%2!=0){ odd=i; dix[i]--; }
// initialize first half of the result
for(i=25;i>=0;i--)
{ if(dix[i]==0)continue;
int m=dix[i];
while(dix[i]>m/2){ temp=char(i+97); res+=temp; dix[i]--; }
}
//initialize middle element
if(odd!=-1)
{
temp=char(odd+97);
res+=temp;
}
//initialize last half of the result
for(i=0;i<26;i++)
{ if(dix[i]==0)continue;
while(dix[i]>0){ temp=char(i+97); res+=temp; dix[i]--; }
}
return;
}	
int main() {
string str= "aabaaccccdddddd",res;
findLargestPal(str,res);
cout<<res<<endl;;
return 0;
}
