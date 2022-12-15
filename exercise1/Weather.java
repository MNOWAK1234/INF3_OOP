package exercise1;

public class Weather 
{
    private final Forecast forecast;
    private final float temperature;
    private final char scale;
    private final String description;

    public Weather(Forecast forecast, float temperature, char c, String description)
    {
        this.forecast=forecast;
        this.temperature=temperature;
        this.scale=c;
        this.description=description;
    }
    public Weather DifferentScale(char scale)
    {
        if(this.scale=='K' && scale=='C')
        {
            float scienceTemperature=this.temperature-273;
            return new Weather(this.forecast, scienceTemperature, scale, this.description);
        }
        else if(this.scale=='C' && scale=='K')
        {
            float casualTemperature=this.temperature+273;
            return new Weather(this.forecast, casualTemperature, scale, this.description);
        }
        else return new Weather(this.forecast, this.temperature, this.scale, this.description);
    }
    public Weather WeatherChange(float TemperatureDifference)
    {
        float newTemperature=this.temperature+TemperatureDifference;
        return new Weather(this.forecast, newTemperature, this.scale, this.description);
    }

    public String toString()
    {
        return Float.toString(this.temperature);
    }
}