#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

int main(int argc, char** argv) {
	int points[4][2], jahat;
	double degree = 0;
	for(int i=0;i<4;i++){
		int tempX, tempY;
		cout<<"\nx"<<i+1<<": ";cin>>tempX;
		cout<<"\ny"<<i+1<<": ";cin>>tempY;
		points[i][0] = tempX;
		points[i][1] = tempY;
	}
	cout << "\nenter the degree: "; cin >> degree;
	cout << "\nenter the jahat (+1 ya -1): "; cin >> jahat;
	
	double radian = (degree * 3.14159265359)/180;
	int cosDeg = round(cos(radian));
	int sinDeg = round(sin(radian));
	
	if(jahat<0){
		sinDeg = -sinDeg;
	}
	
	double matrixT[2][2] = {
		{cosDeg, -sinDeg},
		{sinDeg, cosDeg}
	};
	
	for(int i=0;i<4;i++){
		cout<< "new x"<<i+1<<": "<< (points[i][0]*matrixT[0][0] + points[i][1]*matrixT[1][0]) << endl;
		cout<< "new y"<<i+1<<": "<< (points[i][0]*matrixT[0][1] + points[i][1]*matrixT[1][1]) << endl;
	}

	getch();
	return 0;
}

