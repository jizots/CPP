#include "Serializer.hpp"
#include <iostream>

int	main()
{
	std::cout << "------------- Subject Test -------------" << std::endl;
	Data d1;
	std::cout << "&d1; " << &d1 << std::endl;
	uintptr_t uptr1 = Serializer::serialize(&d1);
	std::cout << "uptr1 " << uptr1 << std::endl;
	std::cout << "uptr1 " << std::hex << uptr1 << std::endl;
	std::cout << "Compair: " << (&d1 == Serializer::deserialize(uptr1)) << std::endl;
	std::cout << std::endl;
	std::cout << "------------- My Test -------------" << std::endl;
	// uintptr_t cst_static = static_cast<uintptr_t>(&d1); //Compile error
	// uintptr_t cst_const = const_cast<uintptr_t>(&d1); //Compile error
	// uintptr_t cst_dynamic = dynamic_cast<uintptr_t>(&d1); //Compile error
	// uintptr_t cst_dynamic = &d1; //Compile error
	// char ptr_c = reinterpret_cast<char>(&d1); // Compile error
	return (0);
}

/*https://learn.microsoft.com/ja-jp/cpp/cpp/reinterpret-cast-operator?view=msvc-170*/