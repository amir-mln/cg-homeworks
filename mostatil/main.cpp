#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <math.h>
using namespace std;

/* amir mahdi molaeyan 952272327 */

void khat_zakhim_x(int x, int y, int n){
	if(n % 2 == 1){
		for(int i= (-n/2) + x; i <= (n/2) + x; i++){
			putpixel(i, y, 10);
		}
	} else {
		for(int i= (-n/2) + x; i < (n/2) + x; i++){
			putpixel(i, y, 10);
		}
	}
}

void khat_zakhim_y(int x, int y, int n){
	if(n % 2 == 1){
		for(int i= (-n/2) + y; i <= (n/2) + y; i++){
			putpixel(x, i, 10);
		}
	} else {
		for(int i= (-n/2) + y; i < (n/2) + y; i++){
			putpixel(x, i, 10);
		}
	}
}

void change(int *one, int *two){
	int temp = *one;
	*one = *two;
	*two = temp;
}

void khat_first(int x0, int y0, int xn, int yn, int n){
	if(x0 > xn || y0 > yn){
		change(&y0, &yn);
		change(&x0, &xn);
	}
	
	if(x0 == xn && y0 != yn){
		// khat amoodi
		for(int i = y0; i <= yn; i++){
			khat_zakhim_x(x0, i, n);
		}
	} else if(x0 != xn && y0 == yn){
		// khat ofohi
		for(int i = x0; i <= xn; i++){
			khat_zakhim_y(i, y0, n);
		}
	}else {
		
		float m = (yn - y0) / (xn - x0), b = y0 - ( m * x0 ), x, y;
		
		if(fabs(m) == 1){
			// khat ghotri
			y = int(y0);
			for(int i = x0; i <= xn; i++){
				khat_zakhim_x(i,y, n);
				y++;
			}
		}
		if(fabs(m) > 1){
			// khat ba shib tond
			for(int i = y0; i <= yn; i++){
				x = (i - b) / m;
				khat_zakhim_x(int(x), i, n);	
			}
			
		}
		if(fabs(m) < 1){
			// khat ba shib tond
			for(int i = x0; i <= xn; i++){
				y = m*i + b;
				khat_zakhim_y(i, int(y), n);	
			}
			
		}
	}
};

void mostatil(int x0, int y0, int xn, int yn, int n){
	khat_first(x0, y0, xn, y0, n);
	khat_first(xn, y0, xn, yn, n);
	khat_first(xn, yn, x0, yn, n);
	khat_first(x0, yn, x0, y0, n);
}

int main(int argc, char** argv) {
	int x0, y0, xn, yn, n;
	 cout << "\nenter the first x: "; cin >> x0;
	 cout << "\nenter the first y: "; cin >> y0;
	 cout << "\nenter the last x: "; cin >> xn;
	 cout << "\nenter the last y: "; cin >> yn;
	 cout << "\nenter the width: "; cin >> n;
	 
	 initwindow(300, 300);
	 mostatil(x0, y0, xn, yn, n);
	 
	 getch();
	return 0;
}
