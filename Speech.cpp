/*
Filename: Speech_V4.cpp
Author: Kenneth Johnson

============================================================================
This file contains the source code for Speech.cpp
The program allows the user to enter the name of a data file. The data is 
then read the into an array and the mean, standard deviation, variance, 
average power and average magnitude are calculated. The results are then 
output as text and graphics are used to plot the data to the console screen.
============================================================================

*/

#include "Graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

class Speech
{
public:
	//constructors & Destructor
	Speech(void); //Default constructor
	Speech(int ak, int aNpts, float aT_incr, double samples[], int aSumcount, double aSum, double aMean, double asum_power,
		   double anAverage_power, double aSum_magnitude, double anAverage_magnitude, double aVarience, double aTempvarience,
		   double aMeanSquared, string aFilename); //Regular constructor
	~Speech(void);//Destructor
	
	//mutators
	void setTheSpeech(int ak, int aNpts, float aT_incr, double samples[], int aSumcount, double aSum, double aMean, double asum_power,
					  double anAverage_power, double aSum_magnitude, double anAverage_magnitude, double aVarience, double aTempvarience,
					  double aMeanSquared, string aFilename);;//set method
	void getTheSpeech(); //get method
	void readData(); //reads data file
	void calculate(); //calculates if seismic event occurred
	void graph(); //uses graphics to display graph on console screen

private:
	int k, npts;
	float  t_incr;
	double samples[2500];
	int sumcount;
	double sum; 
	double mean;
	double sum_power;
	double average_power;
	double sum_magnitude;
	double average_magnitude;
	double varience;
	double tempvarience;
	double meanSquared;
	string filename;
};


inline Speech::Speech(void) {
	k = 0;
	npts = 0;
	t_incr = 0.0;
	int sumcount = 0;
	double sum = 0.00;
	double mean = 0.00;
	double sum_power = 0.00;
	double average_power = 0.00;
	double sum_magnitude = 0.00;
	double average_magnitude = 0.00;
	double varience = 0.00;
	double tempvarience = 0.00;
	double meanSquared = 0.00;
	filename = "an invalid filename";


	//cout << "** DEBUG FROM THE DEFAULT CONSTRUCTOR **" <<
	//	"\n k is: " << k <<
	//	"\n Number of points is: " << npts <<
	//	"\n Time increment is " << t_incr <<
	//	"\n The sumcount is: " << sumcount <<
	//	"\n The sum is: " << sum <<
	//	"\n The mean is: " << mean <<
	//	"\n The sum_power is: " << sum_power <<
	//	"\n The average_power is: " << average_power <<
	//	"\n The sum_magnitude is: " << sum_magnitude <<
	//	"\n The average_magnitude is: " << average_magnitude <<
	//	"\n The varience is: " << varience <<
	//	"\n The temp varience is: " << tempvarience <<
	//	"\n The mean squared is: " << meanSquared <<
	//	"\n The filename is: " << filename << endl << endl;

	//cout << " The sample data is: " << endl;
	//for (int k = 0; k < 2500; ++k) {
	//	samples[k] = {};
	//	cout << samples[k] << endl;
	//}

}

inline Speech::Speech(int ak, int aNpts, float aT_incr, double samples[], int aSumcount, double aSum, double aMean, double asum_power,
					  double anAverage_power, double aSum_magnitude, double anAverage_magnitude, double aVarience, double aTempvarience,
					  double aMeanSquared, string aFilename) {

	k = ak;
	npts = aNpts;
	t_incr = aT_incr;
	sumcount = aSumcount;
	sum = aSum;
	mean = aMean;
	sum_power = asum_power;
	average_power = anAverage_power;
	sum_magnitude = aSum_magnitude;
	average_magnitude = anAverage_magnitude;
	varience = aVarience;
	tempvarience = aTempvarience;
	meanSquared = aMeanSquared;
	filename = aFilename;

	//cout << "** DEBUG FROM THE REGULAR CONSTRUCTOR **" <<
	//	"\n k is: " << k <<
	//	"\n Number of points is: " << npts <<
	//	"\n Time increment is " << t_incr <<
	//	"\n The sumcount is: " << sumcount <<
	//	"\n The sum is: " << sum <<
	//	"\n The mean is: " << mean <<
	//	"\n The sum_power is: " << sum_power <<
	//	"\n The average_power is: " << average_power <<
	//	"\n The sum_magnitude is: " << sum_magnitude <<
	//	"\n The average_magnitude is: " << average_magnitude <<
	//	"\n The varience is: " << varience <<
	//	"\n The temp varience is: " << tempvarience <<
	//	"\n The mean squared is: " << meanSquared <<
	//	"\n The filename is: " << filename << endl << endl;

	//cout << " The sample data is: " << endl;
	//for (int k = 0; k < npts; ++k) {
	//	samples[k] = {};
	//	cout << samples[k] << endl;
	//}

}

