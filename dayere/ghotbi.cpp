
void circle_ghotbi(int xc, int yc, int r){
    int x, y;
    double zavie;
    double radian;
    for(zavie=90; zavie>=45; zavie -= 0.1){
        radian = (zavie*3.141592)/180;
        x = r*cos(radian);
        y = r*sin(radian);
        putpixel(x+xc,y+yc,10);
        putpixel(-x+xc,y+yc,10);
        putpixel(x+xc,-y+yc,10);
        putpixel(-x+xc,-y+yc,10);
        putpixel(y+yc,x+xc,10);
        putpixel(-y+yc,x+xc,10);
        putpixel(y+yc,-x+xc,10);
        putpixel(-y+yc,-x+xc,10);
    }
}