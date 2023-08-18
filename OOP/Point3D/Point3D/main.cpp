
#include"Point.h"
#include<algorithm>
#include <vector>
#include <set>
using namespace std;
template <class T>
void readfile(vector<Point<T>>&lsp,string filename) {
	lsp.clear();
	ifstream ifs(filename);
	if (!ifs.is_open()) {
		cout << "Khong mo duoc file" << endl;
		return;
	}
	int n;
	ifs >> n;
	ifs.ignore();
	for (int i = 0; i < n; i++)
	{
		Point<T>* p = new Point<T>();
		p->docfile(ifs);
		lsp.push_back(*p);
	}
	cout << "Doc file thanh cong" << endl;
	ifs.close();
}
template <class T>
void print(vector<Point<T>>&lsp) {
	cout << "Danh sach cac diem:";
	for (int i = 0; i < lsp.size(); i++)
	{
		cout << lsp[i] << " ";
	}
	cout << endl;
}
template <class T>
void findFarthestPairs(vector<Point<T>>&lsp) {
	if (lsp.size() < 2) {
		cout << "Khong du so diem de tim cap diem." << endl;
		return;
	}

	double maxDistance = 0.0;
	Point<T> p1, p2;

	for (size_t i = 0; i < lsp.size(); ++i) {
		for (size_t j = i + 1; j < lsp.size(); ++j) {
			double distance = lsp[i] - lsp[j];
			if (distance > maxDistance) {
				maxDistance = distance;
				p1 = lsp[i];
				p2 = lsp[j];
			}
		}
	}

	cout << "Cac cap diem co khoang cach xa nhat:" << endl;
	cout << p1 << " va " << p2 << endl;
}
template <class T>
void savePointsToFile(const vector<Point<T>>& lsp, const string& filename) {
	
}
int main() {
    //Point<int> p1(1, 2, 3);
    //Point<int> p2(4, 5, 6);

    //cout << "p1: " << p1 << endl;
    //cout << "p2: " << p2 << endl;

    //cout << "Distance between p1 and p2: " << (p1 - p2) << endl;

    //if (p1 == p2) {
    //    cout << "p1 and p2 are equal." << endl;
    //}
    //else {
    //    cout << "p1 and p2 are not equal." << endl;
    //}
    vector<Point<int>>lsp;
	readfile(lsp, "data.txt");
	print(lsp);
	findFarthestPairs(lsp);


    return 0;
}