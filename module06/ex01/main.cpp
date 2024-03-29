#include "Serialize.hpp"
#include <iostream>

int main(void)
{
	{
		Data *data = new Data;
		uintptr_t ptr = {0};

		data->x = 2;
		data->str = "Patatas!";

		std::cout << "Before serialize data: " << data << " Ptr: " << ptr << std::endl;

		ptr = Serialize::serialize(data);
		std::cout << "After serialize data: " << data << " Ptr: " << ptr << std::endl;
		delete data;
	}

	std::cout << "\n\n===============\n\n";

	{
		Data *data = new Data;
		Data *compare;

		data->str = "Patata!";
		data->x	= 42;

		std::cout << "Subject test!\n";

		std::cout << "Before: " << data << "\n";
		compare = Serialize::deserialize(Serialize::serialize(data));
		std::cout << "After: " << compare << "\n";

		std::cout << "Str after: " << compare->str << "\nX after: " << compare->x << std::endl;

		delete data;
	}

	std::cout << "\n\n================\n";
	system("leaks --quiet Serializer");
}
