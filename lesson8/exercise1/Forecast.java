package exercise1;

public interface Forecast 
{
    float rate(String origin, String target);
    final class Fake implements Forecast
    {
        public float rate(String origin, String target)
        {
            return 1.2345f;
        }
    }
}