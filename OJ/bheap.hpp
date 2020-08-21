#include <iostream>
using namespace std;
class Matrix  
{  
public:  
    Matrix(int mm, int nn)//构造函数  
    {  
        m=mm;  
        n=nn;  
        int i,j;  
        data=new double*[mm];  
        for(i=0;i<mm;i++)  
            data[i]=new double[nn];  
        for(i=0;i<m;i++)//矩阵所有元素清零  
            for(j=0;j<n;j++)  
                data[i][j]=0.0;  
    } //构造M行N列的矩阵  
  
    Matrix(const Matrix &src) //拷贝构造函数  
    {  
        m=src.m;  
        n=src.n;  
          int i,j;  
        data=new double*[m];//动态建立二维数组  
        for(i=0;i<m;i++)  
            data[i]=new double[n];  
        for(i=0;i<m;i++)//动态数组赋值  
            for(j=0;j<n;j++)  
                data[i][j]=src.data[i][j];  
    }  
  
    ~Matrix()//析构函数  
    {  
        for(int i=0;i<m;i++)  
            delete []data[i];  
        delete []data;  
    }  
    Matrix& operator=(const Matrix &src);//重载"="运算符  
    Matrix operator * (const Matrix &m2); //矩阵乘法 
	Matrix operator +(const Matrix &m2);//矩阵乘法的实现 
    void display();  
    void input(double a[][3]); 
	void input(double a[3]); 
 
    private:  
    double **data;  
    int m,n;//矩阵的行数，列数  
};//类定义结束  
  
Matrix& Matrix::operator=(const Matrix &src) //重载"="运算符  
{  
    int i,j;  
    for(i=0;i<m;i++)  
        delete []data[i];  
    delete []data;  
    m=src.m;n=src.n;  
    data=new double*[m];//动态建立二维数组  
    for(i=0;i<m;i++)  
        data[i]=new double[n];  
    for(i=0;i<m;i++)  
        for(j=0;j<n;j++)  
            data[i][j]=src.data[i][j];  
    return *this;  
}  
  
//矩阵*运算符重载  
Matrix Matrix::operator *(const Matrix &m2)//矩阵乘法的实现  
{  
    Matrix m3(this->m,m2.n);  
    if(this->n!=m2.m)  
    {  
        cout<<"两矩阵无法进行乘法运算.\n"<<endl;  
        exit(0);  
    }  
    int i,j,k,l;  
    for(i=0;i<this->m;i++)  
        for(j=0;j<m2.n;j++)  
        {  
            for(k=0;k<this->n;k++)  
             {  
                m3.data[i][j]+=this->data[i][k]*m2.data[k][j];  
             }  
  
        }  
    return m3;  
} 
Matrix Matrix::operator +(const Matrix &m2)//矩阵乘法的实现  
{  
    Matrix m3(this->m,m2.n);  
    if(this->n!=m2.n && this->m!=m2.m)  
    {  
        cout<<"两矩阵无法进行加法运算.\n"<<endl;  
        exit(0);  
    }  
	for(int i =0;i<m2.m;i++)
		for(int j=0;j<m2.n;j++)
			m3.data[i][j] = this->data[i][j]+m2.data[i][j];
    return m3;  
} 
  
//输入矩阵元素  
void Matrix::input(double a[][3])  
{  
    for(int i=0;i<m;i++)  
        for(int j=0;j<n;j++) 
		{
            data[i][j] = a[i][j]; 
 
		}
}  
void Matrix::input(double a[3])  
{  
    for(int i=0;i<m;i++) 
	{
        //for(int j=0;j<n;j++) 
		//{
            data[i][0] = a[i]; 
	//cout<<"i"<<a[i]<<endl;
	}
 
		//}
}
  
//显示矩阵元素  
void Matrix::display()  
{  
    int i,j;  
    for(i=0;i<m;i++)  
    {  
        for(j=0;j<n;j++)  
        {  
            cout<<data[i][j]<<" ";  
        }  
        cout<<endl;  
    }  
} 