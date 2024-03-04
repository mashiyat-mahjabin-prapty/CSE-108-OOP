#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

class Date {
    int year;
    int month;
    int day;
    public: 
	Date(int day, int month, int year) {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    int getYear() {
        return year;
    }

    void setYear(int year) {
        this->year = year;
    }

    int getMonth() {
        return month;
    }

    void setMonth(int month) {
        this->month = month;
    }

    int getDay() {
        return day;
    }

    void setDay(int day) {
        this->day = day;
    }

    void printDate(){
        cout << day << '-' << month << '-' << year;
    }

    int CompareDays(Date d){
        if(day == d.day && month == d.month && year == d.year){
            int i = 0;
            return i;
        }
        else if(year == d.year){
            if(month == d.month){
                if(day > d.day){
                    int i = 1;
                    return i;
                }
                else{
                    int i = -1;
                    return i;
                }
            }
            else if(month > d.month){
                int i = 1;
                return i;
            }
            else{
                int i = -1;
                return i;
            }
        }
        else if(year > d.year){
            int i = 1;
            return i;
        }
        else{
            int i = -1;
            return i;
        }
    }
    int numOfDays(Date d){
        int i = abs(year - d.year);
        int j = abs(month - d.month);
        int k = abs(day - d.day);
        i = (i * 30 * 12) + (j * 30) + k;

        return i;
    }
};
    
class Event {
    	char name[100];
    	Date start;
    	Date end;
public:
	Event(char nm[], Date d1, Date d2) {
        strcpy(name, nm);
        start.setDay(d1.getDay());
        start.setMonth(d1.getMonth());
        start.setYear(d1.getYear());
        end.setDay(d2.getDay());
        end.setMonth(d2.getMonth());
        end.setYear(d2.getYear());
    }
	char getName() {
        return name;
    }

    void setName(char nm[]) {
        strcpy(name,nm);
    }

    Date getStart() {
        return start;
    }

    void setStart(Date strt) {
    	start.setDay(strt.getDay());
    	start.setMonth(strt.getMonth());
    	start.setYear(strt.getYear());
    }

    Date getEnd() {
        return end;
    }

    void setEnd(Date strt) {
        end.setDay(strt.getDay());
    	end.setMonth(strt.getMonth());
    	end.setYear(strt.getYear());
    }

    int durationInDays(){
        return start.numOfDays(end);
    }

    bool doesConflict(Event e) {
        bool result;
        int i = start.CompareDays(e.end);
        int j = end.CompareDays(e.start);

        if (j == 1 || i == -1) {
            result = false;
        } else {
            result = true;
        }
        return result;
    }
};

int main(){
    Date d1(26, 3, 2020);
    Date d2(13, 2, 2019);
    Date d3(10, 1, 2018);
    Date d4(26, 11, 2019);

    if(d2.CompareDays(d4) == 0){
        cout << "The dates are same" << endl;
    }
    else if (d2.CompareDays(d4) == 1) {
        cout << "The first date comes after the second date" << endl;
    }
    else if(d2.CompareDays(d4) == -1) {
        cout << "The first date comes before the second date" << endl;
    }
    if(d3.CompareDays(d2) == 0){
        cout << "The dates are same" <<  endl;
    }
    else if (d3.CompareDays(d2) == 1) {
        cout << "The first date comes after the second date" << endl;
    }
    else if(d3.CompareDays(d2) == -1){
        cout << "The first date comes before the second date" << endl;
    }
    int p = d4.numOfDays(d2);
    cout << "The number of days between the two dates is: " << p << endl;

    Event e1("Wedding1", new Date(11,7,2019), new Date(17,7,2019));
    Event e2("Wedding2", new Date(15,7,2019), new Date(23,7,2019));
    Event e3("Wedding3", new Date(26,12,2019), new Date(29,12,2019));

    int dur = e3.durationInDays();
    cout << e3.getName() << "consisted of" << dur << "days" << endl;
    bool q = e1.doesConflict(e2);
    if(q){
        cout << e1.getName() << " and " << e2.getName() << " collide" << endl;
    }
    else{
        cout << e1.getName() << " and " << e2.getName() << " do not collide" << endl;
    }
}


