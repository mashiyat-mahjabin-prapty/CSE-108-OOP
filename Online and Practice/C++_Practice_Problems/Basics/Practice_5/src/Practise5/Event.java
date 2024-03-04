package Practise5;

import Practice5.Date;
import org.jetbrains.annotations.NotNull;

public class Event {
    private String name;
    private Practice5.Date start = new Date();
    private Practice5.Date end = new Date();

    public Event(){
        this.name = "\0";
        this.start.setDay(0);
        this.start.setMonth(0);
        this.start.setYear(0);
        this.end.setDay(0);
        this.end.setMonth(0);
        this.end.setYear(0);
    }

    public Event(String name, @NotNull Date d1, @NotNull Date d2) {
        this.name = name;
        this.start.setDay(d1.getDay());
        this.start.setMonth(d1.getMonth());
        this.start.setYear(d1.getYear());
        this.end.setDay(d2.getDay());
        this.end.setMonth(d2.getMonth());
        this.end.setYear(d2.getYear());
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Date getStart() {
        return start;
    }

    public void setStart(Date start) {
        this.start = start;
    }

    public Date getEnd() {
        return end;
    }

    public void setEnd(Date end) {
        this.end = end;
    }

    public int durationInDays(){
        return this.start.numOfDays(this.end);
    }

    public boolean doesConflict(Event e) {
        boolean result;
        int i = this.start.CompareDays(e.end);
        int j = this.end.CompareDays(e.start);

        if (j == -1 || i == 1) {
            result = false;
        } else {
            result = true;
        }
        return result;
    }
}
