#include <iostream>
using namespace std;

int main ()
{
    double n;
    double l;
    double lambida;
  
while(true)
{

  cout<<"declare o comprimento"<<endl;
  cin>>l;
  cout<<"digite o numero de harmonicos"<<endl;
  cin>>n;
  
  lambida = (2*l)/n;
  
  cout<<lambida<<endl;
  
}
    return 0;
}