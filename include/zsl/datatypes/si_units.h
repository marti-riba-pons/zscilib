/*
 * Copyright (c) 2021 Kevin Townsend
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @addtogroup DATATYPES_SI SI units and scales
 *
 * @brief Enums for SI base, derived and combined units and scales.
 *
 * \ingroup DATATYPES
 *  @{ */

/**
 * @file
 * @brief SI unit and scale definitions for zscilib.
 *
 * This file contains a list of standard (SI) units and scales used to
 * represent data samples or values in zscilib.
 */

#ifndef ZEPHYR_INCLUDE_ZSL_DATATYPES_SI_UNITS_H_
#define ZEPHYR_INCLUDE_ZSL_DATATYPES_SI_UNITS_H_

#include <zsl/zsl.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Standard SI scales/powers.
 */
enum zsl_dt_si_scale {
	ZSL_DT_SI_SCALE_YOTTA      = 24,   /**< Y: Septillion */
	ZSL_DT_SI_SCALE_ZETTA      = 21,   /**< Z: Sextillion */
	ZSL_DT_SI_SCALE_EXA        = 18,   /**< E: Quintillion */
	ZSL_DT_SI_SCALE_PETA       = 15,   /**< P: Quadrillion */
	ZSL_DT_SI_SCALE_TERA       = 12,   /**< T: Trillion */
	ZSL_DT_SI_SCALE_GIGA       = 9,    /**< G: Billion */
	ZSL_DT_SI_SCALE_MEGA       = 6,    /**< M: Million */
	ZSL_DT_SI_SCALE_KILO       = 3,    /**< k: Thousand */
	ZSL_DT_SI_SCALE_HECTO      = 2,    /**< h: Hundred */
	ZSL_DT_SI_SCALE_DECA       = 1,    /**< da: Ten*/
	ZSL_DT_SI_SCALE_NONE       = 0,    /**< One */
	ZSL_DT_SI_SCALE_DECI       = -1,   /**< d: Tenth */
	ZSL_DT_SI_SCALE_CENTI      = -2,   /**< c: Hundredth */
	ZSL_DT_SI_SCALE_MILLI      = -3,   /**< m: Thousandth */
	ZSL_DT_SI_SCALE_MICRO      = -6,   /**< u: Millionth */
	ZSL_DT_SI_SCALE_NANO       = -9,   /**< n: Billionth */
	ZSL_DT_SI_SCALE_PICO       = -12,  /**< p: Trillionth */
	ZSL_DT_SI_SCALE_FEMTO      = -15,  /**< f: Quadrillionth */
	ZSL_DT_SI_SCALE_ATTO       = -18,  /**< a: Quintillionth */
	ZSL_DT_SI_SCALE_ZEPTO      = -21,  /**< z: Sextillionth */
	ZSL_DT_SI_SCALE_YOCTO      = -24,  /**< y: Septillionth */
};

/**
 * @brief Standard SI units (16-bits).
 *
 * @note Base and derived SI units can be represented in 8-bits, while
 * combined units require 16-bits to represent.
 *
 * Memory map:
 *   - 0              = Undefined
 *   - 0x0010..0x001F = SI base units
 *   - 0x0020..0x003F = SI derived units
 *   - 0x0040..0x00FF = Reserved
 *   - 0x0100..0x7FFF = Combined units 
 *   - 0x8000..0xFEFF = Reserved
 *   - 0xFF00..0xFFFE = User defined units
 */
enum zsl_dt_si_unit {
	ZSL_DT_SI_UNIT_UNDEFINED                                        = 0,

