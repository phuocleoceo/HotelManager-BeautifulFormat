- Trích string[0] để lấy số hiệu Tầng -> lấy giá tầng từ enum gán cho DonGia -> Tính được thành tiền

- QLPhong: Mảng các PhongKS để quản lý cả PhongBT và phòng Vip
			Exception cho chỉ số mảng không hợp lệ
			Template(Generic) cho mảng PhongKS
			Sô lượng phòng tương đương vs size của QLSV
			Đa năng hoá << (đa năng hoá << cho PhongKS trước)
- Menu Switch case (do while , stop when ESC)

- Rảnh : Làm kĩ lớp Date (tháng 2 28/29 ngày , tháng 30/31 ngày)
- Hỏi Thịnh xem thêm biến là sao ? Thêm type để phân biệt 2 loại phòng ?

Compile and Run : 
g++ main.cpp Date.cpp PhongKS.cpp PhongBT.cpp PhongVIP.cpp QLPhong.cpp -o run.exe ; ./run.exe 