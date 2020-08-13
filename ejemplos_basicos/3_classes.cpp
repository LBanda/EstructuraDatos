#include <iostream>
using namespace std;


class fatherland{
	private:
		int var1;
		int var2;
		
	public:
		fatherland() {};
		fatherland(int x, int y): var1(x), var2(y){}; 
		fatherland fathersum( const fatherland, const fatherland);
		fatherland addvals(const fatherland a, const fatherland b);  // declared friend means it can access the private vars.
		friend fatherland addvals(const fatherland &a, const fatherland &b);  // declared friend means it can access the private vars, if friend was removed then there would be no acces to the variables.
		void print(){cout<< "var  "<< var1 <<  " var  " << var2 << endl;}
};

fatherland addvals(const fatherland &a, const fatherland &b) {  //non-member function, needs to be delcared friens to access variables
	fatherland c(a.var1+b.var1, a.var2+b.var2); 
	return c;
}

fatherland fatherland::fathersum(fatherland a, fatherland b){ // member function
	fatherland c;
	c.var1 = a.var1+b.var1;
	a.var1= 10000;
	c.var2 = a.var2+b.var2;
	return c;
}

int main(){
	cout<< "hello world \n";
	fatherland us(1,2);
	fatherland urss(4,5);
	fatherland mex = mex.fathersum(us,urss);
	us.print();
	urss.print();
	mex.print();
	mex = addvals(mex,urss);
	mex.print();
}


