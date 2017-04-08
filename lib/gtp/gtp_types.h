#ifndef __GTP_TYPES_H__
#define __GTP_TYPES_H__

#include "core_tlv_msg.h"
#include "3gpp_common.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* 8.4 Cause */
#define GTP_CAUSE_LOCAL_DETACH  2
#define GTP_CAUSE_COMPLETE_DETACH_3
#define GTP_CAUSE_RAT_CHANGED_FROM_3GPP_TO_NON_3GPP 4
#define GTP_CAUSE_ISR_DEACTIVATION  5
#define GTP_CAUSE_ERROR_INDICATION_RECEIVED_FROM_RNC_ENODEB_S4_SGSN_MME 6
#define GTP_CAUSE_IMSI_DETACH_ONLY  7
#define GTP_CAUSE_REACTIVATION_REQUESTED 8
#define GTP_CAUSE_PDN_RECONNECTION_TO_THIS_APN_DISALLOWED 9
#define GTP_CAUSE_ACCESS_CHANGED_FROM_NON_3GPP_TO_3GPP  10
#define GTP_CAUSE_PDN_CONNECTION_INACTIVITY_TIMER_EXPIRES 11
#define GTP_CAUSE_PGW_NOT_RESPONDING 12
#define GTP_CAUSE_NETWORK_FAILURE 13
#define GTP_CAUSE_QOS_PARAMETER_MISMATCH 14
#define GTP_CAUSE_REQUEST_ACCEPTED  16
#define GTP_CAUSE_REQUEST_ACCEPTED_PARTIALLY 17
#define GTP_CAUSE_NEW_PDN_TYPE_DUE_TO_NETWORK_PREFERENCE 18
#define GTP_CAUSE_NEW_PDN_TYPE_DUE_TO_SINGLE_ADDRESS_BEARER_ONLY 19
#define GTP_CAUSE_CONTEXT_NOT_FOUND 64
#define GTP_CAUSE_INVALID_MESSAGE_FORMAT 65
#define GTP_CAUSE_VERSION_NOT_SUPPORTED_BY_NEXT_PEER 66
#define GTP_CAUSE_INVALID_LENGTH 67
#define GTP_CAUSE_SERVICE_NOT_SUPPORTED 68
#define GTP_CAUSE_MANDATORY_IE_INCORRECT 69
#define GTP_CAUSE_MANDATORY_IE_MISSING  70
#define GTP_CAUSE_SYSTEM_FAILURE 72
#define GTP_CAUSE_NO_RESOURCES_AVAILABLE 73
#define GTP_CAUSE_SEMANTIC_ERROR_IN_THE_TFT_OPERATION 74
#define GTP_CAUSE_SYNTACTIC_ERROR_IN_THE_TFT_OPERATION  75
#define GTP_CAUSE_SEMANTIC_ERRORS_IN_PACKET_FILTER 76
#define GTP_CAUSE_SYNTACTIC_ERRORS_IN_PACKET_FILTER  77
#define GTP_CAUSE_MISSING_OR_UNKNOWN_APN 78
#define GTP_CAUSE_GRE_KEY_NOT_FOUND 80
#define GTP_CAUSE_RELOCATION_FAILURE 81
#define GTP_CAUSE_DENIED_IN_RAT 82
#define GTP_CAUSE_PREFERRED_PDN_TYPE_NOT_SUPPORTED  83
#define GTP_CAUSE_ALL_DYNAMIC_ADDRESSES_ARE_OCCUPIED 84
#define GTP_CAUSE_UE_CONTEXT_WITHOUT_TFT_ALREADY_ACTIVATED 85
#define GTP_CAUSE_PROTOCOL_TYPE_NOT_SUPPORTED 86
#define GTP_CAUSE_UE_NOT_RESPONDING 87
#define GTP_CAUSE_UE_REFUSES 88
#define GTP_CAUSE_SERVICE_DENIED 89
#define GTP_CAUSE_UNABLE_TO_PAGE_UE 90
#define GTP_CAUSE_NO_MEMORY_AVAILABLE 91
#define GTP_CAUSE_USER_AUTHENTICATION_FAILED 92
#define GTP_CAUSE_APN_ACCESS_DENIED_NO_SUBSCRIPTION 93
#define GTP_CAUSE_REQUEST_REJECTED_REASON_NOT_SPECIFIED 94
#define GTP_CAUSE_P_TMSI_SIGNATURE_MISMATCH 95
#define GTP_CAUSE_IMSI_IMEI_NOT_KNOWN 96
#define GTP_CAUSE_SEMANTIC_ERROR_IN_THE_TAD_OPERATION 97
#define GTP_CAUSE_SYNTACTIC_ERROR_IN_THE_TAD_OPERATION 98
#define GTP_CAUSE_REMOTE_PEER_NOT_RESPONDING 100
#define GTP_CAUSE_COLLISION_WITH_NETWORK_INITIATED_REQUEST  101
#define GTP_CAUSE_UNABLE_TO_PAGE_UE_DUE_TO_SUSPENSION 102
#define GTP_CAUSE_CONDITIONAL_IE_MISSING 103
#define GTP_CAUSE_APN_RESTRICTION_TYPE_INCOMPATIBLE 104
#define GTP_CAUSE_INVALID_OVERALL_LENGTH 105
#define GTP_CAUSE_DATA_FORWARDING_NOT_SUPPORTED 106
#define GTP_CAUSE_INVALID_REPLY_FROM_REMOTE_PEER 107
#define GTP_CAUSE_FALLBACK_TO_GTPV1 108
#define GTP_CAUSE_INVALID_PEER  109
#define GTP_CAUSE_TEMPORARILY_REJECTED_DUE_TO_HANDOVER_IN_PROGRESS 110
#define GTP_CAUSE_MODIFICATIONS_NOT_LIMITED_TO_S1_U_BEARERS 111
#define GTP_CAUSE_REQUEST_REJECTED_FOR_A_PMIPV6_REASON 112
#define GTP_CAUSE_APN_CONGESTION 113
#define GTP_CAUSE_BEARER_HANDLING_NOT_SUPPORTED 114
#define GTP_CAUSE_UE_ALREADY_RE_ATTACHED 115
#define GTP_CAUSE_MULTIPLE_PDN_CONNECTIONS_FOR_A_GIVEN_APN_NOT_ALLOWED  116
#define GTP_CAUSE_TARGET_ACCESS_RESTRICTED_FOR_THE_SUBSCRIBER 117
#define GTP_CAUSE_MME_SGSN_REFUSES_DUE_TO_VPLMN_POLICY  119
#define GTP_CAUSE_GTP_C_ENTITY_CONGESTION 120
#define GTP_CAUSE_LATE_OVERLAPPING_REQUEST  121
#define GTP_CAUSE_TIMED_OUT_REQUEST 122
#define GTP_CAUSE_UE_IS_TEMPORARILY_NOT_REACHABLE_DUE_TO_POWER_SAVING 123
#define GTP_CAUSE_RELOCATION_FAILURE_DUE_TO_NAS_MESSAGE_REDIRECTION 124
#define GTP_CAUSE_UE_NOT_AUTHORISED_BY_OCS_OR_EXTERNAL_AAA_SERVER 125
#define GTP_CAUSE_MULTIPLE_ACCESSES_TO_A_PDN_CONNECTION_NOT_ALLOWED 126
#define GTP_CAUSE_REQUEST_REJECTED_DUE_TO_UE_CAPABILITY 127

