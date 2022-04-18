// Talkie library
// Copyright 2011 Peter Knight
// This code is released under GPLv2 license.
//
// Armin Joachimsmeyer 11/2018 converted to .c and .h files
//   and made them unique and named duplicate words with _1.
//
// The following phrases are derived from VM61002/3/4/5 ROMs
//
// A male voice with a US accent.
//
// These phrases have a very military bias
// with lots of very useful engineering words.
// They also have good expression.
//

#include <Arduino.h>

// ROM VM61005
// In this file the original order of ROMs is kept.
// The .c file contains the sorted vocabulary.
extern const uint8_t sp5_ATU[] PROGMEM;
extern const uint8_t sp5_FSS[] PROGMEM;
extern const uint8_t sp5_ILS[] PROGMEM;
extern const uint8_t sp5_IFR[] PROGMEM;
extern const uint8_t sp5_VFR[] PROGMEM;
extern const uint8_t sp5_VHE[] PROGMEM;
extern const uint8_t sp5_LANDING_GEAR[] PROGMEM;
extern const uint8_t sp5_LEVEL_OFF[] PROGMEM;
extern const uint8_t sp5_UNDERCARRIAGE[] PROGMEM;
extern const uint8_t sp5_SPOILERS[] PROGMEM;
extern const uint8_t sp5_AIR_BRAKES[] PROGMEM;
extern const uint8_t sp5_AERIAL[] PROGMEM;
extern const uint8_t sp5_ENGINE[] PROGMEM;
extern const uint8_t sp5_FLAME_OUT[] PROGMEM;
extern const uint8_t sp5_FLAK_LOAD[] PROGMEM;
extern const uint8_t sp5_INBOUND[] PROGMEM;
extern const uint8_t sp5_IGNITE[] PROGMEM;
extern const uint8_t sp5_NO_TURN[] PROGMEM;
extern const uint8_t sp5_FLAPS[] PROGMEM;
extern const uint8_t sp5_EVACUATION[] PROGMEM;
extern const uint8_t sp5_DOORS[] PROGMEM;
extern const uint8_t sp5_CABIN[] PROGMEM;
extern const uint8_t sp5_ARRIVAL[] PROGMEM;
extern const uint8_t sp5_ACKNOWLEDGE[] PROGMEM;
extern const uint8_t sp5_RAISE[] PROGMEM;
extern const uint8_t sp5_LIST[] PROGMEM;
extern const uint8_t sp5_APPROACH[] PROGMEM;
extern const uint8_t sp5_DEPARTURE[] PROGMEM;
extern const uint8_t sp5_DEPARTURE_1[] PROGMEM;
extern const uint8_t sp5_CLEARANCE_DELIVERY[] PROGMEM;
extern const uint8_t sp5_FUEL[] PROGMEM;
extern const uint8_t sp5_IDLE[] PROGMEM;
extern const uint8_t sp5_INCREASE[] PROGMEM;
extern const uint8_t sp5_UP[] PROGMEM;
extern const uint8_t sp5_TAXI[] PROGMEM;
extern const uint8_t sp5_AS[] PROGMEM;
extern const uint8_t sp5_CONVERGING[] PROGMEM;
extern const uint8_t sp5_ABOVE[] PROGMEM;
extern const uint8_t sp5_BRAKE[] PROGMEM;
extern const uint8_t sp5_CALM[] PROGMEM;
extern const uint8_t sp5_BREAKING[] PROGMEM;
extern const uint8_t sp5_CALL[] PROGMEM;
extern const uint8_t sp5_CROSSWIND[] PROGMEM;
extern const uint8_t sp5_CRYSTALS[] PROGMEM;
extern const uint8_t sp5_CYLINDER[] PROGMEM;
extern const uint8_t sp5_CYCLE[] PROGMEM;
extern const uint8_t sp5_DOWN[] PROGMEM;
extern const uint8_t sp5_GROUND[] PROGMEM;
extern const uint8_t sp5_FULL[] PROGMEM;
extern const uint8_t sp5_NEW[] PROGMEM;
extern const uint8_t sp5_LEG[] PROGMEM;
extern const uint8_t sp5_MAINTAIN[] PROGMEM;
extern const uint8_t sp5_LANDING[] PROGMEM;
extern const uint8_t sp5_LEAN[] PROGMEM;
extern const uint8_t sp5_SET[] PROGMEM;
extern const uint8_t sp5_SHORT[] PROGMEM;
extern const uint8_t sp5_WAKE[] PROGMEM;
extern const uint8_t sp5_ADIS[] PROGMEM;
extern const uint8_t sp5_NOTEM[] PROGMEM;
extern const uint8_t sp5_RVRS[] PROGMEM;
extern const uint8_t sp5_SQUALKING[] PROGMEM;
extern const uint8_t sp5_MAGNETOS[] PROGMEM;
extern const uint8_t sp5_STABILISER[] PROGMEM;
extern const uint8_t sp5_PAKM[] PROGMEM;
extern const uint8_t sp5_SELCAL[] PROGMEM;
extern const uint8_t sp5_VORTAC[] PROGMEM;
extern const uint8_t sp5_VOR[] PROGMEM;
extern const uint8_t sp5_BARKER[] PROGMEM;
extern const uint8_t sp5_HEADING[] PROGMEM;
extern const uint8_t sp5_ETA[] PROGMEM;
extern const uint8_t sp5_DOWNWIND[] PROGMEM;
extern const uint8_t sp5_CEILING[] PROGMEM;
extern const uint8_t sp5_MIDPOINT[] PROGMEM;
extern const uint8_t sp5_SIGNET[] PROGMEM;
extern const uint8_t sp5_ROLL_OUT[] PROGMEM;
extern const uint8_t sp5_CROCS[] PROGMEM;
extern const uint8_t sp5_AIRCRAFT[] PROGMEM;
extern const uint8_t sp5_ALTIMETER[] PROGMEM;
extern const uint8_t sp5_AUTOPILOT[] PROGMEM;
extern const uint8_t sp5_LOCALIZER[] PROGMEM;
extern const uint8_t sp5_COWL[] PROGMEM;
extern const uint8_t sp5_INFLIGHT[] PROGMEM;
extern const uint8_t sp5_OVERSPEED[] PROGMEM;
extern const uint8_t sp5_LAUNCH[] PROGMEM;
extern const uint8_t sp5_TOWER[] PROGMEM;
extern const uint8_t sp5_FLIGHTWATCH[] PROGMEM;
extern const uint8_t sp5_STALL[] PROGMEM;
extern const uint8_t sp5_TOUCHDOWN[] PROGMEM;
extern const uint8_t sp5_SQUALK[] PROGMEM;
extern const uint8_t sp5_ELEVATION[] PROGMEM;
extern const uint8_t sp5_CLIMB[] PROGMEM;
extern const uint8_t sp5_BANK[] PROGMEM;
extern const uint8_t sp5_ACCELERATED[] PROGMEM;
extern const uint8_t sp5_TRIM[] PROGMEM;
extern const uint8_t sp5_UNICOM[] PROGMEM;
extern const uint8_t sp5_SLOKE[] PROGMEM;
extern const uint8_t sp5_NINER[] PROGMEM;
extern const uint8_t sp5_GALLEY[] PROGMEM;
extern const uint8_t sp5_FREEDOM[] PROGMEM;
extern const uint8_t sp5_FLIGHT[] PROGMEM;
extern const uint8_t sp5_FLIGHT_1[] PROGMEM;
extern const uint8_t sp5_DEGREE[] PROGMEM;
extern const uint8_t sp5_AIRPORT[] PROGMEM;
extern const uint8_t sp5_AIRSPEED[] PROGMEM;
extern const uint8_t sp5_CLEARANCE[] PROGMEM;
extern const uint8_t sp5_ALTITUDE[] PROGMEM;
extern const uint8_t sp5_RADIAL[] PROGMEM;
extern const uint8_t sp5_REMARK[] PROGMEM;
extern const uint8_t sp5_REFUELLING[] PROGMEM;
extern const uint8_t sp5_OUTER[] PROGMEM;
extern const uint8_t sp5_MIDDLE[] PROGMEM;
extern const uint8_t sp5_INNER[] PROGMEM;
extern const uint8_t sp5_INSTRUMENTS[] PROGMEM;
extern const uint8_t sp5_APPROACHES[] PROGMEM;
extern const uint8_t sp5_GEAR[] PROGMEM;
extern const uint8_t sp5_BOOST[] PROGMEM;
extern const uint8_t sp5_TELEPHONE[] PROGMEM;

