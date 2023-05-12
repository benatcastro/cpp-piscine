#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {

	{
		try {

			Form form;

			cout << form << endl;

			Form form2("Articulo 66 sobre la cultivacion de las patatas alavesas", 5, 10);

			cout << form2 << endl;

			form = form2;

			cout << form << endl;

			Form form3(form2);

			cout << form3 << endl;

			Form form4("Articulo 66 sobre la cultivacion de las patatas alavesas", 151, 10);
			Form form5("Articulo 66 sobre la cultivacion de las patatas alavesas", 150, 0);
			Form form6("Articulo 66 sobre la cultivacion de las patatas alavesas", 151, 0);

		}
		catch (const std::exception &e) {
			cout << "Error: " << e.what() << endl;
		}
	}
	cout << "\n\n";
	{

		try {
			Bureaucrat bobTheSigner("bob-potato-signer", 21);
			Form form("Super duper potato", 20, 20);
			bobTheSigner.signForm(form);
            cout << form;
		}
		catch (const std::exception &e) {
			std::cout << "Error: " << e.what() << endl;
		}
	}
	cout << "\n\n";
	{
		try {
			Bureaucrat bobTheSigner("bob-potato-signer", 20);
			Form form("Super duper potato", 21, 20);
			form.beSigned(bobTheSigner);
		}
		catch (const std::exception &e) {
			std::cout << "Error: " << e.what() << endl;
		}
	}
	cout << "\n\n";



	cout << "============LEAKS============\n";
    system("leaks -quiet Bureaucrat");
}
