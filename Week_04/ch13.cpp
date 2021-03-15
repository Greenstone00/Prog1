#include "Simple_window.h"
#include "Graph.h"


int main()
try {
    

    // 1.
    const Point tl {100, 100};
    Simple_window win {tl, 800, 1000, "Chapter 13 Drill"};
    win.wait_for_button();

    // 2.
    int x_size = 800;
    int y_size = 800;
    int x_grid = 100;
    int y_grid = 100;

    Lines grid;
    for (int x = x_grid; x < x_size; x += x_grid)
        grid.add(Point{x, 0}, Point{x, y_size});    
    for (int y = y_grid; y < y_size; y += y_grid)   // vízszintes grid
        grid.add(Point{0, y}, Point{x_size, y});

    grid.set_color(Color::red);
    win.set_label("Chapter 13 Drill");
    win.attach(grid);
    win.wait_for_button();

    // 3.
    Vector_ref<Rectangle> rects;
    for (int i = 0; i < x_size; i += x_grid) {
        rects.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+x_grid}});
        rects[rects.size() - 1].set_color(Color::invisible);
        rects[rects.size() - 1].set_fill_color(Color::red);
        win.attach(rects[rects.size() - 1]);
    }
    win.set_label("Chapter 13 Drill");
    win.wait_for_button();

    // 4.
    Image kep1 {Point{0,300}, "200.jpeg"};
    Image kep2 {Point{300,600}, "200.jpeg"};
    Image kep3 {Point{500,100}, "200.jpeg"};

    win.attach(kep1);
    win.attach(kep2);
    win.attach(kep3);
    win.set_label("Chapter 13 Drill");
    win.wait_for_button();


    // 5.
    Image galsses {Point{0,0},"100.jpeg"};
    galsses.set_mask(Point{100,100},200,150);

    //Image galsses {Point{0,0}, "100.jpeg"};
    win.attach(galsses);
    win.set_label("Chapter 13 Drill");
    win.wait_for_button();

    for (int i = 0; i < 8; ++i) 
    {
        for (int j = 0; j < 8; ++j) 
        {
            galsses.move(100, 0);
            win.wait_for_button();
        }
        galsses.move(-700, 100);        // buggy picit egy 3szög formában mert takarásba kerül :/
        win.set_label("Chapter 13 Drill");  
        win.wait_for_button();
    }
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "error\n";
    return 2;
}