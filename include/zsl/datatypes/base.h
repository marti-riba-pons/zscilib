/*
 * Copyright (c) 2021 Kevin Townsend
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * \defgroup DATATYPES Data Types
 *
 * @brief SI data types used to represent data samples
 */

/**
 * @file
 * @brief Standard data type definitions for zscilib.
 *
 * This file contains a list of standard (SI) data types used to represent
 * data samples or values in zscilib.
 */

#ifndef ZEPHYR_INCLUDE_ZSL_DATATYPES_BASE_H_
#define ZEPHYR_INCLUDE_ZSL_DATATYPES_BASE_H_

#include <zsl/zsl.h>
#include <zsl/datatypes/si_units.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * TODO: A macro and lookup table is required to associate each data 'type'
 * with the correct default SI unit.
 */

/**
 * @brief Base data type. An 8-bit value representing a family or class of
 *        measured values or data samples. This base type can be further
 *        specialised from it's default type by using of an 8-bit extended
 *        type that is associated with the parent ('base') value. Base types
 *        have common default values if an extended type is not specified
 *        (extended type = 0).
 *
 * Memory map:
 *   - 0 = Undefined
 *   - 0x10..0x7F = Standard data types
 *   - 0x80..0xEF = Reserved
 *   - 0xF0..0xFE = User-defined base data types
 */
enum zsl_dt_base {
	ZSL_DT_BASE_UNDEFINED           = 0,

	ZSL_DT_BASE_AREA                = 0x10, /**< ZSL_DT_SI_UNIT_METERS_2 */
	ZSL_DT_BASE_ACCELERATION        = 0x11, /**< ZSL_DT_SI_UNIT_METER_PER_SECOND_2 (linear, gravity) */
	ZSL_DT_BASE_AMPLITUDE           = 0x12, /**< 0..1.0 */
	ZSL_DT_BASE_CAPACITANCE         = 0x13, /**< ZSL_DT_SI_UNIT_FARAD */
	ZSL_DT_BASE_COLOR               = 0x14, /**< See extended type */
	ZSL_DT_BASE_COORDINATES         = 0x15, /**< XY vector? */
	ZSL_DT_BASE_CURRENT             = 0x16, /**< ZSL_DT_SI_UNIT_AMPERE */
	ZSL_DT_BASE_DIMENSION           = 0x17, /**< ZSL_DT_SI_UNIT_METER (length, width, distance, etc.) */
	ZSL_DT_BASE_FREQUENCY           = 0x18, /**< ZSL_DT_SI_UNIT_HERTZ */
	ZSL_DT_BASE_HUMIDITY            = 0x19, /**< relative humidity in percent */
	ZSL_DT_BASE_INDUCTANCE          = 0x1A, /**< ZSL_DT_SI_UNIT_HENRY */
	ZSL_DT_BASE_LIGHT               = 0x1B, /**< ZSL_DT_SI_UNIT_LUX */
	ZSL_DT_BASE_MAGNETIC_FIELD      = 0x1C, /**< ZSL_DT_SI_UNIT_TESLA */
	ZSL_DT_BASE_MASS                = 0x1D, /**< ZSL_DT_SI_UNIT_KILOGRAM */
	ZSL_DT_BASE_MOMENTUM            = 0x1E, /**< Angular, Linear, Inertia */
	ZSL_DT_BASE_ORIENTATION         = 0x1F, /**< XYZ vector */
	ZSL_DT_BASE_PHASE               = 0x20, /**< ZSL_DT_SI_UNIT_RADIAN */
	ZSL_DT_BASE_PRESSURE            = 0x21, /**< ZSL_DT_SI_UNIT_PASCAL */
	ZSL_DT_BASE_RESISTANCE          = 0x22, /**< ZSL_DT_SI_UNIT_OHM */
	ZSL_DT_BASE_SOUND               = 0x23, /**< ZSL_DT_SI_UNIT_HERTZ */
	ZSL_DT_BASE_TEMPERATURE         = 0x24, /**< ZSL_DT_SI_UNIT_DEGREE_CELSIUS */
	ZSL_DT_BASE_TIME                = 0x25, /**< ZSL_DT_SI_UNIT_SECOND */
	ZSL_DT_BASE_VELOCITY            = 0x26, /**< ZSL_DT_SI_UNIT_METERS_3_SECOND */
	ZSL_DT_BASE_VOLTAGE             = 0x27, /**< ZSL_DT_SI_UNIT_VOLT */
	ZSL_DT_BASE_VOLUME              = 0x28, /**< ZSL_DT_SI_UNIT_METERS_3 */
	ZSL_DT_BASE_ACIDITY             = 0x29, /**< ZSL_DT_SI_UNIT_PH */
	ZSL_DT_BASE_CONDUCTIVITY        = 0x2A, /**< ZSL_DT_SI_UNIT_SIEMENS_PER_METER */

