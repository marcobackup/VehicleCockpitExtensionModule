#include "controller.h"

Controller::Controller(Gauge *gauge, CarParameter *carParameter, Trip *trip, TopBar *topBar, BottomBar *bottomBar, Settings *settings)
    : gauge(gauge)
    , carParameter(carParameter)
    , trip(trip)
    , topBar(topBar)
    , bottomBar(bottomBar)
    , settings(settings)
{}
