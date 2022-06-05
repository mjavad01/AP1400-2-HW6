#ifndef Q4_H
#define Q4_H

#include <numeric>
#include <vector>


namespace q4 
{
    struct Vector2D 
    {
        double x;
        double y;
    };


    struct Sensor
    {
        Vector2D position;
        double accuracy;
    };

    struct x_acc 
    {
        double operator()(double average, Sensor& S)
        {
            return average + S.position.x * S.accuracy;
        }
    };
    struct y_acc 
    {
        double operator()(double average, Sensor& S)
        {
            return average + S.position.y * S.accuracy;
        }
    };

    Vector2D kalman_filter(std::vector<Sensor> sensors)
    {
        double acc {};
        acc = std::accumulate(sensors.begin(), sensors.end(), acc, [](double sum_result, Sensor s) { return sum_result + s.accuracy; });
        double x_avg = std::accumulate(sensors.begin(), sensors.end(), 0.0, x_acc());
        double y_avg = std::accumulate(sensors.begin(), sensors.end(), 0.0, y_acc());
        Vector2D avg {x_avg / acc, y_avg / acc};
        return avg;
    }

}


#endif //Q4_H