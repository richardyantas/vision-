#ifndef INCLUDES_H
#define INCLUDES_H value

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>

#include <iostream>
#include <vector>
#include <cmath>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//Usefull macros
#define for_i(n) for(int i = 0; i < n;i++)

using namespace std;
using namespace cv;

#define windowName "video"
#define windowGray "gray"

enum Pattern{CHESSBOARD,CIRCLES_GRID,ASYMMETRIC_CIRCLES_GRID,RINGS_GRID};
enum modes{DETECT_MODE,CALIBRATION_MODE,UNDISTORTION_MODE};

//RING GRID FUNCTION
bool findRingsGridPattern(cv::Mat Input, cv::Size size, std::vector<cv::Point2f>& points, bool& isTracking, std::vector<cv::Point2f>& oldPoints);
// RING PATTERN DETECTION ADDITIONAL FUNCTIONS
vector<Point2f> getControlPoints(const vector<Point2f> & centers);
bool FindRingPattern(vector<Point2f> &probableCPs,int num_rows,int num_cols);
bool isColinear(Vec4f line, Point2f point);

// Funciones Adicionales para la Matrix Intrinseca
void calcBoardCornerPositions(cv::Size size, float squareSize, std::vector<cv::Point3f> &corners, int patternType);
double computeReprojectionErrors(const std::vector< std::vector<cv::Point3f> >& objectPoints,
									const std::vector< std::vector<cv::Point2f> >& imagePoints,
									const std::vector<cv::Mat>& rvecs,const std::vector<cv::Mat>& tvecs, 
									const cv::Mat& cameraMatrix, const cv::Mat& distCoeffs,
									std::vector<float> & perFrameErrors);

//Funciones para Generar los Numeros Combinatorios
void printCombination(std::vector< std::vector<int> >& v, int arr[], int n, int r);
void combinationUtil(std::vector< std::vector<int> >& v, int arr[], std::vector<int> &data, int start, int end, int index, int r);
std::vector< std::vector<int> > GenerateCombinations(int n, int r);


// Otras Funciones
bool cmpx(Point2f a,Point2f b);
bool cmpy(Point2f a, Point2f b);
float dist(Point2f a, Point2f b);

float StandarDesviation(const std::vector<float> & values );
float SimpleAverage(const std::vector<float> & v);

//Calcula una linea cada cierta cantidad de puntos
float getAvgColinearityFromVector(const std::vector<cv::Point2f>& PointBuffer, cv::Size size);
float printAvgColinearity(const std::vector<float>& v);

//templates

//Funcion para imprimir los valores de un vector
template <typename T>
void PrintSTDVector(const std::vector<T>&v){
	cout << "[";
	for_i(v.size())
		cout << v[i] << ",";
	cout << "]\n";
}


#endif // INCLUDES_H