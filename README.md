# Bài tập lớn môn Kỹ Thuật Lập Trình

# Giới thiệu

  - Yêu cầu của bài tập lớn:

    A. Lý thuyết (Hàm, Con trỏ, Con trỏ mảng, Mảng con trỏ, Con trỏ hàm, Cấp phát động, Xử lý tệp, Kiểu cấu trúc, Danh sách liên kết)

    B. Ứng dụng xây dựng ứng dụng cho bài toán cụ thể với đầy đủ tính năng cần thiết
    
  - Phần B được viết bằng ngôn ngữ C - Thời gian thực hiện từ ngay 08/05/2025 - 22/05/2025
    
# Sinh viên thực hiện

  Sinh viên lớp:  CQ.K65.CNTT - Thuộc trường đại học Giao Thông Vận tải phân hiệu TP. Hồ Chí Minh
  
  - Phần A:

    + Võ Hồng Thiên - MSSV: - Nội dung thực hiện: 

    + Dư Nguyên An - MSSV: - Nội dung thực hiện:
  
  - Phần B:
  
    + Huỳnh Trung Nghĩa - MSSV: 6551071057 - Nội dung thực hiện: Code

    + Dư Nguyên An - MSSV: - Nội dung thực hiện: Viết báo cáo

# Bố cục phần B dựa vào đề bài sau

    Đề bài được lấy ý tưởng từ "Đồ án kết thúc học kỳ năm 1 ngành CNTT - Đại học Khoa Học Tự Nhiên" có điều chỉnh.

    - Thông tin thẻ độc giả cần quản lí bao gồm: họ tên, MSSV, ngày tháng năm sinh, giới tính, ngày lập thẻ và ngày hết hạn của thẻ (48 tháng kể từ ngày lập thẻ).
    
    - Thông tin sách cần quản lí bao gồm: ISBN (mã sách), tên sách, tác giả, năm xuất bản, thể loại, giá sách, số quyển sách.

    - Mỗi phiếu mượn/trả sách chứa thông tin về mã độc giả, ngày mượn, ngày trả dự kiến, ngày trả thực tế, số sách mượn trong 1 lần không hơn 10 cuốn và 1 sách chỉ được mượn 1 lần và danh sách ISBN của các sách được mượn.

        •	Mỗi sách được mượn tối đa trong 91 ngày (nếu quá hạn thẻ dg thì ngày trả dự kiến là ngày thẻ đg hết hạn), nếu quá hạn sẽ bị phạt tiền 5.000 đồng/ngày.

        •	Mượn sách nào, số cuốn sẽ trừ vào số lượng sách ở thông tin sách đó.

        •	Nếu thẻ độc giả hết hạn => yêu cầu trả tất cả sách đã mượn trước đó HOẶC xóa thẻ cũ, tạo thẻ độc giả mới.
    
    - Chương trình cần lưu trữ và cập nhật dữ liệu vào các FILE để đảm bảo dữ liệu.

# Chương trình có các chức năng sau:

  1. Quản lí độc giả

    a. Xem danh sách độc giả trong thư viện

    b. Thêm độc giả

    c. Xóa độc giả theo MSSV

    d. Chỉnh sửa thông tin một độc giả
   
  2. Quản lí sách

    a. Xem danh sách các sách trong thư viện

    b. Tìm kiếm sách theo ISBN

    c. Tìm kiếm sách theo tên sách

    d. Them sach
   
  3. Lập phiếu mượn sách và trả sách

	a. nhap phieu muon sach

	b. xem danh sách các sách đang được mượn bởi 1 độc giả theo MSSV (trả sách sẽ trừ đi số lượng sách và ISBN của sách đó ở phiếu mượn và cộng lại số lượng sách ở thư viện)
    
	c. nhap phieu tra sach

  4. Các thống kê cơ bản

    a. Thống kê số lượng sách trong thư viện

    b. Thống kê số sách đang được mượn

    c. Thống kê số lượng độc giả trễ hạn trả sách

# Cách sử dụng

  1. Chạy trên trình biên dịch C/C++ (VS Code, DevC++, ...)

  2. Chạy chương trình

     Hướng dẫn với VS Code: dùng PowerShell, Command Prompt, Git Bash,...

       - Ví dụ với Git Bash:

         + B1: trỏ tới địa chỉ thư mục dùng: cd "địa chỉ lưu thư mục bài tập lớn này"

         + B2: kiểm tra tới đúng thư mục chưa bằng lệnh: dir

         + B3: dùng:   gcc + tên các file .c + -o main.exe    HOAC   gcc *.c -o main.exe
         
         + B4: để chạy dùng: .\main.exe 
         
  3. Làm theo hướng dẫn trên màn hình console
