# Sử dụng Boost để Serialize Object

## Cách sử dụng

- Bước 1: Cài đặt folder này vào thư mục chạy dự án.
- Bước 2: Sử dụng đúng câu lệnh để build chương trình:

**Câu lệnh để build trong makeFile:**

```
pathBoost = .

main: main.cpp
	g++ -I $(pathBoost) main.cpp -o main $(pathBoost)\lib\libboost_serialization-mgw63-mt-1_62.a
```

**Câu lệnh chạy trong terminal:**

```
    make
```
