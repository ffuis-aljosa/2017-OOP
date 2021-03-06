#include <iostream>
#include <stdexcept>

#include "location.h"
#include "trip.h"

using namespace std;

int main()
{
    try
    {
        Location rio("Rio De Jeneiro", -22.9138851, -43.7261746);

        cout << rio.getName() << " @" << rio.getLatitude() << "," << rio.getLongitude() << endl;

        Location tokyo("Tokyo", 35.6732619, 139.5703043);

        Trip t(rio, tokyo);

        cout << "Idemo na putovanje:" << endl << t << endl << "Bice super zanimljivo";
    }
    catch(runtime_error error)
    {
        cout << error.what() << endl;
    }

    return 0;
}