// ROM VM61004
extern const uint8_t sp4_ALPHA[] PROGMEM;
extern const uint8_t sp4_BRAVO[] PROGMEM;
extern const uint8_t sp4_CHARLIE[] PROGMEM;
extern const uint8_t sp4_DELTA[] PROGMEM;
extern const uint8_t sp4_ECHO[] PROGMEM;
extern const uint8_t sp4_FOXTROT[] PROGMEM;
extern const uint8_t sp4_GOLF[] PROGMEM;
extern const uint8_t sp4_HOTEL[] PROGMEM;
extern const uint8_t sp4_INDIA[] PROGMEM;
extern const uint8_t sp4_JULIET[] PROGMEM;
extern const uint8_t sp4_KILO[] PROGMEM;
extern const uint8_t sp4_LIMA[] PROGMEM;
extern const uint8_t sp4_MIKE[] PROGMEM;
extern const uint8_t sp4_NOVEMBER[] PROGMEM;
extern const uint8_t sp4_OSCAR[] PROGMEM;
extern const uint8_t sp4_PAPA[] PROGMEM;
extern const uint8_t sp4_QUEBEC[] PROGMEM;
extern const uint8_t sp4_ROMEO[] PROGMEM;
extern const uint8_t sp4_SIERRA[] PROGMEM;
extern const uint8_t sp4_TANGO[] PROGMEM;
extern const uint8_t sp4_UNIFORM[] PROGMEM;
extern const uint8_t sp4_VICTOR[] PROGMEM;
extern const uint8_t sp4_WHISKEY[] PROGMEM;
extern const uint8_t sp4_XRAY[] PROGMEM;
extern const uint8_t sp4_ZULU[] PROGMEM;
extern const uint8_t sp4_AFFIRMATIVE[] PROGMEM;
extern const uint8_t sp4_NEGATIVE[] PROGMEM;
extern const uint8_t sp4_MAYDAY[] PROGMEM;
extern const uint8_t sp4_WARNING[] PROGMEM;
extern const uint8_t sp4_ICING[] PROGMEM;
extern const uint8_t sp4_DANGER[] PROGMEM;
extern const uint8_t sp4_EMERGENCY[] PROGMEM;
extern const uint8_t sp4_ROGER[] PROGMEM;
extern const uint8_t sp4_HERTZ[] PROGMEM;
extern const uint8_t sp4_SECURITY[] PROGMEM;
extern const uint8_t sp4_TARGET[] PROGMEM;
extern const uint8_t sp4_TARGET_1[] PROGMEM;
extern const uint8_t sp4_VECTORS[] PROGMEM;
extern const uint8_t sp4_LIGHT[] PROGMEM;
extern const uint8_t sp4_FRONT[] PROGMEM;
extern const uint8_t sp4_WAY[] PROGMEM;
extern const uint8_t sp4_GLIDE[] PROGMEM;
extern const uint8_t sp4_OPEN[] PROGMEM;
extern const uint8_t sp4_OPEN_1[] PROGMEM;
extern const uint8_t sp4_LIGHTS[] PROGMEM;
extern const uint8_t sp4_ON[] PROGMEM;
extern const uint8_t sp4_GUNDISH[] PROGMEM;
extern const uint8_t sp4_R_NAV[] PROGMEM;
extern const uint8_t sp4_SELECT[] PROGMEM;
extern const uint8_t sp4_FILED[] PROGMEM;
extern const uint8_t sp4_MIG[] PROGMEM;
extern const uint8_t sp4_ALERT[] PROGMEM;
extern const uint8_t sp4_ZONE[] PROGMEM;
extern const uint8_t sp4_TERMINAL[] PROGMEM;
extern const uint8_t sp4_RADIOS[] PROGMEM;
extern const uint8_t sp4_SPEED[] PROGMEM;
extern const uint8_t sp4_KNOTS[] PROGMEM;
extern const uint8_t sp4_EXPECT[] PROGMEM;
extern const uint8_t sp4_ACTION[] PROGMEM;
extern const uint8_t sp4_RADIAL[] PROGMEM;
extern const uint8_t sp4_POWER[] PROGMEM;
extern const uint8_t sp4_GAS[] PROGMEM;
extern const uint8_t sp4_INFORMATION[] PROGMEM;
extern const uint8_t sp4_TRUE[] PROGMEM;
extern const uint8_t sp4_PRESSURE[] PROGMEM;
extern const uint8_t sp4_CHECK[] PROGMEM;
extern const uint8_t sp4_CHECK_1[] PROGMEM;
extern const uint8_t sp4_DECREASE[] PROGMEM;
extern const uint8_t sp4_ADVISE[] PROGMEM;
extern const uint8_t sp4_YOU[] PROGMEM;
extern const uint8_t sp4_HAVE[] PROGMEM;
extern const uint8_t sp4_ERROR2[] PROGMEM;
extern const uint8_t sp4_ALL[] PROGMEM;
extern const uint8_t sp4_LONG[] PROGMEM;
extern const uint8_t sp4_LONG_1[] PROGMEM;
extern const uint8_t sp4_NO[] PROGMEM;
extern const uint8_t sp4_IMMEDIATELY[] PROGMEM;
extern const uint8_t sp4_FINAL[] PROGMEM;
extern const uint8_t sp4_PLEASE[] PROGMEM;
extern const uint8_t sp4_START[] PROGMEM;
extern const uint8_t sp4_COURSE[] PROGMEM;
extern const uint8_t sp4_RADAR[] PROGMEM;
extern const uint8_t sp4_PLAN[] PROGMEM;
extern const uint8_t sp4_WINDOWS[] PROGMEM;
extern const uint8_t sp4_WATCH[] PROGMEM;
extern const uint8_t sp4_USE[] PROGMEM;
extern const uint8_t sp4_TURN[] PROGMEM;
extern const uint8_t sp4_TRAFFIC[] PROGMEM;
extern const uint8_t sp4_SLOW[] PROGMEM;
extern const uint8_t sp4_SLOW_1[] PROGMEM;
extern const uint8_t sp4_RELEASE[] PROGMEM;
extern const uint8_t sp4_KEY[] PROGMEM;
extern const uint8_t sp4_IGNITION[] PROGMEM;
extern const uint8_t sp4_DEGREE[] PROGMEM;
extern const uint8_t sp4_RAIN[] PROGMEM;
extern const uint8_t sp4_REPAIR[] PROGMEM;
extern const uint8_t sp4_CANCEL[] PROGMEM;
extern const uint8_t sp4_VERIFY[] PROGMEM;
extern const uint8_t sp4_READY[] PROGMEM;
extern const uint8_t sp4_USE2[] PROGMEM;
extern const uint8_t sp4_OUT[] PROGMEM;
extern const uint8_t sp4_OTHER[] PROGMEM;
extern const uint8_t sp4_OIL[] PROGMEM;
extern const uint8_t sp4_OFF[] PROGMEM;
extern const uint8_t sp4_NEAR[] PROGMEM;
extern const uint8_t sp4_GREAT[] PROGMEM;
extern const uint8_t sp4_MIXTURE[] PROGMEM;
extern const uint8_t sp4_MUCH[] PROGMEM;
extern const uint8_t sp4_GREAT2[] PROGMEM;
extern const uint8_t sp4_IS[] PROGMEM;
extern const uint8_t sp4_CAUTION[] PROGMEM;
extern const uint8_t sp4_BELOW[] PROGMEM;
extern const uint8_t sp4_CYLINDER[] PROGMEM;
extern const uint8_t sp4_CONTACT[] PROGMEM;
extern const uint8_t sp4_AND[] PROGMEM;
extern const uint8_t sp4_FUEL[] PROGMEM;
extern const uint8_t sp4_FOR[] PROGMEM;
extern const uint8_t sp4_SEQUENCE[] PROGMEM;
extern const uint8_t sp4_SIDE[] PROGMEM;
extern const uint8_t sp4_TO[] PROGMEM;
extern const uint8_t sp4_RICH[] PROGMEM;
extern const uint8_t sp4_PUMPS[] PROGMEM;
extern const uint8_t sp4_LEVEL[] PROGMEM;
extern const uint8_t sp4_LEVEL_1[] PROGMEM;
extern const uint8_t sp4_LOWER[] PROGMEM;
extern const uint8_t sp4_REAR[] PROGMEM;
extern const uint8_t sp4_HOLD[] PROGMEM;
extern const uint8_t sp4_LEFT[] PROGMEM;
extern const uint8_t sp4_RIGHT[] PROGMEM;
extern const uint8_t sp4_STRAY[] PROGMEM;
extern const uint8_t sp4_CLOSE[] PROGMEM;
extern const uint8_t sp4_EVACUATE[] PROGMEM;
extern const uint8_t sp4_FAILURE[] PROGMEM;
extern const uint8_t sp4_SERVICE[] PROGMEM;
extern const uint8_t sp4_ABORT[] PROGMEM;
extern const uint8_t sp4_IDEMTIFY[] PROGMEM;
extern const uint8_t sp4_TOO_LOW[] PROGMEM;
extern const uint8_t sp4_CENTRE[] PROGMEM;
extern const uint8_t sp4_AREA[] PROGMEM;
extern const uint8_t sp4_BASE[] PROGMEM;
extern const uint8_t sp4_CONTROL[] PROGMEM;
extern const uint8_t sp4_MEASURED[] PROGMEM;
extern const uint8_t sp4_D[] PROGMEM;
extern const uint8_t sp4_THE[] PROGMEM;
extern const uint8_t sp4_VACUUM[] PROGMEM;
extern const uint8_t sp4_ABEAN[] PROGMEM;