typedef struct _gtp_cause_t {
    c_uint8_t cause_value;
ED4(c_uint8_t spare:5;,
    c_uint8_t pce:1;,
    c_uint8_t bce:1;,
    c_uint8_t cs:1;)
} __attribute__ ((packed)) gtp_cause_t;

/* 8.7 Aggregate Maximum Bit Rate (AMBR) */
typedef struct _gtp_ambr_t {
    c_uint32_t uplink;
    c_uint32_t downlink;
} __attribute__ ((packed)) gtp_ambr_t;

/* 8.13 Protocol Configuration Options (PCO) 
 * 10.5.6.3 Protocol configuration options in 3GPP TS 24.008 
 * RFC 3232 [103]
 * RFC 1661 [102] */
#define GTP_PCO_PPP_FOR_USE_WITH_IP_PDP_TYPE_OR_IP_PDN_TYPE 0

#define GTP_PROTOCOL_OR_CONTAINER_ID_INTERNET_PROTOCOL_CONTROL_PROTOCOL 0x8021
#define GTP_PROTOCOL_OR_CONTAINER_ID_DNS_SERVER_IPV4_ADDRESS_REQUEST 0x000d
#define GTP_PROTOCOL_OR_CONTAINER_ID_IP_ADDRESS_ALLOCATION_VIA_NAS_SIGNALLING 0x000a
typedef struct _gtp_protocol_or_container_id_t {
    c_uint16_t id;
    c_uint8_t length;
    void *contents;
} gtp_protocol_or_container_id_t;

