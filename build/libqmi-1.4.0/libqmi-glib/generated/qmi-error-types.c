
/* Generated data (by glib-mkenums) */

#include "qmi-errors.h"
#include "qmi-error-types.h"
/* enumerations from "../../libqmi-glib/qmi-errors.h" */
static const GEnumValue qmi_core_error_values[] = {
    { QMI_CORE_ERROR_FAILED, "QMI_CORE_ERROR_FAILED", "Failed" },
    { QMI_CORE_ERROR_WRONG_STATE, "QMI_CORE_ERROR_WRONG_STATE", "WrongState" },
    { QMI_CORE_ERROR_TIMEOUT, "QMI_CORE_ERROR_TIMEOUT", "Timeout" },
    { QMI_CORE_ERROR_INVALID_ARGS, "QMI_CORE_ERROR_INVALID_ARGS", "InvalidArgs" },
    { QMI_CORE_ERROR_INVALID_MESSAGE, "QMI_CORE_ERROR_INVALID_MESSAGE", "InvalidMessage" },
    { QMI_CORE_ERROR_TLV_NOT_FOUND, "QMI_CORE_ERROR_TLV_NOT_FOUND", "TlvNotFound" },
    { QMI_CORE_ERROR_TLV_TOO_LONG, "QMI_CORE_ERROR_TLV_TOO_LONG", "TlvTooLong" },
    { QMI_CORE_ERROR_UNSUPPORTED, "QMI_CORE_ERROR_UNSUPPORTED", "Unsupported" },
    { 0, NULL, NULL }
};

/* qmi_core_error_quark() implemented in qmi-errors-quarks.c */

GType
qmi_core_error_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiCoreError"),
                                      qmi_core_error_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
const gchar *
qmi_core_error_get_string (QmiCoreError val)
{
    guint i;

    for (i = 0; qmi_core_error_values[i].value_nick; i++) {
        if (val == qmi_core_error_values[i].value)
            return qmi_core_error_values[i].value_nick;
    }

    return NULL;
}

