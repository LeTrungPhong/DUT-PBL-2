#include "hashtable.h"
#include <fstream>

template<class T>
HashTable<T>::HashTable()
{ }

template<class T>
HashTable<T>::HashTable(long long s, long long sl)
    :size(s),SoLuong(sl),SoNguyenTo(1)
{
    HashTable::TimSoNguyenTo();
    this->kcg = new int[this->size];
    for(int i = 0; i < this->size; i++)
    {
        *(this->kcg + i) = 0;
    }
    this->kh = new T[this->size];
}

template<class T>
HashTable<T>::HashTable(long long s, long long sl, T *k, long long ksl, int check)
    :size(s),SoLuong(sl),SoNguyenTo(1)
{
    HashTable::TimSoNguyenTo();
    this->kcg = new int[this->size];
    for(int i = 0; i < this->size; i++)
    {
        *(this->kcg + i) = 0;
    }
    this->kh = new T[this->size];
    for(int i = 0; i < ksl; i++)
    {
        HashTable::NhapDuLieuVaoHashTable(*(k + i),check);
    }
    delete[] k;
}

template<class T>
void HashTable<T>::NhapDuLieu(long long s, long long sl, T *k, long long ksl, int check)
{
    this->size = s;
    this->SoLuong = sl;
    this->SoNguyenTo = 1;
    HashTable::TimSoNguyenTo();
    this->kcg = new int[this->size];
    for(int i = 0; i < this->size; i++)
    {
        *(this->kcg + i) = 0;
    }
    this->kh = new T[this->size];
    for(int i = 0; i < ksl; i++)
    {
        HashTable::NhapDuLieuVaoHashTable(*(k + i), check);
    }
    delete[] k;
}

template<class T>
HashTable<T>::HashTable(HashTable &t)
{
    this->SoNguyenTo = t.SoNguyenTo;
    this->size = t.size;
    this->SoLuong = t.SoLuong;
    this->kcg = new int[this->size];
    for(int i = 0; i < this->size; i++)
    {
        *(this->kcg + i) = *(t.kcg + i);
    }
    this->kh = new T[this->size];
    for(int i = 0; i < this->size; i++)
    {
        *(this->kh + i) = *(t.kh + i);
    }
}

template<class T>
HashTable<T>::~HashTable()
{
    delete[] this->kcg;
    delete[] this->kh;
}

template<class T>
bool HashTable<T>::KiemTraCoPhaiSoNguyenTo()
{
    for(long long i = 2; i <= sqrt(this->SoNguyenTo); i++)
    {
        if(!(this->SoNguyenTo % i))
        {
            return 0;
        }
    }
    return 1;
}

template<class T>
void HashTable<T>::TimSoNguyenTo()
{
    this->SoNguyenTo = this->size;
    while(1)
    {
        if(HashTable::KiemTraCoPhaiSoNguyenTo())
        {
            break;
        }
        this->SoNguyenTo--;
    }
}

template<class T>
void HashTable<T>::LaySoNguyenTo()
{
    cout << this->SoNguyenTo;
}

template<class T>
long long HashTable<T>::hashing(long long value)
{
    return (value%(this->SoNguyenTo));
}

template<class T>
void HashTable<T>::KiemTraHeSoTai(int check)
{
    if(((float)this->SoLuong / this->size) >= (float)3/4)
    {
        this->size = this->size * 2;
        HashTable::ReHashing(check);
    }
}

template<class T>
void HashTable<T>::ReHashing(int check)
{
    HashTable::TimSoNguyenTo();
    T *temp = new T[this->size / 2];
    for(int i = 0; i < (this->size / 2); i++)
    {
        temp[i] = kh[i];
    }
    delete[] this->kcg;
    delete[] this->kh;
    this->kcg = new int[this->size];
    for(int i = 0; i < this->size; i++)
    {
        *(this->kcg + i) = 0;
    }
    this->kh = new T[this->size];
    this->SoLuong = 0;
    for(int i = 0; i < (this->size / 2); i++)
    {
        HashTable::NhapDuLieuVaoHashTable(temp[i],check);
    }
    delete[] temp;
}

