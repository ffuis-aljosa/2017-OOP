#ifndef LOCATION_H_INCLUDED
#define LOCATION_H_INCLUDED

#include <stdexcept>
#include <cmath>

using namespace std;

class Location
{
private:
    string name;
    double latitude;
    double longitude;

    double degToRad(double deg)
    {
        return deg * 3.14 / 180;
    }

public:
    Location(string _name, double _latitude, double _longitude)
    {
        setName(_name);
        setLatitude(_latitude);
        setLongitude(_longitude);
    }

    string getName() { return name; }
    double getLatitude() { return latitude; }
    double getLongitude() { return longitude; }

    void setName(string _name)
    {
        if (_name == "")
            throw runtime_error("Naziv lokacije ne moze biti prazan");

        name = _name;
    }
    void setLatitude(double _latitude)
    {
        if (_latitude < -90 || 90 < _latitude)
            throw runtime_error("Geografska sirina mora biti izmedju -90 i 90");

        latitude = _latitude;
    }
    void setLongitude(double _longitude)
    {
        if (_longitude < -180 || 180 < _longitude)
            throw runtime_error("Geografska duzina mora biti izmedju -180 i 180");

        longitude = _longitude;
    }

    double distanceFrom(Location l)
    {
        double lat1 = degToRad(latitude),
               lon1 = degToRad(longitude),
               lat2 = degToRad(l.latitude),
               lon2 = degToRad(l.longitude);

        int R = 6372;

        return acos(sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(lon2 - lon1)) * R;
    }
};

#endif // LOCATION_H_INCLUDED
