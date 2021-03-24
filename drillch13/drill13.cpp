#include "simple_window.h"
#include "graph.h"

using namespace std;


int main()
{
	Point pont(3, 1);
	Simple_window nya(pont, 800, 1000, "uwu");
	Lines asd;
	for(int x=100;x<=800;x+=100)
	{
		asd.add(Point(x, 0), Point(x, 800));
	}
	for (int y = 100; y <= 800; y += 100)
	{
		asd.add(Point(0, y), Point(800, y));
	}
	nya.attach(asd);
	Vector_ref <Graph_lib::Rectangle>kerdojel;
	
	for (int i = 0; i < 800; i += 100)
	{
		kerdojel.push_back(new Graph_lib::Rectangle(Point{ i, i }, 101, 101));
		kerdojel[kerdojel.size() - 1].set_fill_color(Color::red);
		nya.attach(kerdojel[kerdojel.size() - 1]);
		
	}
	Image bored1(Point(0, 200), "bored.jpg");
	Image bored2(Point(0, 400), "bored.jpg");
	Image bored3(Point(200, 600), "bored.jpg");
	nya.attach(bored1);
	nya.attach(bored2);
	nya.attach(bored3);
	Image sadge(Point(0, 0), "sad.jpg");
	nya.attach(sadge);
	Point sadgepoint(0, 0);
	while (nya.wait_for_button())
	{
		if (sadgepoint.x < 700)
		{

			sadgepoint.x += 100;
			sadge.move(100, 0);
		}

		else if (sadgepoint.x==700 && sadgepoint.y==700)
		{
			sadge.move(-700, -700);
			sadgepoint.x -= 700;
			sadgepoint.y -= 700;
		}

		else
		{
			sadgepoint.x -= 700;
			sadgepoint.y += 100;
			sadge.move(-700, 100);
		}
	}
	return 0;
}