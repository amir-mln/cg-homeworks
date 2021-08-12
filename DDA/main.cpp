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

void change(float *one, float *two){
	float temp = *one;
	*one = *two;
	*two = temp;
}

void khat_dda(float x0, float y0, float xn, float yn, int n){
	if(x0 == xn && y0 != yn){
		// khat amoodi
		for(int i = y0; i <= yn; i++){
			khat_zakhim_x(x0, i, n);
		}
	} else if(x0 != xn && y0 == yn){
		// khat ofoghi
		for(int i = x0; i <= xn; i++){
			khat_zakhim_y(i, y0, n);
		}
	}else {
		
		float m = (yn - y0) / (xn - x0), x, y;
		
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
			cout << "khat ba shib tond\n";
			if(y0 > yn){
				change(&y0, &yn);
				change(&x0, &xn);
			}
			x = x0;
			for(float i = y0; i <= yn; i++){
				cout<< "\nX: "<<x<<" Y: "<<i<<endl;
				khat_zakhim_x(int(x), int(i), n);
				x += 1/m;	
			}
			
		}
		if(fabs(m) < 1){
			// khat ba shib kond
			cout << "khat ba shib kond\n";
			if(x0 > xn){
				change(&y0, &yn);
				change(&x0, &xn);
			}
			y = y0;
			for(float i = x0; i <= xn; i++){
				cout<< "\nX: "<<i<<" Y: "<<y<<endl;
				khat_zakhim_y(int(i), int(y), n);
				y += m;	
			}
			
		}
	}
};

int main(int argc, char** argv) {
	 
	 int x0, y0, xn, yn, n;
	 cout << "\nenter the first x: "; cin >> x0;
	 cout << "\nenter the first y: "; cin >> y0;
	 cout << "\nenter the last x: "; cin >> xn;
	 cout << "\nenter the last y: "; cin >> yn;
	 cout << "\nenter the width: "; cin >> n;
	 
	 initwindow(300, 300);
	 khat_dda(x0, y0, xn, yn, n);
	 
	 getch();
	return 0;
}


