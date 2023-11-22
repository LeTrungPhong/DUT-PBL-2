#include "hashtable.h"
#include <fstream>

HashTable::HashTable()
{ }

HashTable::HashTable(long long s, long long sl)
    :size(s),SoLuong(sl),SoNguyenTo(1)
{
    HashTable::TimSoNguyenTo();
    this->kcg = new int[this->size];
    for(int i = 0; i < this->size; i++)
    {
        *(this->kcg + i) = 0;
    }
    this->kh = new KhachHang[this->size];
}

HashTable::HashTable(long long s, long long sl, KhachHang *k, long long ksl)
    :size(s),SoLuong(sl),SoNguyenTo(1)
{
    HashTable::TimSoNguyenTo();
    this->kcg = new int[this->size];
    for(int i = 0; i < this->size; i++)
    {
        *(this->kcg + i) = 0;
    }
    this->kh = new KhachHang[this->size];
    for(int i = 0; i < ksl; i++)
    {
        HashTable::NhapKhachHangVaoHashTable(*(k + i));
    }
    delete[] k;
}

void HashTable::NhapDuLieu(long long s, long long sl, KhachHang *k, long long ksl)
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
    this->kh = new KhachHang[this->size];
    for(int i = 0; i < ksl; i++)
    {
        HashTable::NhapKhachHangVaoHashTable(*(k + i));
    }
    delete[] k;
}

HashTable::HashTable(HashTable &t)
{
    this->SoNguyenTo = t.SoNguyenTo;
    this->size = t.size;
    this->SoLuong = t.SoLuong;
    this->kcg = new int[this->size];
    for(int i = 0; i < this->size; i++)
    {
        *(this->kcg + i) = *(t.kcg + i);
    }
    this->kh = new KhachHang[this->size];
    for(int i = 0; i < this->size; i++)
    {
        *(this->kh + i) = *(t.kh + i);
    }
}

HashTable::~HashTable()
{
    delete[] this->kcg;
    delete[] this->kh;
}

bool HashTable::KiemTraCoPhaiSoNguyenTo()
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

void HashTable::TimSoNguyenTo()
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

void HashTable::LaySoNguyenTo()
{
    cout << this->SoNguyenTo;
}

long long HashTable::hashing(long long value)
{
    return (value%(this->SoNguyenTo));
}

void HashTable::KiemTraHeSoTai()
{
    if(((float)this->SoLuong / this->size) >= (float)3/4)
    {
        this->size = this->size * 2;
        HashTable::ReHashing();
    }
}

void HashTable::ReHashing()
{
    HashTable::TimSoNguyenTo();
    KhachHang *temp = new KhachHang[this->size / 2];
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
    this->kh = new KhachHang[this->size];
    this->SoLuong = 0;
    for(int i = 0; i < (this->size / 2); i++)
    {
        HashTable::NhapKhachHangVaoHashTable(temp[i]);
    }
    delete[] temp;
}

bool HashTable::KiemTraViTri(int index)
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

void HashTable::NhapKhachHangVaoHashTable(KhachHang &k)
{
    if(k.LayCCCD(1) == 0) return;
    int kc = 0;
    int index = HashTable::hashing(k.LayCCCD(1));
    while (1)
    {
        if(HashTable::KiemTraViTri(index))
        {
            if(*(this->kcg + index) < kc)
            {
                KhachHang tmp = k;
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
    HashTable::KiemTraHeSoTai();
}

void HashTable::Table()
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

KhachHang& HashTable::operator [] (const int& index)
{
    static KhachHang p;
    return(index >= 0 && index < this->size)?*(this->kh + index):p;
}

const HashTable& HashTable::operator = (const HashTable& h)
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
        this->kh = new KhachHang[this->size];
        for(int i = 0; i < this->size; i++)
        {
            *(this->kh + i) = *(h.kh + i);
        }
    }
    return *this;
}

void HashTable::HienThiTable()
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

void HashTable::LuuKhachHangCuVaoFile()
{
    ofstream outfile("D:\\HK3\\PBL-Project-3\\Khach_Hang_Cu.txt");
    outfile << this->size << endl;
    outfile << this->SoLuong << endl;
    for(int i = 0; i < this->size; ++i)
    {
        if(!((this->kh + i)->LayCCCD() == "0"))
        {
            vector<int> v = (this->kh + i)->LayDichVu();
            outfile << (this->kh + i)->LayCCCD() << "|" << (this->kh + i)->LaySDT() << "|" << (this->kh + i)->LayTenPhong() << "|" << (this->kh + i)->LayBirth() << "|" << (this->kh + i)->LayNgayDen() << "|" << (this->kh + i)->LayNgayDi() << "|" << v[0] << "|" << v[1] << "|" << v[2] << "|" << v[3] << "|" << (this->kh + i)->LayTienPhong() << "|" << (this->kh + i)->LayTen() << endl;
        }
    }
    outfile.close();
}

vector<KhachHang> HashTable::LayDanhSachKhachHangCu()
{
    vector<KhachHang> temp;
    for(int i = 0; i < this->size; ++i)
    {
        if((this->kh + i)->LayCCCD() != "0")
        {
            temp.push_back(*(this->kh + i));
        }
    }
    return temp;
}

vector<KhachHang> HashTable::LayDSKHTheoTTDSC(string cccd, string tenphong, string tenkh)
{
    vector<KhachHang> temp;
    for(int i = 0; i < this->size; ++i)
    {
        if(!(((this->kh + i)->LayCCCD() == cccd || cccd == "") && (this->kh + i)->LayCCCD() != "0")) continue;
        if(!(((this->kh + i)->LayTenPhong() == tenphong || tenphong == "") && (this->kh + i)->LayTenPhong() != "0")) continue;
        if(!(((this->kh + i)->LayTen() == tenkh || tenkh == "") && (this->kh + i)->LayTen() != "0")) continue;
        temp.push_back(*(this->kh + i));
    }
    return temp;
}
