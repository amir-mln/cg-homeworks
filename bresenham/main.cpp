#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <math.h>
using namespace std;

void change(int *one, int *two){
	float temp = *one;
	*one = *two;
	*two = temp;
}

void lineB(int x0, int y0, int xn, int yn){
	
	if(x0 > xn){
		change(&y0, &yn);
		change(&x0, &xn);
	}
	
	if(x0 == xn && y0 != yn){
		// khat amoodi
		for(int i = y0; i <= yn; i++){
			putpixel(x0, i, 10);
		}
	} else if(x0 != xn && y0 == yn){
		// khat ofohi
		for(int i = x0; i <= xn; i++){
			putpixel(i, y0, 10);
		}
	} else {
		float deltaX= xn-x0, deltaY= yn-y0, m= fabs(deltaY/deltaX), p;
		int Xi, Yi;
		if(m == 1){
			// khat ghotri
			Yi = y0;
			for(int i = x0; i <= xn; i++){
				putpixel(i,Yi, 10);
				Yi++;
			}
		}
		if(m < 1){
			// khat ba shib kond
			cout<< "\nm: "<<m<<" -> shib kond.\n";
			putpixel(x0, y0, 10); // tu halghe for, x0 va y0 putpixel nemishan.
			p = (2 * deltaY) - deltaX;
			Xi= x0;
			Yi= y0;
			for(int k=0; k < deltaX; k++ ){
				cout<< "p: "<< p;
				if(p<0){
					p = p + (2 * deltaY);
					// Yk = Yk+1 avaz nemikonim
				}else{
					p = p + (2 * deltaY) - (2 * deltaX);
					Yi++;
				}
				
				Xi++;
				putpixel(Xi, Yi, 10);
				cout<< " X: "<< Xi << " Y: " << Yi <<"\n";
			}						
		}
		if(m > 1){
			// khat ba shib tond
			cout<< "\nm: "<<m<<" -> shib tond.\n";
			putpixel(x0, y0, 10); // tu halghe for, x0 va y0 putpixel nemishan.
			p = (2 * deltaX) - deltaY;
			Xi= x0;
			Yi= y0;
			for(int k=0; k < deltaY; k++ ){
				cout<< "p: "<< p;
				if(p<0){
					p = p + (2 * deltaX);
					// Xk = Xk+1 avaz nemikonim
				}else{
					p = p + (2 * deltaX) - (2 * deltaY);
					Xi++;
				}
				
				Yi++;
				putpixel(Xi, Yi, 10);
				cout<< " X: "<< Xi << " Y: " << Yi <<"\n";
			}						
		}
	}
}

int main(int argc, char** argv) {
	int x0, y0, xn, yn;
	 cout << "\nenter the first x: "; cin >> x0;
	 cout << "\nenter the first y: "; cin >> y0;
	 cout << "\nenter the last x: "; cin >> xn;
	 cout << "\nenter the last y: "; cin >> yn;
	 
	initwindow(100, 100);
	lineB(x0, y0, xn, yn);
	
	getch();
	return 0;
}
