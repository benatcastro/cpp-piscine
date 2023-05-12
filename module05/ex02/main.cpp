#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void scf_tests_self(void) {
	ShruberryCreationForm rrq("paco");
	Bureaucrat executor("bob", 10);
	Bureaucrat executor2("bob", 150);


	try {
		cout << "====Test n:1=====\n";
		rrq.beSigned(executor2);
	}
	catch (std::exception &e) {
		cout << "Exception: " <<  e.what() << endl;
	}
	cout << "\n\n=====================\n\n";
	try {
		cout << "====Test n:2=====\n";
		rrq.execute(executor2);
	}
	catch (std::exception &e) {
		cout << "Exception: " <<  e.what() << endl;
	}
	cout << "\n\n=====================\n\n";
	try {
		cout << "====Test n:3=====\n";
		rrq.beSigned(executor);
		rrq.execute(executor);
	}
	catch (std::exception &e) {
		cout << "Exception: " <<  e.what() << endl;
	}
}

void scf_test_bureaucrat(void) {

	ShruberryCreationForm rrq("paco");
	Bureaucrat executor("bob", 10);
	Bureaucrat executor2("bob", 150);
	try {
		cout << "====Test n:4=====\n";
		executor2.signForm(rrq);
	}
	catch (std::exception &e) {
		cout << "Exception: " <<  e.what() << endl;
	}
	cout << "\n\n=====================\n\n";
	try {
		cout << "====Test n:5=====\n";
		executor2.executeForm(rrq);
	}
	catch (std::exception &e) {
		cout << "Exception: " <<  e.what() << endl;
	}
	cout << "\n\n=====================\n\n";
	try {
		cout << "====Test n:6=====\n";
		executor.signForm(rrq);
		executor.executeForm(rrq);
	}
	catch (std::exception &e) {
		cout << "Exception: " <<  e.what() << endl;
	}
}
void rrf_tests_self(void) {
	RobotomyRequestForm rrq("paco");
	Bureaucrat executor("bob", 10);
	Bureaucrat executor2("bob", 150);


	try {
		cout << "====Test n:1=====\n";
		rrq.beSigned(executor2);
	}
	catch (std::exception &e) {
		cout << "Exception: " <<  e.what() << endl;
	}
	cout << "\n\n=====================\n\n";
	try {
		cout << "====Test n:2=====\n";
		rrq.execute(executor2);
	}
	catch (std::exception &e) {
		cout << "Exception: " <<  e.what() << endl;
	}
	cout << "\n\n=====================\n\n";
	try {
		cout << "====Test n:3=====\n";
		rrq.beSigned(executor);
		rrq.execute(executor);
	}
	catch (std::exception &e) {
		cout << "Exception: " <<  e.what() << endl;
	}
}

void rrf_test_bureaucrat(void) {

	RobotomyRequestForm rrq("paco");
	Bureaucrat executor("bob", 10);
	Bureaucrat executor2("bob", 150);
	try {
		cout << "====Test n:4=====\n";
		executor2.signForm(rrq);
	}
	catch (std::exception &e) {
		cout << "Exception: " <<  e.what() << endl;
	}
	cout << "\n\n=====================\n\n";
	try {
		cout << "====Test n:5=====\n";
		executor2.executeForm(rrq);
	}
	catch (std::exception &e) {
		cout << "Exception: " <<  e.what() << endl;
	}
	cout << "\n\n=====================\n\n";
	try {
		cout << "====Test n:6=====\n";
		executor.signForm(rrq);
		executor.executeForm(rrq);
	}
	catch (std::exception &e) {
		cout << "Exception: " <<  e.what() << endl;
	}
}


void ppf_test_bureaucrat(void) {

	PresidentialPardonForm rrq("paco");
	Bureaucrat executor("bob", 10);
	Bureaucrat executor2("bob", 150);
	try {
		cout << "====Test n:4=====\n";
		executor2.signForm(rrq);
	}
	catch (std::exception &e) {
		cout << "Exception: " <<  e.what() << endl;
	}
	cout << "\n\n=====================\n\n";
	try {
		cout << "====Test n:5=====\n";
		executor2.executeForm(rrq);
	}
	catch (std::exception &e) {
		cout << "Exception: " <<  e.what() << endl;
	}
	cout << "\n\n=====================\n\n";
	try {
		cout << "====Test n:6=====\n";
		executor.signForm(rrq);
		executor.executeForm(rrq);
	}
	catch (std::exception &e) {
		cout << "Exception: " <<  e.what() << endl;
	}
}
void ppf_tests_self(void) {
	PresidentialPardonForm rrq("paco");
	Bureaucrat executor("bob", 10);
	Bureaucrat executor2("bob", 150);


	try {
		cout << "====Test n:1=====\n";
		rrq.beSigned(executor2);
	}
	catch (std::exception &e) {
		cout << "Exception: " <<  e.what() << endl;
	}
	cout << "\n\n=====================\n\n";
	try {
		cout << "====Test n:2=====\n";
		rrq.execute(executor2);
	}
	catch (std::exception &e) {
		cout << "Exception: " <<  e.what() << endl;
	}
	cout << "\n\n=====================\n\n";
	try {
		cout << "====Test n:3=====\n";
		rrq.beSigned(executor);
		rrq.execute(executor);
	}
	catch (std::exception &e) {
		cout << "Exception: " <<  e.what() << endl;
	}
}
int main(void) {

	cout << "ROBOTOMY REQUEST TETS\n";
	rrf_tests_self();
	rrf_test_bureaucrat();
	cout << "PRESIDENTIAL REQUEST TETS\n";
	ppf_tests_self();
	ppf_test_bureaucrat();
	cout << "SHRUBERRY REQUEST TETS\n";
	scf_tests_self();
	scf_test_bureaucrat();
//	cout << "\n\n=====================\n\n";
	cout << "\n\n============LEAKS============\n";
    system("leaks -quiet ex02");
}