#define GTP_MAX_PROTOCOL_OR_CONTAINER_ID    4
#define GTP_MAX_PCO_LEN 253
typedef struct _gtp_pco_t {
ED3(c_uint8_t ext:1;,
    c_uint8_t spare:4;,
    c_uint8_t configuration_protocol:3;)
    c_uint8_t num_of_id;
    gtp_protocol_or_container_id_t ids[GTP_MAX_PROTOCOL_OR_CONTAINER_ID];
} gtp_pco_t;

CORE_DECLARE(c_int16_t) gtp_parse_pco(gtp_pco_t *pco, tlv_octet_t *octet);
CORE_DECLARE(c_int16_t) gtp_build_pco(
        tlv_octet_t *octet, gtp_pco_t *pco, void *data, int data_len);

/* 8.15 Bearer Quality of Service (Bearer QoS) */
#define GTP_BEARER_QOS_LEN 22
typedef struct _gtp_bearer_qos_t {
ED5(c_uint8_t spare1:1;,
    /* See 3GPP TS 29.212[29], clause 5.3.46 Pre-emption-Capability AVP. */
    c_uint8_t pci:1;, 
    /* See 3GPP TS 29.212[29], clause 5.3.45 Priority-Level AVP. 
     * PL encodes each priority level defined for the Priority-Level AVP 
     * as the binary value of the priority level.  */
    c_uint8_t pl:4;,
    c_uint8_t spare2:1;,
    /* See 3GPP TS 29.212[29], clause 5.3.47 Pre-emption-Vulnerability AVP. */
    c_uint8_t pvi:1;)
    c_uint8_t qci; /* specified in 3GPP TS 23.203 [48]. */

    /* specified in 3GPP TS 36.413 [10]. */
    c_uint64_t ul_mbr;
    c_uint64_t dl_mbr;
    c_uint64_t ul_gbr;
    c_uint64_t dl_gbr;

    /* NOTE : The encoding in 3GPP TS 24.301 [23] and 3GPP TS 36.413 [10] 
     * is different from the encoding within this specification.  */
} __attribute__ ((packed)) gtp_bearer_qos_t;

CORE_DECLARE(c_int16_t) gtp_parse_bearer_qos(
    gtp_bearer_qos_t *bearer_qos, tlv_octet_t *octet);
CORE_DECLARE(c_int16_t) gtp_build_bearer_qos(
    tlv_octet_t *octet, gtp_bearer_qos_t *bearer_qos, void *data, int data_len);

/* 8.17 RAT Type */
#define GTP_RAT_TYPE_UTRAN                                  1
#define GTP_RAT_TYPE_GERAN                                  2
#define GTP_RAT_TYPE_WLAN                                   3
#define GTP_RAT_TYPE_GAN                                    4
#define GTP_RAT_TYPE_HSPA_EVOLUTION                         5
#define GTP_RAT_TYPE_EUTRAN                                 6
#define GTP_RAT_TYPE_VIRTUAL                                7
#define GTP_RAT_TYPE_EUTRAN_NB_IOT                          8

/* 8.21 User Location Information (ULI) */
#define GTP_MAX_ULI_LEN sizeof(gtp_uli_t)
typedef struct _gtp_uli_cgi_t {
    plmn_id_t plmn_id;
    c_uint16_t lac;
    c_uint16_t ci;
} __attribute__ ((packed)) gtp_uli_cgi_t;

