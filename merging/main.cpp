#include <iostream>

using namespace std;
class Array
{
public:

    int A[10];
    int length;
    int Size;

};
void display(Array arr)
{
    int i;
    for(i=0;i<arr.length;i++)
    {
        cout<<arr.A[i]<<" ";
    }
}
void Merge(Array *arr1,Array *arr2)
{
    int i,j,k;
    i=j=k=0;
   int *arr3;
   arr3=new int[10];
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
          arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->length;i++)
    {
         arr3->A[k++]=arr1->A[i];
    }
     for(;j<arr2->length;j++)
    {
         arr3->A[k++]=arr1->A[j];
    }

}
int main()
{

   Array arr1{{1,3,5,7},4,4};
Array arr2{{2,4,6,8},4,4};
Array *arr3;
arr3=Merge(&arr1,&arr2);
display(*arr3);
    return 0;
}
