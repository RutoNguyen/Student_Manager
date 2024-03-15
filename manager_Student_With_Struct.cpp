#include <iostream>
#include <string>
#include<fstream> // read file
#include <algorithm> // for transform
#include <cctype>    // for toupper
#include <iomanip> // for setw
#define MAX 100
using namespace std;

struct SinhVien
{
    int id;
    string ten;
    int tuoi;
    string gioiTinh;
    float diemToan;
    float diemLy;
    float diemHoa;
    float diemTB;
    string hocluc;
    SinhVien() : id(0), ten(""), tuoi(0), gioiTinh(""), diemToan(0), diemLy(0), diemHoa(0), diemTB(0), hocluc("") {}
    SinhVien(int _id, string _ten, int _tuoi, string _gioiTinh, float _diemToan,
        float _diemLy, float _diemHoa, float _diemTB, string _hocluc)
        : id(_id), ten(_ten), tuoi(_tuoi), gioiTinh(_gioiTinh), diemToan(_diemToan),
        diemLy(_diemLy), diemHoa(_diemHoa), diemTB(_diemTB), hocluc(_hocluc) {}
};
typedef SinhVien SV;

void printLine(int n);
void nhapThongTinSV(SV& sv, int id);
void nhapSV(SV a[], int id, int n);
void capNhatThongTinSV(SV& sv);
void capNhatSV(SV a[], int id, int n);
int xoaTheoID(SV a[], int id, int n);
void timKiemTheoTen(SV a[], string ten, int n);
void tinhDTB(SV& sv);
void xeploai(SV& sv);
int idLonNhat(SV a[], int n);
void sapxepTheoDTB(SV a[], int n);
void sapXepTheoTen(SV a[], int n);
void showStudent(SV a[], int n);
int docFile(SV a[], string fileName);
void ghiFile(SV a[], int n, string fileName);
void pressAnyKey();

int main()
{
    int key;
    string fileName = "sinhvien.txt";
    SV arraySV[MAX];
    int soluongSV = 0;
    int idCount = 0;

    // nhap danh sach sinh vien tu file
    soluongSV = docFile(arraySV, fileName);
    idCount = idLonNhat(arraySV, soluongSV);

    while (true)
    {
        cout << "CHUONG TRINH QUAN LY SINH VIEN C/C++\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Them sinh vien.                               **\n";
        cout << "**  2. Cap nhat thong tin sinh vien boi ID.          **\n";
        cout << "**  3. Xoa sinh vien boi ID.                         **\n";
        cout << "**  4. Tim kiem sinh vien theo ten.                  **\n";
        cout << "**  5. Sap xep sinh vien theo diem trung binh (GPA). **\n";
        cout << "**  6. Sap xep sinh vien theo ten.                   **\n";
        cout << "**  7. Hien thi danh sach sinh vien.                 **\n";
        cout << "**  8. Ghi danh sach sinh vien vao file.             **\n";
        cout << "**  0. Thoat                                         **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        cin.ignore();
        switch (key)
        {
        case 1:
            cout << "\n1. Them sinh vien.";
            idCount++;
            nhapSV(arraySV, idCount, soluongSV);
            printf("\nThem sinh vien thanh cong!");
            soluongSV++;
            pressAnyKey();
            break;
        case 2:
            if (soluongSV > 0)
            {
                int id;
                cout << "\n2. Cap nhat thong tin sinh vien. ";
                cout << "\n Nhap ID: ";
                cin >> id;
                cin.ignore();
                capNhatSV(arraySV, id, soluongSV);
            }
            else
            {
                cout << "\nSanh sach sinh vien trong!";
            }
            pressAnyKey();
            break;
        case 3:
            if (soluongSV > 0)
            {
                int id;
                cout << "\n3. Xoa sinh vien.";
                cout << "\n Nhap ID: ";
                cin >> id;
                cin.ignore();
                if (xoaTheoID(arraySV, id, soluongSV) == 1)
                {
                    //printf("\nSinh vien co id = %d da bi xoa.", &id);
                    cout << "\nSinh vien co id = " << id << " da bi xoa";
                    soluongSV--;
                }
            }
            else
            {
                cout << "\nSanh sach sinh vien trong!";
            }
            pressAnyKey();
            break;
        case 4:
            if (soluongSV > 0)
            {
                cout << "\n4. Tim kiem sinh vien theo ten.";
                //char strTen[30];
                string strTen;
                cout << "\nNhap ten de tim kiem: ";
                cin.ignore();
                getline(cin, strTen);
                timKiemTheoTen(arraySV, strTen, soluongSV);
            }
            else
            {
                cout << "\nKhong co sinh vien trong danh sach!";
            }
            pressAnyKey();
            break;
        case 5:
            if (soluongSV > 0)
            {
                cout << "\n5. Sap xep sinh vien theo diem trung binh (GPA).";
                sapxepTheoDTB(arraySV, soluongSV);
                showStudent(arraySV, soluongSV);
            }
            else
            {
                cout << "\nSanh sach sinh vien trong!";
            }
            pressAnyKey();
            break;
        case 6:
            if (soluongSV > 0)
            {
                cout << "\n6. Sap xep sinh vien theo ten.";
                sapXepTheoTen(arraySV, soluongSV);
                showStudent(arraySV, soluongSV);
            }
            else
            {
                cout << "\nSanh sach sinh vien trong!";
            }
            pressAnyKey();
            break;
        case 7:
            if (soluongSV > 0)
            {
                cout << "\n7. Hien thi danh sach sinh vien.";
                showStudent(arraySV, soluongSV);
            }
            else
            {
                cout << "\nDanh sach sinh vien!";
            }
            pressAnyKey();
            break;
        case 8:
            if (soluongSV > 0)
            {
                cout << "\n8. Ghi danh sach sinh vien vao file.";
                ghiFile(arraySV, soluongSV, fileName);
            }
            else
            {
                cout << "\nSanh sach sinh vien trong!";
            }
            cout << "\nGhi danh sach sinh vien vao file %s thanh cong!" << fileName;
            pressAnyKey();
            //cin.get();
            break;
        case 0:
            cout << "\nBan da chon thoat chuong trinh!";
            pressAnyKey();
            return 0;
        default:
            cout << "\nKhong co chuc nang nay!";
            cout << "\nHay chon chuc nang trong hop menu.";
            pressAnyKey();
            break;
        }
    }
}