// ROM VM61003
extern const uint8_t sp3_ZERO[] PROGMEM;
extern const uint8_t sp3_ONE[] PROGMEM;
extern const uint8_t sp3_TWO[]  PROGMEM;
extern const uint8_t sp3_THREE[] PROGMEM;
extern const uint8_t sp3_FOUR[] PROGMEM;
extern const uint8_t sp3_FIVE[] PROGMEM;
extern const uint8_t sp3_SIX[] PROGMEM;
extern const uint8_t sp3_SEVEN[] PROGMEM;
extern const uint8_t sp3_EIGHT[] PROGMEM;
extern const uint8_t sp3_NINE[] PROGMEM;
extern const uint8_t sp3_TEN[] PROGMEM;
extern const uint8_t sp3_ELEVEN[] PROGMEM;
extern const uint8_t sp3_TWELVE[] PROGMEM;
extern const uint8_t sp3_THIRTEEN[] PROGMEM;
extern const uint8_t sp3_FOURTEEN[] PROGMEM;
extern const uint8_t sp3_FIFTEEN[] PROGMEM;
extern const uint8_t sp3_SIXTEEN[] PROGMEM;
extern const uint8_t sp3_SEVENTEEN[] PROGMEM;
extern const uint8_t sp3_EIGHTEEN[] PROGMEM;
extern const uint8_t sp3_NINETEEN[] PROGMEM;
extern const uint8_t sp3_TWENTY[] PROGMEM;
extern const uint8_t sp3_THIRTY[] PROGMEM;
extern const uint8_t sp3_FOURTY[] PROGMEM;
extern const uint8_t sp3_FIFTY[] PROGMEM;
extern const uint8_t sp3_SIXTY[] PROGMEM;
extern const uint8_t sp3_SEVENTY[] PROGMEM;
extern const uint8_t sp3_EIGHTY[] PROGMEM;
extern const uint8_t sp3_NINETY[] PROGMEM;
extern const uint8_t sp3_HUNDRED[] PROGMEM;
extern const uint8_t sp3_THOUSAND[] PROGMEM;
extern const uint8_t sp3_MILLION[] PROGMEM;
extern const uint8_t sp3_PATH[] PROGMEM;
extern const uint8_t sp3_NEGATIVE[] PROGMEM;
extern const uint8_t sp3_POINT[] PROGMEM;
extern const uint8_t sp3_AFFIRMATIVE[] PROGMEM;
extern const uint8_t sp3_TIMES[] PROGMEM;
extern const uint8_t sp3_DIVIDED[] PROGMEM;
extern const uint8_t sp3_BY[] PROGMEM;
extern const uint8_t sp3_HOURS[] PROGMEM;
extern const uint8_t sp3_PLUS[] PROGMEM;
extern const uint8_t sp3_MINUS[] PROGMEM;
extern const uint8_t sp3_EQUALS[] PROGMEM;
extern const uint8_t sp3_RED[] PROGMEM;
extern const uint8_t sp3_YELLOW[] PROGMEM;
extern const uint8_t sp3_GREEN[] PROGMEM;
extern const uint8_t sp3_WHITE[] PROGMEM;
extern const uint8_t sp3_THEE[] PROGMEM;
extern const uint8_t sp3_THE[] PROGMEM;
extern const uint8_t sp3_ANSWER[] PROGMEM;
extern const uint8_t sp3_IS[] PROGMEM;
extern const uint8_t sp3_START[] PROGMEM;
extern const uint8_t sp3_STOP[] PROGMEM;
extern const uint8_t sp3_READY[] PROGMEM;
extern const uint8_t sp3_TEMPERATURE[] PROGMEM;
extern const uint8_t sp3_TIME[] PROGMEM;
extern const uint8_t sp3_A_M[] PROGMEM;
extern const uint8_t sp3_P_M[] PROGMEM;
extern const uint8_t sp3_OCLOCK[] PROGMEM;
extern const uint8_t sp3_DEGREES[] PROGMEM;
extern const uint8_t sp3_CELCIUS[] PROGMEM;
extern const uint8_t sp3_FARENHEIT[] PROGMEM;
extern const uint8_t sp3_ERROR[] PROGMEM;
extern const uint8_t sp3_MILES[] PROGMEM;
extern const uint8_t sp3_PER[] PROGMEM;
extern const uint8_t sp3_HOUR[] PROGMEM;
extern const uint8_t sp3_MINUTES[] PROGMEM;
extern const uint8_t sp3_GUSTING_TO[] PROGMEM;
extern const uint8_t sp3_GUST[] PROGMEM;
extern const uint8_t sp3_EAST[] PROGMEM;
extern const uint8_t sp3_WEST[] PROGMEM;
extern const uint8_t sp3_SOUTH[] PROGMEM;
extern const uint8_t sp3_NORTH[] PROGMEM;
extern const uint8_t sp3_NORTHEAST[] PROGMEM;
extern const uint8_t sp3_NORTHWEST[] PROGMEM;
extern const uint8_t sp3_SOUTHEAST[] PROGMEM;
extern const uint8_t sp3_SOUTHWEST[] PROGMEM;
extern const uint8_t sp3_HAIL[] PROGMEM;
extern const uint8_t sp3_TORNADO[] PROGMEM;
extern const uint8_t sp3_WIND[] PROGMEM;
extern const uint8_t sp3_WEATHER[] PROGMEM;
extern const uint8_t sp3_SHOWERS[] PROGMEM;
extern const uint8_t sp3_SLEET[] PROGMEM;
extern const uint8_t sp3_SMOKE[] PROGMEM;
extern const uint8_t sp3_STORM[] PROGMEM;
extern const uint8_t sp3_SNOW[] PROGMEM;
extern const uint8_t sp3_SAND[] PROGMEM;
extern const uint8_t sp3_PELLETS[] PROGMEM;
extern const uint8_t sp3_RAIN[] PROGMEM;
extern const uint8_t sp3_ICE[] PROGMEM;
extern const uint8_t sp3_HEAT[] PROGMEM;
extern const uint8_t sp3_FOG[] PROGMEM;
extern const uint8_t sp3_HEAVY[] PROGMEM;
extern const uint8_t sp3_LAND[] PROGMEM;
extern const uint8_t sp3_THIN[] PROGMEM;
extern const uint8_t sp3_OF[] PROGMEM;
extern const uint8_t sp3_AERIAL[] PROGMEM;
extern const uint8_t sp3_OBSCURED[] PROGMEM;
extern const uint8_t sp3_BROKEN[] PROGMEM;
extern const uint8_t sp3_ALOFT[] PROGMEM;
extern const uint8_t sp3_CEILING[] PROGMEM;
extern const uint8_t sp3_PARTIALLY[] PROGMEM;
extern const uint8_t sp3_VISIBILITY[] PROGMEM;
extern const uint8_t sp3_DRIZZLE[] PROGMEM;
extern const uint8_t sp3_INDICATED[] PROGMEM;
extern const uint8_t sp3_SEVERE[] PROGMEM;
extern const uint8_t sp3_MODERATE[] PROGMEM;
extern const uint8_t sp3_GREENWICH[] PROGMEM;
extern const uint8_t sp3_MEAN[] PROGMEM;
extern const uint8_t sp3_MIST[] PROGMEM;
extern const uint8_t sp3_ESTIMATED[] PROGMEM;
extern const uint8_t sp3_DECREASING[] PROGMEM;
extern const uint8_t sp3_MOVING[] PROGMEM;
extern const uint8_t sp3_PRESSURE[] PROGMEM;
extern const uint8_t sp3_ALTERNATE[] PROGMEM;
extern const uint8_t sp3_CLEAR[] PROGMEM;
extern const uint8_t sp3_CURRENT[] PROGMEM;
extern const uint8_t sp3_BLOWING[] PROGMEM;
extern const uint8_t sp3_AT[] PROGMEM;
extern const uint8_t sp3_TURBULANCE[] PROGMEM;
extern const uint8_t sp3_THINLY[] PROGMEM;
extern const uint8_t sp3_INCREASING[] PROGMEM;
extern const uint8_t sp3_MORE_THAN[] PROGMEM;
extern const uint8_t sp3_LESS_THAN[] PROGMEM;
extern const uint8_t sp3_FREEZING[] PROGMEM;
extern const uint8_t sp3_AIR[] PROGMEM;
extern const uint8_t sp3_BELOW[] PROGMEM;
extern const uint8_t sp3_AND[] PROGMEM;
extern const uint8_t sp3_FOR[] PROGMEM;
extern const uint8_t sp3_HAZE[] PROGMEM;
extern const uint8_t sp3_HIGH[] PROGMEM;
extern const uint8_t sp3_SCATTERED[] PROGMEM;
extern const uint8_t sp3_INCREASING_TO[] PROGMEM;
extern const uint8_t sp3_IN[] PROGMEM;
extern const uint8_t sp3_LOW[] PROGMEM;
extern const uint8_t sp3_THUNDERSTORM[] PROGMEM;
extern const uint8_t sp3_OVERCAST[] PROGMEM;
extern const uint8_t sp3_UNLIMITED[] PROGMEM;
extern const uint8_t sp3_LOW2[] PROGMEM;
extern const uint8_t sp3_PERCENT[] PROGMEM;
extern const uint8_t sp3_OVER[] PROGMEM;

