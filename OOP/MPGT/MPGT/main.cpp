#include"vehicle.h"
#include <vector>
#include <fstream>
int main() {
    int n, N_MAX,N_MAX1, N_MAX2, N_MAX3;
    float L, dt;

    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap L: ";
    cin >> L;
    cout << "Nhap dt: ";
    cin >> dt;
    /*Cau 2
    cout << "Nhap so luong xe toi da cua xe may (N_MAX1): ";
    cin >> N_MAX1;
    cout << "Nhap so luong xe toi da cua xe con (N_MAX2): ";
    cin >> N_MAX2;
    cout << "Nhap so luong xe toi da cua xe tai (N_MAX3): ";
    cin >> N_MAX3;

    vector<vehicle>dsxm,dsxc,dsxt;
    ofstream ofs("mophong1.txt");
    for (int timestep = 0; timestep < n; timestep++) {
        if (dsxm.size() < N_MAX1) {
            vehicle* xm = new vehicle(0, 1);
            dsxm.push_back(*xm);
        }
        if (dsxc.size() < N_MAX2) {
            vehicle* xc = new vehicle(0, 1);
            dsxc.push_back(*xc);
        }
        if (dsxt.size() < N_MAX3) {
            vehicle* xt = new vehicle(0, 1);
            dsxt.push_back(*xt);
        }
        for (int i = 0; i < dsxm.size(); i++)
        {
            dsxm[i].capNhapVitri(dt);
            dsxm[i].dieuChinhTocDo();
            if (dsxm[i].getposition() > L) {
                dsxm.erase(dsxm.begin() + i);
            }
        }
        for (int i = 0; i < dsxc.size(); i++)
        {
            dsxc[i].capNhapVitri(dt);
            dsxc[i].dieuChinhTocDo();
            if (dsxc[i].getposition() > L) {
                dsxc.erase(dsxc.begin() + i);
            }
        }
        for (int i = 0; i <dsxt.size(); i++)
        {
            dsxt[i].capNhapVitri(dt);
            dsxt[i].dieuChinhTocDo();
            if (dsxt[i].getposition() > L) {
                dsxt.erase(dsxt.begin() + i);
            }
        }
        ofs << "Buoc:" << timestep + 1 << endl;
        for (int j = 0; j < dsxm.size(); j++)
        {
            ofs << "Xe may " << j + 1 << ":Vi Tri " << dsxm[j].getposition() << " Km; " << "Toc do: " << dsxm[j].getspeed() << endl;
        }
        for (int j = 0; j < dsxc.size(); j++)
        {
            ofs << "Xe con " << j + 1 << ":Vi Tri " << dsxc[j].getposition() << " Km; " << "Toc do: " << dsxc[j].getspeed() << endl;
        }
        for (int j = 0; j < dsxt.size(); j++)
        {
            ofs << "Xe con " << j + 1 << ":Vi Tri " << dsxt[j].getposition() << " Km; " << "Toc do: " << dsxt[j].getspeed() << endl;
        }
        ofs << endl;
    }
    ofs.close();*/
    //Cau 1
   cout << "Nhap N_MAX: ";
    cin >> N_MAX;
    vector<vehicle>vehicles;
    ofstream ofs("mophong.txt");
    for (int timestep = 0; timestep < n; timestep++) {
        if (vehicles.size() <N_MAX) {
            vehicles.emplace_back(0, 1);
        }
        for ( int i = 0; i < vehicles.size();  i++)
        {
            vehicles[i].capNhapVitri(dt);
            vehicles[i].dieuChinhTocDo();
            if (vehicles[i].getposition() > L) {
                vehicles.erase(vehicles.begin() + i);
            }
        }
        ofs << "Buoc:" << timestep + 1<<endl;
        for (int j = 0; j < vehicles.size(); j++)
        {
            ofs << "Xe " << j + 1 << ":Vi Tri " << vehicles[j].getposition() << " Km; " << "Toc do: " << vehicles[j].getspeed() << endl;
        }
        ofs << endl;
    }
    ofs.close();
   
}