#include <iostream>

using namespace std;

class owner
{
    private:
        string firstname;
        string lastname;
        int age;
        int yearly_income;
        int owns_since;
    public:
        owner(string firstname, string lastname, int age, int yearly_income, int owns_since)
        {
            this->firstname=firstname;
            this->lastname=lastname;
            this->age=age;
            this->yearly_income=yearly_income;
            this->owns_since=owns_since;
        }
        owner();
        bool real_pearson(int current_year)
        {
            return (current_year-owns_since-age>=0);
        }
};
class technical_data
{
    private:
        int year_of_production;
        int engine_BHP;
        int serial_number;
    public:
        technical_data(int year_of_production, int engine_BHP, int serial_number)
        {
            this->year_of_production=year_of_production;
            this->engine_BHP=engine_BHP;
            this->serial_number=serial_number;
        }
        technical_data();
        bool technical_check()
        {
            int serial_number_front=serial_number;
            while(serial_number_front>=100)serial_number_front/=10;
            return (year_of_production%100==serial_number_front);
        }
};
class race_parameters
{
    private:
        double safety_bubble;
        double min_acc;
        double max_acc;
        double turn_ratio;
        double field_of_viev_ratio;
    public:
        race_parameters(double safety_bubble, double min_acc, double max_acc, double turn_ratio)
        {
            this->safety_bubble=safety_bubble;
            this->min_acc=min_acc;
            this->max_acc=max_acc;
            while(turn_ratio>1)turn_ratio/=10;//must be in range (0,1)
            this->turn_ratio=turn_ratio;
            this->field_of_viev_ratio=(1-turn_ratio);
        }
        race_parameters();
        double min_velocity()
        {
            return min_acc*(turn_ratio/0.5);
        }
        double max_velocity()
        {
            return max_acc*(field_of_viev_ratio/0.5);
        }
};
class legal_information
{
    private:
        int next_inspection;
        bool approved;
        char vehicle_class;
        double tax_deduction;
        int last_registered_sell;
    public:
        legal_information(int next_inspection, int current_year, char vehicle_class, double tax_deduction, int last_registered_sell)
        {
            this->next_inspection=next_inspection;
            this->approved=(current_year<=next_inspection);
            this->vehicle_class=vehicle_class;
            this->tax_deduction;
            this->last_registered_sell;
        }
        legal_information();
        int inspections_by_this_owner()
        {
            return(next_inspection-last_registered_sell)/5;
        }
};

class vehicle
{
    private:
        owner Owner;
        technical_data Technical_data;
        race_parameters Race_parameters;
        legal_information Legal_information;
    public:
        vehicle(owner Owner, technical_data Technical_data, race_parameters Race_parameters, legal_information Legal_information)
        {
            this->Owner=Owner;
            this->Technical_data=Technical_data;
            this->Race_parameters=Race_parameters;
            this->Legal_information=Legal_information;
        }
        /*bool all_sales_registered()
        {
            return (Owner.owns_since==legal_information.last_registered_sell);
        }
        bool correct_class_of_vehicle()
        {
            legal_information.last_registered_sell
        }*/
        void is_ok()
        {
            if(owner.real_pearson(2022) && technical_data.technical_check() && legal_informations.inspections_by_this_owner()<2)
            {
                cout<<"Everything OK"<<endl;
            }
            else cout<<"STH wrong"<<endl;
        }
};

int main()
{

}
