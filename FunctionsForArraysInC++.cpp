#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

template <typename X>
class ElementStore{
private:
    X *arr;
    int size;
public:
    ElementStore(X *, int);
    void printMaxFreq();
    void printMinFreq();
};

template<typename X>
ElementStore<X>::ElementStore(X *a, int n){
    size = n;
    arr = new X[size];
    for(int i=0; i<size; i++){
        arr[i]=a[i];
    }
}
template<typename X>
void ElementStore<X>::printMaxFreq(){
    X max = arr[0];
    int count = 0;

    for(int i=0; i<size; i++){
        if(arr[i]>max){
            max = arr[i];
            count = 0;
        }
        if(arr[i]==max)
            count++;
    }
    cout<<"Max: "<<max<<" appears "<<count;
    if(count==1)
        cout<<" time."<<endl;
    else
        cout<<" times."<<endl;
}
template<typename X>
void ElementStore<X>::printMinFreq(){
    X min = arr[0];
    int count=0;

    for(int i=0; i<size; i++){
        if(arr[i]<min){
            min = arr[i];
            count = 0;
        }
        if(arr[i]==min)
            count++;
    }
    cout<<"Min: "<<min<<" appears "<<count;
    if(count==1)
        cout<<" time."<<endl;
    else
        cout<<" times."<<endl;
}

int main() {
	int *A;
	double *B;
    	string *C;
    	int i,n;

	ElementStore<int> *a;
    	ElementStore<double> *b;
    	ElementStore<string> *c;


	cin>>n;
	if (n<2)
	{
		cerr<<"Array size too small"<<endl;
		exit(1);
	}
	A = new int[n];
	for (i=0;i<n;i++)
		cin>>A[i];
	a = new ElementStore<int>(A,n);
	delete[] A;

	B = new double[n];
	for (i=0;i<n;i++)
		cin>>B[i];
	b = new ElementStore<double>(B,n);
	delete[] B;

	C = new string[n];
	for (i=0;i<n;i++)
		cin>>C[i];
	c = new ElementStore<string>(C,n);
	delete[] C;

	a->printMinFreq();
    	a->printMaxFreq();
    	cout<<endl;
	b->printMinFreq();
	b->printMaxFreq();
	cout<<endl;
	c->printMinFreq();
	c->printMaxFreq();

	return 0;
}
