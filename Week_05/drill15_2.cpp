#include "std_lib_facilities.h"

//1es Struct Person --string name and age 
struct Person {
    Person() : first_n(""), second_n(""), ag(0) { } //name => fn and sn
    Person(string fn, string sn, int age) :first_n(fn), second_n(sn), ag(age)
    {
        //7es kivételek
        const string ill_chars = ";:\"'[]*&^%$#@!";
        for (int i = 0; i<fn.size(); ++i)
        {
            for (int j = 0; j<ill_chars.size(); ++j)
            {
                if (fn[i]==ill_chars[j]) error("illegal character: ",string(1,fn[i]));
            }
        }

        for (int i = 0; i<sn.size(); ++i)
        {
            for (int j = 0; j<ill_chars.size(); ++j)
            {
                if (sn[i]==ill_chars[j]) error("illegal character: ",string(1,sn[i]));
            }
        }

        if (ag<0 || ag>=150) error("Age must be between 1 and 150.");
    }

    //5ös
    string first_name() const { return first_n; }
    string second_name() const { return second_n; }
    int age() const { return ag; }
private:
    string first_n;
    string second_n;
    int ag;
};


//6os
istream& operator>>(istream& is, Person& p)
{
    string fname, sname;
    int age;
    is >> fname >> sname >> age;
    if (!is) return is;
    p = Person(fname,sname,age);
    return is;
}

ostream& operator<<(ostream& os, const Person& p)
{
    return os << "Name: " << p.first_name() << ' ' << p.second_name() << ", age: " << p.age();
}

int main()
try {
   //2es
    /*
        Person goofyperson;
    goofyperson.n = "Goofy";
    goofyperson.a = 63;
    cout << "Name: " << goofyperson.n << ", age: " << goofyperson.a << endl;

    //3as
    cout << "Enter name and age: ";
    Person példa;
    cin >> név;
    cout << név << endl;
    */
    //8as from imput to vector
    vector<Person> persons;
    Person kovetkezo;
    cout << "Please enter first name, second name, and age 3 times!" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cin >> kovetkezo;
        persons.push_back(kovetkezo);
    }
    
    for (int i = 0; i < persons.size(); ++i) cout << persons[i] << endl;

}

catch(exception& e){
    cerr << e.what() << endl;
    return 1;
}catch(...){ 
    cerr << "Something went wrong" << endl;
    return 2;
}