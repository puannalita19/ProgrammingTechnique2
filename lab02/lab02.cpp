#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Do not modify the class declaration
class Point{
	private:
		double x, y;
	public:
		Point(double _x=0, double _y=0);
		void setX(double _x);
		void setY(double _y);
		double getX() const;
		double getY() const;
		
		Point operator+ (const Point &right);
		
		
		double operator- (const Point &right);
		Point operator/ (double);
};

// The defintion of some of the methods are given:
Point::Point(double _x, double _y){
 	x = _x; y = _y;
}

void Point::setX(double _x){
	x = _x; 	
}

void Point::setY(double _y){
	y = _y; 	
}

double Point::getX()const{
	return x;
}

double Point::getY()const{
	return y;
}




// Task 1: Complete the definition of the overlaoded operator + (addition). 
//         This operator adds up each coordinate of two points. 
//         For example, if p1 = (1,2) and p2 = (5,7), then p1 + p2 = (6, 9)      

Point Point::operator+ (const Point &right)
{
	Point result (x + right.x, y + right.y);
	return result;
	//result.x = x + right.x;
	//result.y = y + right.y;


}

// Task 2: Complete the definition of the overlaoded operator - (subtraction).  
//         This operator calculates the distance between two points.                     
//         For example, if p1 = (1,2) and p2 = (5,7), then p1 - p2 = 6.403       

double Point::operator- (const Point &right)
{
	double dx = x + right.x;
	double dy = y + right.y;
	
	double distance = sqrt (pow (dx,2) + pow (dy,2));
	return distance;


}

// Task 3: Complete the definition of the overlaoded operator / (division). 
//         This operator divides each coordinate with the right operand.
//         For example, if p = (1,2), then p / 2.0 = (0.5, 1.0)                  

Point Point::operator/ (double right)
{
	Point divisor ( x/right, y/right);
	return divisor;




}

int main()
{
	Point vertices[20];  // The list of verices of a polygon
	int nVertex;         // The number of points (vertices) entered by the user.
	Point center;        // The average or center point of the polygon.  
	
	cout << showpoint << fixed << setprecision(1);
	
	cout << "Enter the number of vertices of a polygon => ";
	cin >> nVertex;
	
	// Task 4: Using a proper loop, read a list 
	//          of points from the keyboard.
	double x,y;
	for (int i=0; i<nVertex; i++)
	{
		cout<<"Enter vertex "<<i+1<< " =>";
		cin>>x >>y;
		vertices [i].setX(x);
		vertices [i].setY(y);
	}                                     
	




	
	// Task 5: Using another loop, calculate the center point by 
	//         taking the average of the vertices of the polygon.                
	
	for (int i=0; i<nVertex; i++)
	{
		center = center + vertices[i];
	}
	
	center = center / nVertex;


	
	// To print the center point.
	cout << "The center is, x=" << center.getX() << " y=" << center.getY() << endl << endl;

	// Task 6: Using another loop, calculate the distance of each 
	//         vertex to the center point of the polygon.                        
	cout << "Vertex \t Coordinates \t Distance to center" << endl;
	for (int i=0; i<nVertex; i++){ 
	cout<<i+1<<"\t ("<<vertices[i].getX()<<","<<vertices[i].getY()<<")\t\t"<<vertices[i] -center<<endl;


		
    }  
   
   return 0;
}

