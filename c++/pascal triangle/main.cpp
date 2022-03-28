#include <iostream>

using namespace std;
int pascal(int n,int r)
{

if(r==0||n==r)
    return 1;
else
    return pascal(n-1,r)+ pascal(n-1,r-1);
}

int main()
{
   int n;
cin>>n;
int i,j,spaces;
for(i=0;i<n;i++)
{
    for(spaces=n;spaces>i;spaces--)
    {
        cout<<" ";
    }
    for(j=0;j<=i;j++)
    {
        cout<<pascal(i,j)<<" ";
    }
cout<<endl;

}
    return 0;
}
