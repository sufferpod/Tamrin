#include <iostream>
#include <string>
using namespace std;

class Date
{
public:
    int year, month, day;
    void print() { cout << year << '/' << month << '/' << day << endl; }
    Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {}
};

class Author
{
public:
    string firstName, lastName;
    void print() { cout << "Author: " << firstName << ' ' << lastName << endl; }
    Author(string fn = "none", string ln = "none") : firstName(fn), lastName(ln) {}
};

class Article
{
protected:
    string title, body;
    Date date;
    Author author;

public:
    virtual void print() = 0;
    Article(string ti = "none", string bo = "none", Date da = {0, 0, 0}, Author au = {"none", "none"}) : title(ti),
                                                                                                         body(bo), date(da), author(au) {}
};

class Lecture : public Article
{
private:
    string jornal;

public:
    Lecture(string jo = "none") : Article(), jornal(jo) {}
    void print()
    {
        cout << "jornal title: " << jornal << '\n'
             << '\t' << body << endl
             << "Date: ";
        date.print();
        cout << "Author: ";
        author.print();
        cout << endl;
    }
};

class Paper : public Article
{
private:
    string affiliation;

public:
    Paper(string af = "khansar") : Article(), affiliation(af) {}
    void print()
    {
        cout << "affiliation: " << affiliation << '\n'
             << '\t' << body << endl
             << "Date: ";
        date.print();
        cout << "Author: ";
        author.print();
        cout << endl;
    }
};
int main()
{
    Article *X, *Y, *Z;
    Y = new Lecture();
    Z = new Paper();
    Y->print();
    Z->print();
    return 0;
}