	ZSL_DT_BASE_USER_1              = 0xF0, /**< User-defined value 1. */
	ZSL_DT_BASE_USER_2              = 0xF1, /**< User-defined value 2. */
	ZSL_DT_BASE_USER_3              = 0xF2, /**< User-defined value 3. */
	ZSL_DT_BASE_USER_4              = 0xF3, /**< User-defined value 4. */
	ZSL_DT_BASE_USER_5              = 0xF4, /**< User-defined value 5. */
	ZSL_DT_BASE_USER_6              = 0xF5, /**< User-defined value 6. */
	ZSL_DT_BASE_USER_7              = 0xF6, /**< User-defined value 7. */
	ZSL_DT_BASE_USER_8              = 0xF7, /**< User-defined value 8. */
	ZSL_DT_BASE_USER_9              = 0xF8, /**< User-defined value 9. */
	ZSL_DT_BASE_USER_10             = 0xF9, /**< User-defined value 10. */
	ZSL_DT_BASE_USER_11             = 0xFA, /**< User-defined value 11. */
	ZSL_DT_BASE_USER_12             = 0xFB, /**< User-defined value 12. */
	ZSL_DT_BASE_USER_13             = 0xFC, /**< User-defined value 13. */
	ZSL_DT_BASE_USER_14             = 0xFD, /**< User-defined value 14. */
	ZSL_DT_BASE_USER_15             = 0xFE, /**< User-defined value 15. */

	ZSL_DT_BASE_MAX                 = 0xFF  /** Reserved. */
};

/**
 * @brief Type used when implementing a unit (8-bits).
 * 
 * Memory map:
 *   - 0 = Undefined
 *   - 0x10..0x3F = Standard C types
 *   - 0x40..0x7F = zscilib types (matrix, vector, etc.)
 *   - 0x80..0xEF = Reserved
 *   - 0xF0..0xFE = User-defined types
 */
enum zsl_dt_unit_type {
	ZSL_DT_UNIT_TYPE_UNDEFINED              = 0x00,

	/** 0x10..0x3F: Standard C types. */
	ZSL_DT_UNIT_TYPE_FLOAT32                = 0x10,
	ZSL_DT_UNIT_TYPE_FLOAT64                = 0x11,
	ZSL_DT_UNIT_TYPE_FLOAT128               = 0x12,
	ZSL_DT_UNIT_TYPE_S8                     = 0x13,
	ZSL_DT_UNIT_TYPE_S16                    = 0x14,
	ZSL_DT_UNIT_TYPE_S32                    = 0x15,
	ZSL_DT_UNIT_TYPE_S64                    = 0x16,
	ZSL_DT_UNIT_TYPE_S64                    = 0x17,
	ZSL_DT_UNIT_TYPE_U8                     = 0x18,
	ZSL_DT_UNIT_TYPE_U16                    = 0x19,
	ZSL_DT_UNIT_TYPE_U32                    = 0x1A,
	ZSL_DT_UNIT_TYPE_U64                    = 0x1B,
	ZSL_DT_UNIT_TYPE_U128                   = 0x1C,
	ZSL_DT_UNIT_TYPE_BOOL                   = 0x1D,
	ZSL_DT_UNIT_TYPE_COMPLEX_32             = 0x30,
	ZSL_DT_UNIT_TYPE_COMPLEX_64             = 0x31,

