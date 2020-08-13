

#include <iostream>
using namespace std;

// create a main class
class Book {

	protected:  //protected so Comic can access them.
		int pages, year;
		string  title, author;

	public:
		Book(){pages = 0; year =0; title =""; author = ""; }
		Book(int p, int y, string t, string a) : pages(p), year(y), title(t), author (a) {};
		int get_pages() const {return pages;}
		int get_year() const{ return year;}
		string get_title() const {return title;}
		string get_author() const {return author;}
		void show()const {cout<< "\n("<< year << ")," << author << ". " << title << " pages:" << pages <<"\n";}
};

//create derivated class 1
class Comic : public Book{
	string artist, company;
	public:
		Comic(int p, int y, string t, string a, string art, string comp) : Book(p,y,t,a), artist(art), company(comp){};
		void set_artist(string a){ artist =a;}
		void set_company(string a){company =a;}
		void show()const{cout<< "\n("<< year << "), author " << author  << ". Illustrated by "<< artist<< ". " << title << " pages:" << pages <<", " << company <<"\n";} // overide of show
};


class Novel : public Book{
	string editorial;
	public:
		Novel(int p, int y, string t, string a, string comp) : Book(p,y,t,a),  editorial(comp){};
		void show()const{cout<< "\n("<< year << "), author " << author  << ". " << title << " pages:" << pages <<", ed." << editorial <<"\n";} // overide of show
};

int main (){
	Book some(300, 2014,"AI for kids", "Newell");
	some.show();
	Comic xmen121(221, 2015, "Uncanny Xmen", "Stan Lee", "Joe ", "Marvel");
	xmen121.show();
	xmen121.set_artist("Joe Camaro");
	xmen121.set_company("Marvel");
	xmen121.show();
	Novel good_omens(435,1990,"Good Omens", "Sir Terry P. & Neil Gayman","Lost tales");
	good_omens.show();
	Book(xmen121).show();// cast and object as its parent
	return 0;
}
