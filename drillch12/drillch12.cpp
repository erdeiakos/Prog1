#include "Simple_window.h"
#include "Graph.h"

int main()
try {
   
    Point tl{ 101, 101 };       

    Simple_window win{ tl, 601, 401, "asd #1" };
    
 
   
    Axis xa{ Axis::x, Point{20, 301}, 280, 10, "x axis" };  

    win.attach(xa);                 
    win.set_label("asd #2"); 
     

    Axis ya{ Axis::y, Point{20, 301}, 280, 10, "y axis" };
    ya.set_color(Color::cyan);              
    ya.label.set_color(Color::dark_red);    
    win.attach(ya);
    win.set_label("asd #3");
                

    
    Function sine{ sin, 0, 101, Point{20, 150}, 1010, 50, 50 }; 
        

    win.attach(sine);
    win.set_label("asd #4");
   

   
    sine.set_color(Color::blue);   

    Graph_lib::Polygon poly;                  
    poly.add(Point{ 301, 201 });      
    poly.add(Point{ 350, 101 });
    poly.add(Point{ 401, 201 });

    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);
    win.set_label("asd #5");
    

    
    Graph_lib::Rectangle r{ Point{201, 201}, 101, 50 };
    win.attach(r);

    Closed_polyline poly_rect;
    poly_rect.add(Point{ 101, 50 });
    poly_rect.add(Point{ 201, 50 });
    poly_rect.add(Point{ 201, 101 });
    poly_rect.add(Point{ 101, 101 });
    poly_rect.add(Point{ 50, 75 });
    win.attach(poly_rect);

    win.set_label("asd #6");
  

   
    r.set_fill_color(Color::yellow);   
    poly.set_style(Line_style(Line_style::dash, 4));
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);
    win.set_label("asd #7");
   
    
    Text t{ Point{150, 150}, "Hello, graphical world!" };
    win.attach(t);
    win.set_label("asd #8");
   
    t.set_font(Font::times_bold);
    t.set_font_size(20);
    win.set_label("asd #9");

   
    Image ii{ Point{101, 50}, "neko.jpg" };
    win.attach(ii);
    win.set_label("asd #10");
    
    ii.move(101, 201);
    win.set_label("asd #11");
   
    Circle c{ Point{101, 201}, 50 };
    Mark m{ Point{101, 201}, 'x' };

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes{ Point{101, 20}, oss.str() };

    Image cal{ Point{225, 225}, "4ab.jpg" };
    cal.set_mask(Point{ 40, 40 }, 201, 150);

    win.attach(c);
    win.attach(m);

    win.attach(sizes);
    win.attach(cal);
    win.set_label("asd #12");
    win.wait_for_button();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "error\n";
    return 2;
}