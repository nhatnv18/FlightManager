# Flight Manager
# Quản Lý Chuyến Bay
PTITHCM - Khoá 2018 CNTT - Giảng viên: Lưu Nguyễn Kỳ Thư

Đề số 4: Quản lý các chuyến bay nội địa thuộc 1 hãng hàng không:
- Máy bay: Mảng con trỏ có tối đa 300 máy bay. Mỗi máy bay có các thông tin(Số hiệu MB (C15), loại máy bay(C40), số chỗ); Mỗi máy bay có 1 số hiệu duy nhất; Số chỗ >=20.
- Chuyến bay: Danh sách liên kết đơn( Mã CB (C15), Ngày giờ khởi hành, sân bay đến , trạng thái, Số hiệu MB, danh sách vé).
Mỗi chuyến bay có 1 mã duy nhất;
trạng thái chuyến bay bao gồm: 0: hủy chuyến, 1: còn vé, 2: hết vé,3: hoàn tất ;
danh sách vé cho biết thông tin vé trên chuyến bay, và số CMND của hành khách đã đặt vé đó.
Mỗi vé có số vé là số thứ tự trên chuyến từ số 1 đến số chỗ .

Danh sách vé được cấp phát bộ nhớ tự động dựa vào số chỗ của máy bay thực hiện chuyến bay.

- Hành khách: cây nhị phân tìm kiếm cân bằng (Số CMND , Ho, Ten, Phai)

Chương trình có các chức năng sau:
a/ Cập nhập danh sách các máy bay(thêm / xóa / hiệu chỉnh).

b/ Cập nhật chuyến bay: cho phép lập chuyến bay mới, hiệu chỉnh ngày giờ khởi hành của chuyến bay, hủy chuyến.

c/ Đặt vé: cho phép đặt vé trên 1 chuyến bay.

    + Nếu thông tin hành khách chưa có thì tự động cập nhật vào danh sách hành khách.
    + Nếu có rồi thì in ra màn hình để kiểm tra.
    + Mỗi vé đều phải ghi nhận số CMND của hành khách.
    + Nếu hành khách chưa có số CMND thì yêu cầu nhập thông tin hành khách trước.
    Trên 1 chuyến bay, mỗi hành khách chỉ được mua 1 vé.

d/ Hủy vé: cho phép hủy vé đã đặt của hành khách.

e/ In danh sách các hành khách thuộc 1 chuyến bay dựa vào mã chuyến bay. Kết xuất:
            DANH SÁCH HÀNH KHÁCH THUỘC CHUYẾN BAY ######

    Ngày giờ khởi hành: dd/mm/yyyy hh:mm. Nơi đến : xxxxxxxxxxx

    STT   SỐ VÉ   SỐ CMND   HỌ TÊN   PHÁI
f/ In danh sách các chuyến bay khởi hành trong ngày dd/mm/yyyy đến nơi XXXX(cho biết cụ thể số lượng các vé còn trống và giờ khởi hành)

g/ In danh sách các vé còn trống của 1 chuyến bay có mã chuyến bay là X.

h/ Thống kê số lượt thực hiện chuyến bay của từng máy bay theo thứ tự số lượt thực hiện giảm dần.
Kết xuất:

        Số hiệu máy bay        Số lượt thực hiện chuyến bay
        
Lưu ý: Chương trình cho phép lưu các danh sách vào file; Kiểm tra các điều kiện khi nhập liệu làm dữ liệu bị sai.

Nhóm tác giả:

	Nguyễn Văn Nhất	- N18DCCN139	<a,b,e,h>
    Lê Nguyễn Đức Tân - N18DCCN182	<c,d,f,g>
