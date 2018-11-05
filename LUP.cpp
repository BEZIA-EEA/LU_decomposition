#include<iostream>
using namespace std;
int main ()
{
    double** A;
    int n,i,j,k,p,f;
    double *b,*X,*Y;
    double tmp,tp;
    cout<<"donner la taille de la matrice A : ";
    cin>>n;
    A=new double* [n];
    for (i=0;i<n;i++)
    {
       A[i]=new double[n];
    }
    b=new double[n];
    X=new double[n];
    Y=new double[n];
    cout<<"vellier saisir la matrice A: "<<endl;
    for (i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            cout<<"A["<<i<<"]["<<j<<"]=";
            cin>>A[i][j];
        }
    cout<<"vellier saisir le vecteur b: "<<endl;
    for(i=0;i<n;i++)
        {
            cout<<"b["<<i<<"]=";
            cin>>b[i];
        }
//afichage
    for (i=0;i<n;i++)
    {
        cout<<" |  ";
        for(j=0;j<n;j++)
        {
            cout<<A[i][j]<<"     ";
        }
        cout<<" | "<<b[i]<<" | "<<endl<<endl;

    }
//traitement
    int u;
    double sm1,sm2;
    for (k=0;k<n-1;k++)
    {
//calcule du pivot 
      sm1=0;
	for(u=0;u<k;u++)
	{sm1=sm1+A[k][u]*A[u][k];}
	A[k][k]=A[k][k]-sm1;
	 if(A[k][k]==0) {p=k;
                            do
                            {
                            p++;
                            }while(A[p][k]==0 and p<n);
			      for(f=0;f<n;f++)
			      {
                                tp=A[k][f];A[k][f]=A[p][f];A[p][f]=tp;
			      }
			    tp=b[k];b[k]=b[p];b[p]=tp;
			    }
//cacul de la k eme coloun de L      
     for(i=k+1;i<n;i++)
      {
	sm1=0;
	for(u=0;u<k;u++)
	{sm1=sm1+A[i][u]*A[u][k];}
	A[i][k]=A[i][k]-sm1;
      }
//cacul de la k eme coloun de U      
      for(j=k+1;j<n;j++)
       {
	sm2=0;
	for(u=0;u<k;u++)
	{sm2=sm2+A[k][u]*A[u][j];}
	A[k][j]=(A[k][j]-sm2)/A[k][k];
       }
    }

//calcule de l[n][n]   
	sm1=0;
	for(u=0;u<n-1;u++)
	{sm1=sm1+A[n-1][u]*A[u][n-1];}
	A[n-1][n-1]=A[n-1][n-1]-sm1;
//afichage
    for (i=0;i<n;i++)
    {
        cout<<" |  ";
        for(j=0;j<n;j++)
        {
            cout<<A[i][j]<<"     ";
        }
        cout<<"|"<<endl<<endl; 
    }
    
    double s0;
    for (i=0;i<n;i++)
    {
        s0=0;
        for(int l=0;l<i;l++)
        {
          s0=s0+A[i][l]*Y[l];
        }
        Y[i]=(b[i]-s0)/A[i][i];
        cout<<"Y["<<i<<"] = "<<Y[i]<<endl;
    }
cout<<"------------------------------"<<endl;
    double s;
    for (i=n-1;i>-1;i--)
    {
        s=0;
        for(int l=i+1;l<n;l++)
        {
          s=s+A[i][l]*X[l];
        }
        X[i]=(Y[i]-s);
        cout<<"X["<<i<<"] = "<<X[i]<<endl;
    }
  
    return 0;
}