typedef struct _gtp_uli_sai_t {
    plmn_id_t plmn_id;
    c_uint16_t lac;
    c_uint16_t sac;
} __attribute__ ((packed)) gtp_uli_sai_t;

typedef struct _gtp_uli_rai_t {
    plmn_id_t plmn_id;
    c_uint16_t lac;
    c_uint16_t rac;
} __attribute__ ((packed)) gtp_uli_rai_t;

typedef struct _gtp_uli_tai_t {
    plmn_id_t plmn_id;
    c_uint16_t tac;
} __attribute__ ((packed)) gtp_uli_tai_t;

typedef struct _gtp_uli_ecgi_t {
    plmn_id_t plmn_id;
    c_uint32_t eci; /* 28 bit */
} __attribute__ ((packed)) gtp_uli_ecgi_t;

typedef struct _gtp_uli_lai_t {
    plmn_id_t plmn_id;
    c_uint16_t lac;
} __attribute__ ((packed)) gtp_uli_lai_t;

typedef struct _gtp_uli_t {
    struct {
    ED7(c_uint8_t spare:2;,
        c_uint8_t lai:1;,
        c_uint8_t ecgi:1;,
        c_uint8_t tai:1;,
        c_uint8_t rai:1;,
        c_uint8_t sai:1;,
        c_uint8_t cgi:1;)
    } flags;
    gtp_uli_cgi_t cgi;
    gtp_uli_sai_t sai;
    gtp_uli_rai_t rai;
    gtp_uli_tai_t tai;
    gtp_uli_ecgi_t ecgi;
    gtp_uli_lai_t lai;
} gtp_uli_t;

CORE_DECLARE(c_int16_t) gtp_parse_uli(gtp_uli_t *uli, tlv_octet_t *octet);
CORE_DECLARE(c_int16_t) gtp_build_uli(
        tlv_octet_t *octet, gtp_uli_t *uli, void *data, int data_len);

/* 8.14 PDN Address Allocation (PAA) */
#define GTP_PAA_IPV4_LEN                                    5
#define GTP_PAA_IPV6_LEN                                    18
typedef struct _gtp_paa_t {
ED2(c_uint8_t spare:6;,
    c_uint8_t pdn_type:2;)
    union {
        c_uint32_t ipv4_prefix;;
        struct {
            c_uint8_t ipv6_prefix_lengh;
            c_uint8_t ipv6_prefix[16];
        };
    };
} gtp_paa_t;

/* 8.22 Fully Qualified TEID (F-TEID) */
#define GTP_F_TEID_S1_U_ENODEB_GTP_U                        0
#define GTP_F_TEID_S1_U_SGW_GTP_U                           1
#define GTP_F_TEID_S12_RNC_GTP_U                            2
#define GTP_F_TEID_S12_SGW_GTP_U                            3
#define GTP_F_TEID_S5_S8_SGW_GTP_U                          4
#define GTP_F_TEID_S5_S8_PGW_GTP_U                          5
#define GTP_F_TEID_S5_S8_SGW_GTP_C                          6
#define GTP_F_TEID_S5_S8_PGW_GTP_C                          7
#define GTP_F_TEID_S5_S8_SGW_PMIPV6                         8
#define GTP_F_TEID_S5_S8_PGW_PMIPV6                         9
#define GTP_F_TEID_S11_MME_GTP_C                            10
#define GTP_F_TEID_S11_S4_SGW_GTP_C                         11
#define GTP_F_TEID_S10_MME_GTP_C                            12
#define GTP_F_TEID_S3_MME_GTP_C                             13
#define GTP_F_TEID_S3_SGSN_GTP_C                            14
#define GTP_F_TEID_S4_SGSN_GTP_U                            15
#define GTP_F_TEID_S4_SGW_GTP_U                             16
#define GTP_F_TEID_S4_SGSN_GTP_C                            17
#define GTP_F_TEID_S16_SGSN_GTP_C                           18
#define GTP_F_TEID_ENODEB_GTP_U_FOR_DL_DATA_FORWARDING      19
#define GTP_F_TEID_ENODEB_GTP_U_FOR_UL_DATA_FORWARDING      20
#define GTP_F_TEID_RNC_GTP_U_FOR_DATA_FORWARDING            21
#define GTP_F_TEID_SGSN_GTP_U_FOR_DATA_FORWARDING           22
#define GTP_F_TEID_SGW_GTP_U_FOR_DL_DATA_FORWARDING         23
#define GTP_F_TEID_SM_MBMS_GW_GTP_C                         24
#define GTP_F_TEID_SN_MBMS_GW_GTP_C                         25
#define GTP_F_TEID_SM_MME_GTP_C                             26
#define GTP_F_TEID_SN_SGSN_GTP_C                            27
#define GTP_F_TEID_SGW_GTP_U_FOR_UL_DATA_FORWARDING         28
#define GTP_F_TEID_SN_SGSN_GTP_U                            29
#define GTP_F_TEID_S2B_EPDG_GTP_C                           30
#define GTP_F_TEID_S2B_U_EPDG_GTP_U                         31
#define GTP_F_TEID_S2B_PGW_GTP_C                            32
#define GTP_F_TEID_S2B_U_PGW_GTP_U                          33
#define GTP_F_TEID_S2A_TWAN_GTP_U                           34
#define GTP_F_TEID_S2A_TWAN_GTP_C                           35
#define GTP_F_TEID_S2A_PGW_GTP_C                            36
#define GTP_F_TEID_S2A_PGW_GTP_U                            37
#define GTP_F_TEID_S11_MME_GTP_U                            38
#define GTP_F_TEID_S11_SGW_GTP_U                            39

