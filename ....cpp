#include "iostream"
#include "string"
#include "vector"
#include "iomanip"
using namespace std;

class KhachHang
{
	public:
		int MaKhachHang;
		string HoTen;
		int Ngay;
		int Thang;
		int Nam;
		void NhapThongTin(){
			cout << "Nhap Ma Khach Hang: "; cin >> MaKhachHang; cin.ignore();
			cout << "Nhap Ho Ten Khach Hang: "; getline(cin,HoTen);
			cout << "Nhap Ngay: ";cin >> Ngay; cout << "Nhap Thang: "; cin >> Thang; cout << "Nhap Nam: ";cin >> Nam; cin.ignore();
		}	
		void XuatThongTin(){
			cout << "+-----------------------------------+\n";
			cout << "- Ma Khach Hang: " << MaKhachHang << "\n";
			cout << "- Ho Ten: " << HoTen << "\n";
			cout << "- Ngay/Thang/Nam: " << Ngay << "/" << Thang <<"/" <<Nam << endl;
		}
		
};
class KhachHangVietNam : public KhachHang
{
	public:
		string DoiTuongKhachHang;
		double SoLuongKW;
		double DonGia;
		double DinhMuc;
		void NhapThongTinKhachHangVN(){
			KhachHang::NhapThongTin();
			cout << "Doi Tuong Khach Hang Gom: Sinh hoat, Kinh doanh, San Xuat\n";
			cout << "Nhap Doi Tuong Khach Hang: "; getline(cin,DoiTuongKhachHang);
			cout << "Nhap So Luong KW dien tieu thu "; cin >> SoLuongKW;
			cout << "Nhap Don Gia: ";cin >> DonGia;
			cout << "Nhap Dinh Muc: ";cin >> DinhMuc;cin.ignore();
		}
		
		double TinhTien(){
			if(SoLuongKW <= DinhMuc)
			{
				return SoLuongKW * DonGia;
			} 
			else
			{
				return (SoLuongKW * DonGia) + ((SoLuongKW - DinhMuc) * DonGia * 2.5);
			}
		}
		void XuatThongTinKhachHangVN(){
			KhachHang::XuatThongTin();
			cout << "- Doi Tuong Khach Hang: " << DoiTuongKhachHang << "\n";
			cout << "- So Luong KW Tieu Thu: " << SoLuongKW << "\n";
			cout << "- Don Gia: " << DonGia << "\n";
			cout << "- Dinh Muc: " << DinhMuc << "\n";
			cout << "- Thanh Tien: " << TinhTien() << endl;;
		}
		static double TinhTBCKhachHangVN(vector<KhachHangVietNam> &VnCusList){
			double ThanhTien=0;
			int SoLuongKhachHang = VnCusList.size();
			for(int i=0;i<SoLuongKhachHang;i++){
				ThanhTien+=VnCusList[i].TinhTien();
			}
			return ThanhTien/SoLuongKhachHang;
		}
		
};
class KhachHangNuocNgoai : public KhachHang
{
	public:
		string QuocTich;
		double SoLuongKW;
		double DonGia;
		void NhapThongTinKhachHangNuocNgoai(){
			KhachHang::NhapThongTin();
			cout << "Nhap Quoc Tich Cua Khach Hang: "; getline(cin,QuocTich);
			cout << "Nhap So Luong KW dien tieu thu "; cin >> SoLuongKW;
			cout << "Nhap Don Gia: ";cin >> DonGia; cin.ignore();
		}
		
		double TinhTien(){
			return SoLuongKW * DonGia;
		}
		
		void XuatThongTinKhachHangNuocNgoai(){
			KhachHang::XuatThongTin();
			cout << "- Quoc Tich: " << QuocTich << "\n";
			cout << "- So Luong KW Tieu Thu: " << SoLuongKW << "\n";
			cout << "- Don Gia:  "<< DonGia << "\n";
			cout << "- Thanh Tien: " << TinhTien() << endl;
		}
		static double TinhTBCKhachHangNuocNgoai(vector<KhachHangNuocNgoai> &TouristCusList){
			double ThanhTien=0;
			int SoLuongKhachHang = TouristCusList.size();
			for(int i=0;i<SoLuongKhachHang;i++){
				ThanhTien+=TouristCusList[i].TinhTien();
			}
			return ThanhTien/SoLuongKhachHang;
		}
		static double TinhTBCAll(vector<KhachHangVietNam> &VnCusList,vector<KhachHangNuocNgoai> &TouristCusList){
			double ThanhTien=0;
			int SoLuongKhachHang = VnCusList.size() + TouristCusList.size();
			if(TouristCusList.size() == 0){
				for(int i=0;i<SoLuongKhachHang;i++){
					ThanhTien+=VnCusList[i].TinhTien();
				}
			}else if(VnCusList.size() == 0){
				for(int i=0;i<SoLuongKhachHang;i++){
					ThanhTien+=TouristCusList[i].TinhTien();
				}
			} else {
				for(int i=0;i<SoLuongKhachHang;i++){
					ThanhTien+=VnCusList[i].TinhTien();
				}
				for(int i=0;i<SoLuongKhachHang;i++){
					ThanhTien+=TouristCusList[i].TinhTien();
				}	
			}
			return ThanhTien/SoLuongKhachHang;
		}
};


