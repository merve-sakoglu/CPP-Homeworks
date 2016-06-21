/********************************
*	CSE 241 HW03            *
*	MERVE SAKOGLU           *
*	121044055               *
*	                        *
*                               *
********************************/
#include<iostream>
#include<math.h>
#include<cstdlib>
using namespace std;

const double DERECE = 180.0;
const double PI = 3.14;

class Triangle{
    public:
        Triangle();
        Triangle(double side1);
        Triangle(double side1,double side2);
        Triangle(double side1,double side2,double side3);
        double getA()const{ return a; }
        double getB()const{ return b; }
        double getC()const{ return c; }
        void set(double side1,double side2,double side);
        double angleA(Triangle angle);
        double angleB(Triangle angle);
        double angleC(Triangle angle);
        bool control(Triangle right);
        double area(Triangle area);
        double perimeter(Triangle perimeter);
        void input();
        void output()const;
    private:
        double a;
        double b;
        double c;
        void testdate();
};

void test1(Triangle& thing,Triangle& thing1);
void test2(Triangle thing2,Triangle thing3);

int main(){
    
    Triangle thing,
             thing1(1.5),
             thing2(1.5,2.0),
             thing3(3.0,4.0,5.0);
    cout << "**********TEST1**********\n";
    thing.input();
    cout << "Call By Referance\n";
    thing.output();
    test1(thing,thing1);
    thing.output();
    thing1.output();


    cout << "**********TEST2**********\n";
    cout << "Call By Value\n";
    thing2.output();
    test2(thing2,thing3);
    thing2.output();
    cout << endl;
    cout << "Perimeter of triangle : " << thing2.perimeter(thing2) << endl;
    cout << "Area of triangle : " << thing2.area(thing2) << endl;
    cout << "Angle A of triangle : " << thing2.angleA(thing2) << endl;
    cout << "Angle B of triangle : " << thing2.angleB(thing) << endl;
    cout << "Angle C of triangle : " << thing2.angleC(thing2) << endl;
    cout << endl;
    thing3.output();
    test2(thing2,thing3);
    thing3.output();

    cout << "Perimeter of triangle : " << thing3.perimeter(thing3) << endl;
    cout << "Area of triangle : " << thing3.area(thing3) << endl;
    cout << "Angle A of triangle : " << thing3.angleA(thing3) << endl;
    cout << "Angle B of triangle : " << thing3.angleB(thing3) << endl;
    cout << "Angle C of triangle : " << thing3.angleC(thing3) << endl;
    return 0;
}
Triangle::Triangle(){
    //no parameter constructor
}
Triangle::Triangle(double side1) : a(side1),b(1),c(1){
    
    testdate();
}
Triangle::Triangle(double side1,double side2) : a(side1) ,b(side2),c(1){

    testdate();
}
Triangle::Triangle(double side1,double side2,double side3) : a(side1),b(side2),c(side3){

    testdate();
}
void Triangle::testdate(){
    
    if((fabs(c-b) > a) || (a > c+b) || (a < 0)){
        cerr << "Invalid value\n";
        exit(1);
    }
    if((fabs(c-a) > b) || (b > c+a) || (b < 0)){
        cerr << "Invalid value\n";
        exit(1);
    }
    if((fabs(b-a) > c)  || (c > b+a) || (c < 0)){
        cerr << "Invalid value\n";
        exit(1);
    }

}
void Triangle::input(){
    
    cout << "A kenari uzunlugunu giriniz" << endl;
    cin >> a;
    cout << "B kenari uzunlugunu giriniz" << endl;
    cin >> b;
    cout << "C kenari uzunlugunu giriniz" << endl;
    cin >> c;
    
    testdate();
}
void Triangle::output()const{
    
    cout << "A :" << a << " ";
    cout << "B :" << b << " ";
    cout << "C :" << c << endl;

}
bool Triangle::control(Triangle right){
    if(pow(right.getA(),2) + pow(right.getB(),2) == pow(right.getC(),2))
        return true;
    else
        return false;
    if((pow(right.getB(),2) + pow(right.getC(),2) == pow(right.getA(),2)))
        return true;
    else 
        return false;
    if((pow(right.getA(),2) + pow(right.getC(),2) == pow(right.getB(),2)))
        return true;
    else 
        return false;
}
void Triangle::set(double side1,double side2,double side3){
    
    if((fabs(side3-side2) < side1) && (side1 < side3+side2))
        a = side1;
    else{
        cerr << "Invalid value\n";
        exit(1);
    }
    if((fabs(side3-side1) < side2) && (side2 < side3+side1))
        b = side2;
    else{
        cerr << "Invalid value\n";
        exit(1);
    }
    if((fabs(side2-side1) < side3) && (side3 < side2+side1))
        c = side3;
    else{
        cerr << "Invalid value\n";
        exit(1);
    }
}
double Triangle::perimeter(Triangle perimeter){

    return (perimeter.getA() + perimeter.getB() + perimeter.getC());
}
double Triangle::area(Triangle area){
    
    double u = area.perimeter(area) / 2;

    return (sqrt(u * (u-area.getA()) * (u-area.getB()) * (u-area.getC())));
}
double Triangle::angleA(Triangle angle){
    
    double side1 = angle.getA();
    double side2 = angle.getB();
    double side3 = angle.getC();
    
    double radyan1 = acos((pow(side2,2.0)+pow(side3,2.0)-pow(side1,2.0))/(2*side2*side3));

    return (radyan1 * DERECE / PI);
}
double Triangle::angleB(Triangle angle){
    
    double side1 = angle.getA();
    double side2 = angle.getB();
    double side3 = angle.getC();

    double radyan2 = acos((pow(side1,2)+pow(side3,2)-pow(side2,2)) / (2*side1*side3));

    return ((radyan2 * DERECE) / PI);
}
double Triangle::angleC(Triangle angle){
    
    double side1 = angle.getA();
    double side2 = angle.getB();
    double side3 = angle.getC();

    double radyan3 = acos((pow(side1,2)+pow(side2,2)-pow(side3,2)) / (2*side1*side2));
    
    return ((radyan3 * DERECE) / PI);
}

void test1( Triangle& thing,Triangle& thing1){
  
    thing.set(3.0,4.0,5.0);
    thing.output();
    cout << endl;
    thing1.set(30.0,40.0,50.0);
  
}
void test2(Triangle thing2,Triangle thing3){
    
    thing2.set(3.0,3.0,3.0);

    thing3.set(6.0,8.0,10.0);
    
}
