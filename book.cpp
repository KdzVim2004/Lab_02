#include "book.h"
#include <stdexcept>
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	try {
		Book book("Война и мир", "Л. Толстой", 1869, 1225);
		cout << formatBookInfo(book) << endl;
		try {
			book.updateYear(3000);
		}
		catch (const invalid_argument& e) {
			cout << "Ошибка при обновлении: " << e.what() << endl;
		}
		book.updateTitle("Война и мир. Том 4");
		cout << formatBookInfo(book) << endl;

		if (isClassic(book)) {
			cout << "Книга является классикой" << endl;
		}
		book.checkout();
		cout << formatBookInfo(book) << endl;

		double days = readingTime(book, 50);
		cout << "Время чтения: " << days << " дней" << endl;

		Book book2("1984", "Д. Оруэлл", 1949, 328);
		if (isOlder(book, book2)) {
			cout << "Первая книга старше второй" << endl;
		}
	}
	catch (const invalid_argument& e) {
		cout << "Ошибка создания книги: " << e.what() << endl;
	}
	return 0;
}