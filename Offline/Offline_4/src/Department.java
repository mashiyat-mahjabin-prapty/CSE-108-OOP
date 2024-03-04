public class Department {

    private int id;
    private String name;
    private Employee [] employees;
    private int employeeCount;
    private static int departmentCount;
    private static Department [] departments = new Department[20];

    // add your code here
    // there can be at most 20 departments

    // you are not allowed to write any other constructor
    public Department(int id, String name) {
        this.id = id;
        this.name = name;
        this.employees = new Employee[10];
        departments[departmentCount] = this;
        departmentCount++;
            // add your code here
    }

    public static double getTotalSalary() {
        double totalSalary = 0.0;
        for (Department d : departments)
        {
            if (d != null)
            {
                for (Employee e : d.employees)
                {
                    if (e != null)
                    {
                        totalSalary += e.getSalary();
                    }
                }
            }

        }
        return totalSalary;
    }

    public void addEmployee(Employee employee) {
            this.employees[employeeCount++] = employee;
    }

    public double getDepartmentSalary() {
        double totsalary = 0.0;
        for (Employee temp : employees)
        {
            if(temp != null)
            {
                totsalary += temp.getSalary();
            }
        }
        return totsalary;
    }

    public Employee getMaxSalaryEmployee() {
        Employee emp = new Employee(0,null,0.0);
        double maxsalary = -1.0;
        for (Employee temp : employees)
        {
            if (temp != null)
            {
                if (temp.getSalary() > maxsalary)
                {
                    maxsalary = temp.getSalary();
                    emp = temp;
                }
            }
        }
        return emp;
    }
    // add your code here
}