	/* 0x0010..0x001F (16-31): SI Base Units. */
	/** @brief A, electric current */
	ZSL_DT_SI_UNIT_AMPERE                                           = 0x10,
	/** @brief cd, Luminous intensity */
	ZSL_DT_SI_UNIT_CANDELA                                          = 0x11,
	/** @brief K, thermodynamic temp. */
	ZSL_DT_SI_UNIT_KELVIN                                           = 0x12,
	/** @brief kg, mass */
	ZSL_DT_SI_UNIT_KILOGRAM                                         = 0x13,
	/** @brief m, length */
	ZSL_DT_SI_UNIT_METER                                            = 0x14,
	/** @brief mol, Amount of substance */
	ZSL_DT_SI_UNIT_MOLE                                             = 0x15,
	/** @brief s, time */
	ZSL_DT_SI_UNIT_SECOND                                           = 0x16,

	/* 0x0020..0x003F (32-63): SI Derived Units. */
	/** @brief Bq, radionucl. activity, 1/s */
	ZSL_DT_SI_UNIT_BECQUEREL                                        = 0x20,
	/** @brief C, electric charge, A*s */
	ZSL_DT_SI_UNIT_COULOMB                                          = 0x21,
	/** @brief Degrees C, Celsius temp, K */
	ZSL_DT_SI_UNIT_DEGREE_CELSIUS                                   = 0x22,
	/** @brief F, elec. capaticance, C/V or s^4*A^2/m^2*kg */
	ZSL_DT_SI_UNIT_FARAD                                            = 0x23,
	/** @brief Gy, Absorbed dose, J/kg or m^2/s^2 */
	ZSL_DT_SI_UNIT_GRAY                                             = 0x24,
	/** @brief H, electric inductance, Wb/A or kg*m^2/s^2*A^2 */
	ZSL_DT_SI_UNIT_HENRY                                            = 0x25,
	/** @brief Hz, frequency, 1/s */
	ZSL_DT_SI_UNIT_HERTZ                                            = 0x26,
	/** @brief J, energy, work, N*m or kg*m^2/s^2 */
	ZSL_DT_SI_UNIT_JOULE                                            = 0x27,
	/** @brief kat, Catamytic activ., mol/s */
	ZSL_DT_SI_UNIT_KATAL                                            = 0x28,
	/** @brief lm, Luminous flux, cd*sr */
	ZSL_DT_SI_UNIT_LUMEN                                            = 0x29,
	/** @brief lx, illuminance, lm/m^2 */
	ZSL_DT_SI_UNIT_LUX                                              = 0x2A,
	/** @brief N, force, m*kg/s^2 */
	ZSL_DT_SI_UNIT_NEWTON                                           = 0x2B,
	/** @brief electric resistence, V/A or kg*m^2/s^3*A^2*/
	ZSL_DT_SI_UNIT_OHM                                              = 0x2C,
	/** @brief Pa, pressure, stress, N/m^2 or kg/m*s^2 */
	ZSL_DT_SI_UNIT_PASCAL                                           = 0x2D,
	/** @brief rad, plane angle, m/m */
	ZSL_DT_SI_UNIT_RADIAN                                           = 0x2E,
	/** @brief S, electric conductance, A/V */
	ZSL_DT_SI_UNIT_SIEMENS                                          = 0x2F,
	/** @brief Sv, Dose equivalent, J/kg or m^2/s^2 */
	ZSL_DT_SI_UNIT_SIEVERT                                          = 0x30,
	/** @brief sr, solid angle, m^2/m^2 */
	ZSL_DT_SI_UNIT_STERADIAN                                        = 0x31,
	/** @brief T, magn. flux dens., Wb/m^2 or kg/A*s^2*/
	ZSL_DT_SI_UNIT_TESLA                                            = 0x32,
	/** @brief V, elec. poten. diff, W/A or kg*m^2/A*s^3 */
	ZSL_DT_SI_UNIT_VOLT                                             = 0x33,
	/** @brief W, power, radiant flux, J/s or kg*m^2/s^3 */
	ZSL_DT_SI_UNIT_WATT                                             = 0x34,
	/** @brief Wb, magnetic flux, V*s or kg*m^2/s^2*A */
	ZSL_DT_SI_UNIT_WEBER                                            = 0x35,