#define GTP_F_TEID_IPV4_LEN                                 9
#define GTP_F_TEID_IPV6_LEN                                 21
typedef struct _gtp_f_teid_t {
ED3(c_uint8_t ipv4:1;,
    c_uint8_t ipv6:1;,
    c_uint8_t interface_type:6;)
    c_uint32_t teid;
    union {
        c_uint32_t ipv4_addr;
        c_uint8_t ipv6_addr[IPV6_LEN];
    };
} __attribute__ ((packed)) gtp_f_teid_t;

/* 8.34 PDN Type  */
#define GTP_PDN_TYPE_IPV4                                   1
#define GTP_PDN_TYPE_IPV6                                   2
#define GTP_PDN_TYPE_BOTH                                   3
#define GTP_PDN_TYPE_NON_IP                                 4

/* 8.44 UE Time Zone */
#define GTP_UE_TIME_ZONE_NO_ADJUSTMENT_FOR_DAYLIGHT_SAVING_TIME 0
#define GTP_UE_TIME_ZONE_1_HOUR_FOR_DAYLIGHT_SAVING_TIME        1
#define GTP_UE_TIME_ZONE_2_HOUR_FOR_DAYLIGHT_SAVING_TIME        2
typedef struct _gtp_ue_timezone_t {
    /* Time Zone" IE in 3GPP TS 24.008 [5].
     * This field uses the same format as the Timezone field used in the 
     * TP-Service-Centre-Time-Stamp, which is defined in 3GPP TS 23.040 [90], 
     * and its value shall be set as defined in 3GPP TS 22.042 */
    c_uint8_t timezone;
ED2(c_uint8_t spare:6;,
    c_uint8_t daylight_saving_time:2;)
} __attribute__ ((packed)) gtp_ue_timezone_t;

/* 8.57 APN Restriction */
#define GTP_APN_NO_RESTRICTION                              0
#define GTP_APN_RESTRICTION_PUBLIC_1                        1
#define GTP_APN_RESTRICTION_PUBLIC_2                        2
#define GTP_APN_RESTRICTION_PRIVATE_1                       3
#define GTP_APN_RESTRICTION_PRIVATE_2                       4

/* 8.58 Selection Mode */
#define GTP_SELECTION_MODE_MS_OR_NETWORK_PROVIDED_APN       0
#define GTP_SELECTION_MODE_MS_PROVIDED_APN                  1
#define GTP_SELECTION_MODE_NETWORK_PROVIDED_APN             2

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __GTP_TYPES_H__ */