// ROM VM61002
extern const uint8_t sp2_ZERO[]          PROGMEM;
extern const uint8_t sp2_FOUR[]          PROGMEM;
extern const uint8_t sp2_EIGHT[]         PROGMEM;
extern const uint8_t sp2_TWELVE[]        PROGMEM;
extern const uint8_t sp2_TWENTY[]        PROGMEM;
extern const uint8_t sp2_ONE[]           PROGMEM;
extern const uint8_t sp2_FIVE[]          PROGMEM;
extern const uint8_t sp2_NINE[]          PROGMEM;
extern const uint8_t sp2_THIR_[]         PROGMEM;
extern const uint8_t sp2_HUNDRED[]       PROGMEM;
extern const uint8_t sp2_TWO[]           PROGMEM;
extern const uint8_t sp2_SIX[]           PROGMEM;
extern const uint8_t sp2_TEN[]           PROGMEM;
extern const uint8_t sp2_FIF_[]          PROGMEM;
extern const uint8_t sp2_THOUSAND[]      PROGMEM;
extern const uint8_t sp2_THREE[]         PROGMEM;
extern const uint8_t sp2_SEVEN[]         PROGMEM;
extern const uint8_t sp2_ELEVEN[]        PROGMEM;
extern const uint8_t sp2__TEEN[]         PROGMEM;
extern const uint8_t sp2_A[]             PROGMEM;
extern const uint8_t sp2_B[]             PROGMEM;
extern const uint8_t sp2_C[]             PROGMEM;
extern const uint8_t sp2_D[]             PROGMEM;
extern const uint8_t sp2_E[]             PROGMEM;
extern const uint8_t sp2_F[]             PROGMEM;
extern const uint8_t sp2_G[]             PROGMEM;
extern const uint8_t sp2_H[]             PROGMEM;
extern const uint8_t sp2_I[]             PROGMEM;
extern const uint8_t sp2_L[]             PROGMEM;
extern const uint8_t sp2_J[]             PROGMEM;
extern const uint8_t sp2_K[]             PROGMEM;
extern const uint8_t sp2_M[]             PROGMEM;
extern const uint8_t sp2_N[]             PROGMEM;
extern const uint8_t sp2_O[]             PROGMEM;
extern const uint8_t sp2_P[]             PROGMEM;
extern const uint8_t sp2_Q[]             PROGMEM;
extern const uint8_t sp2_R[]             PROGMEM;
extern const uint8_t sp2_S[]             PROGMEM;
extern const uint8_t sp2_T[]             PROGMEM;
extern const uint8_t sp2_U[]             PROGMEM;
extern const uint8_t sp2_V[]             PROGMEM;
extern const uint8_t sp2_W[]             PROGMEM;
extern const uint8_t sp2_X[]             PROGMEM;
extern const uint8_t sp2_Y[]             PROGMEM;
extern const uint8_t sp2_Z[]             PROGMEM;
extern const uint8_t sp2_ALPHA[]         PROGMEM;
extern const uint8_t sp2_BRAVO[]         PROGMEM;
extern const uint8_t sp2_CHARLIE[]       PROGMEM;
extern const uint8_t sp2_DELTA[]         PROGMEM;
extern const uint8_t sp2_ECHO[]          PROGMEM;
extern const uint8_t sp2_FOXTROT[]       PROGMEM;
extern const uint8_t sp2_GOLF[]          PROGMEM;
extern const uint8_t sp2_HENRY[]         PROGMEM;
extern const uint8_t sp2_INDIA[]         PROGMEM;
extern const uint8_t sp2_JULIET[]        PROGMEM;
extern const uint8_t sp2_LIMA[]          PROGMEM;
extern const uint8_t sp2_MIKE[]          PROGMEM;
extern const uint8_t sp2_NOVEMBER[]      PROGMEM;
extern const uint8_t sp2_OSCAR[]         PROGMEM;
extern const uint8_t sp2_PAPA[]          PROGMEM;
extern const uint8_t sp2_QUEBEC[]        PROGMEM;
extern const uint8_t sp2_ROMEO[]         PROGMEM;
extern const uint8_t sp2_SIERRA[]        PROGMEM;
extern const uint8_t sp2_TANGO[]         PROGMEM;
extern const uint8_t sp2_UNIFORM[]       PROGMEM;
extern const uint8_t sp2_VICTOR[]        PROGMEM;
extern const uint8_t sp2_WHISKY[]        PROGMEM;
extern const uint8_t sp2_XRAY[]          PROGMEM;
extern const uint8_t sp2_YANKEE[]        PROGMEM;
extern const uint8_t sp2_ZULU[]          PROGMEM;
extern const uint8_t sp2_THE[]           PROGMEM;
extern const uint8_t sp2_WATTS[]         PROGMEM;
extern const uint8_t sp2_METER[]         PROGMEM;
extern const uint8_t sp2_DANGER[]        PROGMEM;
extern const uint8_t sp2_PRESSURE[]      PROGMEM;
extern const uint8_t sp2_CHANGE[]        PROGMEM;
extern const uint8_t sp2_MINUS[]         PROGMEM;
extern const uint8_t sp2_NOT[]           PROGMEM;
extern const uint8_t sp2_START[]         PROGMEM;
extern const uint8_t sp2_LINE[]          PROGMEM;
extern const uint8_t sp2_OFF[]           PROGMEM;
extern const uint8_t sp2_TIME[]          PROGMEM;
extern const uint8_t sp2_AUTOMATIC[]     PROGMEM;
extern const uint8_t sp2_WEIGHT[]        PROGMEM;
extern const uint8_t sp2_SMOKE[]         PROGMEM;
extern const uint8_t sp2_ABORT[]         PROGMEM;
extern const uint8_t sp2_CALL[]          PROGMEM;
extern const uint8_t sp2_CYCLE[]         PROGMEM;
extern const uint8_t sp2_DISPLAY[]       PROGMEM;
extern const uint8_t sp2_EQUAL[]         PROGMEM;
extern const uint8_t sp2_FAST[]          PROGMEM;
extern const uint8_t sp2_ABOUT[]         PROGMEM;
extern const uint8_t sp2_GO[]            PROGMEM;
extern const uint8_t sp2_INCH[]          PROGMEM;
extern const uint8_t sp2_LOW[]           PROGMEM;
extern const uint8_t sp2_MOTOR[]         PROGMEM;
extern const uint8_t sp2_OPEN[]          PROGMEM;
extern const uint8_t sp2_PERCENT[]       PROGMEM;
extern const uint8_t sp2_PROBE[]         PROGMEM;
extern const uint8_t sp2_READY[]         PROGMEM;
extern const uint8_t sp2_SET[]           PROGMEM;
extern const uint8_t sp2_SPEED[]         PROGMEM;
extern const uint8_t sp2_UNDER[]         PROGMEM;
extern const uint8_t sp2_OPERATOR[]      PROGMEM;
extern const uint8_t sp2_AMPS[]          PROGMEM;
extern const uint8_t sp2_MEGA[]          PROGMEM;
extern const uint8_t sp2_PICO[]          PROGMEM;
extern const uint8_t sp2_FIRE[]          PROGMEM;
extern const uint8_t sp2_POWER[]         PROGMEM;
extern const uint8_t sp2_COMPLETE[]      PROGMEM;
extern const uint8_t sp2_REPAIR[]        PROGMEM;
extern const uint8_t sp2_TEMPERATURE[]   PROGMEM;
extern const uint8_t sp2_STOP[]          PROGMEM;
extern const uint8_t sp2_MACHINE[]       PROGMEM;
extern const uint8_t sp2_ON[]            PROGMEM;
extern const uint8_t sp2_CONTROL[]       PROGMEM;
extern const uint8_t sp2_ELECTRICIAN[]   PROGMEM;
extern const uint8_t sp2_AT[]            PROGMEM;
extern const uint8_t sp2_RED[]           PROGMEM;
extern const uint8_t sp2_ALL[]           PROGMEM;
extern const uint8_t sp2_CANCEL[]        PROGMEM;
extern const uint8_t sp2_PHASE[]         PROGMEM;
extern const uint8_t sp2_NOR[]           PROGMEM;
extern const uint8_t sp2_EXIT[]          PROGMEM;
extern const uint8_t sp2_FLOW[]          PROGMEM;
extern const uint8_t sp2_GAUGE[]         PROGMEM;
extern const uint8_t sp2_GREEN[]         PROGMEM;
extern const uint8_t sp2_INSPECTOR[]     PROGMEM;
extern const uint8_t sp2_MANUAL[]        PROGMEM;
extern const uint8_t sp2_MOVE[]          PROGMEM;
extern const uint8_t sp2_OVER[]          PROGMEM;
extern const uint8_t sp2_PLUS[]          PROGMEM;
extern const uint8_t sp2_PULL[]          PROGMEM;
extern const uint8_t sp2_REPEAT[]        PROGMEM;
extern const uint8_t sp2_SHUT[]          PROGMEM;
extern const uint8_t sp2_TEST[]          PROGMEM;
extern const uint8_t sp2_VOLTS[]         PROGMEM;
extern const uint8_t sp2_GALLONS[]       PROGMEM;
extern const uint8_t sp2_HERTZ[]         PROGMEM;
extern const uint8_t sp2_MICRO[]         PROGMEM;
extern const uint8_t sp2_OHMS[]          PROGMEM;
extern const uint8_t sp2_AREA[]          PROGMEM;
extern const uint8_t sp2_CIRCUIT[]       PROGMEM;
extern const uint8_t sp2_CONNECT[]       PROGMEM;
extern const uint8_t sp2_SECONDS[]       PROGMEM;
extern const uint8_t sp2_UNIT[]          PROGMEM;
extern const uint8_t sp2_TIMER[]         PROGMEM;
extern const uint8_t sp2_UP[]            PROGMEM;
extern const uint8_t sp2_IS[]            PROGMEM;
extern const uint8_t sp2_ALERT[]         PROGMEM;
extern const uint8_t sp2_ADJUST[]        PROGMEM;
extern const uint8_t sp2_BETWEEN[]       PROGMEM;
extern const uint8_t sp2_MINUTES[]       PROGMEM;
extern const uint8_t sp2_BUTTON[]        PROGMEM;
extern const uint8_t sp2_CLOCK[]         PROGMEM;
extern const uint8_t sp2_DEVICE[]        PROGMEM;
extern const uint8_t sp2_EAST[]          PROGMEM;
extern const uint8_t sp2_FAIL[]          PROGMEM;
extern const uint8_t sp2_FREQUENCY[]     PROGMEM;
extern const uint8_t sp2_GATE[]          PROGMEM;
extern const uint8_t sp2_HIGH[]          PROGMEM;
extern const uint8_t sp2_INTRUDER[]      PROGMEM;
extern const uint8_t sp2_MEASURE[]       PROGMEM;
extern const uint8_t sp2_NORTH[]         PROGMEM;
extern const uint8_t sp2_PASS[]          PROGMEM;
extern const uint8_t sp2_POSITION[]      PROGMEM;
extern const uint8_t sp2_PUSH[]          PROGMEM;
extern const uint8_t sp2_RIGHT[]         PROGMEM;
extern const uint8_t sp2_SLOW[]          PROGMEM;
extern const uint8_t sp2_TOOL[]          PROGMEM;
extern const uint8_t sp2_WEST[]          PROGMEM;
extern const uint8_t sp2_KILO[]          PROGMEM;
extern const uint8_t sp2_AND[]           PROGMEM;
extern const uint8_t sp2_FARAD[]         PROGMEM;
extern const uint8_t sp2_MILLI[]         PROGMEM;
extern const uint8_t sp2_CAUTION[]       PROGMEM;
extern const uint8_t sp2_LIGHT[]         PROGMEM;
extern const uint8_t sp2_CHECK[]         PROGMEM;
extern const uint8_t sp2_DEGREES[]       PROGMEM;
extern const uint8_t sp2_SERVICE[]       PROGMEM;
extern const uint8_t sp2_SWITCH[]        PROGMEM;
extern const uint8_t sp2_VALVE[]         PROGMEM;
extern const uint8_t sp2_VAL[]           PROGMEM;
extern const uint8_t sp2_NUMBER[]        PROGMEM;
extern const uint8_t sp2_OUT[]           PROGMEM;
extern const uint8_t sp2_POINT[]         PROGMEM;
extern const uint8_t sp2_BREAK[]         PROGMEM;
extern const uint8_t sp2_HOURS[]         PROGMEM;
extern const uint8_t sp2_CALIBRATE[]     PROGMEM;
extern const uint8_t sp2_CRANE[]         PROGMEM;
extern const uint8_t sp2_DIRECTION[]     PROGMEM;
extern const uint8_t sp2_ENTER[]         PROGMEM;
extern const uint8_t sp2_FEET[]          PROGMEM;
extern const uint8_t sp2_FROM[]          PROGMEM;
extern const uint8_t sp2_GAP[]           PROGMEM;
extern const uint8_t sp2_HOLD[]          PROGMEM;
extern const uint8_t sp2_LEFT[]          PROGMEM;
extern const uint8_t sp2_MILL[]          PROGMEM;
extern const uint8_t sp2_UH[]            PROGMEM;
extern const uint8_t sp2_PAST[]          PROGMEM;
extern const uint8_t sp2_PRESS[]         PROGMEM;
extern const uint8_t sp2_RANGE[]         PROGMEM;
extern const uint8_t sp2_SAFE[]          PROGMEM;
extern const uint8_t sp2_SOUTH[]         PROGMEM;
extern const uint8_t sp2_TURN[]          PROGMEM;
extern const uint8_t sp2_YELLOW[]        PROGMEM;

