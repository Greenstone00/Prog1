/*
    g++ ch12.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch12 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
try
{
//using namespace Graph_lib;

Point tl{100,100}; //az ablakunk bal sarka

Simple_window win {tl,600,400,"My Window"}; //600x400-as my window nevű ablak létrehozása

win.wait_for_button();

//Axis
Axis xa {Axis::x,Point{20,320},280,10, "x tengely"};
Axis ya {Axis::y,Point{20,320},280,10, "y tengely"};
ya.set_color(Color::red);
ya.label.set_color(Color::dark_green);


win.attach(xa);
win.attach(ya);
win.set_label("My Window 2&3");

win.wait_for_button();

//Function
Function sine {cos,0,100,Point{20,150},1000,50,50}; //cosinus görbe
win.attach(sine);
win.set_label("My Window 4");
win.wait_for_button();

//Polygon
sine.set_color(Color::dark_blue);

Polygon poly; //3 pontból áll, 3szög
poly.add(Point{300,200});
poly.add(Point{350,100});
poly.add(Point{400,200});

poly.set_color(Color::dark_yellow);
poly.set_style(Line_style::dash);
win.attach(poly);
win.set_label("My Window 5");
win.wait_for_button();

//Rectangle
Rectangle r {Point{250,250},100,50}; //téglalap bal felső sarka
r.set_color(Color::white);
win.attach(r);

Closed_polyline poly_rect;
poly_rect.add(Point{100,50});
poly_rect.add(Point{200,50});
poly_rect.add(Point{200,100});
poly_rect.add(Point{100,100});

poly_rect.add(Point{50,75});
win.attach(poly_rect);

win.set_label("My Window 6");
win.wait_for_button();

//Fill
r.set_fill_color(Color::cyan); //r nevű négyzet kitöltési színe
poly.set_style(Line_style(Line_style::dash,2));
poly_rect.set_style(Line_style(Line_style::dash,6));
poly_rect.set_fill_color(Color::dark_green);
win.set_label("My window 7");
win.wait_for_button();

//Text
Text t{Point{300,300}, "Ez itt a szoveg vagy mi"};
t.set_font(Font::times_bold);
t.set_font_size(60);
win.attach(t);
win.set_label("My window 8");
win.wait_for_button();

//Image
Image kep {Point{200,150},"cica.jpg"};
kep.move(100,200);
win.attach(kep);
win.set_label("My window 9-11");
win.wait_for_button();

//egyéb dolgok(kör, elipszis, meg jelölés)
Circle c {Point{700,700}, 100};

Ellipse e {Point{500,500}, 100, 50};
e.set_fill_color(Color::red);

Mark m {Point{100,200},'x'};

ostringstream oss;
oss<<"screen size: "<<x_max()<<"*"<<y_max()<<"; window size: "<<win.x_max()<<"*"<<win.y_max();
Text sizes {Point{100,20},oss.str()};

Image cal {Point{225,225},"smile.jpg"};
cal.set_mask(Point{40,40},200,150);

win.attach(c);
win.attach(e);
win.attach(m);
win.attach(sizes);
win.attach(cal);
win.set_label("My window 12");
win.wait_for_button();
}

catch (runtime_error& e)
{
	cerr << "Error: " << e.what() << endl;
	return 1;
}
catch (...)
{
	cerr << "Some error\n";
	return 2;
}





