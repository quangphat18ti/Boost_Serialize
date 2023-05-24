# Thư viện Boost và cách cài đặt

## Boost là gì?

- Boost là một thư viện mở rộng của C++.
- Thư viện Boost nhằm mục đích trở nên hữu ích rộng rãi và có thể sử dụng được trên nhiều ứng dụng. Ví dụ, chúng rất hữu ích để xử lý các số lớn có phạm vi vượt quá kiểu dữ liệu double long, long long (264) trong C++.
- Thư viện Boost cũng cung cấp các cấu trúc dữ liệu và thuật toán tiên tiến, các cấu trúc dữ liệu này có thể được sử dụng để xây dựng các ứng dụng phức tạp.

## Cài đặt thư viện Boost

### Cài đặt và sử dụng nhanh với Visual Studio

- Bước 1: [Vào link này](https://vcpkg.io/en/getting-started.html) để cài đặt vcpkg.
- Bước 2: Vào thư mục C:\src\vcpkg (Hoặc 1 thư mục bạn muốn)
- Bước 3: Clone the vcpkg repo (
  `git clone https://github.com/Microsoft/vcpkg.git`)
- Bước 4: Mở cmd tại thư mục vcpkg
- Bước 5: Chạy lệnh (`.\vcpkg\bootstrap-vcpkg.bat`)
- Bước 6: Chạy lệnh (`.\vcpkg\vcpkg integrate install`)
- Bước 7: Mở VS ra và code thôi.

### Tải và cài đặt bài bản

- Bước 1: [Vào link này](https://www.boost.org/doc/libs/1_62_0/more/getting_started/unix-variants.html#errors-and-warnings) để tải bản boost mới nhất.

- Bước 2: Đọc hướng dẫn sử dụng bên dưới và cách cài đặt.

- Lưu ý: [Có thể sử dụng Respo Git của tui để tránh phải làm lại nhiều.](https://github.com/quangphat18ti/Boost-Libraries)

## Tổng quan về Boost

### Cách sử dụng thư viện

**(Nếu sử dụng trong Visual Studio thì không cần phải làm bước này)**

- Cài đặt thư viện Boost vào trong Project.
- Khi build file thì phải dẫn link thư viện Boost trong câu lệnh compile.  
   ` g++ -I path/to/boostLibrary   
main.cpp -o main 
path/to/boostLibrary/lib/libUse`

- Trong đó:
  - path/to/boostLibrary là đường dẫn đến thư viện Boost.
  - libUse là thư viện cần sử dụng (Sẽ được trình bày bên dưới).

### Các thư viện Boost: Thư viện trong Boost được chia làm 2 loại

1. **Thư viện Header-Only**: Thư viện này chỉ cần include vào là có thể sử dụng được. (Các thư viện này được đặt trong thư mục boost)
2. Thư viện không phải Header-Only: Thư viện này cần phải được build trước khi sử dụng. (**Các thư viện này được đặt trong thư mục lib**)
   - Để tìm hiểu thêm về các thư viện này thì có thể vào [link này](https://www.boost.org/doc/libs/1_62_0/more/getting_started/unix-variants.html#build-a-boost-library)

### **Lưu ý về cách sử dụng thư viện loại 2**

1. Trong file .cpp ta vẫn include file .hpp như bình thường.
2. Tuy nhiên khi compile thì phải dẫn đường dẫn đến thư viện đã Compile Boost trong câu lệnh compile.
   - Các thư viện thường có đuôi là **.a** hoặc **.so** và đặt trong folder **/lib** của thư viện Boost.
   - Tuy nhiên, ta cần xác định đúng file thư viện cần sử dụng.
     - Ví dụ: **libboost_serialization-mgw63-mt-1_62.a** là thư viện **serialization** của Boost.

Ví dụ: `g++ -I . main.cpp -o main .\lib\libboost_serialization-mgw63-mt-1_62.a`

Là câu lệnh dùng để Serialize Object.

# Sử dụng Boost để Serialize Object

## Giới thiệu về Serialize Object

- Serialize Object là một quá trình chuyển đổi một Object thành một chuỗi byte để lưu trữ hoặc truyền đi.
- Quá trình ngược lại là Deserialize Object, chuyển đổi một chuỗi byte thành một Object.
- Serialize Object được sử dụng rộng rãi trong các ứng dụng lưu trữ dữ liệu, truyền dữ liệu giữa các ứng dụng, truyền dữ liệu giữa Client và Server. **Đặt biệt là trong việc truyền nhận dữ liệu qua Socket**.

## Thư viện Boost hỗ trợ cho Serialize Object

1. **Thư viện Boost.Serialization**: Với các dữ liệu đơn giản: int, float, double, string, vector, map, set, ... thì thư viện này có thể Serialize và Deserialize được. Tuy nhiên, với các dữ liệu phức tạp hơn như: Object, Class, ... thì thư viện này không hỗ trợ Serialize và Deserialize được.
2. **Thư viện boost/archive/binary_iarchive.hpp**: Thư viện này hỗ trợ Serialize được với các dữ liệu phức tạp hơn như: Object, Class, ...
3. **Thư viện boost/archive/binary_oarchive.hpp**:Thư viện này hỗ trợ DeSerialize được với các dữ liệu phức tạp hơn như: Object, Class, ...

## Hướng dẫn về biên dịch:

- Các thư viện trên đều là thư viện không phải Header-Only.
- Ta cần phải sử dụng thư viện đã được compile khi sử dụng: **libboost_serialization-mgw63-mt-1_62.a**.
- Các thư viện này được đặt trong thư mục **/lib** của thư viện Boost.

Câu lệnh: `g++ -I . main.cpp -o main .\lib\libboost_serialization-mgw63-mt-1_62.a`

Hoặc nếu sử dụng make file: `make`

# Hướng dẫn code

## Serialize Với các kiểu dữ liệu cơ sở (Không cần làm gì)

## Serialize Object

```
class Employee
{
private:
    friend class boost::serialization::access;
    int id;
    string name;
    float salary;

public:
    friend ostream &operator<<(ostream &outDev, const Employee &e)
    {
        outDev << "id: " << e.id << endl;
        outDev << "name: " << e.name << endl;
        outDev << "salary: " << e.salary;
        return outDev;
    }

public:
    template <class Archive>
    void serialize(Archive &a, const unsigned version)
    {
        a & id;
        a & name;
        a & salary;
    }

public:
Employee() {}
Employee(int i, string n, float s) : id(i), name(n), salary(s)
{
}
};
```

2 thành phần phải có là:

    1. friend class boost::serialization::access;
    2. template <class Archive>
        void serialize(Archive &a, const unsigned version)

## Sử dụng VectorSerialize Class để Serialize Object

- Class này chứa 1 `vector<T> m_data`
- Class hỗ trợ 4 phương thức Serialize và Deseralize:
  - `void writeToFile(string filename);`
    - Serialize m_data và ghi vào filename.
  - `void readFromFile(string filename);`
    - Đọc dữ liệu từ filename và Deserialize vào m_data.
  - `string Serialize();`
    - Serialize m_data và trả về chuỗi byte.
  - `void DeSerialize(string receivedDataStr);`
    - Deserialize chuỗi byte và lưu vào m_data.