inline Speech::~Speech(void) {

	//cout << "\n\n Test 4 - Destructor " << endl;
	//cout << "\n\n** DEBUG FROM DESTRUCTOR " <<
	//	"\n k is: " << k <<
	//	"\n Number of points is: " << npts <<
	//	"\n Time increment is " << t_incr <<
	//	"\n The sumcount is: " << sumcount <<
	//	"\n The sum is: " << sum <<
	//	"\n The sum_power is: " << sum_power <<
	//	"\n The average_power is: " << average_power <<
	//	"\n The sum_magnitude is: " << sum_magnitude <<
	//	"\n The average_magnitude is: " << average_magnitude <<
	//	"\n The filename is: " << filename << endl << endl;


	//cout << "\n The sample data is: " << endl;
	//for (int k = 0; k < npts; ++k) {
	//	//cout << samples[k] << endl;

	//}
}

inline void Speech::setTheSpeech(int ak, int aNpts, float aT_incr, double samples[], int aSumcount, double aSum, double aMean, double asum_power,
	double anAverage_power, double aSum_magnitude, double anAverage_magnitude, double aVarience, double aTempvarience,
	double aMeanSquared, string aFilename) {

	k = ak;
	npts = aNpts;
	t_incr = aT_incr;
	sumcount = aSumcount;
	sum = aSum;
	mean = aMean;
	sum_power = asum_power;
	average_power = anAverage_power;
	sum_magnitude = aSum_magnitude;
	average_magnitude = anAverage_magnitude;
	varience = aVarience;
	tempvarience = aTempvarience;
	meanSquared = aMeanSquared;
	filename = aFilename;

	//cout << "** DEBUG FROM setTheSpeech **" <<
	//	"\n k is: " << k <<
	//	"\n Number of points is: " << npts <<
	//	"\n Time increment is " << t_incr <<
	//	"\n The sumcount is: " << sumcount <<
	//	"\n The sum is: " << sum <<
	//	"\n The mean is: " << mean <<
	//	"\n The sum_power is: " << sum_power <<
	//	"\n The average_power is: " << average_power <<
	//	"\n The sum_magnitude is: " << sum_magnitude <<
	//	"\n The average_magnitude is: " << average_magnitude <<
	//	"\n The varience is: " << varience <<
	//	"\n The temp varience is: " << tempvarience <<
	//	"\n The mean squared is: " << meanSquared <<
	//	"\n The filename is: " << filename << endl << endl;
	//	

	//cout << " The sample data is: " << endl;
	//for (int k = 0; ak < npts; ++k) {
		//samples[k] = {};
		//cout << samples[k] << endl;
	//}
}

inline void Speech::getTheSpeech() {
	//cout << "\n\n DEBUG FROM getTheSpeech():"
	//		"\n k is: " << k <<
	//		"\n Number of points is: " << npts <<
	//		"\n Time increment is " << t_incr <<
	//		"\n The sumcount is: " << sumcount <<
	//		"\n The sum is: " << sum <<
	//		"\n The mean is: " << mean <<
	//		"\n The sum_power is: " << sum_power <<
	//		"\n The average_power is: " << average_power <<
	//		"\n The sum_magnitude is: " << sum_magnitude <<
	//		"\n The average_magnitude is: " << average_magnitude <<
	//		"\n The varience is: " << varience <<
	//		"\n The temp varience is: " << tempvarience <<
	//		"\n The mean squared is: " << meanSquared <<
	//		"\n The filename is: " << filename << endl << endl;
	//		
	//cout << " The sample data is: " << endl;
	//for (int k = 0; k < npts; ++k) {
	//	samples[k] = {};
		//cout << samples[k] << endl;
	//}
}

inline void Speech::readData() {

	//----------ASK USER TO ENTER A FILE NAME----------------------------------------
	cout << "\n To begin, please enter the filename:";
	cout << " "; cin >> filename;
	ifstream fin;
	fin.open(filename);
	cout << " " << filename << " is opening..." << endl;
	if (fin.is_open())
	{


		//----------READ THE FILE DATA INTO AN ARRAY-----------
		//cout << " The Data is: ";
		for (k = 0; k < npts; ++k)
		{
			fin >> samples[k];
			//cout << samples[k] << endl;
		}
		fin.close();

	}
	else
	{
		cout << " **ERROR! FILE NOT FOUND!" << endl;
		return readData();
	}
}

