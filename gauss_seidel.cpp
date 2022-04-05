//This program computes the solution to a system of linear equations using the guass seidel method

//~Abhijna Raghavendra and Mansi Gupta [1st year students of IIT Roorkee bored with the MAN 004 class]

//NOTE: this program cannot compute beyond 1000 iterations

#include<iostream>
#include<cmath>
using namespace std;


int main()
{
	int n;
	int t,b;
	cout<<"Enter the number of simaltaneous equations to solve:\n";
	cin>>n;
	float A[n][n], B[n];
	cout<<"Enter the coefficients of Xi ";
	for(int i=0;i<n;i++)
	{
		cout<<"of equation "<<i+1<<endl;
		for(int j=0;j<n;j++)
		{
			cin>>A[i][j];
		}
		cout<<"Enter the \"b\" for equation "<<i+1<<"\n";
		cin>>B[i];
	}
	cout<<"Enter the base and acuuracy: \n";
	cin>>b>>t;
	float X[1000][n];
	cout<<"Enter the initial guess values:\n";
	for(int i=0;i<n;i++)
	{
		cin>>X[0][i];
	}
	float diff=1;
	int k=1;
	while(diff>= (0.5*pow(b,-t)))
	{
		for(int i=0;i<n;i++)
		{
			X[k][i]=B[i]/A[i][i];
			for(int j=0;j<n;j++)
			{
				if(j!=i)
				{
					X[k][i]=X[k][i]-(A[i][j]*X[k-1][j])/A[i][i];
				}	
			}
		}
		cout<<"Iteration "<<k<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<"X["<<i+1<<"]: "<<X[k][i]<<"\n";
		}
		cout<<"---------------------------"<<endl;
		diff=abs((X[k][0]-X[k-1][0])/X[k][0]);
		k++;
	}
	return 0;
}
