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

    Location getFrom() { return from; }
    Location getTo() { return to; }

    double distance()
    {
        return from.distanceFrom(to);
    }
};

ostream& operator << (ostream& ostr, Trip trip)
{
    Location from = trip.getFrom();
    Location to = trip.getTo();

    ostr << from.getName() << " (" << from.getLatitude() << ", "
         << from.getLongitude() << ") - " << to.getName() << " ("
         << to.getLatitude() << ", " << to.getLongitude() << ") "
         << "[" << trip.distance() << "km]";

    return ostr;
}

#endif // TRIP_H_INCLUDED
