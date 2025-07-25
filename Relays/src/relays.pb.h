/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.9.1 */

#ifndef PB_RELAYS_PB_H_INCLUDED
#define PB_RELAYS_PB_H_INCLUDED
#include "utils/pb.h"
#include "utils.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _RelaysCommand {
    BoolState backLeftMotor;
    BoolState backRightMotor;
    BoolState frontLeftMotor;
    BoolState frontRightMotor;
    BoolState arm;
    BoolState science;
    BoolState drive;
    BoolState bypass;
} RelaysCommand;

typedef struct _RelaysData {
    BoolState backLeftMotor;
    BoolState backRightMotor;
    BoolState frontLeftMotor;
    BoolState frontRightMotor;
    BoolState arm;
    BoolState science;
    BoolState drive;
    BoolState bypass;
    BoolState mechanicalOverride;
    float voltageData;
} RelaysData;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define RelaysCommand_init_default               {_BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN}
#define RelaysData_init_default                  {_BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN, 0}
#define RelaysCommand_init_zero                  {_BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN}
#define RelaysData_init_zero                     {_BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN, _BoolState_MIN, 0}

/* Field tags (for use in manual encoding/decoding) */
#define RelaysCommand_backLeftMotor_tag          1
#define RelaysCommand_backRightMotor_tag         2
#define RelaysCommand_frontLeftMotor_tag         3
#define RelaysCommand_frontRightMotor_tag        4
#define RelaysCommand_arm_tag                    5
#define RelaysCommand_science_tag                6
#define RelaysCommand_drive_tag                  7
#define RelaysCommand_bypass_tag                 8
#define RelaysData_backLeftMotor_tag             1
#define RelaysData_backRightMotor_tag            2
#define RelaysData_frontLeftMotor_tag            3
#define RelaysData_frontRightMotor_tag           4
#define RelaysData_arm_tag                       5
#define RelaysData_science_tag                   6
#define RelaysData_drive_tag                     7
#define RelaysData_bypass_tag                    8
#define RelaysData_mechanicalOverride_tag        9
#define RelaysData_voltageData_tag               10

/* Struct field encoding specification for nanopb */
#define RelaysCommand_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    backLeftMotor,     1) \
X(a, STATIC,   SINGULAR, UENUM,    backRightMotor,    2) \
X(a, STATIC,   SINGULAR, UENUM,    frontLeftMotor,    3) \
X(a, STATIC,   SINGULAR, UENUM,    frontRightMotor,   4) \
X(a, STATIC,   SINGULAR, UENUM,    arm,               5) \
X(a, STATIC,   SINGULAR, UENUM,    science,           6) \
X(a, STATIC,   SINGULAR, UENUM,    drive,             7) \
X(a, STATIC,   SINGULAR, UENUM,    bypass,            8)
#define RelaysCommand_CALLBACK NULL
#define RelaysCommand_DEFAULT NULL

#define RelaysData_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    backLeftMotor,     1) \
X(a, STATIC,   SINGULAR, UENUM,    backRightMotor,    2) \
X(a, STATIC,   SINGULAR, UENUM,    frontLeftMotor,    3) \
X(a, STATIC,   SINGULAR, UENUM,    frontRightMotor,   4) \
X(a, STATIC,   SINGULAR, UENUM,    arm,               5) \
X(a, STATIC,   SINGULAR, UENUM,    science,           6) \
X(a, STATIC,   SINGULAR, UENUM,    drive,             7) \
X(a, STATIC,   SINGULAR, UENUM,    bypass,            8) \
X(a, STATIC,   SINGULAR, UENUM,    mechanicalOverride,   9) \
X(a, STATIC,   SINGULAR, FLOAT,    voltageData,      10)
#define RelaysData_CALLBACK NULL
#define RelaysData_DEFAULT NULL

extern const pb_msgdesc_t RelaysCommand_msg;
extern const pb_msgdesc_t RelaysData_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define RelaysCommand_fields &RelaysCommand_msg
#define RelaysData_fields &RelaysData_msg

/* Maximum encoded size of messages (where known) */
#define RELAYS_PB_H_MAX_SIZE                     RelaysData_size
#define RelaysCommand_size                       16
#define RelaysData_size                          23

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