	/* 0x1000..0x10FF: ZSL_DT_BASE_AREA Combined Units. */
	/** @brief m^2 */
	ZSL_DT_SI_UNIT_METERS_2                                         = 0x1000,

	/* 0x1100..0x11FF: ZSL_DT_BASE_ACCELERATION Combined Units. */
	/** @brief m/s^2 */
	ZSL_DT_SI_UNIT_METER_PER_SECOND_2                               = 0x1100,

	/* 0x1200..0x12FF: ZSL_DT_BASE_AMPLITUDE Combined Units. */

	/* 0x1300..0x13FF: ZSL_DT_BASE_CAPACITANCE Combined Units. */

	/* 0x1400..0x14FF: ZSL_DT_BASE_COLOR Combined Units. */

	/* 0x1500..0x15FF: ZSL_DT_BASE_COORDINATES Combined Units. */

	/* 0x1600..0x16FF: ZSL_DT_BASE_CURRENT Combined Units. */

	/* 0x1700..0x17FF: ZSL_DT_BASE_DIMENSION Combined Units. */

	/* 0x1800..0x18FF: ZSL_DT_BASE_FREQUENCYY Combined Units. */

	/* 0x1900..0x19FF: ZSL_DT_BASE_HUMIDITY Combined Units. */

	/* 0x1A00..0x1AFF: ZSL_DT_BASE_INDUCTANCE Combined Units. */

	/* 0x1B00..0x1BFF: ZSL_DT_BASE_LIGHT Combined Units. */
	/** @brief cd/m^2 */
	ZSL_DT_SI_UNIT_CANDELA_PER_METER_2                              = 0x1B00,
	/** @brief J/m^2 */
	ZSL_DT_SI_UNIT_JOULE_PER_METER_2                                = 0x1B01,
	/** @brief J/m^2/Hz */
	ZSL_DT_SI_UNIT_JOULE_PER_METER_2_PER_HZ                         = 0x1B02,
	/** @brief J/m^2/nm */
	ZSL_DT_SI_UNIT_JOULE_PER_METER_2_PER_NM                         = 0x1B03,
	/** @brief Energy density, J/m^3 */
	ZSL_DT_SI_UNIT_JOULE_PER_METER_3                                = 0x1B04,
	/** @brief lm/m^2 */
	ZSL_DT_SI_UNIT_LUMEN_PER_METER_2                                = 0x1B05,
	/** @brief lm/W */
	ZSL_DT_SI_UNIT_LUMEN_PER_WATT                                   = 0x1B06,
	/** @brief lm s, AKA talbot */
	ZSL_DT_SI_UNIT_LUMEN_SECOND                                     = 0x1B07,
	/** @brief lm s/m^3 */
	ZSL_DT_SI_UNIT_LUMEN_SECOND_PER_METER_3                         = 0x1B08,
	/** @brief lx s */
	ZSL_DT_SI_UNIT_LUX_SECOND                                       = 0x1B09,
	/** @brief W/Hz */
	ZSL_DT_SI_UNIT_WATTS_PER_HERTZ                                  = 0x1B0A,
	/** @brief W/m^2 */
	ZSL_DT_SI_UNIT_WATTS_PER_METER_2                                = 0x1B0B,
	/** @brief W/m^2/Hz */
	ZSL_DT_SI_UNIT_WATTS_PER_METER_2_PER_HZ                         = 0x1B0C,
	/** @brief W/m^2/nm */
	ZSL_DT_SI_UNIT_WATTS_PER_METER_2_PER_NM                         = 0x1B0D,
	/** @brief W/nm */
	ZSL_DT_SI_UNIT_WATTS_PER_NM                                     = 0x1B0E,
	/** @brief W/sr */
	ZSL_DT_SI_UNIT_WATTS_PER_STERADIAN                              = 0x1B0F,
	/** @brief W/sr/Hz */
	ZSL_DT_SI_UNIT_WATTS_PER_STERADIAN_PER_HERTZ                    = 0x1B10,
	/** @brief W/sr/m^2 */
	ZSL_DT_SI_UNIT_WATTS_PER_STERADIAN_PER_METER_2                  = 0x1B11,
	/** @brief W/sr/m^2/Hz */
	ZSL_DT_SI_UNIT_WATTS_PER_STERADIAN_PER_METER_2_PER_HZ           = 0x1B12,
	/** @brief W/sr/m^2/nm */
	ZSL_DT_SI_UNIT_WATTS_PER_STERADIAN_PER_METER_2_PER_NM           = 0x1B13,
	/** @brief W/sr/nm */
	ZSL_DT_SI_UNIT_WATTS_PER_STERADIAN_PER_NM                       = 0x1B14,