void tinhDTB(SV& sv)
{
    sv.diemTB = (sv.diemToan + sv.diemLy + sv.diemHoa) / 3;
}

void xeploai(SV& sv)
{
    if (sv.diemTB >= 8)
        sv.hocluc = "Gioi";
    else if (sv.diemTB >= 6.5)
        sv.hocluc = "Kha";
    else if (sv.diemTB >= 5)
        sv.hocluc = "Trung binh";
    else
        sv.hocluc = "Yeu";
}

void nhapThongTinSV(SV& sv, int id)
{
    cout << "\n Nhap ten: ";
    //cin.ignore();
    getline(cin, sv.ten);
    cout << " Nhap gioi tinh: ";
    //cin.ignore();
    getline(cin, sv.gioiTinh);
    //cin.ignore();
    cout << " Nhap tuoi: ";
    cin >> sv.tuoi;
    cout << " Nhap diem Toan: ";
    cin >> sv.diemToan;
    cout << " Nhap diem Ly: ";
    cin >> sv.diemLy;
    cout << " Nhap diem Hoa: ";
    cin >> sv.diemHoa;
    sv.id = id;
    tinhDTB(sv);
    xeploai(sv);
}

void nhapSV(SV a[], int id, int n)
{
    printLine(40);
    cout << "\n Nhap sinh vien thu: " << n + 1;
    nhapThongTinSV(a[n], id);
    printLine(40);
}

void capNhatThongTinSV(SV& sv)
{
    cout << "\n Nhap ten: ";
    cin.ignore();
    getline(cin, sv.ten);
    cout << " Nhap gioi tinh: ";
    cin.ignore();
    getline(cin, sv.gioiTinh);
    cout << " Nhap tuoi: ";
    cin >> sv.tuoi;
    cout << " Nhap diem Toan: ";
    cin >> sv.diemToan;
    cout << " Nhap diem Ly: ";
    cin >> sv.diemLy;
    cout << " Nhap diem Hoa: ";
    cin >> sv.diemHoa;
    tinhDTB(sv);
    xeploai(sv);
}

void capNhatSV(SV a[], int id, int n)
{
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].id == id)
        {
            found = 1;
            printLine(40);
            cout << "\n Cap nhat thong tin sinh vien co ID = " << id;
            capNhatThongTinSV(a[i]);
            printLine(40);
            break;
        }
    }
    if (found == 0)
    {
        printf("\n Sinh vien co ID = %d khong ton tai.", id);
    }
}

int xoaTheoID(SV a[], int id, int n)
{
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].id == id)
        {
            found = 1;
            printLine(40);
            for (int j = i; j < n; j++)
            {
                a[j] = a[j + 1];
            }
            cout << "\n Da xoa SV co ID = " << id;
            printLine(40);
            break;
        }
    }
    if (found == 0)
    {
        printf("\n Sinh vien co ID = %d khong ton tai.", id);
        return 0;
    }
    else
    {
        return 1;
    }
}

