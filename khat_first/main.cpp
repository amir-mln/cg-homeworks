 #include <iostream>
 #include <graphics.h>
 #include <conio.h>
 #include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void khat_first(int x0, int y0, int xn, int yn){
	if(x0 == xn && y0 != yn){
		// khat amoodi
		for(int i = y0; i <= yn; i++){
			putpixel(x0, i, 10);
		}
	} else if(x0 != xn && y0 == yn){
		// khat ofohi
		for(int i = x0; i <= xn; i++){
			putpixel(i, yn, 10);
		}
	}else {
		
		float m = (yn - y0) / (xn - x0), b = y0 - ( m * x0 ), x, y;
		
		if(fabs(m) == 1){
			// khat ghotri
			y = int(y0);
			for(int i = x0; i <= xn; i++){
				putpixel(i,y,10);
				y++;
			}
		}
		if(fabs(m) > 1){
			// khat ba shib tond
			for(int i = y0; i <= yn; i++){
				x = (i - b) / m;
				putpixel(int(x), i, 10);	
			}
			
		}
		if(fabs(m) < 1){
			// khat ba shib tond
			for(int i = x0; i <= xn; i++){
				y = m*i + b;
				putpixel(i, int(y), 10);	
			}
			
		}
	}
};

int main(int argc, char** argv) {
	 
	 int x0, y0, xn, yn;
	 cout << "\nenter the first x: "; cin >> x0;
	 cout << "\nenter the first y: "; cin >> y0;
	 cout << "\nenter the last x: "; cin >> xn;
	 cout << "\nenter the last y: "; cin >> yn;
	 
	 initwindow(300, 300);
	 khat_first(x0, y0, xn, yn);
	 
	 getch();
	return 0;
}

