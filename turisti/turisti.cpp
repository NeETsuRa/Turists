#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "vozlisce.h"
using namespace std;

bool vsebuje(vector <vozlisce*> a, int mat){
	for (int i=0; i<a.size(); i++){
		if (a[i]->v==mat)
			return false;
	}
	return true;
}


int maxvozl (vector <vozlisce*> a, int ** mat, int v){
	int j=0;
	int l=0;
		for (int h=0; h<v; h++){
			for (int u=0; u<v; u++){
				if (!vsebuje(a,mat[u][h]))
					if (mat [u][h]>j){
						j=mat[u][h];
						l=h;
			}
			}}
		return l;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int v;
	cout << "vnesi stevilo vozlisc" << endl;
	cin >> v;
	cout << endl;

	int p;
	cout << "vnesi stevilo povezav" << endl;
	cin >> p;
	cout << endl;
	

	int ** mat;
	mat =new int * [v];
	for (int j=0; j<v; j++)
			mat[j]=new int [v];

	for (int i=0; i<v; i++)
		for (int j=0; j<v; j++)
			mat[i][j]=-1;

	cout << "povezave ter cene teh povezav" << endl;
	for (int i=0; i<p; i++){
		int h,s,c;
		cin >> h;
		cin >> s;
		cin >> c;

		mat [s-1][h-1]=c;
		mat [h-1][s-1]=c;

	}
	cout << "vpisi od kod do kod ter koliko turistov" << endl;
	int h, s;
	cin >> h;
	cin >> s;
	cin >> mat [h-1][s-1] >>mat [s-1][h-1];

	vector <vozlisce*> a;
	vozlisce* k;
	k=new vozlisce;
	k->v=h;
	a.push_back(k);
	int i;//vozlišèe iz vektorja
	int j=maxvozl(a,mat,v);//njegov max par v matriki ki še ni porabljen







	for (int i=0; i<v; i++){
		cout << endl;
		for (int j=0; j<v; j++)
			cout << mat[i][j]<< " ";
	}



	for (int i=0; i<v; i++)
		delete[] mat[i];
	delete [] mat;

	cin.ignore();
	cin.get();
	return 0;
}