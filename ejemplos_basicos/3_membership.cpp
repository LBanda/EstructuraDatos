/*
*   Author Ng
*
*   class example testing objects
*/


#include<iostream>

using namespace std;

//member functions
class dog{
	string color;
	int legs;
	public:
		dog(string a, int b) {color = a; legs = b;}

		 /*
		 The first const is meant to stop users to attempt to overwrite the returned value
		 check http://duramecho.com/ComputerInformation/WhyHowCppConst.html
		 const member function means that the memebers i.e. color and legs cant be modified in the fuciton.
		 */
        const int getlegs() const {return legs;} // const member function declared inline
		const string get() const {return color;} // const member function declared inline

		void show(){cout<< color << endl;} //  member function declared inline
		void setColor(const string c);  // member function declare below
};

void hello(){  // non member function becuase it is not part of any class.
	cout<< "hello world message >D" << endl;
}

void dog::setColor(const string c){   // member function of class dog.
	color =c;
	hello();
}

int main (){
	hello();
	dog firulais("brown",4);
	firulais.show();
	firulais.setColor("yellow");
	firulais.show();
	string test1 = firulais.get();
	test1 ="3";
	int leg = firulais.getlegs();
	leg=19;
	return 0;
}
