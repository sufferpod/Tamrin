#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Date
{
public:
    int year, month, day;
    void print() { cout << setfill('0') << setw(2) << year << '/' << setfill('0') << setw(2) << month << '/' << setfill('0') << setw(2) << day << endl; }
    Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {}
};

class Author
{
public:
    string firstName, lastName;
    void print() { cout << "Author: " << firstName << ' ' << lastName << endl; }
    Author(string fn, string ln) : firstName(fn), lastName(ln) {}
};

class Article
{
protected:
    string title, body;
    Date date;
    Author author;

public:
    virtual void print() = 0;
    Article(string ti, string bo, Date da, Author au) : title(ti),
                                                        body(bo), date(da), author(au) {}
};

class Lecture : public Article
{
private:
    string jornal;

public:
    Lecture(string jo, string ti, string bo, Date da, Author au) : Article(ti, bo, da, au), jornal(jo) {}
    void print()
    {
        cout << "jornal title: " << jornal << '\n'
             << '\t' << body << endl
             << "Date: ";
        date.print();
        author.print();
        cout << endl;
    }
};

class Paper : public Article
{
private:
    string affiliation;

public:
    Paper(string af, string ti, string bo, Date da, Author au) : Article(ti, bo, da, au), affiliation(af) {}
    void print()
    {
        cout << "affiliation: " << affiliation << '\n'
             << '\t' << body << endl
             << "Date: ";
        date.print();
        author.print();
        cout << endl;
    }
};
int main()
{
    Article *X, *Y, *Z;
    Y = new Lecture("Khanbook", "sadra", "body", Date(3, 3, 3), Author("mobina", "miri"));
    Z = new Paper("Khansar", "sadra", "body", Date(3, 3, 3), Author("mobina", "miri"));
    Y->print();
    Z->print();
    return 0;
}
#w
