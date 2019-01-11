#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#include<dos.h>
class Draw_Conics
{
	int x1,x2,y1,y2,h,k,r,x,y,midx,midy;
	void axes()
	{
		int gd=DETECT,gm,midx,midy;
		initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		midx=(getmaxx()/2)+350;
		midy=(getmaxy()/2)+350;
		setcolor(getmaxcolor());
		line(midx,250,0,250);
		line(325,0,325,midy);
	}
public:
	void straight_line() ;
	void Circle();
	void parabola();
	void hyperbola();
};
int main()
{
	int choice;
	Draw_Conics obj;
	clrscr();
	while(1)
	{
		clrscr();
		cout<<"enter the choice\n"<<
		"enter 1 to draw a line"<<endl<<
		"enter 2 to parabola"<<endl<<
		"enter 3 to draw circle"<<endl<<
		"enter 4 to draw ellipse"<<endl<<
		"enter 5 to draw hyperbola"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1 :
				obj.straight_line();
				break;
			case 2:
				obj.parabola();
				break;
			case 3:
				obj.Circle();
				break;
			case 4:
			       //	obj.ellipse();
				break;
			case 5:
				obj.hyperbola();
				break;
			default:
				exit(0);
		}
	}
	cout<<"\n\n\t\tThank You\n\t\tBy Pritul Dave ,Kushal Master,Rutvik Shyani\n";
	delay(5000);
	return 0;
}
void Draw_Conics::straight_line()
{
	int gd = DETECT, gm;
	int x1,x2,y1,y2;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	cout<<"enter the value of x1:";
	cin>>x1;
	cout<<"enter the value of x2:";
	cin>>x2;
	cout<<"enter the value of y1:";
	cin>>y1;
	cout<<"enter the value of y2:";
	cin>>y2;
	axes();
	line(x1,y1,x2,y2);
	getch();
	closegraph();
}
void Draw_Conics::Circle()
{
	int h,k,r;
	int gd = DETECT, gm;
	int x,y;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	cout<<"enter value of x coordinates : ";
	cin>>h;
	cout<<"enter value of y : ";
	cin>>k;
	cout<<"enter the radius : ";
	cin>>r;
	axes();
	circle(h+399,k+199,r);
	//ellipse(x+399,y+199,10,360,xr+60,yr+60);
	getch();
	closegraph();
}
void Draw_Conics::parabola()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	int x,y,a;
	int ch;
	cout<<"enter 1 to draw parabola symmetric about x axis \n"<<
	"enter 2 to draw parabola symmetric about y axis";
	cin>>ch;
	if(ch==1)
	{
		cout<<"enter 1 to draw parabola symmetric about +ve x axis \n"<<
		"enter 2 to draw parabola symmetric about -ve x axis";
		cin>>ch;
		if(ch==1)
		{	cout<<"enter the value of "<<endl;
			cin>>a;
			axes();
			for(x=1;x<300;x++)
			{
				y=2*sqrt(a*x);
				putpixel(x+325,250-y,WHITE);
				putpixel(x+325,250+y,WHITE);
			}
		}
		else
		{
			cout<<"enter the value of x"<<endl;
			cin>>x;
			axes();
			for(x=1;x<300;x++)
			{
			       y=2*sqrt(a*x);
			       putpixel(325-x,250-y,WHITE);
			       putpixel(325-x,250+y,WHITE);
			}
		}
		getch();
		closegraph();
	}
	else
	{
		cout<<"enter 1 to draw parabola symmetric about +ve y axis \n"<<
			"enter 2 to draw parabola symmetric about -ve y axis";
			cin>>ch;

		if(ch==1)
		{
			cout<<"enter the value of y"<<endl;
			cin>>y;
			axes();
			for(y=1;y<300;y++)
			{
				x=2*sqrt(4*y);
				putpixel(325+x,250-y,WHITE);
				putpixel(325-x,250-y,WHITE);
			}
		}
		else
		{
			cout<<"enter the value of y"<<endl;
			cin>>y;
			axes();
			for(y=1;y<300;y++)
			{
			       x=2*sqrt(4*y);
			      putpixel(325+x,250+y,WHITE);
			      putpixel(325-x,250+y,WHITE);
			}
		}
		getch();
		closegraph();
	}

}
void Draw_Conics::hyperbola()
{
	int gd=DETECT,gm,midx,midy,stangle,endangle,radius;
	cout<<"enter the value of radius";
	cin>>radius;
	/*cout<<"enter the value of stangle ";
	cin>>stangle;
	cout<<"enter the value of endangle ";
	cin>>endangle;      */
	if(radius>=100||radius<=0)
	{
		cout<<"out of range";
		getch();
		return;

	}
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	axes();
	midx=getmaxx()/2;
	midy=getmaxy()/2+50;
	arc(midx, midy, 45, 135, radius+50);
	arc( midx, midy-220, 225, 315, radius+50);
	getch();
	closegraph();
}
/*void
   midx = getmaxx() / 2;
   midy = getmaxy() / 2+50;
   setcolor(getmaxcolor());

   /* draw arc */


   /* clean up */
  /* getch();
   closegraph();
   return 0;  */

