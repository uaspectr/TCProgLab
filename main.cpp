#include "bint.h"

void usage()
{
	cout << "Использование: TCProgLab входной_файл1.txt (+-x/%^) входной_файл2.txt файл_результата.txt -b(бинарный режим, если необходимо)\n";

	exit(-1);
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");

	bint b1, b2, b3;

	bool binary = false;

	if (argc < 5 || argc > 6)
		usage();
	else if (argc == 6)
	if (!strcmp(argv[5], "-b"))
		binary = true;
	else
		usage();

	if (binary == false)
	{
		b1 = b1.read(argv[1]);
		b2 = b2.read(argv[3]);
	}
	else
	{
		b1 = b1.readbin(argv[1]);						// закомментировать, если используются 2 строчки ниже
		b2 = b2.readbin(argv[3]);						// закомментировать, если используются 2 строчки ниже

		// для создания заготовок бинарных файлов:
		//bint b1("99999999999999999999999999999999"); 	// раскомментировать, если не используются 2 строчки выше
		//bint b2("99999999999999999999999999999999"); 	// раскомментировать, если не используются 2 строчки выше
	}

	if (!strcmp(argv[2], "+"))
		b3 = b1 + b2;
	else if (!strcmp(argv[2], "-"))
		b3 = b1 - b2;
	else if (!strcmp(argv[2], "x"))
		b3 = b1 * b2;
	else if (!strcmp(argv[2], "/"))
		b3 = b1 / b2;
	else if (!strcmp(argv[2], "%"))
		b3 = b1 % b2;
	else if (!strcmp(argv[2], "^"))
		b3 = b1 ^ b2;
	else
		usage();

	if (binary == false)
		b3.write(string(b3), argv[4]);
	else
		b3.writebin(b3, argv[4]);

	return 0;
}