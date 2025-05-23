# Bài tập lớn môn Kỹ Thuật Lập Trình

# Giới thiệu

  - Yêu cầu của bài tập lớn:

    A. Lý thuyết (Hàm, Con trỏ, Con trỏ mảng, Mảng con trỏ, Con trỏ hàm, Cấp phát động, Xử lý tệp, Kiểu cấu trúc, Danh sách liên kết)

    B. Ứng dụng xây dựng ứng dụng cho bài toán cụ thể với đầy đủ tính năng cần thiết
    
# Sinh viên thực hiện:

  Sinh viên lớp: CQ.K65.CNTT - Trường đại học Giao Thông Vận tải phân hiệu TP. Hồ Chí Minh
  
   + Huỳnh Trung Nghĩa - MSSV: 6551071057
    
   + Võ Hồng Thiên - MSSV: 6551071078
 
   + Dư Nguyên An - MSSV: 6551071001 

# Đề bài phần B: Ứng dụng

  Thông tin thẻ độc giả cần quản lí bao gồm: họ tên, MSSV, ngày tháng năm sinh, giới tính, ngày lập thẻ và ngày hết hạn của thẻ (48 tháng kể từ ngày lập thẻ).

  Thông tin sách cần quản lí bao gồm: ISBN (mã sách), tên sách, tác giả, năm xuất bản, thể loại, giá sách, số quyển sách.

  Mỗi phiếu mượn/trả sách chứa thông tin về mã độc giả, ngày mượn, ngày trả dự kiến, ngày trả thực tế, số sách mượn trong 1 lần <= 10 và danh sách ISBN của các sách được mượn.

    •	Mỗi sách được mượn tối đa trong 91 ngày (nếu quá hạn thẻ dg thì ngày trả dự kiến là ngày thẻ đg hết hạn), nếu quá hạn sẽ bị phạt tiền 5.000 đồng/ngày.

    •	Mượn sách nào, số cuốn sẽ trừ vào số lượng sách ở thông tin sách đó

    •	Nếu thẻ độc giả hết hạn => yêu cầu trả tất cả sách đã mượn trước đó HOẶC xóa thẻ cũ, tạo thẻ độc giả mới;

  Chương trình cần lưu trữ và cập nhật dữ liệu vào các FILE.

  Chương trình có các chức năng sau:

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

      a. nhập phiếu mượn sách

      b. nhập phiếu trả sách

      c. xem danh sách các sách đang được mượn bởi 1 độc giả theo MSSV (trả sách sẽ trừ đi số lượng sách và ISBN của sách đó ở phiếu mượn và cộng lại số lượng sách ở thư viện)

    4. Các thống kê

      a. Thống kê số lượng sách trong thư viện

      b. Thống kê số sách đang được mượn

      c. Thống kê số lượng độc giả trễ hạn trả sách
 
# Hướng dẫn chạy chương trình;

  1. Chạy trên trình biên dịch C/C++ (VS Code, DevC++, ...)

  2. Chạy chương trình

     Hướng dẫn với VS Code: dùng PowerShell, Command Prompt, Git Bash,...

       - Ví dụ với Git Bash:

         + B1: trỏ tới địa chỉ thư mục dùng: cd "địa chỉ lưu thư mục bài tập lớn này"

         + B2: kiểm tra tới đúng thư mục chưa bằng lệnh: dir

         + B3: dùng:   gcc + tên các file .c + -o main.exe    HOAC   gcc *.c -o main.exe
         
         + B4: để chạy dùng: .\main.exe 
         
  3. Làm theo hướng dẫn trên màn hình console.