int main(){
	vector<KhachHangVietNam> VnCusList;
	vector<KhachHangNuocNgoai> TouristCusList;
	int choice;
	
	do{
		cout << "+---------------------------MENU---------------------------+" << "\n";
		cout << "|"<< setw(41) <<"1  - Nhap Thong Tin Khach Hang Viet Nam" << setw(19) << "|\n";
		cout << "|"<< setw(43) <<"2  - Nhap Thong Tin Khach Hang Nuoc Ngoai"<< setw(17) << "|\n";
		cout << "|"<< setw(49) <<"3  - Xuat Thong Tin Toan Bo Khach Hang Viet Nam"<< setw(11) << "|\n";
		cout << "|"<< setw(51) <<"4  - Xuat Thong Tin Toan Bo Khach Hang Nuoc Ngoai"<< setw(9) << "|\n";
		cout << "|"<< setw(56) <<"5  - Tong So Luong Khach Hang (Viet Nam Va Nuoc Ngoai)"<< setw(4) << "|\n";
		cout << "|"<< setw(51) <<"6  - Tinh Trung Binh Cong Cua Khach Hang Viet Nam"<< setw(9) << "|\n";
		cout << "|"<< setw(53) <<"7  - Tinh Trung Binh Cong Cua Khach Hang Nuoc Ngoai"<< setw(7) << "|\n";
		cout << "|"<< setw(50) <<"8  - Tinh Trung Binh Cong Cua Toan Bo Khach Hang"<< setw(10) << "|\n";
		cout << "|"<< setw(38) <<"9  - Tim Hoa Don Theo Ngay Thang Nam"<< setw(22) << "|\n";
		cout << "|"<< setw(46) <<"10 - Xoa Toan Bo Hoa Don Khach Hang Viet Nam"<< setw(14) << "|\n";
		cout << "|"<< setw(48) <<"11 - Xoa Toan Bo Hoa Don Khach Hang Nuoc Ngoai"<< setw(12) << "|\n";
		cout << "|"<< setw(17) <<"0  - Thoat Menu" << setw(43) << "|\n";
		cout << "+----------------------------------------------------------+" << "\n";
		cout << "---> " << "Nhap Lua chon: ";
		cin >> choice;cin.ignore();
		// Thêm khách hàng Việt Nam vào danh sách
		if(choice == 1){
			int n;
			cout << "Nhap so luong: ";
			cin >> n;cin.ignore();
			KhachHangVietNam *x = new KhachHangVietNam[n];
			
			for(int i = 0 ; i < n ; i++){
				x->NhapThongTinKhachHangVN();
    			VnCusList.push_back(*x);
				cout << "---> "<< "Da them khach hang vao danh sach!!!\n";
			}
    		delete[] x;	
		} 
		// Thêm khách hàng nước ngoài vào danh sách
		else if(choice == 2){
			int n;
			cout << "Nhap so luong: ";
			cin >> n;cin.ignore();
			KhachHangNuocNgoai *y = new KhachHangNuocNgoai[n];
			for(int i = 0 ; i < n ; i++){
				y->NhapThongTinKhachHangNuocNgoai();
    			TouristCusList.push_back(*y);
    			cout << "---> "<<"Da them khach hang vao danh sach!!!\n";
			}
			delete[] y;
		} 
		// In ra toàn bộ khách hàng Việt Nam
		else if(choice == 3){
			cout << "====Danh Sach Khach Hang Viet Nam====\n";
			for(int i = 0 ; i < VnCusList.size() ; i++){
				VnCusList[i].XuatThongTinKhachHangVN();
			}
		} 
		// In ra toàn bộ danh sách khách hàng nước ngoài
		else if(choice == 4){
			cout << "====Danh Sach Khach Hang Nuoc Ngoai====\n";
			for(int i = 0 ; i < TouristCusList.size() ; i++){
				TouristCusList[i].XuatThongTinKhachHangNuocNgoai();
			}
		} 
		//Tổng số lượng khách hàng (Việt Nam và nước ngoài) 
		else if(choice == 5){
			cout << "So Luong Khach Hang la: " << VnCusList.size() + TouristCusList.size() << "\n";
		} 
		//Tính trung bình cộng của khách hàng Việt Nam
		else if(choice == 6){
			cout << "Tong Trung Binh Cong Cua Toan Bo Khach Hang Viet Nam: "<< KhachHangVietNam::TinhTBCKhachHangVN(VnCusList)<< "\n";
		}
		// Tính trung bình cộng của khách hàng nước ngoài 
		else if(choice == 7){
			cout << "Tong Trung Binh Cong Cua Toan Bo Khach Hang Nuoc Ngoai La: "<< KhachHangNuocNgoai::TinhTBCKhachHangNuocNgoai(TouristCusList)<< "\n";
		}
		// Tính Trung bình cộng của toàn bộ khách hàng 
		else if(choice == 8){
			cout << "Tong Trung Binh Cong Cua Toan Bo Khach Hang La: "<<KhachHangNuocNgoai::TinhTBCAll(VnCusList,TouristCusList) << "\n";
		}
		// Tìm hóa đơn theo ngày/tháng/năm
		else if(choice == 9){
			int M;
			int Y;
			cout << "Nhap Thang: ";cin >> M; cout << "Nhap Nam: ";cin >> Y;
			for(int i=0;i < VnCusList.size();i++){
				if(VnCusList[i].Thang == M && VnCusList[i].Nam == Y){
					VnCusList[i].XuatThongTinKhachHangVN();
				}
			}
			for(int i=0;i < TouristCusList.size();i++){
				if(TouristCusList[i].Thang == M && TouristCusList[i].Nam == Y){
					TouristCusList[i].XuatThongTinKhachHangNuocNgoai();
				}
			}
		} else if(choice == 10){
			VnCusList.clear();
			cout << "---> "<< "Da Xoa Toan Bo Du Lieu Khach Hang Viet Nam\n";
		} else if(choice == 11){
			TouristCusList.clear();
			cout << "---> "<< "Da Xoa Toan Bo Du Lieu Khach Hang Nuoc Ngoai\n";
		}
		
} while (choice != 0);	
system("cls");
cout << "====THOAT MENU====";
	return 0;
} 	