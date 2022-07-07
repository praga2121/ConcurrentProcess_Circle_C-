/*REFERENCES:
1. https://www.tutorialspoint.com/cplusplus/cpp_multithreading.htm#:~:text=Multithreading%20is%20a%20specialized%20form,%2Dbased%20and%20thread%2Dbased.
2. https://www.code4example.com/cpp/cpp-program-to-calculate-area-and-perimeter-of-circle/
3. https://www.techcrashcourse.com/2017/01/cpp-program-to-calculate-area-circumference-of-circle.html
*/

#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
#include <thread> //Multithreading 

using namespace std;
float circleArea [10]; // To tabulate 10 inputs into the array.
float circlePerimeter [10]; //To tabulate 10 inputs into the array.


void circle(double r, int i){
	
	double radius = r;
		
		//Calculating the area of the circle using the formula :A = ?r2 (PI * radius * radius)
        int CalculateArea = (int)((M_PI*radius*radius) * 100 + .5);
        float area = (CalculateArea/100.0)*1.00;
        
        //Calculate the perimeter of the circle using the formula : : 2?r (2 * PI * radius)
        int CalculatePerimeter = (int)((2*M_PI*radius) * 100 + .5); 
		float perimeter = (CalculatePerimeter/100.0)*1.00;
		
		//Display the perimeter and area of circles inputted in the array form. 
        circleArea [i]= area;
        circlePerimeter [i]= perimeter;
}

int main()
{
	double radius;
    int array[10];
    
	for(int i=0;i<10;i++){
		cout << "Radius of Circle "<<i+1<<": ";
    	cin >> radius;
    	
    	array[i]=radius;
	}
	//creating the thread. 
	thread c1(circle,array[0],0);
	thread c2(circle,array[1],1);
	thread c3(circle,array[2],2);
	thread c4(circle,array[3],3);
	thread c5(circle,array[4],4);
	thread c6(circle,array[5],5);
	thread c7(circle,array[6],6);
	thread c8(circle,array[7],7);
	thread c9(circle,array[8],8);
	thread c10(circle,array[9],9);
	
	c1.join();
	c2.join();
	c3.join();
	c4.join();
	c5.join();
	c6.join();
	c7.join();
	c8.join();
	c9.join();
	c10.join();
	
	//tabulate the arrays
    cout
    	<< "\n"
        << left
        << setw(10)
        << "No."
        << left
        << setw(10)
        << "Radius"
        << left
        << setw(13)
        << "Area"
        << left
        << setw(10)
        << "Perimeter"
        << endl;

	//tabulate the arrays
    for (int i = 0; i < 10; i++)
    {
        cout
            << left
            << setw(10)
            << i+1
            << left
            << setw(10)
            
            <<array[i]
            << left
            << setw(13)
  
            <<circleArea[i]
            << left
            << setw(10)
     
            <<circlePerimeter[i]
            << endl;
    }
    return 0;
}