template<class T>
bool HashTable<T>::KiemTraViTri(int index)
{
    if((this->kh + index)->LayCCCD(1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
void HashTable<T>::NhapDuLieuVaoHashTable(T &k, int check)
{
    if(k.LayCCCD(1) == 0) return;
    int kc = 0;
    int index = HashTable::hashing(k.LayCCCD(1));
    while (1)
    {
        if(!check)
        {
            if((this->kh + index)->LayCCCD() == k.LayCCCD())
            {
                *(this->kh + index) = k;
                return;
            }
        }
        if(HashTable::KiemTraViTri(index))
        {
            if(*(this->kcg + index) < kc)
            {
                T tmp = k;
                k = kh[index];
                kh[index] = tmp;
                int temp = *(this->kcg + index);
                *(this->kcg + index) = kc;
                kc = temp;
            }
        }
        else
        {
            kh[index] = k;
            *(this->kcg + index) = kc;
            break;
        }
        kc++;
        index++;
        if(index == this->size)
        {
            index = 0;
        }
    }

    this->SoLuong++;
    HashTable::KiemTraHeSoTai(check);
}

template<class T>
void HashTable<T>::XoaKhachHang(string CCCD)
{
    int index = HashTable::hashing(stoll(CCCD));
    int kc = 0;
    while(1)
    {
        if((this->kh + index)->LayCCCD() == CCCD)
        {
            break;
        }
        index++;
        if(index == this->size)
        {
            index = 0;
        }
        if(*(this->kcg + index) == 0)
        {
            return;
        }
    }
    while(1)
    {
        T temp;
        if(*(this->kcg + (index + 1)) == 0)
        {
            *(this->kh + index) = temp;
            *(this->kcg + index) = 0;
            this->SoLuong--;
            break;
        }
        else
        {
            *(this->kh + index) = *(this->kh + (index + 1));
            *(this->kcg + index) = *(this->kcg + index + 1) - 1;
        }
        index++;
    }
}

template<class T>
bool HashTable<T>::KiemTraDuLieuCu(T &t)
{
    int index = HashTable::hashing(stoll(t.LayCCCD()));
    while(1)
    {
        if((this->kh + index)->LayCCCD() == t.LayCCCD())
        {
            return true;
        }
        else
        {
            index++;
            if(index == this->size)
            {
                index = 0;
            }
            if(*(this->kcg + index) == 0)
            {
                return false;
            }
        }
    }
}

template<class T>
bool HashTable<T>::KiemTraThongTin(T &t)
{
    int index = HashTable::hashing(stoll(t.LayCCCD()));
    while(1)
    {
        if((this->kh + index)->LayCCCD() == t.LayCCCD())
        {
            if(*(this->kh + index) == t)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            index++;
            if(index == this->size)
            {
                index = 0;
            }
            if(*(this->kcg + index) == 0)
            {
                return false;
            }
        }
    }
}

template<class T>
void HashTable<T>::Table()
{
    int count = 0;
    int tmp = this->size;
    while(tmp)
    {
        count++;
        tmp /= 10;
    }
    for(int i = 0; i < this->size; i++)
    {
        int tmp = i;
        int dem = 0;
        while(tmp)
        {
            dem++;
            tmp /= 10;
        }
        if(i == 0) dem = 1;
        while (count - dem)
        {
            cout << " ";
            dem++;
        }
        cout << "[" << i << "] " ;
        cout << (this->kh + i)->LayCCCD() << " " << *(this->kcg + i) << endl;
    }
}

template<class T>
T &HashTable<T>::operator [](const int& index)
{
    static T p;
    return(index >= 0 && index < this->size)?*(this->kh + index):p;
}

template<class T>
const HashTable<T>& HashTable<T>::operator = (const HashTable<T>& h)
{
    if(this != &h)
    {
        this->SoNguyenTo = h.SoNguyenTo;
        this->size = h.size;
        this->SoLuong = h.SoLuong;
        this->kcg = new int[this->size];
        for(int i = 0; i < this->size; i++)
        {
            *(this->kcg + i) = *(h.kcg + i);
        }
        this->kh = new T[this->size];
        for(int i = 0; i < this->size; i++)
        {
            *(this->kh + i) = *(h.kh + i);
        }
    }
    return *this;
}

template<class T>
void HashTable<T>::HienThiTable()
{
    int count = 0;
    int tmp = this->size;
    while(tmp)
    {
        count++;
        tmp /= 10;
    }
    for(int i = 0; i < this->size; i++)
    {
        int tmp = i;
        int dem = 0;
        while(tmp)
        {
            dem++;
            tmp /= 10;
        }
        if(i == 0) dem = 1;
        while (count - dem)
        {
            cout << " ";
            dem++;
        }
        cout << "[" << i << "] " ;
        cout << (this->kh + i)->LayCCCD() << " " << *(this->kcg + i) << endl;
    }
}

template<class T>
void HashTable<T>::LuuHoaDonVaoFile()
{
    ofstream outfile("D:\\HK3\\PBL-Project-3\\FileLichSu.txt");
    outfile << this->size << endl;
    outfile << this->SoLuong << endl;
    for(int i = 0; i < this->size; ++i)
    {
        if(!((this->kh + i)->LayCCCD() == "0"))
        {
            vector<int> v = (this->kh + i)->LayDichVu();
            outfile << (this->kh + i)->LayMaHD() << "|" << (this->kh + i)->LayCCCD() << "|" << (this->kh + i)->LayTenPhong() << "|" << (this->kh + i)->LayNgayDen() << "|" << (this->kh + i)->LayNgayDi() << "|" << (this->kh + i)->LayNgayDiThucTe()  << "|" << v[0] << "|" << v[1] << "|" << v[2] << "|" << v[3] << "|" << (this->kh + i)->LayTienPhong() << endl;
        }
    }
    outfile.close();
}

template<class T>
void HashTable<T>::LuuKhachHangCuVaoFile()
{
    ofstream outfile("D:\\HK3\\PBL-Project-3\\Khach_Hang_Cu.txt");
    outfile << this->size << endl;
    outfile << this->SoLuong << endl;
    for(int i = 0; i < this->size; ++i)
    {
        if(!((this->kh + i)->LayCCCD() == "0"))
        {
            vector<int> v = (this->kh + i)->LayDichVu();
            outfile << (this->kh + i)->LayCCCD() << "|" << (this->kh + i)->LaySDT() << "|" << (this->kh + i)->LayBirth() << "|" << (this->kh + i)->LaySoLuong() << "|" << (this->kh + i)->LayTen() << endl;
        }
    }
    outfile.close();
}

template<class T>
void HashTable<T>::LayDuLieuTuFileKhachHangCu()
{
    ifstream file;
    file.open("D:\\HK3\\PBL-Project-3\\Khach_Hang_Cu.txt");
    if (!file.is_open()) {
        cout << "Error opening data file !!!" << endl;
        return;
    }
    string line;
    getline(file, line);
    this->size = stoi(line);
    getline(file, line);
    int sl = stoi(line);
    this->kh = new T[this->size];
    this->kcg = new int[this->size];
    for(int i = 0; i < this->size; ++i)
    {
        *(this->kcg + i) = 0;
    }
    this->SoLuong = 0;
    this->SoNguyenTo = 1;
    HashTable::TimSoNguyenTo();
    // 0 : CCCD
    // 1 : SDT
    // 2 : ngay thang nam sinh
    // 3 : So luong
    // 4 : Ten
    for(int i = 0; i < sl; i++)
    {
        T temp;
        getline(file, line);
        vector<string> token = HashTable::split(line,"|");
        vector<string> ns = split(token[2],"/");
        temp.NhapThongTin(token[0],token[4],token[1],stoi(ns[0]),stoi(ns[1]),stoi(ns[2]));
        temp.NhapSoLuong(stoi(token[3]));
        HashTable::NhapDuLieuVaoHashTable(temp,0);
    }
    file.close();
}

template<class T>
void HashTable<T>::LayDuLieuTuFileHoaDon()
{
    ifstream file;
    file.open("D:\\HK3\\PBL-Project-3\\FileLichSu.txt");
    if (!file.is_open()) {
        cout << "Error opening data file !!!" << endl;
        return;
    }
    string line;
    getline(file, line);
    this->size = stoi(line);
    getline(file, line);
    int sl = stoi(line);
    this->kh = new T[this->size];
    this->kcg = new int[this->size];
    for(int i = 0; i < this->size; ++i)
    {
        *(this->kcg + i) = 0;
    }
    this->SoLuong = 0;
    this->SoNguyenTo = 1;
    HashTable::TimSoNguyenTo();
    // 0 : MaHD
    // 1 : CCCD
    // 2 : Ten Phong
    // 3 : Ngay den
    // 4 : Ngay di
    // 5 : Ngay di thuc te
    // 6 : Dich Vu 1
    // 7 : Dich Vu 2
    // 8 : Dich Vu 3
    // 9 : Dich Vu 4
    // 10 : Tong Tien
    for(int i = 0; i < sl; i++)
    {
        T temp;
        getline(file, line);
        vector<string> token = HashTable::split(line,"|");
        vector<int> dv;
        dv.push_back(stoi(token[6]));
        dv.push_back(stoi(token[7]));
        dv.push_back(stoi(token[8]));
        dv.push_back(stoi(token[9]));
        vector<string> nden = split(token[3],"/");
        vector<string> ndi = split(token[4],"/");
        vector<string> nditt = split(token[5],"/");
        Date Ngayden;
        Ngayden.Gio = stoi(nden[0]);
        Ngayden.Ngay = stoi(nden[1]);
        Ngayden.Thang = stoi(nden[2]);
        Ngayden.Nam = stoi(nden[3]);
        Date Ngaydi;
        Ngaydi.Gio = stoi(ndi[0]);
        Ngaydi.Ngay = stoi(ndi[1]);
        Ngaydi.Thang = stoi(ndi[2]);
        Ngaydi.Nam = stoi(ndi[3]);
        Date Ngayditt;
        Ngayditt.Gio = stoi(nditt[0]);
        Ngayditt.Ngay = stoi(nditt[1]);
        Ngayditt.Thang = stoi(nditt[2]);
        Ngayditt.Nam = stoi(nditt[3]);
        temp.NhapThongTinHD(token[0],token[1],token[2],dv,Ngayden,Ngaydi,Ngayditt,stoi(token[10]));
        HashTable::NhapDuLieuVaoHashTable(temp,1);
    }
    file.close();
}

template<class T>
T& HashTable<T>::LayThongTinTheoID(string cccd)
{
    int index = HashTable::hashing(stoll(cccd));
    while(1)
    {
        if((this->kh + index)->LayCCCD() == cccd)
        {
            return *(this->kh + index);
        }
        else
        {
            index++;
            if(index == this->size) index = 0;
            if(*(this->kcg + index) == 0)
            {
                T temp;
                return temp;
            }
        }
    }
}

template<class T>
T& HashTable<T>::LayThongTinTheoID(string cccd, string mhd)
{
    int index = HashTable::hashing(stoll(cccd));
    while(1)
    {
        if((this->kh + index)->LayCCCD() == cccd && (this->kh + index)->LayMaHD() == mhd)
        {
            return *(this->kh + index);
        }
        else
        {
            index++;
            if(index == this->size) index = 0;
            if(*(this->kcg + index) == 0)
            {
                T temp;
                return temp;
            }
        }
    }
}

template<class T>
vector<T> HashTable<T>::LayDanhSachKhachHangCu()
{
    vector<T> temp;
    for(int i = 0; i < this->size; ++i)
    {
        if((this->kh + i)->LayCCCD() != "0")
        {
            temp.push_back(*(this->kh + i));
        }
    }
    return temp;
}

template<class T>
vector<T> HashTable<T>::LayDSKHTheoTTDSC(string cccd, string tenphong, string tenkh)
{
    vector<T> temp;
    for(int i = 0; i < this->size; ++i)
    {
        if(!(((this->kh + i)->LayCCCD() == cccd || cccd == "") && (this->kh + i)->LayCCCD() != "0")) continue;
        if(!(((this->kh + i)->LayTenPhong() == tenphong || tenphong == "") && (this->kh + i)->LayTenPhong() != "0")) continue;
        if(!(((this->kh + i)->LayTen() == tenkh || tenkh == "") && (this->kh + i)->LayTen() != "0")) continue;
        temp.push_back(*(this->kh + i));
    }
    return temp;
}

template<class T>
vector<string> HashTable<T>::split(string str, string delimiter)
{
    size_t pos = 0;
    vector<string> tokens;
    while ((pos = str.find(delimiter)) != string::npos)
    {
        string temp_token = str.substr(0, pos);
        tokens.push_back(temp_token);
        str.erase(0, pos + delimiter.length());
    }
    tokens.push_back(str);
    return tokens;
}

template class HashTable<KhachHang>;
template class HashTable<HoaDon>;
