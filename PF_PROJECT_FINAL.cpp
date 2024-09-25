#include<iostream>
using namespace std;
const int col=3;
int rows;
int determinant=0;
void display(int array[][col]);
void symmetric(int arr[][col]);
void identity(int arr[][col]);
void determinent(int arr[][col]);
void adjoint(int arr[][col]);
void solution(int adjointpassing[][col] , int determinant);
void inverse(int adjointpassing[][col],int determinant);
int main()
{
    int action;
 cout << "*****WELCOME TO MATRIX CALCULATOR*****"<< endl;
 cout<<"Enter the number of rows: ";
 cin>>rows;
 if(rows!=col)
 {
    exit;
 }
 else
 {
 int arr[rows][col];
 int adjointpassing[rows][col];
 for(int i=0;i<rows;i++)
 {
    for(int j=0;j<col;j++)
    {
        cout<<"Enter the element of row "<<i+1<<" and "<<" coloum "<<j+1<<" :";
        cin>>arr[i][j];
    }
 }
 for(int i=0;i<rows;i++)
 {
    for(int j=0;j<col;j++)
    {
        adjointpassing[i][j]=arr[i][j];
    }
 }
 
 for(int j=1;j=1;1)
 {
    cout<<"Enter the action to be performed from (1 to 7) and 8 to terminate the program"<<endl;
   	cout << "1) To display a matrix" << endl;
	cout << "2) To check whether the entered matrix is symmetric matrix or not" << endl;
	cout << "3) To check whether the entered matrix is identity matrix or not" << endl;
	cout << "4) To determine the determinant of entered matrix" << endl;
	cout << "5) To determine the adjoint of entered matrix" << endl;
	cout << "6) To determine the inverse of entered matrix" << endl;
	cout << "7) To determine the solution of entered matrix" << endl;
    cin>>action;
    if(action==1)
    {
        display(arr);
    }
    if(action==2)
    {
        symmetric(arr);
    }
    if(action==3)
    {
        identity(arr);
    }
    if(action==4)
    {	   
		determinent(arr);	
	}
	if(action==5)
	{
		adjoint(adjointpassing);
	}

	if(action==6)
	{
		if(determinant==0)
		{
			determinent(arr);
		}
		for(int i=0;i<rows;i++)
		{
			for(int p=0;p<col;p++)
			{
		if(adjointpassing[i][p]==arr[i][p])
		continue;
		else break;
	}
	if(i==rows-1)
	{
		adjoint(adjointpassing);		
	}
	else break;
	}
	 if  (determinant==0)
	cout<<"The answer is undefined "<<endl;
else{

		inverse(adjointpassing,determinant);
		}
	}
	if(action==7){
       solution(adjointpassing,determinant);	
	   }
	 if(action==8)
    {
    	cout << "Thanks for using , GOODBYE.";
        break;
    }
}
 }
 }
