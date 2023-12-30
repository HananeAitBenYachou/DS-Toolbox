#pragma once
#pragma warning (disable : 4996)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class clsDate
{
public : 

	string ConvertNumberToString(long long Number)
	{
		if (Number <= 0)
			return "";

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
						   "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return arr[Number] + " ";
		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","", "Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninety" };

			return arr[Number / 10] + " " + ConvertNumberToString(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return "One Hundred " + ConvertNumberToString(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return ConvertNumberToString(Number / 100) + "Hundreds " + ConvertNumberToString(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + ConvertNumberToString(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return ConvertNumberToString(Number / 1000) + "Thousands " + ConvertNumberToString(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Million " + ConvertNumberToString(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return ConvertNumberToString(Number / 1000000) + "Millions " + ConvertNumberToString(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One Billion " + ConvertNumberToString(Number % 1000000000);
		}

		if (Number >= 2000000000 && Number <= 999999999999)
		{
			return ConvertNumberToString(Number / 1000000000) + "Billions " + ConvertNumberToString(Number % 1000000000);
		}

		if (Number >= 1000000000000 && Number <= 1999999999999)
		{
			return "One Trillion " + ConvertNumberToString(Number % 1000000000000);
		}

		if (Number >= 2000000000000 && Number <= 999999999999999)
		{
			return ConvertNumberToString(Number / 1000000000000) + "Trillions " + ConvertNumberToString(Number % 1000000000000);
		}

	}

	bool IsLeapYear(short Year)
	{
		//return (Year % 400 == 0) ? true : (Year % 100 != 0 && Year % 4 == 0 ? true : false); 

		return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);
	}

	short NumberOfDaysInYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}

	short NumberOfHoursInYear(short Year)
	{
		return NumberOfDaysInYear(Year) * 24;
	}

	int NumberOfMinutesInYear(short Year)
	{
		return NumberOfHoursInYear(Year) * 60;
	}

	int NumberOfSecondsInYear(short Year)
	{
		return NumberOfMinutesInYear(Year) * 60;
	}

	short NumberOfDaysInMonth(short Month, short Year)
	{
		if (Month < 1 || Month > 12)
			return 0;

		short MonthDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : MonthDays[Month - 1];
	}

	short NumberOfHoursInMonth(short Month, short Year)
	{
		return NumberOfDaysInMonth(Month, Year) * 24;
	}

	int NumberOfMinutesInMonth(short Month, short Year)
	{
		return NumberOfHoursInMonth(Month, Year) * 60;
	}

	int NumberOfSecondsInMonth(short Month, short Year)
	{
		return NumberOfMinutesInMonth(Month, Year) * 60;
	}

	struct stDate
	{
		short Year;
		short Month;
		short Day;
	};

	short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a, y, m, d;

		a = (14 - Month) / 12;

		y = Year - a;

		m = Month + (12 * a) - 2;

		d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;
	}

	short DayOfWeekOrder(stDate Date)
	{
		return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	}

	string DayShortName(short DayOfWeekOrder)
	{
		string WeekDay[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return WeekDay[DayOfWeekOrder];
	}

	string MonthShortName(short Month)
	{
		string Months[] = { "", "Jan","Feb","Mar","Apr","Mai","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

		return Months[Month];
	}

	void PrintMonthCalendar(short Month, short Year)
	{
		cout << "\n  ______________ " << MonthShortName(Month) << " ______________\n\n";

		cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

		short i = 0;

		short FirstDayOfMonth = DayOfWeekOrder(1, Month, Year);

		for (i = 0; i < FirstDayOfMonth; i++)
		{
			printf("%5s", " ");
		}

		short NumberOfDays = NumberOfDaysInMonth(Month, Year);

		for (short j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		cout << "\n  _________________________________\n\n";

	}

	void PrintScreenHeader(short Year)
	{
		cout << "\n  _________________________________\n\n";
		cout << "           Calendar - " << Year;
		cout << "\n  _________________________________\n";
	}

	void PrintYearCalendar(short Year)
	{
		PrintScreenHeader(Year);

		short i = 1;

		while (i <= 12)
		{
			PrintMonthCalendar(i, Year);
			i++;
		}

	}

	short NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;

		for (short i = 1; i < Month; i++)
		{
			TotalDays += NumberOfDaysInMonth(i, Year);

		}

		TotalDays += Day;

		return TotalDays;
	}

	stDate GetDateOrderInYear(short DateOrderInYear, short Year)
	{
		stDate Date;
		Date.Day = 0;
		Date.Month = 1;
		Date.Year = Year;

		short RemainingDays = DateOrderInYear;
		short DaysInMonth = 0;

		while (true)
		{

			DaysInMonth = NumberOfDaysInMonth(Date.Month, Year);

			if (RemainingDays > DaysInMonth)
			{
				RemainingDays -= DaysInMonth;

				Date.Month++;
			}

			else
			{
				Date.Day = RemainingDays;
				break;
			}

		}


		return Date;
	}

	stDate DateAddDays(stDate Date, short NumberOfDays)
	{
		//both ways are correct ! 
		//short RemainingDays = NumberOfDays + Date.Day; 
		short RemainingDays = NumberOfDays + NumberOfDaysFromTheBeginningOfTheYear(Date.Day, Date.Month, Date.Year);
		short MonthDays = 0;
		Date.Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;

				if (++Date.Month > 12)
				{
					Date.Year++;
					Date.Month = 1;
				}
			}

			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}

		return Date;
	}

	bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : ((Date1.Month == Date2.Month) ? Date1.Day < Date2.Day : false)) : false);
	}

	bool IsDate1EqualDate2(stDate Date1, stDate Date2)
	{
		//return (Date1.Year == Date2.Year ) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);

		return (Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month ? (Date1.Day == Date2.Day ? true : false) : false) : false;
	}

	bool IsLastMonthInYear(short Month)
	{
		return Month == 12;
	}

	bool IsLastDayInMonth(stDate Date)
	{

		return Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year);
	}

	stDate IncreaseDateByOneDay(stDate Date)
	{

		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{
				Date.Month = 1;
				Date.Day = 1;
				Date.Year++;
			}

			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}

		else
			Date.Day++;


		//IsLastDayInMonth(Date) ? (IsLastMonthInYear(Date.Month) ? (Date.Month = 1, Date.Day = 1, Date.Year++) : (Date.Day = 1, Date.Month++)) : Date.Day++;

		return Date;
	}

	void SwapDates(stDate& Date1, stDate& Date2)
	{
		stDate temp = Date1;
		Date1 = Date2;
		Date2 = temp;
	}

	int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
	{
		int TotalDays = 0;
		short SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			TotalDays++;
			Date1 = IncreaseDateByOneDay(Date1);
		}


		return IncludeEndDay ? ++TotalDays * SwapFlagValue : TotalDays * SwapFlagValue;

	}

	int CalculateAgeInDays(stDate BirthDate, stDate CurrentDate, bool IncludeEndDay = false)
	{
		int TotalDays = GetDifferenceInDays(BirthDate, CurrentDate, IncludeEndDay);

		return TotalDays;
	}

	stDate GetSystemDate()
	{
		stDate Date;

		time_t t = time(0);
		tm* now = localtime(&t);

		Date.Day = now->tm_mday;
		Date.Month = now->tm_mon + 1;
		Date.Year = now->tm_year + 1900;

		return Date;
	}

	stDate IncreaseDateByXDays(stDate Date, short NumberOfDays)
	{
		for (short i = 1; i <= NumberOfDays; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}

	stDate IncreaseDateByOneWeek(stDate Date)
	{
		Date = IncreaseDateByXDays(Date, 7);
		return Date;
	}

	stDate IncreaseDateByXWeeks(stDate Date, short NumberOfWeeks)
	{
		for (short i = 1; i <= NumberOfWeeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}

	stDate IncreaseDateByOneMonth(stDate Date)
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Month = 1;
			Date.Year++;
		}

		else
			Date.Month++;

		short CurrentMonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);

		if (Date.Day > CurrentMonthDays)
		{
			Date.Day = CurrentMonthDays;
		}

		return Date;
	}

	stDate IncreaseDateByXMonths(stDate Date, short NumberOfMonths)
	{
		for (short i = 1; i <= NumberOfMonths; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}

	stDate IncreaseDateByOneYear(stDate Date)
	{
		Date.Year++;
		return Date;
	}

	stDate IncreaseDateByXYears(stDate Date, short NumberOfYears)
	{
		for (short i = 1; i <= NumberOfYears; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}

	stDate IncreaseDateByXYearsFaster(stDate Date, short NumberOfYears)
	{
		Date.Year += NumberOfYears;
		return Date;
	}

	stDate IncreaseDateByOneDecade(stDate Date)
	{
		Date.Year += 10;
		return Date;
	}

	stDate IncreaseDateByXDecades(stDate Date, short NumberOfDecades)
	{

		for (short i = 1; i <= (NumberOfDecades * 10); i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}

	stDate IncreaseDateByXDecadesFaster(stDate Date, short NumberOfDecades)
	{
		Date.Year += (NumberOfDecades * 10);
		return Date;
	}

	stDate IncreaseDateByOneCentury(stDate Date)
	{
		Date.Year += 100;
		return Date;
	}

	stDate IncreaseDateByOneMillennium(stDate Date)
	{
		Date.Year += 1000;
		return Date;
	}

	/***************************************/

	stDate DecreaseDateByOneDay(stDate Date)
	{

		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Year--;
				Date.Month = 12;
			}
			else
			{
				Date.Month--;
			}

			Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
		}

		else
			Date.Day--;

		return Date;
	}

	stDate DecreaseDateByXDays(stDate Date, short NumberOfDays)
	{
		for (short i = 1; i <= NumberOfDays; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	stDate DecreaseDateByOneWeek(stDate Date)
	{
		Date = DecreaseDateByXDays(Date, 7);
		return Date;
	}

	stDate DecreaseDateByXWeeks(stDate Date, short NumberOfWeeks)
	{
		for (short i = 1; i <= NumberOfWeeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}

	stDate DecreaseDateByOneMonth(stDate Date)
	{

		if (Date.Month == 1)
		{
			Date.Year--;
			Date.Month = 12;
		}

		else
			Date.Month--;

		short CurrentMonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);
		if (Date.Day > CurrentMonthDays)
		{
			Date.Day = CurrentMonthDays;
		}

		return Date;
	}

	stDate DecreaseDateByXMonths(stDate Date, short NumberOfMonths)
	{
		for (short i = 1; i <= NumberOfMonths; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	stDate DecreaseDateByOneYear(stDate Date)
	{
		Date.Year--;
		return Date;
	}

	stDate DecreaseDateByXYears(stDate Date, short NumberOfYears)
	{
		for (short i = 1; i <= NumberOfYears; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}

	stDate DecreaseDateByXYearsFaster(stDate Date, short NumberOfYears)
	{
		Date.Year -= NumberOfYears;
		return Date;
	}

	stDate DecreaseDateByOneDecade(stDate Date)
	{
		Date.Year -= 10;
		return Date;
	}

	stDate DecreaseDateByXDecades(stDate Date, short NumberOfDecades)
	{
		for (short i = 1; i <= (NumberOfDecades * 10); i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}

	stDate DecreaseDateByXDecadesFaster(stDate Date, short NumberOfDecades)
	{
		Date.Year -= (NumberOfDecades * 10);
		return Date;
	}

	stDate DecreaseDateByOneCentury(stDate Date)
	{
		Date.Year -= 100;
		return Date;
	}

	stDate DecreaseDateByOneMillennium(stDate Date)
	{
		Date.Year -= 1000;
		return Date;
	}

	bool IsEndOfWeek(stDate Date)
	{
		return DayOfWeekOrder(Date) == 6;
	}

	bool IsWeekEnd(stDate Date)
	{
		short DayOrderInWeek = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);

		return DayOrderInWeek == 5 || DayOrderInWeek == 6;
	}

	bool IsBusinessDay(stDate Date)
	{
		return !IsWeekEnd(Date);
	}

	short DaysUntilEndOfWeek(stDate Date)
	{
		return 6 - DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	}

	short DaysUntilEndOfMonth(stDate Date)
	{
		stDate Date2;

		Date2.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
		Date2.Month = Date.Month;
		Date2.Year = Date.Year;


		return GetDifferenceInDays(Date, Date2, true);
	}

	short DaysUntilEndOfYear(stDate Date)
	{
		stDate Date2;

		Date2.Day = 31;
		Date2.Month = 12;
		Date2.Year = Date.Year;

		return GetDifferenceInDays(Date, Date2, true);
	}

	short CalculateVacationDays(stDate DateFrom, stDate DateTo)
	{
		short VacationDays = 0;

		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				VacationDays++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}
		return VacationDays;
	}

	stDate CalculateVacationReturnDate(stDate DateFrom, short VacationDays)
	{

		while (VacationDays > 0)
		{
			if (IsWeekEnd(DateFrom))
			{
				VacationDays++;
			}

			DateFrom = IncreaseDateByOneDay(DateFrom);
			VacationDays--;
		}

		return DateFrom;
	}

	enum enDateComparison { eBefore = -1, eEqual = 0, eAfter = 1 };

	bool IsDate1AfterDate2(stDate Date1, stDate Date2)
	{
		//return (Date1.Year > Date2.Year) ? true : ((Date1.Year == Date2.Year) ? ((Date1.Month > Date2.Month) ? true : (Date1.Month == Date2.Month ? (Date1.Day > Date2.Day) : false)): false);

		//return !(IsDate1BeforeDate2(Date1, Date2) || IsDate1EqualDate2(Date1, Date2)); 

		return !(IsDate1BeforeDate2(Date1, Date2)) && !(IsDate1EqualDate2(Date1, Date2));
	}

	enDateComparison CompareDates(stDate Date1, stDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateComparison::eBefore;

		else if (IsDate1AfterDate2(Date1, Date2))
			return enDateComparison::eAfter;

		return enDateComparison::eEqual;
	}

	struct stPeriod
	{
		stDate StartDate;
		stDate EndDate;
	};

	bool IsOverLapedPeriods(stPeriod Period1, stPeriod Period2)
	{
		return
			!(IsDate1BeforeDate2(Period2.EndDate, Period1.StartDate) || IsDate1AfterDate2(Period2.StartDate, Period1.EndDate));
	}

	short CalculatePeriodLength(stPeriod Period, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
	}

	bool IsDateWithinPeriod(stPeriod Period, stDate Date)
	{

		return !(IsDate1BeforeDate2(Date, Period.StartDate) || IsDate1AfterDate2(Date, Period.EndDate));
	}

	bool IsValidDate(stDate Date)
	{
		if (Date.Month < 1 || Date.Month> 12)
			return false;

		else if (Date.Day < 1 || Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year))
			return false;

		return true;
	}

	void SwapPeriods(stPeriod& Period1, stPeriod& Period2)
	{
		stPeriod Temp;
		Temp = Period1;
		Period1 = Period2;
		Period2 = Temp;
	}

	short CountOverlapDays(stPeriod Period1, stPeriod Period2)
	{
		short Days = 0;
		short Period1Length = CalculatePeriodLength(Period1, true);
		short Period2Length = CalculatePeriodLength(Period2, true);

		if (!IsOverLapedPeriods(Period1, Period2))
			return 0;

		if (Period2Length < Period1Length)
			SwapPeriods(Period1, Period2);

		while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
		{
			if (IsDateWithinPeriod(Period2, Period1.StartDate))
				Days++;

			Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
		}

		return Days;
	}

	vector<string> SplitString(string S1, string Delim)
	{
		vector<string> vString;
		short pos = 0;
		string sWord; // define a string variable 
		// use find() function to get the position of the delimiters 
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word 

			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			S1.erase(0, pos + Delim.length());
		}

		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}

		return vString;
	}

	stDate StringToDate(string Datestring)
	{
		vector<string> vDate = SplitString(Datestring, "/");
		stDate Date;

		Date.Day = stoi(vDate[0]);
		Date.Month = stoi(vDate[1]);
		Date.Year = stoi(vDate[2]);

		return Date;
	}

	string DateToString(stDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

};

