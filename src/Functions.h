#pragma once
#include<opencv2/opencv.hpp>
#include<vector>
using namespace std;
using namespace cv;

///f_max: ia ca parametru un std::vector<int> si intoarce valoarea maxima din acesta.
double f_max(vector<int> v);

///DrawLine:   creaza o linie dreapta intre doua puncte.
///@param -p0, p1 punctele intre care se creaza linia (elementul first = cu coordonata y si second = cu coordonata x).
///@param -r, g, b culoarea pe care o va avea linia in format RGB.
///@param -img este imaginea in care se va trasa linia.
void DrawLine(pair<int, int> p0, pair<int, int>p1, int r, int g, int b, Mat& img);

///CreateVecForHist: scaleaza numarul aparitiilor diferitelor nuante de culoare sa incapa intre 0 si 100.
///@param -color vectorul cu intesitatile fiecarei nuante de o anumita culoare.
///@param -hist matricea in care se va realiza histograma.
///@param -vec vectorul in care se vor afla coordonatele punctelor care indica intensitatea nuantelor culorii scalate astfel incat sa cuprinda valori intre 0 si 100.
void CreateVecForHist(vector<int> color, Mat hist, vector<pair<int, int>>& vec);

///showImg:    creaza o fereastra de tipul WINDOW_FREERATIO .
///@param -name numele ferestrei.
///@param -img imaginea care urmeaza sa fie afisata in fereastra.
///@param -pozX, pozY pozitia unde urmeaza sa fie afisata fereastra pe ecran.
///@param -length, height reprezinta lungimea si inaltimea imagini
void showImg(string name, Mat img, int pozX, int pozY, int length, int hight);