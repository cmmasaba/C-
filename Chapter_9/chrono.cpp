#include "chrono.h"

namespace Chrono {
	//member functions

	Date::Date(int yy, Month mm, int dd)
		:y{yy}, m{mm}, d{dd}
	{
		if(!is_date(yy, mm, dd))
			throw Invalid{};
	}

	const Date& default_date(void)
	{
		static Date dd {2001, Month::jan, 1};
		return dd;
	}

	Date::Date(void)
		:y{default_date().year()},
		m{default_date().month()},
		d{default_date().day()}
	{
	}

	void Date::add_day(int n)
	{
		int days_of_month = 31;
		switch(m) {
			case Chrono::Month::jan:
			{
				if((d+n) > days_of_month) {
                        	       	int delta_days = days_of_month - d;
                        	       	n -= delta_days;
					m = Chrono::Month::feb;
                                	d = n;
                        	} else {
                                	d += n;
                        	}
			}
			case Chrono::Month::feb:
			{
				days_of_month = (is_leapyear(y)) ? 29 : 28;
                        	if((d+n) > days_of_month) {
                               		int delta_days = days_of_month - d;
                               		n -= delta_days;
                               		m = Chrono::Month::mar;
                               		d = n;
                        	} else {
                               	d += n;
                        	}
			}
			case Chrono::Month::mar:
			{
				if((d+n) > days_of_month) {
                        	        int delta_days = days_of_month - d;
                                        n -= delta_days;
                                        m = Chrono::Month::apr;
                                        d = n;
                                } else {
                                        d += n;
                                }
			}
			case Chrono::Month::apr:
			{
				days_of_month = 30;
				if((d+n) > days_of_month) {
                                        int delta_days = days_of_month - d;
                                        n -= delta_days;
                                        m = Chrono::Month::may;
                                        d = n;
                                } else {
                                        d += n;
                                }
			}
			case Chrono::Month::may:
			{
				if((d+n) > days_of_month) {
                                        int delta_days = days_of_month - d;
                                        n -= delta_days;
                                        m = Chrono::Month::jun;
                                        d = n;
                                } else {
                                        d += n;
                                }
			}
			case Chrono::Month::jun:
			{
				days_of_month = 30;
                                if((d+n) > days_of_month) {
                                        int delta_days = days_of_month - d;
                                        n -= delta_days;
                                        m = Chrono::Month::jul;
                                        d = n;
                                } else {
                                        d += n;
                                }
			}
			case Chrono::Month::jul:
			{
				if((d+n) > days_of_month) {
                                        int delta_days = days_of_month - d;
                                        n -= delta_days;
                                        m = Chrono::Month::aug;
                                        d = n;
                                } else {
                                        d += n;
                                }
			}
			case Chrono::Month::aug:
			{
				if((d+n) > days_of_month) {
                                        int delta_days = days_of_month - d;
                                        n -= delta_days;
                                        m = Chrono::Month::sep;
                                        d = n;
                                } else {
                                        d += n;
                                }
			}
			case Chrono::Month::sep:
			{
				days_of_month = 30;
                                if((d+n) > days_of_month) {
                                        int delta_days = days_of_month - d;
                                        n -= delta_days;
                                        m = Chrono::Month::oct;
                                        d = n;
                                } else {
                                        d += n;
                                }
			}
			case Chrono::Month::oct:
			{
				if((d+n) > days_of_month) {
                                        int delta_days = days_of_month - d;
                                        n -= delta_days;
                                        m = Chrono::Month::nov;
                                        d = n;
                                } else {
                                        d += n;
                                }
			}
			case Chrono::Month::nov:
			{
				days_of_month = 30;
                                if((d+n) > days_of_month) {
                                        int delta_days = days_of_month - d;
                                        n -= delta_days;
                                        m = Chrono::Month::dec;
                                        d = n;
                                } else {
                                        d += n;
                                }
			}
			case Chrono::Month::dec:
			{
				if((d+n) > days_of_month) {
                        	        int delta_days = days_of_month - d;
                                        n -= delta_days;
                                        m = Chrono::Month::jan;
					add_year(1);
                                        d = n;
                                } else {
                                        d += n;
                                }
			}
                }
	}

	void Date::add_month(int n)
	{
	}

	void Date::add_year(int n)
	{
		if(m==Chrono::Month::feb && d==29 && !is_leapyear(y+n)){
			m = Chrono::Month::mar;
			d = 1;
		}
		y += n;
	}

	//helper functions
	
	bool is_date(int y, Month m, int d)
	{
		if(d<=0) return false;
		if(m<Month::jan || Month::dec<m) return false;

		int days_in_month = 31;
		switch(m) {
			case Month::feb:
				days_in_month = (is_leapyear(y)) ? 29 : 28;
				break;
			case Month::apr: case Month::jun: case Month::sep:
			case Month::nov:
				days_in_month = 30;
				break;
		}
		if(days_in_month<d) return false;

		return true;
	}

	bool is_leapyear(int y)
	{
		bool leap;

		if(y % 400 == 0 || y % 4 == 0)
			leap = true;
		else if (y % 100 == 0)
			leap = false;
		else leap = false;
		return leap;
	}

	bool operator==(const Date& a, const Date& b)
	{
		return a.year()==b.year()
			&& a.month()==b.month()
			&& a.day()==b.day();
	}

	bool operator!=(const Date& a, const Date& b)
	{
		return !(a==b);
	}

	bool operator>(const Date& a, const Date& b)
	{
		return a.day() > b.day() ||
			a.month() > b.month() ||
			a.year() > b.year();
	}

	ostream& operator<<(ostream& os, const Date& d)
	{
		return os << "("<<d.year()
			//<< ","<<d.month()
			<< ","<<d.day()<<")";
	}

	istream& operator>>(istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is>>ch1>>y>>ch2>>m>>ch3>>d>>ch4;
		if(!is) return is;
		if(ch1!='('||ch2!=','||ch3!=','||ch4!=')'){
			is.clear(ios_base::failbit);
			return is;
		}

		dd = Date(y, Month(m), d);
		return is;
	}
	
	enum class Day {
		sunday, monday, tuesday, wednesday, thursday, friday, saturday
	};

	/*
	Day day_of_week(const Date& d)
	{
	}

	Date next_sunday(const Date& d)
	{
	}

	Date next_weekday(const Date& d)
	{
	}
	*/
}
