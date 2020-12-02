- QLPhong: Mảng các PhongKS để quản lý cả PhongBT và phòng Vip
			Exception cho chỉ số mảng không hợp lệ
			Template(Generic) cho mảng PhongKS
			Sô lượng phòng tương đương vs size của QLSV
			Đa năng hoá << (đa năng hoá << cho PhongKS trước)=

			Xoa data[k], tao them 1 ham NewPhongKS(template) de them phong roi dung ham Add

- Rảnh : Làm kĩ lớp Date (tháng 2 28/29 ngày , tháng 30/31 ngày)
- Thêm type để phân biệt 2 loại phòng ?

- if tinhtrang=true thi bo qua buoc nhap ngay thang Nhan Tra Phong , roi tao doi tuong vs 2 tham so NULL

Compile and Run : 
g++ main.cpp Date.cpp PhongKS.cpp PhongBT.cpp PhongVIP.cpp QLPhong.cpp -std=c++11 -o run.exe ; ./run.exe 


Tạo 2 mảng bằng template , tạo 1 mảng ** của PhongKS để quản lý 2 mảng kia

single ton or static

Teacher** t , mỗi t là 1 *teacher