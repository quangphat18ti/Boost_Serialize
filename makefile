pathBoost = .

main: main.cpp
	g++ -I $(pathBoost) main.cpp -o main $(pathBoost)\lib\libboost_serialization-mgw63-mt-1_62.a