	/** 0x40..0x7F: zscilib types (matrix, vector, etc.). */
	ZSL_DT_UNIT_TYPE_ZSL_VECTOR_REAL32      = 0x40,
	ZSL_DT_UNIT_TYPE_ZSL_VECTOR_REAL64      = 0x41,
	ZSL_DT_UNIT_TYPE_ZSL_MATRIX_REAL32      = 0x50,
	ZSL_DT_UNIT_TYPE_ZSL_MATRIX_REAL64      = 0x51,

	/** 0xF0..0xFE: User-defined types. */
	ZSL_DT_UNIT_TYPE_USER_1                 = 0xF0,
	ZSL_DT_UNIT_TYPE_USER_2                 = 0xF1,
	ZSL_DT_UNIT_TYPE_USER_3                 = 0xF2,
	ZSL_DT_UNIT_TYPE_USER_4                 = 0xF3,
	ZSL_DT_UNIT_TYPE_USER_5                 = 0xF4,
	ZSL_DT_UNIT_TYPE_USER_6                 = 0xF5,
	ZSL_DT_UNIT_TYPE_USER_7                 = 0xF6,
	ZSL_DT_UNIT_TYPE_USER_8                 = 0xF7,
	ZSL_DT_UNIT_TYPE_USER_9                 = 0xF8,
	ZSL_DT_UNIT_TYPE_USER_10                = 0xF9,
	ZSL_DT_UNIT_TYPE_USER_11                = 0xFA,
	ZSL_DT_UNIT_TYPE_USER_12                = 0xFB,
	ZSL_DT_UNIT_TYPE_USER_13                = 0xFC,
	ZSL_DT_UNIT_TYPE_USER_14                = 0xFD,
	ZSL_DT_UNIT_TYPE_USER_15                = 0xFE,

	ZSL_DT_UNIT_TYPE_MAX                    = 0xFF
};

/**
 * @brief Defines a specific measurement type and SI unit for a data sample.
 *        Composed of an 8-bit base measurement type (base_type), an optional
 *        8-bit extended type (ext_type), and a 16-bit SI unit that indicates
 *        what SI unit and scale the measurement type makes use of (unit).
 *
 * Using a base and extended value pair for measurement type allows for
 * specialisation from the default type associated with a measurement family.
 * It should be possible to represent any reasonably standard measurement
 * using these value pairs in a 16-bit space.
 *
 * Indicating the SI unit (and scale) alongside the measurement type allows
 * for better control over the samples, and the ability to choose a more
 * appropriate scale depending on the source of the measurement (uA versus A,
 * for example).
 *
 * @note Must be in little-endian format.
 *
 * @note When the extended type is left at 0, the base type's default
 *       unit will be used (ZSL_DT_SI_UNIT_AMPERE for ZSL_DT_BASE_CURRENT,
 *       for example).
 */
struct zsl_dt_type {
	union {
		struct {
			/**
			 * @brief The base measurement type, which will be associated with
			 * a specific default SI unit and scale.
			 */
			uint8_t base_type;

			/**
			 * @brief The extended measurement type, which allows for
			 * specialisation of the base type. This field must be interpretted
			 * relative to the sample's base_type.
			 *
			 * Leaving this value at 0 indicates that the base_type's default
			 * SI unit and scale should be used.
			 */
			uint8_t ext_type;
		};
		/**
		 * @brief Represents the base and extended data types.
		 */
		uint16_t type;
	};

	/**
	 * @brief The SI unit and scale used for this measurement. Must be
	 * a member of zsl_dt_si_unit.
	 *
	 * @note This will normally indicate the default unit associated with
	 * .type, but can optionally be overriden by the producer to adjust for
	 * scale, for example.
	 */
	uint16_t unit;
};

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_INCLUDE_ZSL_DATATYPES_BASE_H_ */

/** @} */ /* End of DATATYPES group */