static const GEnumValue qmi_protocol_error_values[] = {
    { QMI_PROTOCOL_ERROR_NONE, "QMI_PROTOCOL_ERROR_NONE", "None" },
    { QMI_PROTOCOL_ERROR_MALFORMED_MESSAGE, "QMI_PROTOCOL_ERROR_MALFORMED_MESSAGE", "MalformedMessage" },
    { QMI_PROTOCOL_ERROR_NO_MEMORY, "QMI_PROTOCOL_ERROR_NO_MEMORY", "NoMemory" },
    { QMI_PROTOCOL_ERROR_INTERNAL, "QMI_PROTOCOL_ERROR_INTERNAL", "Internal" },
    { QMI_PROTOCOL_ERROR_ABORTED, "QMI_PROTOCOL_ERROR_ABORTED", "Aborted" },
    { QMI_PROTOCOL_ERROR_CLIENT_IDS_EXHAUSTED, "QMI_PROTOCOL_ERROR_CLIENT_IDS_EXHAUSTED", "ClientIdsExhausted" },
    { QMI_PROTOCOL_ERROR_UNABORTABLE_TRANSACTION, "QMI_PROTOCOL_ERROR_UNABORTABLE_TRANSACTION", "UnabortableTransaction" },
    { QMI_PROTOCOL_ERROR_INVALID_CLIENT_ID, "QMI_PROTOCOL_ERROR_INVALID_CLIENT_ID", "InvalidClientId" },
    { QMI_PROTOCOL_ERROR_NO_THRESHOLDS_PROVIDED, "QMI_PROTOCOL_ERROR_NO_THRESHOLDS_PROVIDED", "NoThresholdsProvided" },
    { QMI_PROTOCOL_ERROR_INVALID_HANDLE, "QMI_PROTOCOL_ERROR_INVALID_HANDLE", "InvalidHandle" },
    { QMI_PROTOCOL_ERROR_INVALID_PROFILE, "QMI_PROTOCOL_ERROR_INVALID_PROFILE", "InvalidProfile" },
    { QMI_PROTOCOL_ERROR_INVALID_PIN_ID, "QMI_PROTOCOL_ERROR_INVALID_PIN_ID", "InvalidPinId" },
    { QMI_PROTOCOL_ERROR_INCORRECT_PIN, "QMI_PROTOCOL_ERROR_INCORRECT_PIN", "IncorrectPin" },
    { QMI_PROTOCOL_ERROR_NO_NETWORK_FOUND, "QMI_PROTOCOL_ERROR_NO_NETWORK_FOUND", "NoNetworkFound" },
    { QMI_PROTOCOL_ERROR_CALL_FAILED, "QMI_PROTOCOL_ERROR_CALL_FAILED", "CallFailed" },
    { QMI_PROTOCOL_ERROR_OUT_OF_CALL, "QMI_PROTOCOL_ERROR_OUT_OF_CALL", "OutOfCall" },
    { QMI_PROTOCOL_ERROR_NOT_PROVISIONED, "QMI_PROTOCOL_ERROR_NOT_PROVISIONED", "NotProvisioned" },
    { QMI_PROTOCOL_ERROR_MISSING_ARGUMENT, "QMI_PROTOCOL_ERROR_MISSING_ARGUMENT", "MissingArgument" },
    { QMI_PROTOCOL_ERROR_ARGUMENT_TOO_LONG, "QMI_PROTOCOL_ERROR_ARGUMENT_TOO_LONG", "ArgumentTooLong" },
    { QMI_PROTOCOL_ERROR_INVALID_TRANSACTION_ID, "QMI_PROTOCOL_ERROR_INVALID_TRANSACTION_ID", "InvalidTransactionId" },
    { QMI_PROTOCOL_ERROR_DEVICE_IN_USE, "QMI_PROTOCOL_ERROR_DEVICE_IN_USE", "DeviceInUse" },
    { QMI_PROTOCOL_ERROR_NETWORK_UNSUPPORTED, "QMI_PROTOCOL_ERROR_NETWORK_UNSUPPORTED", "NetworkUnsupported" },
    { QMI_PROTOCOL_ERROR_DEVICE_UNSUPPORTED, "QMI_PROTOCOL_ERROR_DEVICE_UNSUPPORTED", "DeviceUnsupported" },
    { QMI_PROTOCOL_ERROR_NO_EFFECT, "QMI_PROTOCOL_ERROR_NO_EFFECT", "NoEffect" },
    { QMI_PROTOCOL_ERROR_NO_FREE_PROFILE, "QMI_PROTOCOL_ERROR_NO_FREE_PROFILE", "NoFreeProfile" },
    { QMI_PROTOCOL_ERROR_INVALID_PDP_TYPE, "QMI_PROTOCOL_ERROR_INVALID_PDP_TYPE", "InvalidPdpType" },
    { QMI_PROTOCOL_ERROR_INVALID_TECHNOLOGY_PREFERENCE, "QMI_PROTOCOL_ERROR_INVALID_TECHNOLOGY_PREFERENCE", "InvalidTechnologyPreference" },
    { QMI_PROTOCOL_ERROR_INVALID_PROFILE_TYPE, "QMI_PROTOCOL_ERROR_INVALID_PROFILE_TYPE", "InvalidProfileType" },
    { QMI_PROTOCOL_ERROR_INVALID_SERVICE_TYPE, "QMI_PROTOCOL_ERROR_INVALID_SERVICE_TYPE", "InvalidServiceType" },
    { QMI_PROTOCOL_ERROR_INVALID_REGISTER_ACTION, "QMI_PROTOCOL_ERROR_INVALID_REGISTER_ACTION", "InvalidRegisterAction" },
    { QMI_PROTOCOL_ERROR_INVALID_PS_ATTACH_ACTION, "QMI_PROTOCOL_ERROR_INVALID_PS_ATTACH_ACTION", "InvalidPsAttachAction" },
    { QMI_PROTOCOL_ERROR_AUTHENTICATION_FAILED, "QMI_PROTOCOL_ERROR_AUTHENTICATION_FAILED", "AuthenticationFailed" },
    { QMI_PROTOCOL_ERROR_PIN_BLOCKED, "QMI_PROTOCOL_ERROR_PIN_BLOCKED", "PinBlocked" },
    { QMI_PROTOCOL_ERROR_PIN_ALWAYS_BLOCKED, "QMI_PROTOCOL_ERROR_PIN_ALWAYS_BLOCKED", "PinAlwaysBlocked" },
    { QMI_PROTOCOL_ERROR_UIM_UNINITIALIZED, "QMI_PROTOCOL_ERROR_UIM_UNINITIALIZED", "UimUninitialized" },
    { QMI_PROTOCOL_ERROR_MAXIMUM_QOS_REQUESTS_IN_USE, "QMI_PROTOCOL_ERROR_MAXIMUM_QOS_REQUESTS_IN_USE", "MaximumQosRequestsInUse" },
    { QMI_PROTOCOL_ERROR_INCORRECT_FLOW_FILTER, "QMI_PROTOCOL_ERROR_INCORRECT_FLOW_FILTER", "IncorrectFlowFilter" },
    { QMI_PROTOCOL_ERROR_NETWORK_QOS_UNAWARE, "QMI_PROTOCOL_ERROR_NETWORK_QOS_UNAWARE", " NetworkQosUnaware" },
    { QMI_PROTOCOL_ERROR_INVALID_QOS_ID, "QMI_PROTOCOL_ERROR_INVALID_QOS_ID", "InvalidQosId" },
    { QMI_PROTOCOL_ERROR_QOS_UNAVAILABLE, "QMI_PROTOCOL_ERROR_QOS_UNAVAILABLE", "QosUnavailable" },
    { QMI_PROTOCOL_ERROR_FLOW_SUSPENDED, "QMI_PROTOCOL_ERROR_FLOW_SUSPENDED", "FlowSuspended" },
    { QMI_PROTOCOL_ERROR_GENERAL_ERROR, "QMI_PROTOCOL_ERROR_GENERAL_ERROR", "GeneralError" },
    { QMI_PROTOCOL_ERROR_UNKNOWN_ERROR, "QMI_PROTOCOL_ERROR_UNKNOWN_ERROR", "UnknownError" },
    { QMI_PROTOCOL_ERROR_INVALID_ARGUMENT, "QMI_PROTOCOL_ERROR_INVALID_ARGUMENT", "InvalidArgument" },
    { QMI_PROTOCOL_ERROR_INVALID_INDEX, "QMI_PROTOCOL_ERROR_INVALID_INDEX", "InvalidIndex" },
    { QMI_PROTOCOL_ERROR_NO_ENTRY, "QMI_PROTOCOL_ERROR_NO_ENTRY", "NoEntry" },
    { QMI_PROTOCOL_ERROR_DEVICE_STORAGE_FULL, "QMI_PROTOCOL_ERROR_DEVICE_STORAGE_FULL", "DeviceStorageFull" },
    { QMI_PROTOCOL_ERROR_DEVICE_NOT_READY, "QMI_PROTOCOL_ERROR_DEVICE_NOT_READY", "DeviceNotReady" },
    { QMI_PROTOCOL_ERROR_NETWORK_NOT_READY, "QMI_PROTOCOL_ERROR_NETWORK_NOT_READY", "NetworkNotReady" },
    { QMI_PROTOCOL_ERROR_WMS_CAUSE_CODE, "QMI_PROTOCOL_ERROR_WMS_CAUSE_CODE", "Wms.CauseCode" },
    { QMI_PROTOCOL_ERROR_WMS_MESSAGE_NOT_SENT, "QMI_PROTOCOL_ERROR_WMS_MESSAGE_NOT_SENT", "Wms.MessageNotSent" },
    { QMI_PROTOCOL_ERROR_WMS_MESSAGE_DELIVERY_FAILURE, "QMI_PROTOCOL_ERROR_WMS_MESSAGE_DELIVERY_FAILURE", "Wms.MessageDeliveryFailure" },
    { QMI_PROTOCOL_ERROR_WMS_INVALID_MESSAGE_ID, "QMI_PROTOCOL_ERROR_WMS_INVALID_MESSAGE_ID", "Wms.InvalidMessageId" },
    { QMI_PROTOCOL_ERROR_WMS_ENCODING, "QMI_PROTOCOL_ERROR_WMS_ENCODING", "Wms.Encoding" },
    { QMI_PROTOCOL_ERROR_AUTHENTICATION_LOCK, "QMI_PROTOCOL_ERROR_AUTHENTICATION_LOCK", "AuthenticationLock" },
    { QMI_PROTOCOL_ERROR_INVALID_TRANSITION, "QMI_PROTOCOL_ERROR_INVALID_TRANSITION", "InvalidTransaction" },
    { QMI_PROTOCOL_ERROR_SESSION_INACTIVE, "QMI_PROTOCOL_ERROR_SESSION_INACTIVE", "SessionInactive" },
    { QMI_PROTOCOL_ERROR_SESSION_INVALID, "QMI_PROTOCOL_ERROR_SESSION_INVALID", "SessionInvalid" },
    { QMI_PROTOCOL_ERROR_SESSION_OWNERSHIP, "QMI_PROTOCOL_ERROR_SESSION_OWNERSHIP", "SessionOwnership" },
    { QMI_PROTOCOL_ERROR_INSUFFICIENT_RESOURCES, "QMI_PROTOCOL_ERROR_INSUFFICIENT_RESOURCES", "InsufficientResources" },
    { QMI_PROTOCOL_ERROR_DISABLED, "QMI_PROTOCOL_ERROR_DISABLED", "Disabled" },
    { QMI_PROTOCOL_ERROR_INVALID_OPERATION, "QMI_PROTOCOL_ERROR_INVALID_OPERATION", "InvalidOperation" },
    { QMI_PROTOCOL_ERROR_INVALID_QMI_COMMAND, "QMI_PROTOCOL_ERROR_INVALID_QMI_COMMAND", "InvalidQmiCommand" },
    { QMI_PROTOCOL_ERROR_WMS_T_PDU_TYPE, "QMI_PROTOCOL_ERROR_WMS_T_PDU_TYPE", "Wms.TPduType" },
    { QMI_PROTOCOL_ERROR_WMS_SMSC_ADDRESS, "QMI_PROTOCOL_ERROR_WMS_SMSC_ADDRESS", "Wms.SmscAddress" },
    { QMI_PROTOCOL_ERROR_INFORMATION_UNAVAILABLE, "QMI_PROTOCOL_ERROR_INFORMATION_UNAVAILABLE", "InformationUnavailable" },
    { QMI_PROTOCOL_ERROR_SEGMENT_TOO_LONG, "QMI_PROTOCOL_ERROR_SEGMENT_TOO_LONG", "SegmentTooLong" },
    { QMI_PROTOCOL_ERROR_SEGMENT_ORDER, "QMI_PROTOCOL_ERROR_SEGMENT_ORDER", "SegmentOrder" },
    { QMI_PROTOCOL_ERROR_BUNDLING_NOT_SUPPORTED, "QMI_PROTOCOL_ERROR_BUNDLING_NOT_SUPPORTED", "BundlingNotSupported" },
    { QMI_PROTOCOL_ERROR_SIM_FILE_NOT_FOUND, "QMI_PROTOCOL_ERROR_SIM_FILE_NOT_FOUND", "SimFileNotFound" },
    { QMI_PROTOCOL_ERROR_ACCESS_DENIED, "QMI_PROTOCOL_ERROR_ACCESS_DENIED", "AccessDenied" },
    { QMI_PROTOCOL_ERROR_HARDWARE_RESTRICTED, "QMI_PROTOCOL_ERROR_HARDWARE_RESTRICTED", "HardwareRestricted" },
    { QMI_PROTOCOL_ERROR_CAT_EVENT_REGISTRATION_FAILED, "QMI_PROTOCOL_ERROR_CAT_EVENT_REGISTRATION_FAILED", "Cat.EventRegistrationFailed" },
    { QMI_PROTOCOL_ERROR_CAT_INVALID_TERMINAL_RESPONSE, "QMI_PROTOCOL_ERROR_CAT_INVALID_TERMINAL_RESPONSE", "Cat.InvalidTerminalResponse" },
    { QMI_PROTOCOL_ERROR_CAT_INVALID_ENVELOPE_COMMAND, "QMI_PROTOCOL_ERROR_CAT_INVALID_ENVELOPE_COMMAND", "Cat.InvalidEnvelopeCommand" },
    { QMI_PROTOCOL_ERROR_CAT_ENVELOPE_COMMAND_BUSY, "QMI_PROTOCOL_ERROR_CAT_ENVELOPE_COMMAND_BUSY", "Cat.EnvelopCommandBusy" },
    { QMI_PROTOCOL_ERROR_CAT_ENVELOPE_COMMAND_FAILED, "QMI_PROTOCOL_ERROR_CAT_ENVELOPE_COMMAND_FAILED", "Cat.EnvelopeCommandFailed" },
    { 0, NULL, NULL }
};

/* qmi_protocol_error_quark() implemented in qmi-errors-quarks.c */

GType
qmi_protocol_error_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiProtocolError"),
                                      qmi_protocol_error_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
const gchar *
qmi_protocol_error_get_string (QmiProtocolError val)
{
    guint i;

    for (i = 0; qmi_protocol_error_values[i].value_nick; i++) {
        if (val == qmi_protocol_error_values[i].value)
            return qmi_protocol_error_values[i].value_nick;
    }

    return NULL;
}


/* Generated data ends here */

