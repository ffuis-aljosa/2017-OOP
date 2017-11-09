#ifndef TRIP_H_INCLUDED
#define TRIP_H_INCLUDED

#include "location.h"

class Trip
{
private:
    Location from;
    Location to;

public:
    Trip(Location _from, Location _to)
    : from(_from), to(_to)
    {}

    double distance()
    {
        return from.distanceFrom(to);
    }
};

#endif // TRIP_H_INCLUDED