// void timKiemTheoTen(SV a[], string ten, int n)
// {
//     SV arrayFound[MAX];
//     char tenSV[30];
//     int found = 0;
//     for (int i = 0; i < n; i++)
//     {
//         strcpy(tenSV, a[i].ten);
//         if (strstr(strupr(tenSV), strupr(ten)))
//         {
//             arrayFound[found] = a[i];
//             found++;
//         }
//     }
//     showStudent(arrayFound, found);
// }
void timKiemTheoTen(SV a[], string ten, int n)
{
    SV arrayFound[MAX];
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        // Chuy?n ??i tên c?a sinh viên và tên tìm ki?m sang ch? in hoa ?? so sánh không phân bi?t ch? hoa ch? th??ng
        string tenSVUpper = a[i].ten;
        // transform trong th? vi?n <algorithm>
        transform(tenSVUpper.begin(), tenSVUpper.end(), tenSVUpper.begin(), ::toupper);
        string tenTimKiemUpper = ten;
        transform(tenTimKiemUpper.begin(), tenTimKiemUpper.end(), tenTimKiemUpper.begin(), ::toupper);

        if (tenSVUpper.find(tenTimKiemUpper) != string::npos)
        {
            arrayFound[found] = a[i];
            found++;
        }
    }

    if (found > 0)
    {
        showStudent(arrayFound, found);
    }
    else
    {
        cout << "Khong tim thay sinh vien nao co ten: " << ten << endl;
    }
}
void showStudent(SV a[], int n)
{
    printLine(100);
    cout << "\n\tSTT\tID\tHo va ten\tGioi tinh\tTuoi\tToan\tLy\tHoa\tDiem TB\tHoc luc";
    for (int i = 0; i < n; i++)
    {
        // in sinh vien thu i ra man hinh
        cout << "\n\t" << i + 1;
        cout << "\t" << a[i].id;
        cout << "\t" << a[i].ten;
        cout << "\t\t" << a[i].gioiTinh;
        cout << "\t\t" << a[i].tuoi;
        printf("\t%.2f\t%.2f\t%.2f", a[i].diemToan, a[i].diemLy, a[i].diemHoa);
        printf("\t%.2f", a[i].diemTB);
        cout << "\t" << a[i].hocluc;
    }
    printLine(100);
}

void sapxepTheoDTB(SV a[], int n)
{
    // Sap xep theo DTB tang dan
    SV tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].diemTB > a[j].diemTB)
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void sapXepTheoTen(SV a[], int n)
{
    // Sap xep sinh vien theo ten theo thu tu tang dan
    SV tmp;
    string tenSV1, tenSV2;
    for (int i = 0; i < n; i++)
    {
        tenSV1 = a[i].ten;
        for (int j = i + 1; j < n; j++)
        {
            tenSV2 = a[j].ten;
            transform(tenSV1.begin(), tenSV1.end(), tenSV1.begin(), ::toupper);
            transform(tenSV2.begin(), tenSV2.end(), tenSV2.begin(), ::toupper);
            if (tenSV1 > tenSV2)
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int idLonNhat(SV a[], int n)
{
    int idMax = 0;
    if (n > 0)
    {
        idMax = a[0].id;
        for (int i = 0; i < n; i++)
        {
            if (a[i].id > idMax)
            {
                idMax = a[i].id;
            }
        }
    }
    return idMax;
}
int docFile(SV a[], string filename) {
    ifstream fileIn(filename);
    if (!fileIn) {
        cout << "Khong the mo file" << endl;
    }
    cout << "Chuan bi doc file: " << filename << endl;
    int i = 0;
    while (fileIn >> a[i].id >> a[i].ten >> a[i].gioiTinh >> a[i].tuoi >> a[i].diemToan >> a[i].diemLy >> a[i].diemHoa >> a[i].diemTB >> a[i].hocluc) {
        i++;
        cout << "Doc ban ghi thu: " << i << endl;
    }
    cout << "So luong sinh vien trong file la: " << i << endl;
    fileIn.close();

    return i;
}
void ghiFile(SV a[], int n, string fileName) {
    fstream fileOut(fileName);
    if (!fileOut.is_open()) {
        cout << "\nKhong the mo file: " << fileName << endl;
        cout << "Tao file moi voi ten: " << fileName << endl;
        fileOut.open(fileName);
        if (!fileOut.is_open()) {
            cerr << "Khong the tao hoac mo file!" << endl;
            return;
        }
    }
    // Ghi du lieu vào file
    for (int i = 0; i < n; i++) {
        fileOut << setw(5) << a[i].id << setw(30) << a[i].ten << setw(5) << a[i].gioiTinh
            << setw(5) << a[i].tuoi << setw(10) << a[i].diemToan << setw(10) << a[i].diemLy
            << setw(10) << a[i].diemHoa << setw(10) << a[i].diemTB << setw(10) << a[i].hocluc << endl;
    }
    // Dóng file sau khi ghi xong
    fileOut.close();

    cout << "Du lieu da duoc ghi vao file " << fileName << endl;
}

void printLine(int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "_";
    }
    cout << endl;
}

void pressAnyKey()
{
    cout << "\n\nBam phim bat ky de tiep tuc...";
    //cin.ignore();
    cin.get();
    system("cls");
}