void display(int arr[][col])
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void symmetric(int arr[][col])
{
	int l;
    for(int i=0;i<=rows;i++)
    {
    	
    	            if(i==rows)
            {
                cout<<"It is symmetric"<<endl;
                break;
            }
        for(int j=0;j<col;j++)
        {
            if(arr[i][j]==arr[j][i])
            {
             continue;
            }
            else
            {
                cout<<"It is not symmetric"<<endl;
                 l=1;
                break;
            }
        }
        if(l==1)
        {
        	i=rows+1;
		}
    }
}
void identity(int arr[][col])
{
    int r;
    for (int i=0;i<rows;i++)
    {
        if(arr[i][i]==1)
        {
            if(i==rows-1)
            {
                for(int j=0;j<rows;j++)
                {
                    for(int k=0;k<col;k++)
                    {
                        if(j==k){
                        k=k+1;}
                        else if(k!=j)
                        {
                            if(arr[j][k]==0){
                           continue;
                            }
                            else
							{
							 cout<<"It is not identity matix"<<endl;
                            r=r+1;
                            break;
                        }
                    }
                }
                if(r==2)
                break;
                if(j==rows-1)
                {
                    cout<<"It is identity matrix "<<endl;
                    break;
                }
            }
        }
    }
    else 
    {
    	cout<<"It is not identity matrix"<<endl;
    	break;
	}
}
}
void determinent(int arr[][col])
{   if (col==2){
	determinant=arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];
	cout<<"The determinent is: "<<determinant<<endl;
}
    if(col==3){
	
	int deter1;
	int deter2;
	int deter3;
	deter1=arr[0][0]*((arr[1][1]*arr[2][2])-(arr[1][2]*arr[2][1]));
	deter2=-(arr[0][1])*((arr[1][0]*arr[2][2])-(arr[1][2]*arr[2][0]));
	deter3=arr[0][2]*((arr[1][0]*arr[2][1])-(arr[1][1]*arr[2][0]));
	determinant=deter1+deter2+deter3;
    cout<<"The determinent is: "<<determinant<<endl;
}
}
void adjoint(int adjointpassing[][col])
{
	if(col==2){
			int z=adjointpassing[0][0];
	adjointpassing[0][0]=adjointpassing[1][1];
	adjointpassing[1][1]=z;
	adjointpassing[1][0]=-(adjointpassing[1][0]);
	adjointpassing[0][1]=-(adjointpassing[0][1]);
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<adjointpassing[i][j]<<"\t";
		}
		cout<<endl;
	}
	}
	if(col==3){
	int fun[3][3];
	for(int l=0;l<rows;l++)
	{
		for(int k=0;k<col;k++)
		{
			fun[l][k]=adjointpassing[l][k];
		}
	}
	
	adjointpassing[0][0]=((fun[1][1]*fun[2][2])-(fun[1][2]*fun[2][1]));
	adjointpassing[1][0]=-((fun[1][0]*fun[2][2])-(fun[1][2]*fun[2][0]));
	adjointpassing[2][0]=((fun[1][0]*fun[2][1])-(fun[1][1]*fun[2][0]));
    adjointpassing[0][1]=-((fun[0][1]*fun[2][2])-(fun[0][2]*fun[2][1]));
	adjointpassing[1][1]=((fun[0][0]*fun[2][2])-(fun[0][2]*fun[2][0]));
	adjointpassing[2][1]=-((fun[0][0]*fun[2][1])-(fun[0][1]*fun[2][0]));
	adjointpassing[0][2]=((fun[0][1]*fun[1][2])-(fun[0][2]*fun[1][1]));
	adjointpassing[1][2]=-((fun[0][0]*fun[1][2])-(fun[0][2]*fun[1][0]));
	adjointpassing[2][2]=((fun[0][0]*fun[1][1])-(fun[0][1]*fun[1][0]));

	cout<<"The adjoint is: "<<endl;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<adjointpassing[i][j]<<"\t";
		}
		cout<<endl;
	}}
}
void inverse(int adjointpassing[][col],int determinant)
{
	double inverse[rows][col];
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<col;j++)
		{
		inverse[i][j]=adjointpassing[i][j];
		}
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<col;j++)
		{
		inverse[i][j]=inverse[i][j]/determinant;
		cout<<inverse[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void solution(int adjointpassing[][col],int determinant)
{
	if(col==2)
	{
		int arr2[2][1];
		cout<<"Enter a matrix of "<<rows<<" x 1 "<<endl;
		for(int i=0;i<rows;i++)
		{
			cout<<"Enter the element of row "<<i+1<<" and 1: ";
			cin>>arr2[i][0];
		}
		cout<<"Matrix B is: "<<endl;
		for (int i=0;i<col;i++){
		cout<<arr2[i][0]<<endl;
	}
		int mi[rows][1];
		mi[0][0] = adjointpassing[0][0] * arr2[0][0] + adjointpassing[0][1] * arr2[1][0] ;
      	mi[1][0] = adjointpassing[1][0] * arr2[0][0] + adjointpassing[1][1] * arr2[1][0] ;
      	
      	mi[0][0]=mi[0][0]/determinant;
      	mi[1][0]=mi[1][0]/determinant;
      	
      	cout<<"Values of x1 , x2 are: "<<endl;
      	cout << "x1 ="<<mi[0][0]<<endl;
        cout << "x2 ="<<mi[1][0]<<endl;
      	
		
	}
	 if(col==3){
    int arr2[3][1];
    cout<<"Enter a matrix B of order "<<rows<<" x " << " 1 "<<endl;
    for (int i=0;i<col;i++){
    	cout<<"Enter the element of row "<<i+1<<" and col 1: ";
		cin>>arr2[i][0]; 
		cout << endl;
	}
	for (int i=0;i<col;i++){
		cout<<arr2[i][0]<<endl;
	}
	int mi [rows][1];
	mi[0][0] = adjointpassing[0][0] * arr2[0][0] + adjointpassing[0][1] * arr2[1][0] + adjointpassing[0][2] * arr2[2][0];
	mi[1][0] = adjointpassing[1][0] * arr2[0][0] + adjointpassing[1][1] * arr2[1][0] + adjointpassing[1][2] * arr2[2][0];
	mi[2][0] = adjointpassing[2][0] * arr2[0][0] + adjointpassing[2][1] * arr2[1][0] + adjointpassing[2][2] * arr2[2][0];
	
		mi[0][0]=mi[0][0]/determinant;
      	mi[1][0]=mi[1][0]/determinant;
      	mi[2][0]=mi[2][0]/determinant;
	
	
	
cout << "Values of x1 , x2 , x3 are: "<< endl;	
cout << "x1 ="<<mi[0][0]<<endl;
cout << "x2 ="<<mi[1][0]<<endl;
cout << "x3 ="<<mi[2][0]<<endl;}
}
