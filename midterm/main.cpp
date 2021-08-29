#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <math.h>
using namespace std;
// molaeyan 952272327
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
			putpixel(x0, y0, 10); // tu halghe for, x0 va y0 putpixel nemishan.
			p = (2 * deltaY) - deltaX;
			Xi= x0;
			Yi= y0;
			for(int k=0; k < deltaX; k++ ){
				if(p<0){
					p = p + (2 * deltaY);
					// Yk = Yk+1 avaz nemikonim
				}else{
					p = p + (2 * deltaY) - (2 * deltaX);
					Yi++;
				}
				Xi++;
				putpixel(Xi, Yi, 10);
			}						
		}
		if(m > 1){
			// khat ba shib tond
			putpixel(x0, y0, 10); // tu halghe for, x0 va y0 putpixel nemishan.
			p = (2 * deltaX) - deltaY;
			Xi= x0;
			Yi= y0;
			for(int k=0; k < deltaY; k++ ){
				if(p<0){
					p = p + (2 * deltaX);
					// Xk = Xk+1 avaz nemikonim
				}else{
					p = p + (2 * deltaX) - (2 * deltaY);
					Xi++;
				}
				Yi++;
				putpixel(Xi, Yi, 10);
			}						
		}
	}
}

void mosallas(int x1, int y1, int x2, int y2, int x3, int y3){
	lineB(x1, y1, x2, y2);
	lineB(x2, y2, x3, y3);
	lineB(x1, y1, x3, y3);
}

void davaran_va_print(int x1, int y1, int x2, int y2, int x3, int y3, double radian, int jahat){
	int cosDeg = cos(radian);
	int sinDeg = sin(radian);
	if(jahat<0){
		sinDeg = -sinDeg;
	}
	double matrixT[2][2] = {
		{cosDeg, -sinDeg},
		{sinDeg, cosDeg}
	};
	
	int m2[3][2] = { 
		{ (x1*matrixT[0][0] + y1*matrixT[1][0]) , (x1*matrixT[0][1] + y1*matrixT[1][1]) }, 
		{ (x2*matrixT[0][0] + y2*matrixT[1][0]) , (x2*matrixT[0][1] + y2*matrixT[1][1]) }, 
		{ (x3*matrixT[0][0] + y3*matrixT[1][0]) , (x3*matrixT[0][1] + y3*matrixT[1][1]) }, 
	};
	
	for(int i=0; i<3; i++){
		cout<< "x"<< i+1 << " jadid: " << m2[i][0] <<", y"<< i+1 << " jadid: "<<m2[i][1]<<endl;
	}
	
	mosallas(x1, y1, x2, y2, x3, y3);
	mosallas(m2[0][0], m2[0][1], m2[1][0], m2[1][1], m2[2][0], m2[2][1]);

}

int main(int argc, char** argv) {
	int x1, y1, x2, y2, x3, y3, jahat;
	double degree = 0;
	
	 cout << "\nenter the first x: "; cin >> x1;
	 cout << "\nenter the first y: "; cin >> y1;
	 cout << "\nenter the second x: "; cin >> x2;
	 cout << "\nenter the second y: "; cin >> y2;
	 cout << "\nenter the third x: "; cin >> x3;
	 cout << "\nenter the third y: "; cin >> y3;
	 cout << "\nenter the degree: "; cin >> degree;
	 cout << "\nenter the jahat (+1 ya -1): "; cin >> jahat;
	double degreeToRadian = (degree * 3.14159265359)/180;
	initwindow(300,300);
	davaran_va_print(x1, y1, x2, y2, x3, y3, degreeToRadian, jahat);

	getch();
	return 0;
}