//Algorithm for Speech calculation
inline void Speech::calculate() {

	for (k = 0; k < npts; ++k)
	{
		sum = sum + samples[k];
		sumcount++;
		sum_power = sum_power + pow(samples[k], 2);
		sum_magnitude = sum_magnitude + abs(samples[k]);
	}

	mean = sum / sumcount;
	average_power = sum_power / sumcount;
	average_magnitude = sum_magnitude / sumcount;
	meanSquared = pow(mean, 2);

	for (int k = 0; k < 1000; k++)
	{

		tempvarience += pow((samples[k] - mean), 2);
	}

	tempvarience /= 1000;
	varience = tempvarience;
	double stdDev = sqrt(varience);
	cout << "\n Sum is: " << sum << endl;
	cout << " Mean is: " << mean << endl;
	cout << " Standard Deviation is: " << stdDev << '\n';
	cout << " Varience is: " << varience << '\n';
	cout << " Average power is: " << average_power << endl;
	cout << " Average Magnitude is: " << average_magnitude << endl;

}


inline void Speech::graph() {

	HWND hWnd = GetForegroundWindow();
	HDC hDC = GetDC(hWnd);



	line line1(60, 455, 0, 0, 0, 870); //(x position, y position, red, green, blue, length) draws axis
	square square1(40, 270, 18, 105, 255, 980, 355, 255, 255, 255);
	square square2(45, 275, 54, 140, 207, 970, 345, 0, 0, 0); //(x pos, y pos, red, green, blue, length, width, fill red, fill green, fill blue


	//----------------------LEGEND FOR GRAPH-----------------------------------------//
	square square3(860, 285, 255, 255, 255, 145, 70, 0, 0, 0); // creates outer box
	square square4(865, 290, 54, 140, 207, 135, 60, 0, 0, 0); // creates inner box
	line line2(915, 318, 0, 196, 0, 70);		// creates line to represent signal
	triangle triangle1(400, 455, 0, 0, 0, 200, 240, 0, 0, 0); // abscissa triangle
	triangle triangle2(400, 455, 0, 0, 0, 200, 240, 0, 0, 0); // ordinate triangle



	line line3(60, 455, 0, 0, 0, 10); //(x position, y position, red, green, blue, length) draws x-ticks
	line line4(85, 303, 0, 0, 0, 10); //(x position, y position, red, green, blue, length) draws y-ticks
	square1.draw(hDC);
	square2.draw(hDC);
	square3.draw(hDC);
	square4.draw(hDC);
	line1.draw_ax(hDC);
	line2.draw(hDC);
	line3.draw_h(hDC);
	line4.draw_v(hDC);
	triangle1.draw_h(hDC);
	triangle2.draw_v(hDC);

	//Output Graphic text
	TCHAR mytext[9] = TEXT("Time [s]");
	TextOut(hDC, 900, 475, mytext, ARRAYSIZE(mytext));

	TCHAR mytext2[10] = TEXT("Amplitude");
	TextOut(hDC, 60, 285, mytext2, ARRAYSIZE(mytext2));

	TCHAR mytext3[8] = TEXT("Signal");     // creates text for legend
	TextOut(hDC, 870, 308, mytext3, ARRAYSIZE(mytext3));

	//---------------Plot Data points--------------------------------------
	for (int k = 0; k < 1000; k++)
	{
		point* point1 = new point(93 + (0.8 * 1 * k), 455 - (105 * samples[k]), 0, 196, 0);
		point1->draw(hDC);
		delete point1;
	}

}


int main(void){
	cout << " ====== SPEECH APPLICATION ===== \n ====== Author: Kenneth Johnson =======" << endl;
	//cout << " Main has started " << endl;
	Speech s1;
	Speech s2 (1, 2500, 0.005, {}, 6, 0.256, 0.347, 0.471, 1.561, 0.678, 0.785, 0.896, 0.947,
		       2.167, "Filename2");
	s2.setTheSpeech(0, 1000, 0, {}, 0, 0, 0, 0, 0, 0, 0, 0, 0, //set values to zero for calcultaions
					0, "Filename3"); 
	s2.getTheSpeech();
	s2.readData();
	s2.calculate();
	cout << "\n** To Display the Graph, please press <Enter>.. " << endl;
	_getch();
	s2.graph();
	_getch();
	//cout << " Main has ended " << endl;
	
	return 0;

}
