#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <math.h>
using namespace std;


void beizi(int rx, int ry, int xc, int yc){
	int x, y, rx2, ry2, m, n;
	float p;
	x= 0;
	y= ry;
	rx2= rx*rx;
	ry2= ry*ry;
	m= 2*ry2*x;
	n= 2*rx2*y;
	p= ry2 - (rx2*ry) + (rx2 / 4);
	putpixel(x+xc,y+yc,10);
	putpixel(x+xc,-y+yc,10);
	cout<< "\n****************************\n";
	cout<< "p1 avali: " << p << endl;
	while(m<=n){
		x++;
		if(p<0){
			p = p + (2*ry2*x) + ry2; 
		}else{
			y--;
			p = p + (2*ry2*x) - (2*rx2*y) + ry2;
		}
		m= 2*ry2*x;
		n= 2*rx2*y;
		cout<< "p1: "<< p <<" x: "<< x <<" y: "<< y <<" m: "<< m <<" n: "<< n << endl;
		putpixel(x+xc,y+yc,10);
		putpixel(-x+xc,y+yc,10);
		putpixel(x+xc,-y+yc,10);
		putpixel(-x+xc,-y+yc,10);
	}
	cout<< "\n****************************\n";
	p= ry2*((x+0.5)*(x+0.5)) + rx2*((y-1)*(y-1)) - rx2*ry2;
	cout<< "p2 avali: " << p << endl;
	while(y>0){
		y--;
		if(p<0){
			x++;
			p = p + (2*ry2*x) - (2*rx2*y) + rx2;
		}else{
			p = p - (2*rx2*y) + rx2;
		}
		cout<< "p2: "<< p <<" x: "<< x <<" y: "<< y <<" m: "<< m <<" n: "<< n << endl;
		putpixel(x+xc,y+yc,10);
		putpixel(-x+xc,y+yc,10);
		putpixel(x+xc,-y+yc,10);
		putpixel(-x+xc,-y+yc,10);
	}
}

void beizi_por(int rx, int ry, int xc, int yc){
	
	if(rx > ry){
		while(ry > 1){
			beizi(rx, ry, xc, yc);
			ry--;
			rx--;
		}
		while(rx > 1){
			beizi(rx, ry, xc, yc);
			rx--;
		}
	}else{
		while(rx > 1){
			beizi(rx, ry, xc, yc);
			ry--;
			rx--;
		}
		while(ry > 1){
			beizi(rx, ry, xc, yc);
			ry--;
		}
	}
	putpixel(xc, yc, 10);

}

int main(int argc, char** argv) {
	int xc, yc, rx, ry;
	cout<<"enter xc: ";cin>>xc;
	cout<<"enter yc: ";cin>>yc;
	cout<<"enter rx: ";cin>>rx;
	cout<<"enter ry: ";cin>>ry;
	initwindow(250,250);
	beizi_por(rx, ry, xc, yc);

	getch();
	return 0;
}
