long double getAngle(const pair<long long, long long>& p1, const pair<long long, long long>& p2, const pair<long long, long long>& p3)
{
    return abs(atan2((long double)p3.second - p1.second, (long double)p3.first - p1.first) -
           atan2((long double)p2.second - p1.second, (long double)p2.first - p1.first));
}

long double getDistance(const pair<long long, long long>& p1, const pair<long long, long long>& p2)
{
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

long double getArea(const pair<long long, long long>& p1, const pair<long long, long long>& p2, const pair<long long, long long>& p3)
{
    return 1.0/2.0 * sin(getAngle(p1, p2, p3)) * getDistance(p1, p2) * getDistance(p1, p3);
}
