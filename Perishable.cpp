#include "Perishable.h"
#include "Date.h"
#include "Product.h"
using namespace std;
namespace AMA {
	Perishable::Perishable() {
		this->m_type = 'P';
		this->expiry_date = Date();
	}
	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
		Product::store(file, false);

		file << ',' << expiry_date.m_year << '/'
			<< '0' << expiry_date.m_month << '/' << expiry_date.m_day;

		if (newLine)
		{
			file << '\n';
		}

		return file;

	}
	std::fstream& Perishable::load(std::fstream& file) {
		Product::load(file);
		/*file.ignore();*/

		expiry_date.read(file);
		file.ignore();

		return file;
	}
	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		Product::write(os, linear);
		if (!this->isEmpty() && this->isClear())
		{
			if (!linear)
			{
				os << endl << " Expiry date: ";
			}
			expiry_date.write(os);
		}
		return os;
	}
	std::istream& Perishable::read(std::istream& is) {
		Product::read(is);
		Date temp;

		if (!is.fail()) {

			std::cout << " Expiry date (YYYY/MM/DD): ";
			temp.read(is);
			if (temp.checkError == 1)
			{
				message("Invalid Date Entry");
				is.clear();
				is.setstate(std::ios::failbit);
			}
			else if (temp.checkError == 2)
			{
				message("Invalid Year in Date Entry");
				is.clear();
				is.setstate(std::ios::failbit);
			}
			else if (temp.checkError == 3)
			{
				message("Invalid Month in Date Entry");
				is.clear();
				is.setstate(std::ios::failbit);
			}
			else if (temp.checkError == 4)
			{
				message("Invalid Day in Date Entry");
				is.clear();
				is.setstate(std::ios::failbit);
			}
			this->expiry_date = temp;

		}

		return is;

	}
	const Date& Perishable::expiry() const {

		return expiry_date;
	}

}