	/* 0x1C00..0x1CFF: ZSL_DT_BASE_MAGNETIC_FIELD Combined Units. */
	/** @brief uT */
	ZSL_DT_SI_UNIT_MICROTESLA                                       = 0x1C00,

	/* 0x1D00..0x1DFF: ZSL_DT_BASE_MASS Combined Units. */
	/** @brief g */
	ZSL_DT_SI_UNIT_GRAMS                                            = 0x1D00,

	/* 0x1E00..0x1EFF: ZSL_DT_BASE_MOMENTUM Combined Units. */

	/* 0x1F00..0x1FFF: ZSL_DT_BASE_ORIENTATION Combined Units. */

	/* 0x2000..0x20FF: ZSL_DT_BASE_PHASE Combined Units. */

	/* 0x2100..0x21FF: ZSL_DT_BASE_PRESSURE Combined Units. */
	/** @brief hPA */
	ZSL_DT_SI_UNIT_HECTOPASCAL                                      = 0x2100,

	/* 0x2200..0x22FF: ZSL_DT_BASE_RESISTANCE Combined Units. */

	/* 0x2300..0x23FF: ZSL_DT_BASE_SOUND Combined Units. */

	/* 0x2400..0x24FF: ZSL_DT_BASE_TEMPERATURE Combined Units. */

	/* 0x2500..0x25FF: ZSL_DT_BASE_TIME Combined Units. */

	/* 0x2600..0x26FF: ZSL_DT_BASE_VELOCITY Combined Units. */
	/** @brief m^3/s, flow rate. */
	ZSL_DT_SI_UNIT_METERS_3_SECOND                                  = 0x2601,

	/* 0x2700..0x27FF: ZSL_DT_BASE_VOLTAGE Combined Units. */
	/** @brief mV */
	ZSL_DT_SI_UNIT_MILLIVOLTS                                       = 0x2700,

	/* 0x2800..0x28FF: ZSL_DT_BASE_VOLUME Combined Units. */
	/** @brief m^3 */
	ZSL_DT_SI_UNIT_METERS_3                                         = 0x2800,

	/* 0x2900..0x29FF: ZSL_DT_BASE_ACIDITY Combined Units. */
	/** @brief pH level (not actually a unit, shhh!) */
	ZSL_DT_SI_UNIT_PH                                               = 0x2900,

	/* 0x2A00..0x2AFF: ZSL_DT_BASE_CONDUCTIVITY Combined Units. */
	/** @brief S/m */
	ZSL_DT_SI_UNIT_SIEMENS_PER_METER                                = 0x2A00,

	/* 0xFF00..0xFFFE = User defined units. */
	ZSL_DT_SI_UNIT_USER_DEFINED_1                                   = 0xFF00,
	ZSL_DT_SI_UNIT_USER_DEFINED_255                                 = 0xFFFE,

	ZSL_DT_SI_UNIT_MAX                                              = 0xFFFF
};

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_INCLUDE_ZSL_DATATYPES_SI_UNITS_H_ */

/** @} */ /* End of DATATYPES_SI group */
