package exercise1;

public class Main 
{
    public static void main(String[] args)
    {
        Forecast forecast=new Forecast.Fake();
        Weather today=new Weather(forecast, 28, 'C', "sunny");
        Weather tonight=today.WeatherChange(10);
        Weather US=today.DifferentScale('K');
        Weather EU=US.DifferentScale('C');
        assert "1.2345".equals(tonight.toString());
        System.out.print("Would it ever work????");
    }
}